#pragma once

#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>

#include "../colors/colors.hpp"

#include "node.hpp"
#include "iterator.hpp"
#include "stack.hpp"

// #1 A node is eather RED or BLACK

// #2 The root and leaves are BLACK

// #3 If a node is RED, then its children are BLACK

// #4 All paths to a node's leaf descendant contains the same number of black nodes 

namespace ft
{
	template <typename Key, typename Value>
	class mapIterator;

	template <typename Key, typename Value, typename Compare = std::less<Key>,
		typename Allocator = std::allocator<ft::pair<const Key, Value> > >
	class RedBlackTree
	{
		public:		
			typedef Key																					key_type; // type of key used to pair with value (1st template parameter)
			typedef Value																				mapped_type; // type of the value paired with key (2nd template parameter)
			typedef ft::pair<const Key, Value>															value_type; 	 // represent the key-value pair
			typedef Compare		 																		key_compare;	 // The third template parameter (Compare)	defaults to: less<key_type>
			typedef Allocator																			allocator_type;	 // The fourth template parameter (Alloc)	defaults to: allocator<value_type>
			typedef typename allocator_type::reference													reference;		 // for the default allocator: value_type&
			typedef typename allocator_type::const_reference											const_reference; // for the default allocator: const value_type&
			typedef typename allocator_type::pointer													pointer;		 // for the default allocator: value_type*
			typedef typename allocator_type::const_pointer												const_pointer;	 // for the default allocator: const value_type*
			typedef typename allocator_type::difference_type											difference_type; // a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
			typedef typename allocator_type::size_type													size_type;		 // an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
			typedef ft::mapIterator<RedBlackTree<Key, Value, Compare, Allocator>, value_type>			iterator; 		 // a bidirectional iterator to value_type
			typedef ft::mapIterator<RedBlackTree<Key, Value, Compare, Allocator>, const value_type>		const_iterator;  // a bidirectional iterator to const value_type
			typedef ft::reverse_iterator<iterator>														reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>												const_reverse_iterator;
			typedef Node<Key, Value>																	*node_ptr;

//	CONSTRUCTORS ----------------------------------------------------------------------------

			// default constructor
			RedBlackTree(const Allocator & allocator = Allocator())
			: nil_(0)
			, comp_(std::less<Key>())
			, allocator_(allocator)
			, size_(0)
			{
				# if DEBUG
					std::cout << SPRINGGREEN3 << "RedBlackTree default constructor called" << std::endl;
				#endif

				root_ = nil_;
			};

			// constuctor with specific compare function and allocator function
			RedBlackTree(key_compare comp, allocator_type allocator)
			: nil_(0)
			, comp_(comp)
			, allocator_(allocator)
			, size_(0)
			{
				# if DEBUG
					std::cout << SPRINGGREEN3 << "RedBlackTree constructor #1 called" << std::endl;
				#endif

				root_ = nil_;
			};

			// copy constructor
			RedBlackTree(const RedBlackTree<Key, Value, Compare, Allocator> & original)
			{
				#if DEBUG
					std::cout << MAGENTA3 << "Calling RedBlackTree copy constructor" << RESET << std::endl;
				#endif
	
				if (this != &original)
					*this = original;
			};

//	DESTRUCTORS --------------------------------------------------------------------------------------

			~RedBlackTree()
			{
				#if DEBUG
					std::cout << MAGENTA3 << "Calling RedBlackTree destructor" << RESET << std::endl;
				#endif
				
				if (root_)
				{
					deleteTree(root_);
					root_ = NULL;
				}
				if (nil_)
				{
					delete nil_;
					nil_ = NULL;
				}
			}

//	MEMBER FUNCTIONS ---------------------------------------------------------------------------------

//		ASSIGNEMENT ----------------------------------------------------------------------------------------------------------------------------

