#pragma once

// C++98 doesn't have std::ptrdiff_t so we use std::ptrdiff_t with an additional include <cstddef>.
#include <cstddef>

namespace ft
{

	template <class Category, class T, class Distance = std::ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         									value_type;
		typedef Distance  									difference_type;
		typedef Pointer   									pointer;
		typedef Reference 									reference;
		typedef Category  									iterator_category;
	};

	template <typename Iterator>
		struct iterator_traits {
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
		};
	
	template <typename T>
		struct iterator_traits<T*> 
		{
			// Specifies the category of the iterator, in this case 
			// std::random_access_iterator_tag which means that the 
			// iterator is a random access iterator.
			typedef std::random_access_iterator_tag		iterator_category;
			// value_type: Specifies the type of the elements that can be 
			// accessed through the iterator.
			typedef T 									value_type;
			// difference_type: Specifies the type of the difference between
			// two iterators.
			typedef std::ptrdiff_t						difference_type;
		    // pointer: Specifies the type of the pointer to an element.
			typedef T*									pointer;
			// reference: Specifies the type of the reference to an element.
			typedef T&									reference;
		};
	
	template <typename T>
		struct iterator_traits<const T*> 
		{
			typedef std::random_access_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef const T*							pointer;
			typedef const T&							reference;
		};
}