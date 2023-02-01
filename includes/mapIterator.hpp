#pragma once

// # include "../../utils/utility.hpp"
// # include "node.hpp"

# include <cstddef>

namespace ft
{
    template <typename Tp>
    struct MapIterator
    {
        typedef Tp                              value_type;
        typedef Tp*                             pointer;
        typedef Tp&                             reference;
        typedef std::ptrdiff_t                  difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef MapIterator<Tp>                       Self;
        typedef node_base::base_ptr             base_ptr;
        typedef node<Tp>*                       link_type;

//	CONSTRUCTORS ----------------------------------------------------------------------------

        MapIterator()
        : node_()
        {};
        
        MapIterator(base_ptr x) :
        node_(x)
        {};

//	OPERATOR OVERLOADS ----------------------------------------------------------------------------

        reference   operator*() const   
        {
            return(*(static_cast<link_type>(node_)->getDataPtr()));
        };

        pointer     operator->() const  
        {
            return(static_cast<link_type>(node_)->getDataPtr());
        };


        Self&   operator++()
        {
            this->node_ = node_increment(this->node_);
            return (*this);
        }

        Self    operator++(int)
        {
            Self    tmp(*this);

            this->node_ = node_increment(this->node_);
            return (tmp);
        }

        Self&   operator--()
        {
            this->node_ = node_decrement(this->node_);
            return (*this);
        }

        Self    operator--(int)
        {
            Self    tmp(*this);

            this->node_ = node_decrement(this->node_);
            return (tmp);
        }

        friend bool operator==(const Self& x, const Self& y)    { return (x.node_ == y.node_); }
        friend bool operator!=(const Self& x, const Self& y)    { return (x.node_ != y.node_); }

        base_ptr    node_;
    };

    template <class Tp>
    struct ConstMapIterator
    {
        typedef Tp                              value_type;
        typedef const Tp*                       pointer;
        typedef const Tp&                       reference;
        typedef MapIterator<Tp>                 iterator;
        typedef std::ptrdiff_t                  difference_type;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef ConstMapIterator<Tp>            Self;
        typedef node_base::const_base_ptr       base_ptr;
        typedef const node<Tp>*                 link_type;

//	CONSTRUCTORS ----------------------------------------------------------------------------

        ConstMapIterator()
        : node_()                          
        {};
        
        ConstMapIterator(base_ptr x)
        : node_(x)               
        {};
        
        ConstMapIterator(const iterator& x)
        : node_(x.node_)  
        {};
        

        iterator    _const_cast() const 
        { 
            return iterator(const_cast<typename iterator::base_ptr>(this->node_));
        };


//	OPERATOR OVERLOADS ----------------------------------------------------------------------------

        reference   operator*() const   
        { 
            return (*(static_cast<link_type>(node_)->getDataPtr()));
        };

        pointer     operator->() const  
        { 
            return (static_cast<link_type>(node_)->getDataPtr());
        };

        Self&   operator++()
        {
            this->node_ = node_increment(this->node_);
            return (*this);
        }

        Self    operator++(int)
        {
            Self    tmp(*this);

            this->node_ = node_increment(this->node_);
            return (tmp);
        }

        Self&   operator--()
        {
            this->node_ = node_decrement(this->node_);
            return (*this);
        }

        Self    operator--(int)
        {
            Self    tmp(*this);

            this->node_ = node_decrement(this->node_);
            return (tmp);
        }

        friend bool operator==(const Self& x, const Self& y)    { return (x.node_ == y.node_); }
        friend bool operator!=(const Self& x, const Self& y)    { return (x.node_ != y.node_); }

        base_ptr    node_;
    };
}