			// deep copy of tree
			RedBlackTree<Key, Value, Compare, Allocator> & operator=(const RedBlackTree<Key, Value, Compare, Allocator> & rhs)
			{
				#if DEBUG
					std::cout << MAGENTA3 << "Calling RedBlackTree assignement operator" << RESET << std::endl;
				#endif

				if (this == &rhs)
					return *this;

				if (size_ > 0) // first we clear content of this
					clear();

				if (rhs.root_ != 0) // if rhs's tree isn't empty, copy rhs in this
				{
					// creating new nil_
					Value value = rhs.nil_->getValue();
					nil_ = new Node<Key, Value>(rhs.nil_->key, value);
					nil_->color = BLACK;
					nil_->parent = 0;
					nil_->left = nil_;
					nil_->right = nil_;
					
					comp_ = rhs.comp_;
					allocator_ = rhs.allocator_;
					size_ = rhs.size_;

					copyTree(root_, rhs.root_, rhs.nil_, 0);
				}
				return *this;
			}

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
				if (node == 0)
				{
					std::cout << "Nothing to print!" << std::endl;
					return ;
				}
				if (node != nil_)
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
				if (node == nil_ || node == 0)
					return;
			
				printRBTree(node->right, depth + 1, false);
			
				for (int i = 0; i < depth; i++)
					std::cout << "    ";
				if (node->key != root_->key)
				std::cout << (isLeft ? "└──" : "┌──");
				if (isRed(node))
					std::cout << RED1;
				std::cout << "(" << node->key << ")" << RESET;
				std::cout << std::endl;
			
				printRBTree(node->left, depth + 1, true);
			}

//		MODIFIERS --------------------------------------------------------------------------------------

			// inserts new node.
			// returns a pair, with its member pair::first set to an iterator pointing to either
			// the newly inserted element or to the element with an equivalent key in the map
			ft::pair<iterator, bool>	insert(const value_type & input_pair)
			{
				if (size_ == allocator_.max_size())
					throw (std::length_error("map::insert"));

				node_ptr node = findNode(root_, input_pair.first);
				
				// if node with input key exists
				if (node != nil_)
				{
					iterator output(node, this);
					return ft::make_pair(output, false);
				}

				// if nil_ hasn't been created yet
				if (nil_ == 0)
				{
					mapped_type value = input_pair.second;
					nil_ = new Node<Key, Value>(input_pair.first, value);
					nil_->color = BLACK;
					nil_->parent = 0;
					nil_->left = nil_;
					nil_->right = nil_;
				}

				// insert node
				Value value = input_pair.second;
				node = insertHelper(root_, input_pair.first, value);
				node->color = RED;
				if (!root_)
					root_ = node;
				size_++;
				fixViolation(node);

				iterator output(node, this);
				return ft::make_pair(output, true);
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

				if (node != nil_)
					return iterator(node, this);
				if (position == begin() || (--position)->first < input_pair.first)
				{
					++position;
					Value value = input_pair.second;
					node = insertHelper(position.getNode(), input_pair.first, value);
				}

				else
				{
					Value value = input_pair.second;
					node = insertHelper(position.getNode(), input_pair.first, value);
					node->color = RED;
					if (!root_)
						root_ = node;
					fixViolation(node);
				}
				size_++;
				return iterator(node, this);
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
					for(; first != last; first++)
						insert(*first);
				};

