#pragma once

// C++98 doesn't have std::ptrdiff_t so we use std::ptrdiff_t with an additional include <cstddef>.
#include <cstddef>
#include <iterator>

#include "remove_cv.hpp"

namespace ft
{
	struct input_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag	: public input_iterator_tag {};
	struct random_access_iterator_tag	: public forward_iterator_tag {};
	struct output_iterator_tag			: public bidirectional_iterator_tag {};

	// our base for different iterator types. Stock all the caracteristic of an
	// iterator for later use.
	template <typename Category, typename T, typename Distance = std::ptrdiff_t,
			typename Pointer = T*, typename Reference = T&>
	struct iterator
	{
		typedef T         									value_type;
		typedef Distance  									difference_type;
		typedef Pointer   									pointer;
		typedef Reference 									reference;
		typedef Category  									iterator_category;
	};

// ITERATOR_TRAITS ----------------------------------------------------------------------------------------------
	template <typename Iterator>
		struct iterator_traits
		{
			// Specifies the category of the iterator, in this case 
			// std::random_access_iterator_tag which means that the 
			// iterator is a random access iterator.
			typedef typename Iterator::iterator_category	iterator_category;
			// value_type: Specifies the type of the elements that can be 
			// accessed through the iterator.
			typedef typename Iterator::value_type			value_type;
			// difference_type: Specifies the type of the difference between
			// two iterators.
			typedef typename Iterator::difference_type		difference_type;
		    // pointer: Specifies the type of the pointer to an element.
			typedef typename Iterator::pointer				pointer;
			// reference: Specifies the type of the reference to an element.
			typedef typename Iterator::reference			reference;
		};
	
	template <typename T>
		struct iterator_traits<T*> 
		{
			typedef std::random_access_iterator_tag		iterator_category;
			typedef T 									value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef T*									pointer;
			typedef T&									reference;
		};
	
	template <typename T>
		struct iterator_traits<const T*>
		{
			typedef std::random_access_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef const T*							pointer;
			typedef const T&							reference;
		};

// REVERSE_ITERATOR ----------------------------------------------------------------------------------------------


// std::reverse_iterator is an iterator adaptor that reverses the direction of a given iterator,
	template <typename Iterator>
	class reverse_iterator
	{
		protected:
			Iterator current_position;

		public:
			typedef typename ft::iterator_traits<Iterator>::iterator_category 	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type        	value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type   	difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer           	pointer;
			typedef typename ft::iterator_traits<Iterator>::reference         	reference;

	// CONSTRUCTORS --------------------------------------------------------------------------------------------------------------
			// default constructor
			reverse_iterator()
			: current_position() 
			{};

			// Initializes current_position with it.
			explicit reverse_iterator(Iterator input_it)
			: current_position(input_it)
			{};

			// copy constructor - initializes current with u.current.
			template <typename OtherIterator>
				reverse_iterator(const OtherIterator & other)
				: current_position(other.base())
				{};

	// MEMBER FUNCTIONS --------------------------------------------------------------------------------------------------------------

			// returns the underlying base iterator (returns current_postion)
			Iterator base() const
			{ 
				return current_position;
			};

			reference operator*() const
			{ 
				Iterator tmp(current_position); return *--tmp;
			};

	// 	OPERATOR OVERLOADS --------------------------------------------------------------------------------------------------------------
			pointer operator->() const
			{ 
				return &(operator*());
			};

			reverse_iterator& operator++()
			{
				--current_position;
				return *this;
			};

			reverse_iterator operator++(int)
			{
				reverse_iterator tmp(*this);
				--current_position;
				return tmp;
			};

			reverse_iterator& operator--()
			{
				++current_position;
				return *this;
			};

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp(*this);
				++current_position;
				return tmp;
			};

			reverse_iterator operator+(difference_type n) const
			{
				return reverse_iterator(current_position - n);
			};

			reverse_iterator& operator+=(difference_type n)
			{
				current_position -= n;
				return *this;
			};

			reverse_iterator operator-(difference_type n) const
			{
				return reverse_iterator(current_position + n);
			};

			reverse_iterator& operator-=(difference_type n)
			{
				current_position += n;
				return *this;
			};

			reference operator[](difference_type n) const
			{
				return current_position[-n - 1];
			};
	};

	template <class Iterator>
		bool    operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return (x.base() == y.base());
		}

	template <class T, class U>
		bool    operator==(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
		{
			return (x.base() == y.base());
		}

	template <class Iterator>
		bool    operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return (x.base() != y.base());
		}

	template <class T, class U>
		bool    operator!=(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
		{
			return (x.base() != y.base());
		}

	template <class Iterator>
		bool    operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return (x.base() < y.base());
		}

	template <class T, class U>
		bool    operator>(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
		{
			return (x.base() < y.base());
		}

	template <class Iterator>
		bool    operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return (x.base() <= y.base());
		}

	template <class T, class U>
		bool    operator>=(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
		{
			return (x.base() <= y.base());
		}

	template <class Iterator>
		bool    operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return (x.base() > y.base());
		}

	template <class T, class U>
		bool    operator<(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
		{
			return (x.base() > y.base());
		}

	template <class Iterator>
		bool    operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return (x.base() >= y.base());
		}

	template <class T, class U>
		bool    operator<=(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
		{
			return (x.base() >= y.base());
		}

	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type    operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
		{
			return (y.base() - x.base());
		}

	template <class T, class U>
		typename reverse_iterator<T>::difference_type    operator-(const reverse_iterator<T>& x, const reverse_iterator<U>& y)
		{
			return (y.base() - x.base());
		}

	template <class Iterator>
		reverse_iterator<Iterator>  operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
		{
			return (x + n);
		}
}