#pragma once

#include <iostream>
#include <cstddef>
#include "node.hpp"
#include "iterator.hpp"
#include "pair.hpp"
#include "utils.hpp"

// FOR DEBUG
// #include <utility>

// this is an iterator that will browse through my binary search tree
// mapIterator point to a pair<const Key, Value> of type value_type
namespace ft
{
	template <typename Key, typename Value, typename Allocator = std::allocator<ft::pair<const Key, Value> > >
		class mapIterator
		{
			public:
				typedef ft::pair<const Key, Value >     value_type;
				typedef value_type&                     reference;
				typedef value_type*                     pointer;
				typedef std::bidirectional_iterator_tag iterator_category;
				typedef std::ptrdiff_t                  difference_type;

            private:
                typedef Node<Key, Value>  *  node_ptr;

                node_ptr        node_;
                pointer         pointer_;
                Allocator       allocator_;

                
            public:

                // default constructor
                mapIterator()
                : pointer_(0)
                {
                    #if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator default constructor" << RESET << std::endl;
                    #endif
                };

                // constructor
                mapIterator(node_ptr input_node)
                : node_(input_node)
                {
                    #if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator constructor from node" << RESET << std::endl;
                    #endif

                    pointer_ = allocator_.allocate(1);
                    allocator_.construct(pointer_, ft::pair<Key, Value>(node_->key, node_->value));
                };

                // copy constructor
                mapIterator(const mapIterator<Key, Value, Allocator> & original)
                : node_(original.node_)
                , allocator_(original.allocator_)
                {
                    # if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator copy constructor" << RESET << std::endl;
                    #endif

                    pointer_ = allocator_.allocate(1);
                    allocator_.construct(pointer_, ft::pair<Key, Value>(node_->key, node_->value));
                };

                // destructor
                ~mapIterator(void)
                {
                    # if DEBUG
                        std::cout << PALETURQUOISE1 << "Calling mapIterator destructor" << RESET << std::endl;
                    #endif

                    if (pointer_)
                    {
                        allocator_.destroy(pointer_);
                        allocator_.deallocate(pointer_, 1);
                        pointer_ = 0;
                    }
                };



// GETTERS ---------------------------------------------------------------------------------------------
				
                node_ptr    getNode() const
                {
                    return node_;
                }

// OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------
				
                // assignement operator
                mapIterator<Key, Value>&    operator=(const mapIterator<Key, Value> & rhs)
                {
                    # if DEBUG
                        std::cout << SEAGREEN3 << "Calling assignement operator" << RESET << std::endl;
                    # endif

                    if (this == &rhs)
                        return *this;
                    node_ = rhs.node_;
                    allocator_ = rhs.allocator_;
                    this->~mapIterator();
                    pointer_ = allocator_.allocate(1);
                    allocator_.construct(pointer_, ft::make_pair(node_->key, node_->value));
                    return *this;
                };

                // // this is a type conversion operator function. Its genereic form is
                // // operator type() 
                // // where type is the type to which the class should be converted.
                // // Here, we convert to mapIterator<const T>
                // // wich allows conversion to a constant type T
                // // (initially, our class is mapIterator<Key, Value>).
                // operator mapIterator<const T>() const
                // {
                // 	return (mapIterator<const T>(pointer_));
                // }
                
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
                    if (node_->right)
                    {
                        node_ = node_->right;
                        while (node_->left)
                            node_ = node_->left;
                    }
                    else
                    {
                        node_ptr parent = node_->parent;
                        while (node_ == parent->right)
                        {
                            node_ = parent;
                            parent = parent->parent;
                        }
                        if (node_->right != parent)
                            node_ = parent;
                    }
                    return *this;
                };

                // increment pointer and return a reference to its new
                // state. (--i)
                mapIterator<Key, Value> &	operator--(void)
                {
                    pointer_--;
                    return *this;
                };

                // increment pointer but return its initial state (i++)
                mapIterator<Key, Value>	operator++(int)
                {
                    mapIterator<Key, Value> tmp(*this);
                    if (node_->right)
                    {
                        node_ = node_->right;
                        while (node_->left)
                            node_ = node_->left;
                    }
                    else
                    {
                        node_ptr parent = node_->parent;
                        while (node_ == parent->right)
                        {
                            node_ = parent;
                            parent = parent->parent;
                        }
                        if (node_->right != parent)
                            node_ = parent;
                    }
                    allocator_.destroy(pointer_);
                    allocator_.construct(pointer_, ft::make_pair(node_->key, node_->value));
                    return (tmp);
                };

                // decrement pointer but return its initial state (i--)
                mapIterator<Key, Value>	operator--(int)
                {
                    mapIterator<Key, Value> tmp(*this);
                    pointer_--;
                    return (tmp);
                };
    	};

	// RELATIONNAL OPERATOR OVERLOADS ---------------------------------------------------------------------------------------------

	template <typename Key, typename Value>
		bool	operator==(const mapIterator<Key, Value> & gandalf, const mapIterator<Key, Value> & sauron)
		{
			return gandalf.getNode()->key == sauron.getNode()->key;
		};

	template <typename Key, typename Value>
		bool	operator!=(const mapIterator<Key, Value> & gandalf, const mapIterator<Key, Value> & sauron)
		{
			return gandalf.getNode()->key != sauron.getNode()->key;
		};

    template <typename Key, typename Value, typename Allocator>
    std::ostream & operator<<(std::ostream & o, const mapIterator<Key, Value, Allocator> & rhs)
    {
        o << LIGHTGREEN1 << "Printing pair iterator point to --> " << std::endl
            << "Key = " << rhs->first << std::endl
            << "Value = " << rhs->second << std::endl
            << RESET
            << std::endl;
        return o;
    }

}