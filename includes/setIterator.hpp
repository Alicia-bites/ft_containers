#pragma once

#include <cstddef>
#include <iostream>

#include "node.hpp"
#include "pair.hpp"
#include "utils.hpp"
// #include "RedBlackTree.hpp"

// FOR DEBUG
// #include <utility>

namespace ft
{

    // this is an iterator that will browse through my binary search tree
    // setIterator point to a pair<const Key, Value> of type value_type
	template <typename RBT, typename Key>
		class setIterator
		{
			public:
                typedef typename RBT::key_type              key_type;
                typedef typename RBT::mapped_type           mapped_type;
				typedef const Key                          	value_type;
				typedef value_type&                         reference;
				typedef value_type*                         pointer;
				typedef std::bidirectional_iterator_tag     iterator_category;
				typedef std::ptrdiff_t                      difference_type;

            private:
                typedef typename RBT::node_ptr          node_ptr;
                typedef RBT*                            RBTree_ptr;

                RBTree_ptr  tree_;
                node_ptr    node_;
                node_ptr    nil_;
                node_ptr    root_;
                node_ptr    biggest_;
                node_ptr    smallest_;
                pointer     pointer_; // pointer to data, which is a node attribute of type Key

            public:

                // default constructor
                setIterator()
                : tree_(0)
                , node_(0)
                , nil_(0)
                , root_(0)
                , biggest_(0)
                , smallest_(0)
                , pointer_(0)
                {
                    #if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling setIterator default constructor" << RESET << std::endl;
                    #endif
                };

                // constructor
                setIterator(node_ptr input_node, RBTree_ptr tree)
                : tree_(tree)
                , node_(input_node)
                , nil_(tree_->getNil())
                , root_(tree_->getRoot())
                , biggest_(tree->getBiggestNode(root_))
                , smallest_(tree->getSmallestNode(root_))
                , pointer_(&input_node->data)
                {
                    #if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling setIterator constructor from node" << RESET << std::endl;
                    #endif

                    if (!input_node || input_node == nil_)
                        pointer_ = 0;
                };

                // copy constructor
                // setIterator(const setIterator<typename remove_cv<Key>::type, Value> & original)
                setIterator(const setIterator<RBT, Key> & original)
                {
                    # if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling setIterator copy constructor" << RESET << std::endl;
                    #endif

                    if (this == &original)
                        return ;
                    tree_ = original.getTree();
                    node_ = original.getNode();
                    pointer_ = original.base();
                    nil_ = original.getNil();
                    root_ = original.getRoot();
                    biggest_ = original.getBiggest();
                    smallest_ = original.getSmallest();
                };

                // destructor
                ~setIterator(void)
                {
                    # if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling setIterator destructor" << RESET << std::endl;
                    #endif
                };



// GETTERS ---------------------------------------------------------------------------------------------
				
                pointer base() const
                {
                    return pointer_;
                }
                
                node_ptr    getNode() const
                {
                    return node_;
                }

                node_ptr    getNil() const
                {
                    return nil_;
                }

                RBTree_ptr  getTree() const
                {
                    return tree_;
                }

                node_ptr    getRoot() const
                {
                    return root_;
                }

                node_ptr    getBiggest() const
                {
                    return biggest_;
                }

                node_ptr    getSmallest() const
                {
                    return smallest_;
                }

// OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
				
                // assignement operator
                // setIterator<Key, Value>&    operator=(const setIterator<typename remove_cv<Key>::type, Value> & rhs)
                setIterator<RBT, Key>&    operator=(const setIterator<RBT, Key> & rhs)
                {
                    # if DEBUG
                        std::cout << SEAGREEN3 << "Calling assignement operator" << RESET << std::endl;
                    # endif

                    tree_ = rhs.getTree();
                    node_ = rhs.getNode();
                    nil_ = rhs.getNil();
                    root_ = rhs.getRoot();
                    biggest_ = rhs.getBiggest();
                    smallest_ = rhs.getSmallest();
                    pointer_ = rhs.base();

                    return *this;
                };
                
                // dereference
                reference operator*(void) const
                {
                    return *pointer_;
                };

                // allows a object of this class to be accessed like a pointer. 
                pointer	operator->(void) const
                {
                    return pointer_;
                };

