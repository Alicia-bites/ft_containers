#pragma once

#include "../colors/colors.hpp"
#include "pair.hpp"
#include "mapIterator.hpp"

#include <iostream>
// #include <stdlib.h>
// #include <iterator>
// #include <cstddef>
// #include <memory>

// FOR DEBUG
// #include <utility>

// BINARY SEARCH TREE ---------------------------------------------------------------------------------------------

namespace ft
{
	template <typename Key, typename Value>
	class Node
	{
		public:
			Key					key;
			Value				value;
			Node<Key, Value>	*left;
			Node<Key, Value>	*right;

			// default constructor
			Node(const Key & key, const Value & value)
			: key(key)
			, value(value)
			, left(0)
			, right(0)
			{};

			// copy constructor
			Node(const Node & original)
			{
				if (this != &original)
				{
					key = original->key;
					value = original->value;
					left = original->left;
					right = original->right;
				}
			}
	};

	template <typename Key, typename Value, typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, Value> > >
	class BinarySearchTree
	{
		public:

			public:
				typedef Key													key_type; // type of key used to pair with value (1st template parameter)
				typedef Value												mapped_type; // type of the value paired with key (2nd template parameter)
				typedef ft::pair<const Key, Value>							value_type; 	 // represent the key-value pair
				typedef Compare		 										key_compare;	 // The third template parameter (Compare)	defaults to: less<key_type>
				typedef Allocator											allocator_type;	 // The fourth template parameter (Alloc)	defaults to: allocator<value_type>
				typedef typename allocator_type::reference					reference;		 // for the default allocator: value_type&
				typedef typename allocator_type::const_reference			const_reference; // for the default allocator: const value_type&
				typedef typename allocator_type::pointer					pointer;		 // for the default allocator: value_type*
				typedef typename allocator_type::const_pointer				const_pointer;	 // for the default allocator: const value_type*
				typedef typename allocator_type::difference_type			difference_type; // a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
				typedef typename allocator_type::size_type					size_type;		 // an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

				typedef Node<Key, Value>									*node_ptr;

			// default constructor
			BinarySearchTree(const Allocator & allocator = Allocator())
			: root_(0)
			, comp_(std::less<Key>())
			, treeAllocator_(allocator)
			, size_(0)
			{};

			// constuctor with specific compare function and allocator function
			BinarySearchTree(key_compare comp, allocator_type treeAllocator)
			: root_(0)
			, comp_(comp)
			, treeAllocator_(treeAllocator)
			, size_(0)
			{};

			// copy constructor
			BinarySearchTree(const BinarySearchTree & original)
			: comp_(original.comp_)
			, treeAllocator_(original.treeAllocator_)
			{
				if (this != &original)
				{
					copyTree(root_, original.root_);
				}

			};

			// inserts new node
			// returns a pair, with its member pair::first set to an iterator pointing to either
			// the newly inserted element or to the element with an equivalent key in the map
			ft::pair<node_ptr, bool>	insert(const value_type & input_pair)
			{
				node_ptr node = findNode(root_, input_pair.first);
				
				if (node)
					return ft::make_pair(node, false);
				root_ = insertHelper(root_, input_pair.first, input_pair.second);
				return ft::make_pair(root_, true);
			};
		
			// accessor
			Value &operator[](const Key &key)
			{
				node_ptr node = findNode(root_, key);
				
				if (node == 0)
					node = insertHelper(root_, key, Value());
				return node->value;
			};

			// print all the keys and values of the tree
			void	printTree(node_ptr root)
			{
				if (root != NULL)
				{
					printTree(root->left);
					std::cout << "key = " << root->key << " | value = " << root->value << std::endl;
					printTree(root->right);
				}
			};

			// return a pointer to root node
			node_ptr	getRoot() const
			{
				return root_;
			};

			void copyTree(node_ptr & copy, node_ptr original)
			{
				if (original == 0)
					copy = 0;
				else
				{
					copy = new Node<Key, Value>();
					copy->data = original->data;
					copyTree(copy->left, original->left);
					copyTree(copy->right, original->right);
				}
			}

		protected:
			node_ptr							root_;
			std::allocator<Node<Key, Value> >	nodeAllocator_;
			key_compare							comp_; // key comparator
			allocator_type						treeAllocator_;
			size_type							size_; // total number of nodes

		private :		
			
			bool	KeyisTaken(const Key &key)
			{
				if (findNode(root_, key))
					return 1;
				else
					return 0;
			};

			// recursive function, used to insert a new node
			node_ptr	insertHelper(node_ptr node, const Key &key, const Value &value)
			{
				if (node == 0)
					return new Node<Key, Value>(key, value);
				if (key < node->key)
					node->left = insertHelper(node->left, key, value);
				else if (node->key < key)
					node->right = insertHelper(node->right, key, value);
				else
					node->value = value;
				return node;
			};

			// a function that searches a specific node and returns it
			node_ptr findNode(node_ptr node, const Key &key) const
			{
				while (node != 0 && node->key != key)
				{
					if (key < node->key)
						node = node->left;
					else
						node = node->right;
				}
				return node;
			};
	};
}