#pragma once

#include <iostream>
#include "remove_cv.hpp"

namespace ft
{
	template <typename T>
	// the specific vector implemented for our own vector container
	class vectorIterator
	{
		
		public:

			typedef T                               value_type;
			typedef T*                              pointer;
			typedef T&                              reference;
			typedef std::ptrdiff_t                  difference_type;
			typedef std::random_access_iterator_tag iterator_category;

			// constructor
			vectorIterator(pointer ptr = pointer())
			: pointer_(ptr)
			{};

			// copy constructor
			vectorIterator(const vectorIterator<typename remove_cv<value_type>::type> & src)
			: pointer_(src.base())
			{};

			// destructor
			~vectorIterator(void)
			{};

// GETTERS ---------------------------------------------------------------------------------------------
				
			pointer base() const
			{
				return pointer_;
			}


// OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
				
			// assignement operator
			vectorIterator<T>&    operator=(const vectorIterator<typename remove_cv<value_type>::type> & rhs)
			{
				pointer_ = rhs.base();
				return *this;
			};
			
			// dereference
			reference operator*(void) const
			{
				return *pointer_;
			};

			// allows a object of this class to be accessed like a pointer. 
			pointer	operator->(void) const
			{
				return pointer_;
			};

			// allows access to the element at position n.
			reference	operator[](difference_type n) const
			{
				return *(pointer_ + n);
			};

	// ARITHMETIC OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
	
			vectorIterator<T>	operator+(difference_type n) const
			{
				return pointer_ + n;
			};

			vectorIterator<T>	operator-(difference_type n) const
			{
				return pointer_ - n;
			};

			// increment pointer and return a reference to its new
			// state. (++i)
			vectorIterator<T> &	operator++(void)
			{
				pointer_++;
				return *this;
			};

			// increment pointer and return a reference to its new
			// state. (--i)
			vectorIterator<T> &	operator--(void)
			{
				pointer_--;
				return *this;
			};

			// increment pointer but return its initial state (i++)
			vectorIterator<T>	operator++(int)
			{
				vectorIterator<T> tmp(*this);
				pointer_++;
				return (tmp);
			};

			// decrement pointer but return its initial state (i--)
			vectorIterator<T>	operator--(int)
			{
				vectorIterator<T> tmp(*this);
				pointer_--;
				return (tmp);
			};

			// add n to the current position of the pointer and
			// returns its new state.
			vectorIterator<T> &	operator+=(difference_type n)
			{
				pointer_ += n;
				return (*this);
			};

			// substract n to the current position of the pointer and
			// returns its new state.
			vectorIterator<T> &	operator-=(difference_type n)
			{
				pointer_ -= n;
				return (*this);
			};
		
		private:
			pointer pointer_;
	};

// DISPLAY OPERATOR OVERLOAD ---------------------------------------------------------------------------------------------
	
	template <typename T>
		std::ostream &  operator<<(std::ostream & o, const vectorIterator<T> & gandalf)
		{
			o << gandalf.base();
			return (o);
		};

// ARITHMETIC OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------

	template <typename T>
		vectorIterator<T> operator+(typename vectorIterator<T>::difference_type x, const vectorIterator<T> & y)
		{
			return x + y.base();
		};

	template <typename T>
		typename vectorIterator<T>::difference_type operator-(const vectorIterator<T>& x, const vectorIterator<T> & y)
		{
			return x.base() - y.base();
		};

	template <typename T, typename U>
		typename vectorIterator<T>::difference_type operator-(const vectorIterator<T>& gandalf, const vectorIterator<U>& sauron)
		{
			return (gandalf.base() - sauron.base());
		}

	// RELATIONNAL OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------

	template <typename T>
		bool	operator==(const vectorIterator<T> & gandalf, const vectorIterator<T> & sauron)
		{
			return gandalf.base() == sauron.base();
		};

	template <typename T>
		bool	operator!=(const vectorIterator<T> & gandalf, const vectorIterator<T> & sauron)
		{
			return gandalf.base() != sauron.base();
		};

	template <typename T>
		bool operator<(const vectorIterator<T> & gandalf, const vectorIterator<T> & sauron)
		{
			return gandalf.base() < sauron.base();
		};

	template <typename T>	
		bool operator>(const vectorIterator<T> & gandalf, const vectorIterator<T>& sauron)
		{
			return gandalf.base() > sauron.base();
		};

	template <typename T>
		bool operator<=(const vectorIterator<T> & gandalf, const vectorIterator<T>& sauron)
		{
			return gandalf.base() <= sauron.base();
		};
	
	template <typename T>
		bool operator>=(const vectorIterator<T> & gandalf, const vectorIterator<T>& sauron)
		{
			return gandalf.base() >= sauron.base();
		};

	template <typename T, typename U>
		bool operator==(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.base() == sauron.base();
		}
	
	template <typename T, typename U>
		bool operator!=(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.base() != sauron.base();
		}
	
	template <typename T, typename U>
		bool operator<(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.base() < sauron.base();
		}
	
	template <typename T, typename U>
		bool operator>(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.base() > sauron.base();
		}
	
	template <typename T, typename U>
		bool operator<=(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.base() <= sauron.base();
		}
	
	template <typename T, typename U>
		bool operator>=(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.base() >= sauron.base();
		}

}