			size_t	remove(const key_type & key)
			{
				node_ptr node_to_be_deleted = findNode(root_, key); 
				if (node_to_be_deleted == 0 || node_to_be_deleted == nil_)
					return 0;

				# if DEBUG
				std::cout << DEEPSKYBLUE6 << "removing " << key << RESET << std::endl;
				# endif

				removeHelper(key);
				delete node_to_be_deleted;
				node_to_be_deleted = 0;

				# if DEBUG
					printRBTree(root_);
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << DARKCYAN << "Is RedBlackTree? " << is_rb_tree() << RESET << std::endl;
				#endif

				size_--;
				return 1;
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
					remove(to_delete.top());
					to_delete.pop();
				}
			}

			void	swap(RedBlackTree<Key, Value, Compare, Allocator> & swapMe)
			{
				node_ptr					tmpRoot			= swapMe.root_;
				node_ptr					tmpNil			= swapMe.nil_;
				key_compare					tmpComp			= swapMe.comp_;
				allocator_type				tmpAllocator	= swapMe.allocator_;
				size_type					tmpSize			= swapMe.size_;
				
				swapMe.root_ = root_;
				swapMe.nil_ = nil_;
				swapMe.comp_ = comp_;
				swapMe.allocator_ = allocator_;
				swapMe.size_ = size_;

				root_ = tmpRoot;
				nil_ = tmpNil;
				comp_ = tmpComp;
				allocator_ = tmpAllocator;
				size_ = tmpSize;
			}

			void	clear()
			{
				# if DEBUG
					std::cout << SPRINGGREEN3 << "RedBlackTree clear function called" << std::endl;
				#endif
				if (root_ == 0)
					return ;
				if (root_ != nil_)
					deleteTree(root_);
				delete nil_;
				nil_ = NULL;
				root_ = NULL;
				size_ = 0;
			}

//		GETTERS --------------------------------------------------------------------------------------

			node_ptr	getRoot() const
			{
				return root_;
			};

			node_ptr	getNil() const
			{
				return nil_;
			};

			size_t		getSize() const
			{
				return size_;
			}

			node_ptr	getSmallestNode(node_ptr node) const
			{
				if (node == nil_)
					return node;
				while (node->left != nil_)
					node = node->left;
				return node;
			}

			node_ptr	getBiggestNode(node_ptr node) const
			{
				if (node == 0)
					return node;
				while (node->right != nil_)
					node = node->right;
				return node;
			}

			allocator_type	get_allocator() const
			{
				return allocator_;
			}
			
		//		ITERATORS --------------------------------------------------------------------------------------

			iterator	begin()
			{
				return iterator(getSmallestNode(root_), this);
			};

			const_iterator	begin() const
			{
				return const_iterator(getSmallestNode(root_), this);
			};

			// returns a past-the-end element.
			// I decided to return an iterator pointing to null
			// and linked to the biggest element in the container
			// so that decrementation is possible.
			iterator	end()
			{
				// linking end() with last node,
				// in order to get a correct
				// result when doing end()--
				node_ptr beyondEnd = nil_;
				if (nil_)
				{
					node_ptr biggest = getBiggestNode(root_);
					// beyondEnd->key = biggest->key;
					// beyondEnd->setValue(biggest->getValue());
					beyondEnd->parent = biggest;
				}
				return iterator(beyondEnd, this);
			};

			const_iterator	end() const
			{
				node_ptr beyondEnd = nil_;
				if (nil_)
				{
					node_ptr biggest = getBiggestNode(root_);
					beyondEnd->parent = biggest;
				}
				return const_iterator(beyondEnd, this);
			};

			// returns a reverse iterator pointing to the last element
			// in the container (i.e., its reverse beginning).
			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			};

			const_reverse_iterator rbegin() const
			{
				// if map is empty
				if (!root_)
					return const_reverse_iterator(const_iterator(NULL, this));
				node_ptr biggest = getBiggestNode(root_);
				const_iterator output(biggest, this);
				return const_reverse_iterator(output);				
			};

			reverse_iterator	rend()
			{
				return reverse_iterator(begin());
			};

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			};

