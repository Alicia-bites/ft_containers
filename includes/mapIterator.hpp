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
    // mapIterator point to a pair<const Key, Value> of type value_type
	template <typename RBT, typename Value>
		class mapIterator
		{
			public:
                typedef typename RBT::key_type              key_type;
                typedef typename RBT::mapped_type           mapped_type;
				typedef typename RBT::value_type            value_type;
				typedef value_type&                         reference;
				typedef value_type*                         pointer;
				typedef std::bidirectional_iterator_tag     iterator_category;
				typedef std::ptrdiff_t                      difference_type;

                private:
                    typedef typename RBT::node_ptr          node_ptr;
                    typedef RedBlackTree<key_type, Value>	* RBTree_ptr;

                    RBTree_ptr  tree_;
                    node_ptr    node_;
                    node_ptr    nil_;

                    pointer     pointer_; // pointer to data, which is a node attribute of type pair<const Key, value>

                public:

                    // default constructor
                    mapIterator()
                    : tree_(0)
                    , node_(0)
                    , nil_(0)
                    , pointer_(0)
                    {
                        #if DEBUG
                            std::cout << PALETURQUOISE1 << "Calling mapIterator default constructor" << RESET << std::endl;
                        #endif
                    };

                // constructor
                mapIterator(node_ptr input_node, RBTree_ptr tree)
                : tree_(tree)
                , node_(input_node)
                , nil_(tree_->getNil())
                , pointer_(&input_node->data)
                {
                    #if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator constructor from node" << RESET << std::endl;
                    #endif

                    if (!input_node)
                        pointer_ = 0;
                };

                // copy constructor
                // mapIterator(const mapIterator<typename remove_cv<Key>::type, Value> & original)
                mapIterator(const mapIterator<RBT, Value> & original)

                {
                    # if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator copy constructor" << RESET << std::endl;
                    #endif

                    tree_ = original.getTree();
                    node_ = original.getNode();
                    pointer_ = original.base();
                    nil_ = original.getNil();
                };

                // destructor
                ~mapIterator(void)
                {
                    # if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator destructor" << RESET << std::endl;
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

// OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
				
                // assignement operator
                // mapIterator<Key, Value>&    operator=(const mapIterator<typename remove_cv<Key>::type, Value> & rhs)
                mapIterator<RBT, Value>&    operator=(const mapIterator<RBT, Value> & rhs)
                {
                    # if DEBUG
                        std::cout << SEAGREEN3 << "Calling assignement operator" << RESET << std::endl;
                    # endif

                    tree_ = rhs.getTree();
                    node_ = rhs.getNode();
                    pointer_ = rhs.base();
                    nil_ = rhs.getNil();
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

	// ARITHMETIC OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
	
                // increment pointer and return a reference to its new
                // state. (++i)
                mapIterator<RBT, Value> &	operator++(void)
                {
                    increment();
                    return *this;
                };

                // increment pointer and return a reference to its new
                // state. (--i)
                mapIterator<RBT, Value> &	operator--(void)
                {
                    decrement();
                    return *this;
                };

                // increment pointer but return its initial state (i++)
                mapIterator<RBT, Value>	operator++(int)
                {
                    mapIterator<RBT, Value> tmp(*this);
                    increment();
                    return (tmp);
                };

                // decrement pointer but return its initial state (i--)
                mapIterator<RBT, Value>	operator--(int)
                {
                    mapIterator<RBT, Value> tmp(*this);
                    decrement();
                    return (tmp);
                };

            private :

                void    increment()
                {
                    // if (node_ == nil_)
                    // {
                    //     node_ = tree_.getBiggestNode(tree_.getRoot());
                    //     pointer_ = &node_->data;
                    //     return ;                         
                    // }
                    if (node_->right != nil_)
                    {
                        node_ = node_->right;
                        while (node_->left != nil_)
                            node_ = node_->left;
                    }
                    else
                    {
                        node_ptr parent = node_->parent;
                        if (parent == nil_)
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

                    // if (node_ == 0)
                    // {
                    //     node_ = tree_.getSmallestNode(tree_.getRoot());
                    //     pointer_ = &node_->data;
                    //     return ;                         
                    // }
                    if (node_->left != nil_)
                    {
                        node_ = node_->left;
                        while (node_->right != nil_)
                            node_ = node_->right;
                    }
                    else
                    {
                        node_ptr parent = node_->parent;
                        if (parent == nil_)
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

	// template <typename RBT, typename Value>
	// 	bool	operator==(const mapIterator<RBT, Value> & lhs, const mapIterator<RBT, Value> & rhs)
	// 	{
    //         if (lhs.base() == 0 && rhs.base() == 0)
    //             return true;
    //         else if (lhs.base() == 0 && rhs.base() != 0)
    //             return false;
    //         else if (lhs.base() != 0 && rhs.base() == 0)
    //             return false;
	// 		return lhs.getNode()->key == rhs.getNode()->key;
	// 	};

    template <typename RBT, typename A, typename B>
		bool	operator==(const mapIterator<RBT, A> & lhs, const mapIterator<RBT, B> & rhs)
		{
            if (lhs.base() == 0 && rhs.base() == 0)
                return true;
            else if (lhs.base() == 0 && rhs.base() != 0)
                return false;
            else if (lhs.base() != 0 && rhs.base() == 0)
                return false;
			return lhs.getNode()->key == rhs.getNode()->key;
		};

	// template <typename RBT, typename Value>
	// 	bool	operator!=(const mapIterator<RBT, Value> & lhs, const mapIterator<RBT, Value> & rhs)
	// 	{
    //         if (lhs.base() == 0 && rhs.base() == 0)
    //             return false;
    //         else if (lhs.base() == 0 && rhs.base() != 0)
    //             return true;
    //         else if (lhs.base() != 0 && rhs.base() == 0)
    //             return true;
	// 		return lhs.getNode()->key != rhs.getNode()->key;
	// 	};
    
    template <typename RBT, typename A, typename B>
		bool	operator!=(const mapIterator<RBT, A> & lhs, const mapIterator<RBT, B> & rhs)
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

