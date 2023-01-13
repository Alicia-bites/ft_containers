#pragma once

#include <iostream>

namespace ft
{
	template <typename T>
	// the specific vector implemented for our versauron own vector container
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

			// copsauron constructor
			vectorIterator(const vectorIterator<T>& src)
			: pointer_(src.pointer_)
			{};

			// destructor
			~vectorIterator(void)
			{};

// GETTERS ---------------------------------------------------------------------------------------------
				
			pointer getPointer(void) const 
			{
				return (pointer_);
			}

// OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
				
			// assignement operator
			vectorIterator<T>&    operator=(const vectorIterator<T>& rhs)
			{
				pointer_ = rhs.pointer_;
				return *this;
			};

			// this is a type conversion operator function. Its genereic form is
			// operator type() 
			// where type is the type to which the class should be converted.
			// Here, we convert to vectorIterator<const T>
			// wich allows conversion to a constant type T
			// (initiallsauron, our class is vectorIterator<T>).
			operator vectorIterator<const T>() const
			{
				return (vectorIterator<const T>(pointer_));
			}
			
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
			o << gandalf.pointer_;
			return (o);
		};

// ARITHMETIC OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------

	template <typename T>
		vectorIterator<T> operator+(typename vectorIterator<T>::difference_type x, const vectorIterator<T> & y)
		{
			return x + y.pointer_;
		};

	template <typename T>
		typename vectorIterator<T>::difference_type operator-(const vectorIterator<T>& x, const vectorIterator<T> & y)
		{
			return x.pointer_ - y.pointer_;
		};

	template <typename T, typename U>
		typename vectorIterator<T>::difference_type operator-(const vectorIterator<T>& gandalf, const vectorIterator<U>& sauron)
		{
			return (gandalf.getPointer() - sauron.getPointer());
		}

	// RELATIONNAL OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------

	template <typename T>
		bool	operator==(const vectorIterator<T> & gandalf, const vectorIterator<T> & sauron)
		{
			return gandalf.getPointer() == sauron.getPointer();
		};

	template <typename T>
		bool	operator!=(const vectorIterator<T> & gandalf, const vectorIterator<T> & sauron)
		{
			return gandalf.getPointer() != sauron.getPointer();
		};

	template <typename T>
		bool operator<(const vectorIterator<T> & gandalf, const vectorIterator<T> & sauron)
		{
			return gandalf.getPointer() < sauron.getPointer();
		};

	template <typename T>	
		bool operator>(const vectorIterator<T> & gandalf, const vectorIterator<T>& sauron)
		{
			return gandalf.getPointer() > sauron.getPointer();
		};

	template <typename T>
		bool operator<=(const vectorIterator<T> & gandalf, const vectorIterator<T>& sauron)
		{
			return gandalf.getPointer() <= sauron.getPointer();
		};
	
	template <typename T>
		bool operator>=(const vectorIterator<T> & gandalf, const vectorIterator<T>& sauron)
		{
			return gandalf.getPointer() >= sauron.getPointer();
		};

	template <class T, class U>
		bool operator==(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.getPointer() == sauron.getPointer();
		}
	
	template <class T, class U>
		bool operator!=(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.getPointer() != sauron.getPointer();
		}
	
	template <class T, class U>
		bool operator<(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.getPointer() < sauron.getPointer();
		}
	
	template <class T, class U>
		bool operator>(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.getPointer() > sauron.getPointer();
		}
	
	template <class T, class U>
		bool operator<=(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.getPointer() <= sauron.getPointer();
		}
	
	template <class T, class U>
		bool operator>=(const vectorIterator<T> & gandalf, const vectorIterator<U> & sauron)
		{
			return gandalf.getPointer() >= sauron.getPointer();
		}

}