//		TREE OPERATIONS --------------------------------------------------------------------------------------

			iterator	 find(const key_type & key)
			{
				node_ptr node = findNode(root_, key);
				iterator output(node, this);
				if (!node)
					return output;
				return output;
			}

			size_type count(const key_type & k) const
			{
				node_ptr node = findNode(root_, k);
				if (node == nil_ || node == 0)
					return 0;
				return 1;
			}

			// returns iterator to node whose key is greater
			// than k.
			iterator	upper_bound(const key_type & k)
			{
				iterator output = begin();
				if (comp_(k, output->first))
					return output;
				iterator endOfTime = end();
				while (output != endOfTime && comp_(output->first, k))
					output++;
				if (output == end())
					return end();
				if (output.getNode() == getBiggestNode(root_))
				{
					if (comp_(k, output->first))
						return output;
					else
						return end();
				}
				output++;
				return output;
			}

			// returns iterator that points to the first node that is not
			// less than k. (i.o.w --> k or greater than k)
			iterator	lower_bound(const key_type & k)
			{
				iterator output = begin();
				iterator endOfTime = end();
				while (output != endOfTime && comp_(output->first, k))
					++output;
				return output;
			}

			pair<iterator, iterator> equal_range(const Key & k)
			{
				iterator low = lower_bound(k);
				iterator up = upper_bound(k);

				return ft::make_pair(low, up);
			}

			pair<const_iterator, const_iterator> equal_range(const key_type & k) const
			{
				const_iterator low = lower_bound(k);
				const_iterator up = upper_bound(k);

				return ft::make_pair(low, up);
			}

			// a function that searches a specific node and returns it
			node_ptr findNode(node_ptr node, const Key &key) const
			{
				while (node != nil_ && node->key != key)
				{
					if (/*key < node->key*/ comp_(key, node->key))
						node = node->left;
					else
						node = node->right;
				}
				return node;
			};

		private :
			node_ptr							root_;
			node_ptr							nil_;
			std::allocator<Node<Key, Value> >	nodeAllocator_;
			key_compare							comp_; // key comparator
			allocator_type						allocator_;
			size_type							size_; // total number of nodes

//		COPY TOOL --------------------------------------------------------------------------------------

			void copyTree(node_ptr & new_node, node_ptr node, node_ptr nil, node_ptr parent)
			{
				if (node == nil)
				{
					new_node = nil_;
					new_node->parent = parent;
					return ;
				}
				else
				{
					Value value = node->getValue();
					new_node = new Node<Key, Value>(node->key,value);

					new_node->parent = parent;
					new_node->color = node->color;
					copyTree(new_node->left, node->left, nil, new_node);
					copyTree(new_node->right, node->right, nil, new_node);
				}
			};


