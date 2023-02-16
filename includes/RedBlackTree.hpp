#pragma once

#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>

#include "node.hpp"
#include "../colors/colors.hpp"
#include "iterator.hpp"
#include "mapIterator.hpp"

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
			typedef ft::mapIterator<Key, Value>							iterator; 		 // a bidirectional iterator to value_type
			typedef ft::mapIterator<const Key, Value>					const_iterator;  // a bidirectional iterator to const value_type
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

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
				#if DEBUG
					std::cout << MAGENTA3 << "Callind RedBlackTree copy constructor" << RESET << std::endl;
				#endif

				if (this != &original)
					copyTree(root_, original.root_);
			};

//	DESTRUCTORS --------------------------------------------------------------------------------------

			~RedBlackTree()
			{
				#if DEBUG
					std::cout << MAGENTA3 << "Calling RedBlackTree destructor" << RESET << std::endl;
				#endif

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
				#if DEBUG
					std::cout << MAGENTA3 << "Calling RedBlackTree assignement operator" << RESET << std::endl;
				#endif

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
				node->color = RED;
				if (!root_)
					root_ = node;
				size_++;
				fixViolation(node);
				return ft::make_pair(node, true);
			};

			size_t	remove(const key_type & key)
			{
				size_t n = 0;
				while (findNode(root_, key))
				{
					root_ = removeHelper(root_, key);
					n++;
				}
				size_ -= n;
				return n;
			}

//		GETTERS --------------------------------------------------------------------------------------

			// return a pointer to root node
			node_ptr	getRoot() const
			{
				return root_;
			};

			size_t		getSize() const
			{
				return size_;
			}

			node_ptr	getSmallestNode(node_ptr node) const
			{
				while (node->left != NULL)
				{
					if (node->key > node->left->key)
						node = node->left;
				}
				return node;
			}

			node_ptr	getBiggestNode(node_ptr node) const
			{
				while (node->right != NULL)
				{
					if (node->key < node->right->key)
						node = node->right;
				}
				return node;
			}

			// void inorder()
			// {
			// 	inorderHelper(root_);
			// }
			
			// void inorderHelper(node_ptr node)
			// {
			// 	if (node == NULL)
			// 		return;
			
			// 	inorderHelper(node->left);
			// 	cout << node->key << " ";
			// 	inorderHelper(node->right);
			// }
			
			// print tree level by level
			void	printLevelOrder()
			{
				printLevelOrderHelper(root_);
			}

			// If x is a power of 2, it will have only one bit set to 1,
			// which will be the leftmost (most significant) bit. 
			bool isPowerOfTwo(int x)
			{ 
				return (x != 0) && ((x & (x - 1)) == 0);
			}

			void	printLevelOrderHelper(node_ptr node)
			{
				if (node == NULL)
					return;
				std::queue<node_ptr > q;
				q.push(node);

				int n = 1;
				while (!q.empty())
				{
					if (isPowerOfTwo(n))
						std::cout << std::endl;
					node_ptr tmp = q.front();
					std::cout << tmp->key << " ";
					q.pop();
					n++;
					if (tmp->left != NULL)
						q.push(tmp->left);
					if (tmp->right != NULL)
						q.push(tmp->right);
				}
			}
		
		//		ITERATORS --------------------------------------------------------------------------------------
	
			iterator	begin()
			{
				return iterator(getSmallestNode(root_));
			};

			const_iterator	begin() const
			{
				return iterator(getSmallestNode(root_));
			};

			iterator	end()
			{
				// return iterator(getBiggestNode(root_));
				return NULL;
			};

			const_iterator	end() const
			{
				return NULL;
			};

			reverse_iterator	rbegin()
			{
				return reverse_iterator(end());
			};

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			};

			// reverse_iterator	rend()
			// {
			// 	return tree_.rend();
			// };

			// const_reverse_iterator rend() const
			// {
			// 	return tree_.rend();
			// };

		protected:
			node_ptr							root_;
			std::allocator<Node<Key, Value> >	nodeAllocator_;
			key_compare							comp_; // key comparator
			allocator_type						allocator_;
			size_type							size_; // total number of nodes

		private :		

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