                operator typename RBT::const_iterator() const
                {
                    return typename RBT::const_iterator(node_, tree_);
                }

                operator typename RBT::iterator() const
                {
                    return typename RBT::iterator(node_, tree_);
                }

	// ARITHMETIC OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
	
                // increment pointer and return a reference to its new
                // state. (++i)
                setIterator<RBT, Key> &	operator++(void)
                {
                    increment();
                    return *this;
                };

                // increment pointer and return a reference to its new
                // state. (--i)
                setIterator<RBT, Key> &	operator--(void)
                {
                    decrement();
                    return *this;
                };

                // increment pointer but return its initial state (i++)
                setIterator<RBT, Key>	operator++(int)
                {
                    setIterator<RBT, Key> tmp(*this);
                    increment();
                    return (tmp);
                };

                // decrement pointer but return its initial state (i--)
                setIterator<RBT, Key>	operator--(int)
                {
                    setIterator<RBT, Key> tmp(*this);
                    decrement();
                    return (tmp);
                };

            private :

            	// check if node is the past-the-end element
                bool isEnd(node_ptr node)
                {
                    if (node->key == nil_->key)
                    {
                        if (node->parent == biggest_)
                            return true;
                    }
                    return false;
                }

                void    increment()
                {
                    // std::cout << *node_ << std::endl;
                    // std::cout << *(node_->left) << std::endl;

                    // if you try to increment beyond biggest Key, always return a pointer
                    // to the node who's got the biggest key.
                    if (node_ == nil_)
                    {
                        node_ = biggest_;
                        pointer_ = &node_->data;
                        return ;
                    }
                    if (node_->right != nil_)
                    {
                        node_ = node_->right;
                        while (node_->left != nil_)
                            node_ = node_->left;
                    }
                    else
                    {
                        node_ptr parent = node_->parent;
                        if (parent == 0)
                        {
                            node_ = nil_;
                            pointer_ = 0;
                            return ;
                        }
                        while (node_ == parent->right)
                        { 
                            node_ = parent;
                            parent = parent->parent;
                            if (parent == 0)
                            {
                                node_ = nil_;
                                pointer_ = 0;
                                return ;
                            }
                        }
                        if (node_->right != parent)
                            node_ = parent;
                    }
                    pointer_ = &node_->data;
                }

                void    decrement()
                {
                    if (isEnd(node_))
                    {
                        node_ = node_->parent;
                        pointer_ = &node_->data;
                        return ;
                    }
                    // if you try to decrement beyond smallest Key, always return a pointer
                    // to the node who's got the smallest key.
                    if (node_ == 0)
                    {
                        node_ = smallest_;
                        pointer_ = &node_->data;
                        return ;                         
                    }
                    if (node_->left != nil_)
                    {
                        node_ = node_->left;
                        while (node_->right != nil_)
                            node_ = node_->right;
                    }
                    else
                    {
                        node_ptr parent = node_->parent;
                        if (parent == 0)
                        {
                            node_ = nil_;
                            pointer_ = 0;
                            return ;
                        }
                        while (node_ == parent->left)
                        {
                            node_ = parent;
                            parent = parent->parent;
                            if (parent == 0)
                            {
                                node_ = nil_;
                                pointer_ = 0;
                                return ;
                            }
                        }
                        if (node_->left != parent)
                            node_ = parent;
                    }
                    pointer_ = &node_->data;
                }
    	};
	// RELATIONNAL OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------

    template <typename RBT, typename A, typename B>
		bool	operator==(const setIterator<RBT, A> & lhs, const setIterator<RBT, B> & rhs)
		{
            if (lhs.base() == 0 && rhs.base() == 0)
                return true;
            else if (lhs.base() == 0 && rhs.base() != 0)
                return false;
            else if (lhs.base() != 0 && rhs.base() == 0)
                return false;
			return lhs.getNode()->key == rhs.getNode()->key;
		};

    template <typename RBT, typename A, typename B>
		bool	operator!=(const setIterator<RBT, A> & lhs, const setIterator<RBT, B> & rhs)
		{
            if (lhs.base() == 0 && rhs.base() == 0)
                return false;
            else if (lhs.base() == 0 && rhs.base() != 0)
                return true;
            else if (lhs.base() != 0 && rhs.base() == 0)
                return true;
			return lhs.getNode()->key != rhs.getNode()->key;
		};
}
