#pragma once

#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <cstddef>
#include <memory>

#include "../colors/colors.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"
#include "algorithms.hpp"
#include "pair.hpp"
#include "mapIterator.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			// HOMEMADE TYPE DEFINITION

            typedef Key                                     key_type; // type of key used to pair with value (1st template parameter)
            typedef T                                       mapped_type; // type of the value paired with key (2nd template parameter)
            typedef pair<const Key, T>                      value_type; // represent the key-value pair
            typedef Compare                                 key_compare; // comparaison fonction used to compare keys (3rd template parameter, defaults to: less<key_type>)
            typedef Allocator                               allocator_type; // (4th template parameter, defaults to: allocator<value_type>)
            typedef typename Allocator::reference           reference; // for the default allocator: value_type &
            typedef typename Allocator::const_reference     const_reference; // for the default allocator: const value_type&
            typedef std::size_t                             size_type;
            typedef std::ptrdiff_t                          difference_type;
            typedef typename Allocator::pointer             pointer; // for the default allocator: value_type*
            typedef typename Allocator::const_pointer       const_pointer; 	// for the default allocator: const value_type*
			// typedef ft::mapIterator			 				iterator; // a bidirectional iterator to value_type
			// typedef ft::mapIterator<const T>				const_iterator; // a bidirectional iterator to const value_type
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			class value_compare : public std::binary_function<value_type,value_type,bool>
			{
				friend class map;

				protected:
					Compare	comp;
					value_compare(Compare c) : comp(c)
					{}

				public:
					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

//	CONSTRUCTORS ----------------------------------------------------------------------------

			// Constructs an empty container, with no elements.
			explicit map(const Compare& comp = Compare(), const Allocator& = Allocator());

			// Constructs a container with as many elements as the range [first,last),
			// with each element constructed from its corresponding element in that range.
			// Input iterators to the initial and final positions in a range.
			// The range used is [first,last), which includes all the elements between
			// first and last, including the element pointed by first but not the element
			// pointed by last.
			template <class InputIterator>
				map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());
			
			// Constructs a container with a copy of each of the elements in x
			map(const map<Key,T,Compare,Allocator>& x);


//	DESTRUCTORS --------------------------------------------------------------------------------------

			// This destroys all container elements, and deallocates all the storage capacity allocated by the map container using its allocator.
			~map();

//	MEMBER FUNCTIONS ---------------------------------------------------------------------------------

//		ASSIGNEMENT ----------------------------------------------------------------------------------------------------------------------------

			map<Key,T,Compare,Allocator> & operator=(const map<Key,T,Compare,Allocator>& x);
	
//		ITERATORS --------------------------------------------------------------------------------------
	
			iterator	begin();
			const_iterator	begin() const;
			iterator	end();
			const_iterator	end() const;
			reverse_iterator	rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator	rend();
			const_reverse_iterator rend() const;

//		CAPACITY --------------------------------------------------------------------------------------
			bool	empty() const;
			size_type	size() const;
			size_type	max_size() const;

//		ACCESSORS --------------------------------------------------------------------------------------
			
			T &	operator[](const key_type& x);

//		MODIFIERS --------------------------------------------------------------------------------------
			
			pair<iterator, bool>	insert(const value_type& x);
			iterator	insert(iterator position, const value_type& x);
			template <class InputIterator>
				void 	insert(InputIterator first, InputIterator last);
			void	erase(iterator position);
			size_type	erase(const key_type& x);
			void	erase(iterator first, iterator last);
			void	swap(map<Key,T,Compare,Allocator>&);
			void	clear();

//		MODIFIERS --------------------------------------------------------------------------------------
			key_compare	key_comp() const;
			value_compare	value_comp() const;

//		MAP OPERATIONS --------------------------------------------------------------------------------------

			iterator	find(const key_type& x);
			const_iterator find(const key_type& x) const;
			size_type	count(const key_type& x) const;
			iterator	lower_bound(const key_type& x);
			const_iterator lower_bound(const key_type& x) const;
			iterator	upper_bound(const key_type& x);
			const_iterator upper_bound(const key_type& x) const;
			pair<iterator,iterator>	equal_range(const key_type& x);
			pair<const_iterator,const_iterator>	equal_range(const key_type& x) const;
	};

//		COMPARATORS --------------------------------------------------------------------------------------

	template <class Key, class T, class Compare, class Allocator>
		bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
	template <class Key, class T, class Compare, class Allocator>
		bool operator< (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
	template <class Key, class T, class Compare, class Allocator>
		bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
	template <class Key, class T, class Compare, class Allocator>
		bool operator> (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
	template <class Key, class T, class Compare, class Allocator>
		bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);
	template <class Key, class T, class Compare, class Allocator>
		bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y);

//		SPECIALIZED ALGORITHM --------------------------------------------------------------------------------------

	template <class Key, class T, class Compare, class Allocator>
		void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y);
}