//		MODIFIERS --------------------------------------------------------------------------------------
	
	//		NODE REMOVER --------------------------------------------------------------------------------------

			void	transplant(node_ptr u, node_ptr v)
			{
				if (u->parent == 0)
					root_ = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			void	removeHelper(Key key)
			{
				node_ptr z = findNode(root_, key);

				if (z == 0)
				{
					std::cout << "Key not found!" << std::endl;
					return ;
				}

				node_ptr y = z;
				int y_orig_color = y->color; 
				node_ptr x;
				
				// case 1
				if (z->left == nil_)
				{
					x = z->right;
					transplant(z, z->right);
				}

				// case 2
				else if (z->right == nil_)
				{
					x = z->left;
					transplant(z, z->left);
				}

				// case 3
				else
				{
					y = getSmallestNode(z->right);
					y_orig_color = y->color;
					x = y->right;
					
					if (y->parent == z)
						x->parent = y;
					else
					{
						transplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					
					transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				
				if (y_orig_color == BLACK)
					delete_fixup(x);
			}

			void	delete_fixup(node_ptr x)
			{
				while (x != root_ and x->color == BLACK)
				{
					if (x == x->parent->left)
					{
						node_ptr w = x->parent->right;
						// type 1
						if (w->color == RED)
						{
							w->color = BLACK;
							x->parent->color = RED;			
							rotateLeft(x->parent);
							w = x->parent->right;
						}
						// type 2
						if (w->left->color == BLACK and w->right->color == BLACK)
						{
							w->color = RED;
							x = x->parent;
						}
						else
						{
							// type 3
							if (w->right->color == BLACK)
							{
								w->left->color = BLACK;
								w->color = RED;
								rotateRight(w);
								w = x->parent->right;
							}
							// type 4
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->right->color = BLACK;
							rotateLeft(x->parent);
							x = root_;
						}
					}
					else
					{
						node_ptr w = x->parent->left;
						// type 1
						if (w->color == RED)
						{
							w->color = BLACK;
							x->parent->color = RED;
							rotateRight(x->parent);
							w = x->parent->left;
						}
						// type 2
						if (w->right->color == BLACK and w->left->color == BLACK)
						{
							w->color = RED;
							x = x->parent;
						}
						else
						{
							// type 3
							if (w->left->color == BLACK)
							{
								w->right->color = BLACK;
								w->color = RED;
								rotateLeft(w);
								w = x->parent->left;
							}
							// type 4
							w->color = x->parent->color;
							x->parent->color = BLACK;
							w->left->color = BLACK;
							rotateRight(x->parent);
							x = root_;
						}
					}
				}
				x->color = BLACK;
			}

	//		DELETE TREE --------------------------------------------------------------------------------------

			void deleteTree(node_ptr node)
			{
				#if DEBUG
					std::cout << MEDIUMORCHID3 << "Deleting node: " << node->key << RESET << std::endl;
				#endif
			
				if (node == nil_ || node == 0)
					return;
			
				deleteTree(node->left);
				deleteTree(node->right);

				delete node;
				node = NULL;
			}
	
	//		ROTATE NODE TOOLS --------------------------------------------------------------------------------------

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

				if (node->right != nil_) // if LC exists
					node->right->parent = node; // P becomes LC's parent
				
				right_child->parent = node->parent; // N's parent becomes G

				if (node->parent == 0) // if G is NULL
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
			
				if (node->left != nil_)
					node->left->parent = node;
			
				left_child->parent = node->parent;
			
				if (node->parent == 0)
					root_ = left_child;
				else if (node == node->parent->left)
					node->parent->left = left_child;
				else
					node->parent->right = left_child;
			
				left_child->right = node;
				node->parent = left_child;
			}

	//		INSERT TOOLS --------------------------------------------------------------------------------------

			// recursive function, used to insert a new node
			// from root_, find the next available place to create new Node
			// !! WITHOUT CARING ABOUT BALANCE
			node_ptr	insertHelper(node_ptr node, const Key &key, Value &value)
			{
				if (node == 0)
				{
					node_ptr newNode = new Node<Key, Value>(key, value);
					newNode->left = nil_;
					newNode->right = nil_;
					return newNode;
				}
				if (key == node->key)
				{
					node->setValue(value);
					return node;
				}
				if (/*key < node->key*/ comp_(key, node->key))
				{
					if (node->left == nil_)
					{
						node->left = new Node<Key, Value> (key, value);
						node->left->parent = node;
						node->left->left = nil_;
						node->left->right = nil_;
						return node->left;
					}
					return insertHelper(node->left, key, value);
				}
				if (node->right == nil_)
				{
					node->right = new Node<Key, Value> (key, value);
					node->right->parent = node;
					node->right->left = nil_;
					node->right->right = nil_;
					return node->right;
				}
				return insertHelper(node->right, key, value);
			};

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

	//		CHECK RBTree TOOLS --------------------------------------------------------------------------------------

			bool is_rb_tree()
			{
				int black_height = -1;
				return is_rb_subtree(root_, black_height);
			}

			bool is_rb_subtree(node_ptr node, int & black_height)
			{
				if (node == NULL)
				{
					// Empty subtree is a valid RBT.
					black_height = 0;
					return true;
				}

				// Check BST property.
				if ((node->left != NULL && node->left->key >= node->key) ||
					(node->right != NULL && node->right->key <= node->key))
					return false;

				// Recursively check left and right subtrees.
				int left_black_height, right_black_height;
				if (!is_rb_subtree(node->left, left_black_height) ||
					!is_rb_subtree(node->right, right_black_height))
					return false;

				// Check RBT properties.
				if (node->color != RED &&
					node->color != BLACK)
					return false;

				if (node->color == BLACK)
					black_height = left_black_height + 1;
				else
					black_height = left_black_height;

				if (left_black_height != right_black_height)
					return false;

				return true;
			}
	};
}