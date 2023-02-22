#pragma once

#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>

#include "node.hpp"
#include "../colors/colors.hpp"
// #include "iterator.hpp"
#include "mapReverseIterator.hpp"
#include "mapIterator.hpp"
#include "stack.hpp"

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

//		CAPACITY --------------------------------------------------------------------------------------
			bool	empty() const
			{
				return (size_ == 0 ? true : false);
			};

			size_type	size() const
			{
				return size_;
			};

			size_type	max_size() const
			{
				return allocator_.max_size();
			};

//		ACCESSORS --------------------------------------------------------------------------------------

			Value &operator[](const Key &key)
			{
				node_ptr node = findNode(root_, key);
				
				if (node == 0)
					node = insertHelper(root_, key, Value());
				if (root_ == 0)
					root_ = node;
				return node->value;
			};

//		VISUALIZERS --------------------------------------------------------------------------------------
			
			// print one node whose key matches the key passed as argument
			void printNode(const Key & key)
			{
				node_ptr node = findNode(root_, key);
				std::cout << *node << std::endl;
			}

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

			bool isRed(node_ptr node)
			{
				 if (node->color == RED)
				 	return 1;
				return 0;
			}

			void printRBTree(Node<Key, Value>* node, int depth = 0, bool isLeft = false)
			{
				if (node == 0)
					return;
			
				// Print right child
				printRBTree(node->right, depth + 1, false);
			
				// Print current node
				for (int i = 0; i < depth; i++)
					std::cout << "    ";
				if (node->key != root_->key)
				std::cout << (isLeft ? "└──" : "┌──");
				if (isRed(node))
					std::cout << RED1;
				std::cout << "(" << node->key << ")" << RESET;
				std::cout << std::endl;
			
				// Print left child
				printRBTree(node->left, depth + 1, true);
			}

