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


#include "RedBlackTree.hpp"
// #include "BST.hpp"

namespace ft
{
	template <typename Key, typename Value, typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, Value> > >
	class map
	{
		public:
			// HOMEMADE TYPE DEFINITION

			typedef Key                                     		key_type; // type of key used to pair with value (1st template parameter)
			typedef Value                                   		mapped_type; // type of the value paired with key (2nd template parameter)
			typedef ft::pair<const Key, Value>                  	value_type; // represent the key-value pair
			typedef Compare                                 		key_compare; // comparaison fonction used to compare keys (3rd template parameter, defaults to: less<key_type>)
			typedef Allocator                               		allocator_type; // (4th template parameter, defaults to: allocator<value_type>)
			typedef typename Allocator::reference           		reference; // for the default allocator: value_type &
			typedef typename Allocator::const_reference     		const_reference; // for the default allocator: const value_type&
			typedef std::size_t                             		size_type;
			typedef std::ptrdiff_t                          		difference_type;
			typedef typename Allocator::pointer             		pointer; // for the default allocator: value_type*
			typedef typename Allocator::const_pointer       		const_pointer; 	// for the default allocator: const value_type*
			typedef ft::mapIterator<Key, Value>						iterator; // a bidirectional iterator to value_type
			typedef ft::mapIterator<const Key, Value>				const_iterator; // a bidirectional iterator to const value_type
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

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

		private :
			// typedef RBTree<key_type, value_type, std::_Select1st<value_type>, key_compare, allocator_type>    RBTree;
			typedef RedBlackTree<key_type, mapped_type, key_compare, Allocator>	RBTree;	
			RBTree    tree_;

			// typedef BinarySearchTree<key_type, mapped_type>			BST;
			// BST	tree_;

			ft::Node<Key, Value> *node_ptr;

//	CONSTRUCTORS ----------------------------------------------------------------------------

		public :
			// Constructs an empty container, with no elements.
			explicit map(const Compare& comp = Compare(), const Allocator & allocator = Allocator())
			: tree_(comp, allocator)
			{
				#if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling map default constructor" << RESET << std::endl;
				#endif
			};

			// Constructs a container with as many elements as the range [first,last),
			// with each element constructed from its corresponding element in that range.
			// Input iterators to the initial and final positions in a range.
			// The range used is [first,last), which includes all the elements between
			// first and last, including the element pointed by first but not the element
			// pointed by last.
			template <class InputIterator>
				map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator & allocator = Allocator())
				: tree_(comp, allocator)
				{
					#if DEBUG
						std::cout << LIGHTSEAGREEN << "Calling map range constructor" << RESET << std::endl;
					#endif

					insert(first, last);
				};
			
			// Copy constructor
			// Constructs a container with a copy of each of the elements in x
			map(const map<Key,Value,Compare,Allocator>& src)
			: tree_(src.tree_)
			{
				#if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling map copy constructor" << RESET << std::endl;
				#endif
			};


//	DESTRUCTORS --------------------------------------------------------------------------------------

			// This destroys all container elements, and deallocates all the storage capacity allocated by the map container using its allocator.
			~map()
			{
				#if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling map destructor" << RESET << std::endl;
				#endif

			};

//	MEMBER FUNCTIONS ---------------------------------------------------------------------------------

//		ASSIGNEMENT ----------------------------------------------------------------------------------------------------------------------------

			map<Key,Value,Compare,Allocator> & operator=(const map<Key,Value,Compare,Allocator>& rhs)
			{
				#if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling map assignement operator" << RESET << std::endl;
				#endif

                if (this != &rhs)
                    this->tree_ = rhs.tree_;
                return (*this);
			};
	
//		ITERATORS --------------------------------------------------------------------------------------
	
			iterator	begin()
			{
				return tree_.begin();
			};

			const_iterator	begin() const
			{
				return tree_.begin();
			};

			iterator	end()
			{
				return tree_.end();
			};

			const_iterator	end() const
			{
				return tree_.end();
			};

			reverse_iterator	rbegin()
			{
				return tree_.rbegin();
			};

			const_reverse_iterator rbegin() const
			{
				return tree_.rbegin();
			};

			reverse_iterator	rend()
			{
				return tree_.rend();
			};

			const_reverse_iterator rend() const
			{
				return tree_.rend();
			};

//		CAPACITY --------------------------------------------------------------------------------------
			bool	empty() const
			{
				return tree_.empty();
			};

			size_type	size() const
			{
				return tree_.size();
			};

			size_type	max_size() const
			{
				return tree_.max_size();
			};

//		ACCESSORS --------------------------------------------------------------------------------------
			
			Value &	operator[](const key_type& x)	
			{
				tree_[x];
			};

			RBTree &	getTree()
			{
				return tree_;
			}

//		MODIFIERS --------------------------------------------------------------------------------------
			
			// Extends the container by inserting new elements, effectively increasing the container
			// size by the number of elements inserted.
			// Because element keys in a map are unique, the insertion operation checks whether each
			// inserted element has a key equivalent to the one of an element already in the container,
			// and if so, the element is not inserted, returning an iterator to this existing element
			// (if the function returns a value).
			ft::pair<iterator, bool>	insert(const value_type & input_pair)
			{
				return tree_.insert(input_pair);
			};
			
			// iterator	insert(iterator position, const value_type& x);
			// template <class InputIterator>
			// 	void 	insert(InputIterator first, InputIterator last);

			// Removes from the map container either a single element or a range of
			// elements ([first,last)).
			// This effectively reduces the container size by the number of elements
			// removed, which are destroyed.
			void	erase(iterator position)
			{
				tree_.remove(position.first);
			};

			// Removes from the map container either a single element or a range of
			// elements ([first,last)).
			// This effectively reduces the container size by the number of elements
			// removed, which are destroyed.
			size_type	erase(const key_type& input_key)
			{
				return tree_.remove(input_key);
			};

			// void	erase(iterator first, iterator last);
			// void	swap(map<Key,T,Compare,Allocator>&);
			// void	clear();

//		OBSERVERS --------------------------------------------------------------------------------------
			key_compare	key_comp() const;
			value_compare	value_comp() const;

//		MAP OPERATIONS --------------------------------------------------------------------------------------

			// iterator	find(const key_type& x);
			// const_iterator find(const key_type& x) const;
			size_type	count(const key_type& x) const;
			// iterator	lower_bound(const key_type& x);
			// const_iterator lower_bound(const key_type& x) const;
			// iterator	upper_bound(const key_type& x);
			// const_iterator upper_bound(const key_type& x) const;
			// pair<iterator,iterator>	equal_range(const key_type& x);
			// pair<const_iterator,const_iterator>	equal_range(const key_type& x) const;


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