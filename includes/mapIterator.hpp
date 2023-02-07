#pragma once

#include <iostream>
#include <cstddef>
// #include "iterator.hpp"
#include "pair.hpp"
#include "BST.hpp"
#include "utils.hpp"
#include "iterator.hpp"

// FOR DEBUG
#include <utility>

// this is an iterator that will browse through my binary search tree
// mapIterator point to a pair<const Key, Value> of type value_type
namespace ft
{
	template <typename Key, typename Value>
		class mapIterator
		{
			public:
				typedef std::pair<const Key, Value >     value_type;
				typedef value_type&                     reference;
				typedef value_type*                     pointer;
				typedef std::bidirectional_iterator_tag iterator_category;
				typedef std::ptrdiff_t                  difference_type;

            private:
                typedef Node<Key, Value>    node_ptr;

                pointer    pointer_;
            
            public:

                // default constructor
                mapIterator()
                : pointer_(0)
                {};
                // constructor
                mapIterator(node_ptr input_node)
                :pointer_(input_node)
                {};

                // copy constructor
                mapIterator(const mapIterator<Key, Value> & src)
                : pointer_(src.getPointer())
                {};

                // destructor
                ~mapIterator(void)
                {};

                pointer base() const
                {
                    return pointer_;
                }

// GETTERS ---------------------------------------------------------------------------------------------
				
                pointer getPointer(void) const 
                {
                    return (pointer_);
                }

// OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
				
                // assignement operator
                mapIterator<Key, Value>&    operator=(const mapIterator<Key, Value> & rhs)
                {
                    pointer_ = rhs.getPointer();
                    return *this;
                };

                // // this is a type conversion operator function. Its genereic form is
                // // operator type() 
                // // where type is the type to which the class should be converted.
                // // Here, we convert to mapIterator<const T>
                // // wich allows conversion to a constant type T
                // // (initially, our class is mapIterator<Key, Value>).
                // operator mapIterator<const T>() const
                // {
                // 	return (mapIterator<const T>(pointer_));
                // }
                
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
	
                mapIterator<Key, Value>	operator+(difference_type n) const
                {
                    return pointer_ + n;
                };

                mapIterator<Key, Value>	operator-(difference_type n) const
                {
                    return pointer_ - n;
                };

                // increment pointer and return a reference to its new
                // state. (++i)
                mapIterator<Key, Value> &	operator++(void)
                {
                    pointer_++;
                    return *this;
                };

                // increment pointer and return a reference to its new
                // state. (--i)
                mapIterator<Key, Value> &	operator--(void)
                {
                    pointer_--;
                    return *this;
                };

                // increment pointer but return its initial state (i++)
                mapIterator<Key, Value>	operator++(int)
                {
                    mapIterator<Key, Value> tmp(*this);
                    pointer_++;
                    return (tmp);
                };

                // decrement pointer but return its initial state (i--)
                mapIterator<Key, Value>	operator--(int)
                {
                    mapIterator<Key, Value> tmp(*this);
                    pointer_--;
                    return (tmp);
                };

                // add n to the current position of the pointer and
                // returns its new state.
                mapIterator<Key, Value> &	operator+=(difference_type n)
                {
                    pointer_ += n;
                    return (*this);
                };

                // substract n to the current position of the pointer and
                // returns its new state.
                mapIterator<Key, Value> &	operator-=(difference_type n)
                {
                    pointer_ -= n;
                    return (*this);
                };
		
    	};

// DISPLAY OPERATOR OVERLOAD ---------------------------------------------------------------------------------------------
	
	template <typename Key, typename Value>
		std::ostream &  operator<<(std::ostream & o, const mapIterator<Key, Value> & gandalf)
		{
			o << gandalf.getPointer();
			return (o);
		};

// ARITHMETIC OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------

	template <typename Key, typename Value>
		mapIterator<Key, Value> operator+(typename mapIterator<Key, Value>::difference_type x, const mapIterator<Key, Value> & y)
		{
			return x + y.getPointer();
		};

	template <typename Key, typename Value>
		typename mapIterator<Key, Value>::difference_type operator-(const mapIterator<Key, Value>& x, const mapIterator<Key, Value> & y)
		{
			return x.getPointer() - y.getPointer();
		};

	// template <typename T, typename U>
	// 	typename mapIterator<Key, Value>::difference_type operator-(const mapIterator<Key, Value>& gandalf, const mapIterator<U>& sauron)
	// 	{
	// 		return (gandalf.getPointer() - sauron.getPointer());
	// 	}

	// RELATIONNAL OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------

	template <typename Key, typename Value>
		bool	operator==(const mapIterator<Key, Value> & gandalf, const mapIterator<Key, Value> & sauron)
		{
			return gandalf.getPointer() == sauron.getPointer();
		};

	template <typename Key, typename Value>
		bool	operator!=(const mapIterator<Key, Value> & gandalf, const mapIterator<Key, Value> & sauron)
		{
			return gandalf.getPointer() != sauron.getPointer();
		};

	template <typename Key, typename Value>
		bool operator<(const mapIterator<Key, Value> & gandalf, const mapIterator<Key, Value> & sauron)
		{
			return gandalf.getPointer() < sauron.getPointer();
		};

	template <typename Key, typename Value>	
		bool operator>(const mapIterator<Key, Value> & gandalf, const mapIterator<Key, Value>& sauron)
		{
			return gandalf.getPointer() > sauron.getPointer();
		};

	template <typename Key, typename Value>
		bool operator<=(const mapIterator<Key, Value> & gandalf, const mapIterator<Key, Value>& sauron)
		{
			return gandalf.getPointer() <= sauron.getPointer();
		};
	
	template <typename Key, typename Value>
		bool operator>=(const mapIterator<Key, Value> & gandalf, const mapIterator<Key, Value>& sauron)
		{
			return gandalf.getPointer() >= sauron.getPointer();
		};

	// template <class T, class U>
	// 	bool operator==(const mapIterator<Key, Value> & gandalf, const mapIterator<U> & sauron)
	// 	{
	// 		return gandalf.getPointer() == sauron.getPointer();
	// 	}
	
	// template <class T, class U>
	// 	bool operator!=(const mapIterator<Key, Value> & gandalf, const mapIterator<U> & sauron)
	// 	{
	// 		return gandalf.getPointer() != sauron.getPointer();
	// 	}
	
	// template <class T, class U>
	// 	bool operator<(const mapIterator<Key, Value> & gandalf, const mapIterator<U> & sauron)
	// 	{
	// 		return gandalf.getPointer() < sauron.getPointer();
	// 	}
	
	// template <class T, class U>
	// 	bool operator>(const mapIterator<Key, Value> & gandalf, const mapIterator<U> & sauron)
	// 	{
	// 		return gandalf.getPointer() > sauron.getPointer();
	// 	}
	
	// template <class T, class U>
	// 	bool operator<=(const mapIterator<Key, Value> & gandalf, const mapIterator<U> & sauron)
	// 	{
	// 		return gandalf.getPointer() <= sauron.getPointer();
	// 	}
	
	// template <class T, class U>
	// 	bool operator>=(const mapIterator<Key, Value> & gandalf, const mapIterator<U> & sauron)
	// 	{
	// 		return gandalf.getPointer() >= sauron.getPointer();
	// 	}

}