//		MODIFIERS --------------------------------------------------------------------------------------

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
				if (node == NULL)
					return;
			
				deleteTree(node->left);
				deleteTree(node->right);
				
				#if DEBUG
					std::cout << MEDIUMORCHID3 << "Deleting node: " << node->value << RESET << std::endl;
				#endif
				delete node;
			}

						/*         G                    G
			          / \                  / \
					 P   U      ->        N   U
					/ \                  / \
			       B   N                P   RC
				      / \              / \
					 LC  RC           B   LC
			*/
			// rotate a node in the left direction.
			// the node's right child will take its place.
			// node correspond to P.
			void	rotateLeft(node_ptr node)
			{
				node_ptr right_child = node->right; // right_child is a copy of N

				node->right = right_child->left; // LC becomes P's right child

				if (node->right) // if LC exists
					node->right->parent = node; // P becomes LC's parent
				
				right_child->parent = node->parent; // N's parent becomes G

				if (node->parent == NULL) // if G is NULL
					root_ = right_child; // then N needs to be root_
				else if (node == node->parent->left) // if P is a left child
					node->parent->left = right_child; // N becomes G's left's child
				else // if P is a right child
					node->parent->right = right_child; // N becomes G's right child
				
				right_child->left = node; // P becomes N's left child
				node->parent = right_child; // N becomes P's parent
			}

			// rotate a node in the right direction.
			// the node's left child will take its place.
			// if confused, see rotateLeft, rotateRIght is its mirror.
			void	rotateRight(node_ptr node)
			{
				node_ptr left_child = node->left;

				node->left = left_child->right;
			
				if (node->left != NULL)
					node->left->parent = node;
			
				left_child->parent = node->parent;
			
				if (node->parent == NULL)
					root_ = left_child;
				else if (node == node->parent->left)
					node->parent->left = left_child;
				else
					node->parent->right = left_child;
			
				left_child->right = node;
				node->parent = left_child;
			}

			// rebalance the tree to respect to following rules ;
			// #1 A node is eather RED or BLACK
			// #2 The root and leaves are BLACK
			// #3 If a node is RED, then its children are BLACK
			// #4 All paths to a node's leaf (=e.i NULL node) descendant contains the same number of black nodes 
			void	fixViolation(node_ptr node)
			{
				node_ptr	parent = NULL;
				node_ptr	grand_parent = NULL;

				while (node != root_ && node->color != BLACK && node->parent->color == RED)
				{
					parent = node->parent;
					grand_parent = node->parent->parent;

					if (parent == grand_parent->left) // if parent is a left child
					{
						node_ptr uncle = grand_parent->right; // then the uncle is the right child

						if (uncle != NULL && uncle->color == RED) // case 2 --> node's uncle is red
						{
							grand_parent->color = RED;
							parent->color = BLACK;
							uncle->color = BLACK;
							node = grand_parent; // we go up the tree to the root_ node
						}
						else // case 3 --> node's uncle is black
						{
							if (node == parent->right) // if our node is a right child --> case 3.1 : triangle
							{
								rotateLeft(parent); // rotate in the opposite direction
								node = parent; // we go up the tree 
								parent = node->parent; // updating parent
							}
							parent->color = BLACK;
							grand_parent->color = RED;
							rotateRight(grand_parent);
						}
					}
					else // if parent is a right child
					{
						node_ptr uncle = grand_parent->left;

						if (uncle != NULL && uncle->color == RED) // case 2 --> node's uncle is red
						{
							grand_parent->color = RED;
							parent->color = BLACK;
							uncle->color = BLACK;
							node = grand_parent;
						}
						else // case 3 --> node's uncle is black
						{
							if (node == parent->left) // if  our node is a left child --> case 3.1 : triangle
							{
								rotateRight(parent); // we rotate in the opposite direction
								node = parent;
								parent = node->parent;
							}
							parent->color = BLACK;
							parent->color = RED;
							rotateLeft(grand_parent);
						}
					}
				}
				root_->color = BLACK; // case 0 --> root node is red (root_ must always be black)
			}
	};
}