//		MODIFIERS --------------------------------------------------------------------------------------

			// inserts new node.
			// returns a pair, with its member pair::first set to an iterator pointing to either
			// the newly inserted element or to the element with an equivalent key in the map
			ft::pair<node_ptr, bool>	insert(const value_type & input_pair)
			{
				if (size_ == allocator_.max_size())
					throw (std::length_error("map::insert"));

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

			// inserts a new node.
			// optimizes its insertion time if position points to the element that will
			// precede the inserted element.
			// returns an iterator pointing to either the newly inserted element or to the
			// element that already had an equivalent key in the map.
			iterator	insert(iterator position, const value_type & input_pair)
			{
				if (size_ == allocator_.max_size())
					throw (std::length_error("map::insert"));

				node_ptr node = findNode(root_, input_pair.first);
				if (node)
					return iterator(node);
				if (position == begin() || (--position)->first < input_pair.first)
				{
					++position;
					node = insertHelper(position.getNode(), input_pair.first, input_pair.second);
				}

				else
				{
					node = insertHelper(root_, input_pair.first, input_pair.second);
					node->color = RED;
					if (!root_)
						root_ = node;
					fixViolation(node);
				}
				size_++;
				return iterator(node);
			};

			// returns a fresh key, guarantied unused
			Key 	extractKey()
			{
				Key lastKey = '0';
				if (root_ == NULL)
					return lastKey++;
				lastKey = getBiggestNode(root_)->key;
				Key newKey = lastKey + 1;
				return newKey;
			}

			template <class InputIterator>
				void	insert(InputIterator first, InputIterator last)
				{
					if (size_ == allocator_.max_size())
						throw (std::length_error("map::insert"));
	
					for (; first != last; first++)
					{
						node_ptr node = insertHelper(root_, first->first, first->second);
						node->color = RED;
						if (!root_)
							root_ = node;
						size_++;
						fixViolation(node);
					}
				};

			size_t	remove(const key_type & key)
			{
				size_t n = 0;
				while (findNode(root_, key))
				{
					removeHelper(root_, key);
					n++;
				}
				size_ -= n;
				return n;
			}

			void	remove(iterator first, iterator last)
			{
				// creating a stack to store elements;
				ft::stack<Key> to_delete_tmp;
				for(; first != last; first++)
					to_delete_tmp.push(first->first);
				
				// reversing order of stack to delete elements in the right order
				Key item;
				ft::stack<Key> to_delete;
				while (!to_delete_tmp.empty())
				{
					item = to_delete_tmp.top();
					to_delete_tmp.pop();
					to_delete.push(item);
				}

				while (!to_delete.empty())
				{
					std::cout << "removing " << to_delete.top() << std::endl;
					remove(to_delete.top());
					to_delete.pop();
				}
				std::cout << "size_ = " << size_ << std::endl;
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
				if (node == 0)
					return node;
				while (node->left != NULL)
				{
					if (comp_(node->left->key, node->key))
						node = node->left;
				}
				return node;
			}

			node_ptr	getBiggestNode(node_ptr node) const
			{
				if (node == 0)
					return node;
				while (node->right != NULL)
				{
					if (comp_(node->key, node->right->key))
						node = node->right;
				}
				return node;
			}

			void inorder()
			{
				inorderHelper(root_);
			}
		
		//		ITERATORS --------------------------------------------------------------------------------------
	
			iterator	begin()
			{
				return iterator(getSmallestNode(root_));
			};

			const_iterator	begin() const
			{
				return const_iterator(getSmallestNode(root_));
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

			reverse_iterator rbegin()
			{
				iterator it(getBiggestNode(root_));
				return reverse_iterator(it);
			};

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(getBiggestNode(root_));
			};

			reverse_iterator	rend()
			{
				iterator it(NULL);
				return reverse_iterator(it);
			};

			const_reverse_iterator rend() const
			{
				return NULL;
			};

//		TREE OPERATIONS --------------------------------------------------------------------------------------

			node_ptr	 find(const key_type & key)
			{
				node_ptr node = findNode(root_, key);
				if (!node)
					return NULL;
				return node;
			}

			node_ptr	upper_bound(const key_type & key)
			{
				node_ptr node = findNode(root_, key);
				node_ptr output = node->parent;
				return output;
			}

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
				if (/*key < node->key*/ comp_(key, node->key))
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

			// // optimized insertHelper if iterator position points to the element that
			// // would be BEFORE the newly inserted element
			// node_ptr insertHelper(node_ptr node, const Key& key, const Value& value, const_iterator position)
			// {
			// 	if (node == 0)
			// 		return new Node<Key, Value>(key, value);

			// 	if (key == node->key)
			// 	{
			// 		node->value = value;
			// 		return node;
			// 	}

			// 	if (key < node->key)
			// 	{
			// 		if (node->left == 0)
			// 		{
			// 			node->left = new Node<Key, Value>(key, value);
			// 			node->left->parent = node;
			// 			if (node == position.getNode())
			// 				node = node->left;
			// 			return node->left;
			// 		}
			// 		return insertHelper(node->left, key, value, position);
			// 	}
			// 	else
			// 	{
			// 		if (node->right == 0)
			// 		{
			// 			node->right = new Node<Key, Value>(key, value);
			// 			node->right->parent = node;
			// 			if (node == position.getNode()->left)
			// 				position.getNode()->left = node->right;
			// 			return node->right;
			// 		}
			// 		return insertHelper(node->right, key, value, position);
			// 	}
			// }


			// a function that searches a specific node and returns it
			node_ptr findNode(node_ptr node, const Key &key) const
			{
				while (node != 0 && node->key != key)
				{
					if (/*key < node->key*/ comp_(key, node->key))
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
			// node_ptr removeHelper(node_ptr node, Key key)
			// {
			// 	if (node == NULL)
			// 		return node;
			// 	if (/*key < node->key*/ comp_(key, node->key))
			// 		node->left = removeHelper(node->left, key);
			// 	else if (/*key > node->key*/ comp_(node->key, key))
			// 		node->right = removeHelper(node->right, key);
			// 	else 
			// 	{
			// 		if (node->left == NULL)
			// 		{
			// 			node_ptr tmp = node->right;
			// 			if (tmp)
			// 				tmp->parent = node->parent;
			// 			delete node;
			// 			return tmp;
			// 		}
			// 		else if (node->right == NULL)
			// 		{
			// 			node_ptr tmp = node->left;
			// 			if (tmp)
			// 				tmp->parent = node->parent;
			// 			delete node;
			// 			return tmp;
			// 		} 
			// 		else
			// 		{
			// 			node_ptr tmp = node->right;
			// 			while (tmp->left)
			// 				tmp = tmp->left;
			// 			node->key = tmp->key;
			// 			node->value = tmp->value;
			// 			node->right = removeHelper(node->right, tmp->key);
			// 		}
			// 	}
			// 	return node;
			// }

			node_ptr removeHelper(node_ptr node, Key key)
			{
				if (node == NULL)
					return node;
				
				if (key < node->key)
					node->left = removeHelper(node->left, key); // just looking for the key
				else if (key > node->key)
					node->right = removeHelper(node->right, key); // just looking for the key
				// the key has been found, let's delete the corresponding node :
				else
				{
					if (node->left == NULL and node->right == NULL) // node has no child
					{
						if (node == node->parent->left)
							node->parent->left = 0;
						if (node == node->parent->right)
							node->parent->right = 0;
						delete node;
						return NULL;
					} 
					else if (node->left == NULL) // node with only one child
					{
						node_ptr tmp = node->right;
						tmp->parent = node->parent;
						delete(node);
						fixViolation(tmp);
						return tmp;
					}
					else if (node->right == NULL) // node with only one child
					{
						node_ptr tmp = node->left;
						tmp->parent = node->parent;
						delete(node);
						fixViolation(tmp);
						return tmp;
					}
			
					// node_ptr successor = getSmallestNode(node->right);
					node_ptr successor = getBiggestNode(node->left);
					node->key = successor->key;
					
					node->left = removeHelper(node->left, successor->key);
				}
				return node;
			}

			// remove node and return a pointer to its replacer
			// node_ptr removeHelper(node_ptr root_, Key key)
			// {
			// 	// if (node == 0)
			// 		// return node;
				
			// 	node_ptr node = findNode(root_, key);
			// 	std::cout << "node->key = " << node->key << std::endl;
			// 	if (node->left == 0 && node->right == 0) // node has no child
			// 	{
			// 		std::cout << "deleted " << node->key << std::endl;
			// 		node_ptr successor = node->parent;
			// 		delete node;
			// 		return successor;
			// 	}
			// 	else if (node->left == 0) // node has only right child
			// 	{
			// 		node_ptr successor = node->right;
			// 		successor->key = node->key;
			// 		std::cout << "deleted " << node->key << std::endl;
			// 		delete node;
			// 		return successor;
			// 	}
			// 	else if (node->right == 0) // node has only left child
			// 	{
			// 		node_ptr successor = node->left;
			// 		successor->key = node->key;
			// 		std::cout << "deleted " << node->key << std::endl;
			// 		delete node;
			// 		return successor;
			// 	}
			// 	node_ptr successor = getBiggestNode(node->left);
			// 	node->key = successor->key;
			// 	delete successor;
			// 	successor = 0;
			// 	return node;
			// }

			// void	fixViolationAfterDeletion()
			// {
				// 
			// }
			
			void deleteTree(node_ptr node)
			{
				if (node == NULL)
					return;
			
				deleteTree(node->left);
				deleteTree(node->right);
				
				#if DEBUG
					std::cout << MEDIUMORCHID3 << "Deleting node: " << node->key << RESET << std::endl;
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
							grand_parent->color = RED;
							rotateLeft(grand_parent);
						}
					}
				}
				root_->color = BLACK; // case 0 --> root node is red (root_ must always be black)
			}

			void inorderHelper(node_ptr node)
			{
				if (node == NULL)
					return;
			
				inorderHelper(node->left);
				std::cout << node->key << " ";
				inorderHelper(node->right);
			}
	};
}