#pragma once

#include <iostream>
#include <algorithm>

#include "type_traits.hpp"
// #include "mapIterator.hpp"

namespace ft 
{
	template <typename T1, typename T2>
		struct pair
		{
			T1 first;
			T2 second;

			// default constructor
			pair()
			: first(T1())
			, second(T2())
			{};

			// pair constructor
			pair(const T1 & x, const T2 & y)
			: first(x)
			, second(y)
			{};

			// copy constructor
			template<class U, class V>
				pair(const pair<U, V> & p)
				: first (p.first)
				, second (p.second)
				{};

			// destructor
			~pair()
			{};

			// Exchanges the contents of the pair object with the contents of pr.
			void swap (pair & rhs)
			{
				std::swap(first, rhs.first);
				std::swap(second, rhs.second);
			};

			pair & operator=(const pair & rhs)
			{
				if (this != &rhs)
				{
					first = rhs.first;
					second = rhs.second;
				}
				return *this;
			};
		};

		template <typename T1, typename T2>
			bool operator==(const pair<T1, T2> & x, const pair<T1, T2> & y)
			{
				return x.first == y.first && x.second == y.second;
			};

		template <typename T1, typename T2>
			bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
			{
				return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
			};

		template <typename T1, typename T2>
			bool    operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y)
			{
				return !(x == y);
			};
			
		template <typename T1, typename T2>
			bool    operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
			{
				return !(y < x);
			};
			
		template <typename T1, typename T2>
			bool    operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
			{
				return y < x;
			};
			
		template <typename T1, typename T2>
			bool    operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
			{
				return !(x < y);
			};
			
		template <typename T1, typename T2>
			void    swap(pair<T1, T2> & x, pair<T1, T2> & y)
			{
				x.swap(y);
			};
		
			// Constructs a pair object with its first element set to x and its second element set to y.
		template <typename T1, typename T2>
			pair<T1, T2>    make_pair(T1 x, T2 y)
			{
				return pair<T1, T2>(x, y);	
			};

		// // Constructs a pair object with its first element set to x and its second element set to y.
		// template <typename T1, typename T2>
		// 	pair<T1, T2>    make_pair(T1 x, typename enable_if<is_same<T2, const char *>::value, T2>::type y)
		// 	{
		// 		return pair<T1, T2>(x, std::string(y));	
		// 	};

		// // Constructs a pair object with its first element set to x and its second element set to y.
		// template <typename T1, typename T2>
		// 	pair<T1, T2>    make_pair(typename enable_if<is_same<T1, const char *>::value, T1>::type x, T2 y)
		// 	{
		// 		return pair<T1, T2>(x, std::string(y));	
		// 	};
}