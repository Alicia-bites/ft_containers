#pragma once

// # include "../../utils/utility.hpp"
# include "node.hpp"

# include <cstddef>

namespace ft
{
    node_base*          node_increment(node_base* x);
    const node_base*    node_increment(const node_base* x);
    node_base*          node_decrement(node_base* x);
    const node_base*    node_decrement(const node_base* x);

    template <class Tp>
    struct ItMap
    {
        typedef Tp  value_type;
        typedef Tp* pointer;
        typedef Tp& reference;

        typedef std::ptrdiff_t                  difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;

        typedef ItMap<Tp>           Self;
        typedef node_base::base_ptr base_ptr;
        typedef node<Tp>*           link_type;

        ItMap() : _node()            {}
        ItMap(base_ptr x) : _node(x) {}

        reference   operator*() const   { return(*(static_cast<link_type>(_node)->getDataPtr())); }
        pointer     operator->() const  { return(static_cast<link_type>(_node)->getDataPtr()); }

        Self&   operator++()
        {
            this->_node = node_increment(this->_node);
            return (*this);
        }

        Self    operator++(int)
        {
            Self    tmp(*this);

            this->_node = node_increment(this->_node);
            return (tmp);
        }

        Self&   operator--()
        {
            this->_node = node_decrement(this->_node);
            return (*this);
        }

        Self    operator--(int)
        {
            Self    tmp(*this);

            this->_node = node_decrement(this->_node);
            return (tmp);
        }

        friend bool operator==(const Self& x, const Self& y)    { return (x._node == y._node); }
        friend bool operator!=(const Self& x, const Self& y)    { return (x._node != y._node); }

        base_ptr    _node;
    };

    template <class Tp>
    struct ConstItMap
    {
        typedef Tp          value_type;
        typedef const Tp*   pointer;
        typedef const Tp&   reference;
        
        typedef ItMap<Tp>   iterator;

        typedef std::ptrdiff_t                  difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;

        typedef ConstItMap<Tp>              Self;
        typedef node_base::const_base_ptr   base_ptr;
        typedef const node<Tp>*             link_type;

        ConstItMap() : _node()                          {}
        ConstItMap(base_ptr x) : _node(x)               {}
        ConstItMap(const iterator& x) : _node(x._node)  {}

        iterator    _const_cast() const { return iterator(const_cast<typename iterator::base_ptr>(this->_node)); }

        reference   operator*() const   { return (*(static_cast<link_type>(_node)->getDataPtr())); }
        pointer     operator->() const  { return (static_cast<link_type>(_node)->getDataPtr()); }

        Self&   operator++()
        {
            this->_node = node_increment(this->_node);
            return (*this);
        }

        Self    operator++(int)
        {
            Self    tmp(*this);

            this->_node = node_increment(this->_node);
            return (tmp);
        }

        Self&   operator--()
        {
            this->_node = node_decrement(this->_node);
            return (*this);
        }

        Self    operator--(int)
        {
            Self    tmp(*this);

            this->_node = node_decrement(this->_node);
            return (tmp);
        }

        friend bool operator==(const Self& x, const Self& y)    { return (x._node == y._node); }
        friend bool operator!=(const Self& x, const Self& y)    { return (x._node != y._node); }

        base_ptr    _node;
    };
}