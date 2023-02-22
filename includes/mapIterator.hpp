#pragma once

#include <iostream>
#include <cstddef>
#include "node.hpp"
// #include "mapReverseIterator.hpp"
#include "pair.hpp"
#include "utils.hpp"

// FOR DEBUG
// #include <utility>

// this is an iterator that will browse through my binary search tree
// mapIterator point to a pair<const Key, Value> of type value_type
namespace ft
{
	template <typename Key, typename Value>
		class mapIterator
		{
			public:
                typedef Key                             key_type;
                typedef Value                           mapped_type;
				typedef ft::pair<const Key, Value >     value_type;
				typedef value_type&                     reference;
				typedef value_type*                     pointer;
				typedef std::bidirectional_iterator_tag iterator_category;
				typedef std::ptrdiff_t                  difference_type;

                private:
                    typedef Node<typename remove_cv<Key>::type, Value>  *  node_ptr;

                    node_ptr        node_;
                    pointer         pointer_;
                    bool            freeMe_;

                public:

                    // default constructor
                    mapIterator()
                    : node_(0)
                    , pointer_(0)
                    , freeMe_(0)
                    {
                    #if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator default constructor" << RESET << std::endl;
                    #endif
                };

                // constructor
                mapIterator(node_ptr input_node)
                : node_(input_node)
                , freeMe_(0)
                // , pointer_(&input_node->data)
                {
                    #if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator constructor from node" << RESET << std::endl;
                    #endif
                    
                    if (node_->key != input_node->data.first)
                    {
                        pointer_ = new pair<const Key, Value>(node_->key, node_->value);
                        freeMe_ = 1;
                    }
                    else
                        pointer_ = &input_node->data;
                };

                // copy constructor
                mapIterator(const mapIterator<typename remove_cv<Key>::type, Value> & original)
                : freeMe_(0)
                {
                    # if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator copy constructor" << RESET << std::endl;
                    #endif

                    node_ = original.getNode();
                    pointer_ = original.base();
                    // freeMe_ = original.getFreeMe();
                };

                // destructor
                ~mapIterator(void)
                {
                    # if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator destructor" << RESET << std::endl;
                    #endif

                    if (freeMe_)
                        delete pointer_;
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

                bool getFreeMe() const
                {
                    return freeMe_;
                }

// OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
				
                // assignement operator
                mapIterator<Key, Value>&    operator=(const mapIterator<typename remove_cv<Key>::type, Value> & rhs)
                {
                    # if DEBUG
                        std::cout << SEAGREEN3 << "Calling assignement operator" << RESET << std::endl;
                    # endif

                    node_ = rhs.getNode();
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

	// ARITHMETIC OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
	
                // increment pointer and return a reference to its new
                // state. (++i)
                mapIterator<Key, Value> &	operator++(void)
                {
                    increment();
                    return *this;
                };

                // increment pointer and return a reference to its new
                // state. (--i)
                mapIterator<Key, Value> &	operator--(void)
                {
                    decrement();
                    return *this;
                };

                // increment pointer but return its initial state (i++)
                mapIterator<Key, Value>	operator++(int)
                {
                    mapIterator<Key, Value> tmp(*this);
                    increment();
                    return (tmp);
                };

                // decrement pointer but return its initial state (i--)
                mapIterator<Key, Value>	operator--(int)
                {
                    mapIterator<Key, Value> tmp(*this);
                    decrement();
                    return (tmp);
                };

            private :

                void    increment()
                {
                    if (node_->right)
                    {
                        node_ = node_->right;
                        while (node_->left)
                            node_ = node_->left;
                    }
                    else
                    {
                        node_ptr parent = node_->parent;
                        if (!parent)
                        {
                            node_ = NULL;
                            pointer_ = NULL;
                            return ;
                        }
                        while (node_ == parent->right)
                        { 
                            node_ = parent;
                            parent = parent->parent;
                            if (!parent)
                            {
                                node_ = 0;
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
                    if (node_->left)
                    {
                        node_ = node_->left;
                        while (node_->right)
                            node_ = node_->right;
                    }
                    else
                    {
                        node_ptr parent = node_->parent;
                        if (!parent)
                        {
                            node_ = NULL;
                            pointer_ = NULL;
                            return ;
                        }
                        while (node_ == parent->left)
                        {
                            node_ = parent;
                            parent = parent->parent;
                            if (!parent)
                            {
                                node_ = 0;
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

	template <typename Key, typename Value>
		bool	operator==(const mapIterator<Key, Value> & lhs, const mapIterator<Key, Value> & rhs)
		{
            if (lhs.getNode() == 0 && rhs.getNode() == 0)
                return true;
            else if (lhs.getNode() == 0 && rhs.getNode() != 0)
                return false;
            else if (lhs.getNode() != 0 && rhs.getNode() == 0)
                return false;
			return lhs.getNode()->key == rhs.getNode()->key;
		};

    template <typename Key, typename Value>
		bool	operator==(const mapIterator<Key, Value> & lhs, const mapIterator<typename remove_cv<Key>::type, Value> & rhs)
		{
            if (lhs.getNode() == 0 && rhs.getNode() == 0)
                return true;
            else if (lhs.getNode() == 0 && rhs.getNode() != 0)
                return false;
            else if (lhs.getNode() != 0 && rhs.getNode() == 0)
                return false;
			return lhs.getNode()->key == rhs.getNode()->key;
		};

	template <typename Key, typename Value>
		bool	operator!=(const mapIterator<Key, Value> & lhs, const mapIterator<Key, Value> & rhs)
		{
            if (lhs.getNode() == 0 && rhs.getNode() == 0)
                return false;
            else if (lhs.getNode() == 0 && rhs.getNode() != 0)
                return true;
            else if (lhs.getNode() != 0 && rhs.getNode() == 0)
                return true;
			return lhs.getNode()->key != rhs.getNode()->key;
		};
    
    template <typename Key, typename Value>
		bool	operator!=(const mapIterator<Key, Value> & lhs, const mapIterator<typename remove_cv<Key>::type, Value> & rhs)
		{
            if (lhs.getNode() == 0 && rhs.getNode() == 0)
                return false;
            else if (lhs.getNode() == 0 && rhs.getNode() != 0)
                return true;
            else if (lhs.getNode() != 0 && rhs.getNode() == 0)
                return true;
			return lhs.getNode()->key != rhs.getNode()->key;
		};
}