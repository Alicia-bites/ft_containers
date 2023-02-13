#pragma once

#include <cstdio>
#include <iostream>

#include "node.hpp"
#include "../colors/colors.hpp"

// #1 A node is eather RED or BLACK

// #2 The root and leaves are BLACK

// #3 If a node is RED, then its children are BLACK

// #4 All paths to a node's leaf descendant contains the same number of black nodes 

namespace ft
{
	template <typename Key, typename Value, typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, Value> > >
	class RedBlackTree
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
			RedBlackTree(const Allocator & allocator = Allocator())
			: root_(0)
			, comp_(std::less<Key>())
			, allocator_(allocator)
			, size_(0)
			{};

			// constuctor with specific compare function and allocator function
			RedBlackTree(key_compare comp, allocator_type allocator)
			: root_(0)
			, comp_(comp)
			, allocator_(allocator)
			, size_(0)
			{};

			// copy constructor
			RedBlackTree(const RedBlackTree<Key, Value, Compare, Allocator> & original)
			: comp_(original.comp_)
			, allocator_(original.allocator_)
			{
				if (this != &original)
					copyTree(root_, original.root_);
			};

//	DESTRUCTORS --------------------------------------------------------------------------------------

			~RedBlackTree()
			{
				std::cout << MAGENTA3 << "Calling RedBlackTree destructor" << std::endl;
				deleteTree(root_);
			}

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
			void	printTree(node_ptr node)
			{
				if (node != NULL)
				{
					printTree(node->left);
					std::cout << *node << std::endl;
					printTree(node->right);
				}
			};

//		MODIFIERS --------------------------------------------------------------------------------------

			// inserts new node.
			// returns a pair, with its member pair::first set to an iterator pointing to either
			// the newly inserted element or to the element with an equivalent key in the map
			ft::pair<node_ptr, bool>	insert(const value_type & input_pair)
			{
				node_ptr node = findNode(root_, input_pair.first);
				
				if (node)
					return ft::make_pair(node, false);
				node = insertHelper(root_, input_pair.first, input_pair.second);
				if (!root_)
					root_ = node;

				// fixViolation(root_);
				return ft::make_pair(node, true);
			};

			size_t	remove(const key_type & key)
			{
				size_t n = 0;
				node_ptr node = findNode(root_, key);
				while (findNode(node, key))
				{
					removeHelper(root_, key);
					n++;
				}
				return n;
			}

			// remove node from tree.
			// !! when calling function, always set first parameter to tree.getroot()
			// second parameter should be the key of the item you want to remove.
			node_ptr removeHelper(node_ptr node, int key)
			{
				if (node == NULL)
					return node;
				if (key < node->key)
					node->left = removeHelper(node->left, key);
				else if (key > node->key)
					node->right = removeHelper(node->right, key);
				else 
				{
					if (node->left == NULL)
					{
						node_ptr tmp = node->right;
						if (tmp)
							tmp->parent = node->parent;
						delete node;
						return tmp;
					}
					else if (node->right == NULL)
					{
						node_ptr tmp = node->left;
						if (tmp)
							tmp->parent = node->parent;
						delete node;
						return tmp;
					} 
					else
					{
						node_ptr tmp = node->right;
						while (tmp->left)
							tmp = tmp->left;
						node->key = tmp->key;
						node->value = tmp->value;
						node->right = removeHelper(node->right, tmp->key);
					}
				}
				return node;
			}


			void deleteTree(node_ptr node)
			{
				if (node == NULL) return;
			
				deleteTree(node->left);
				deleteTree(node->right);
			
				std::cout << MEDIUMORCHID3 << "Deleting node: " << node->value << RESET << std::endl;
				delete node;
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
			// from root_, find the next available place to create new Node
			// !! WITHOUT CARING ABOUT BALANCE
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
					{
						node->left = new Node<Key, Value> (key, value);
						node->left->parent = node;
						return node->left;
					}
					return insertHelper(node->left, key, value);
				}
				if (node->right == 0)
				{
					node->right = new Node<Key, Value> (key, value);
					node->right->parent = node;
					return node->right;
				}
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