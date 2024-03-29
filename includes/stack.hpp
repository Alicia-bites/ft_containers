#pragma once

# include <iostream>
# include "vector.hpp"

namespace ft 
{
	// T - the type of the stored elements.
	// Container - the type of the underlying container to use to store the elements.
	template <typename T, typename Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	typename	Container::value_type	value_type;
			typedef	typename	Container::size_type	size_type;
			typedef				Container				container_type;

		// the underlying container
		protected:
			Container c;

		public:
			explicit stack(const Container & underlying_container = Container())
			: c(underlying_container) 
			{}

			// MEMBER FUNCTIONS -----------------------------------------------------------
			
			// checks whether the underlying container is empty
			bool empty() const 
			{
				return c.empty();
			}

			// returns the number of elements
			size_type size() const 
			{
				return c.size();
			}

			// accesses the top element
			value_type &	top() 
			{
				return c.back();
			}

			// accesses the top element
			const value_type& top() const 
			{
				return c.back();
			}

			// inserts element at the top
			void push(const value_type & x) 
			{
				c.push_back(x);
			}

			// removes the top element
			void pop() 
			{
				c.pop_back();
			}

			// NON_MEMBER FUNCTIONS -----------------------------------------------------------
			
			// Compares the contents of the underlying containers of two 
			// container adaptors. The comparison is done by applying the 
			// corresponding operator to the underlying containers.

			friend bool operator<(const stack<T, Container>& x, const stack<T, Container>& y)
			{ 
				return (x.c < y.c);
			}

			friend bool operator>(const stack<T, Container>& x, const stack<T, Container>& y)
			{ 
				return (x.c > y.c); 
			}

			friend bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
			{ 
				return (x.c <= y.c);
			}

			friend bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
			{ 
				return (x.c >= y.c);
			}

			friend bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
			{ 
				return (x.c == y.c);
			}

			friend bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
			{ 
				return (x.c != y.c);
			}
	};
}