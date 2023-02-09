#pragma once

#include "../colors/colors.hpp"
#include "pair.hpp"
#include "mapIterator.hpp"
#include "node.hpp"

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
	// template <typename Key, typename Value>
	// class Node
	// {
	// 	public:

	// 		Key					key;
	// 		Value				value;
	// 		Node<Key, Value>	*left;
	// 		Node<Key, Value>	*right;

	// 		// default constructor
	// 		Node()
	// 		: key(0)
	// 		, value(0)
	// 		, left(0)
	// 		, right(0)
	// 		{};

	// 		// constructor #1
	// 		Node(const Key & key, const Value & value)
	// 		: key(key)
	// 		, value(value)
	// 		, left(0)
	// 		, right(0)
	// 		{};

	// 		// copy constructor
	// 		Node(const Node & original)
	// 		{
	// 			if (this != &original)
	// 			{
	// 				key = original.key;
	// 				value = original.value;
	// 				left = original.left;
	// 				right = original.right;
	// 			}
	// 		}
	// };

	// template<typename Key, typename Value>
	// std::ostream & operator<<(std::ostream & o, const Node<Key, Value> & rhs)
	// {
		
	// 	o << "key = "
	// 		<< rhs.key
	// 		<< std::endl
	// 		<< "value = "
	// 		<< rhs.value
	// 		<< std::endl;
	// 	if (rhs.left)
	// 	{
	// 		o << "left->key = "
	// 			<< rhs.left->key
	// 			<< std::endl
	// 			<< "left->value = "
	// 			<< rhs.right->key
	// 			<< std::endl;
	// 	}
	// 	if (rhs.right)
	// 	{
	// 		o << "right->key = "
	// 		<< rhs.left->key
	// 		<< std::endl
	// 		<< "right->value = "
	// 		<< rhs.right->key
	// 		<< std::endl;
	// 	}
	// 	return o;
	// }

	template <typename Key, typename Value, typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, Value> > >
	class BinarySearchTree
	{
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

//	CONSTRUCTORS ----------------------------------------------------------------------------

			// default constructor
			BinarySearchTree(const Allocator & allocator = Allocator())
			: root_(0)
			, comp_(std::less<Key>())
			, allocator_(allocator)
			, size_(0)
			{};

			// constuctor with specific compare function and allocator function
			BinarySearchTree(key_compare comp, allocator_type allocator)
			: root_(0)
			, comp_(comp)
			, allocator_(allocator)
			, size_(0)
			{};

			// copy constructor
			BinarySearchTree(const BinarySearchTree<Key, Value, Compare, Allocator> & original)
			: comp_(original.comp_)
			, allocator_(original.allocator_)
			{
				if (this != &original)
				{
					copyTree(root_, original.root_);
				}
			};

//	DESTRUCTORS --------------------------------------------------------------------------------------

			~BinarySearchTree()
			{}

//	MEMBER FUNCTIONS ---------------------------------------------------------------------------------

//		ASSIGNEMENT ----------------------------------------------------------------------------------------------------------------------------

//		ACCESSORS --------------------------------------------------------------------------------------

			Value &operator[](const Key &key)
			{
				node_ptr node = findNode(root_, key);
				
				if (node == 0)
					node = insertHelper(root_, key, Value());
				return node->value;
			};

			// print all the keys and values of the tree.
			void	printTree(node_ptr root)
			{
				if (root != NULL)
				{
					printTree(root->left);
					std::cout << "key = " << root->key << " | value = " << root->value << std::endl;
					printTree(root->right);
				}
			};

//		MODIFIERS --------------------------------------------------------------------------------------

			// inserts new node.
			// returns a pair, with its member pair::first set to an iterator pointing to either
			// the newly inserted element or to the element with an equivalent key in the map
			ft::pair<node_ptr, bool>	insert(const value_type & input_pair)
			{
				if (root_ == 0)
				{
					root_ = new Node<Key, Value> (input_pair.first, input_pair.second);
					return ft::make_pair(root_, true);
				}

				node_ptr node = findNode(root_, input_pair.first);
				
				if (node)
					return ft::make_pair(node, false);
				node = insertHelper(root_, input_pair.first, input_pair.second);
				return ft::make_pair(node, true);
			};

			// remove node from tree.
			// !! when calling function, always set first parameter to tree.getroot()
			// second parameter should be the key of the item you want to remove.
			node_ptr remove(node_ptr root, int key)
			{
				if (root == NULL)
					return root;
				if (key < root->key)
					root->left = remove(root->left, key);
				else if (key > root->key)
					root->right = remove(root->right, key);
				else 
				{
					if (root->left == NULL)
					{
						node_ptr tmp = root->right;
						delete root;
						return tmp;
					}
					else if (root->right == NULL)
					{
						node_ptr tmp = root->left;
						delete root;
						return tmp;
					} 
					else
					{
						node_ptr tmp = root->right;
						while (tmp->left)
							tmp = tmp->left;
						root->key = tmp->key;
						root->value = tmp->value;
						root->right = remove(root->right, tmp->key);
					}
				}
				return root;
			}
//		GETTERS --------------------------------------------------------------------------------------

			// return a pointer to root node
			node_ptr	getRoot() const
			{
				return root_;
			};

//		COPY TOOL --------------------------------------------------------------------------------------

			void copyTree(node_ptr & copy, node_ptr original)
			{
				if (original == 0)
					copy = 0;
				else
				{
					copy = nodeAllocator_.allocate(1);
					nodeAllocator_.construct(copy, *original);
					// copy = new Node<Key, Value>(original->key, original->value);
					copyTree(copy->left, original->left);
					copyTree(copy->right, original->right);
				}
			};

		protected:
			node_ptr							root_;
			std::allocator<Node<Key, Value> >	nodeAllocator_;
			key_compare							comp_; // key comparator
			allocator_type						allocator_;
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
				if (key == node->key)
				{
					node->value = value;
					return node;
				}
				if (key < node->key)
				{
					if (node->left == 0)
						return new Node<Key, Value> (key, value);
					return insertHelper(node->left, key, value);
				}
				if (node->right == 0)
						return new Node<Key, Value> (key, value);
					return insertHelper(node->right, key, value);
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