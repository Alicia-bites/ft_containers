#pragma once

#include <iostream>
#include <stdlib.h>
#include <cstddef>
// #include <memory>

#include "../colors/colors.hpp"

#include "type_traits.hpp"
#include "algorithms.hpp"
#include "pair.hpp"
#include "RedBlackTree.hpp"
// #include "setIterator.hpp"

namespace ft
{
	template <typename Key, typename Compare = std::less<Key>, typename Allocator = std::allocator<Key> >
	class set
	{
		public:
			// types:
			typedef Key											key_type;
			typedef Key											value_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
			typedef Allocator									allocator_type;
			typedef typename Allocator::reference				reference;
			typedef typename Allocator::const_reference			const_reference;
			typedef typename Allocator::pointer					pointer;
			typedef typename Allocator::const_pointer			const_pointer;
			typedef ft::setIterator								iterator;
			typedef ft::setIterator								const_iterator;
			typedef ft::setIterator								size_type;
			typedef ft::setIterator								difference_type;
			typedef reverse_iterator<iterator>					reverse_iterator;
			typedef reverse_iterator<const_iterator>			const_reverse_iterator;

		private:
			typedef RedBlackTree<key_type, setped_type, key_compare, Allocator>	* RBTree_ptr;	
			RBTree_ptr    tree_;

			Node<Key, Value> *node_ptr;

			Allocator		allocator_;

		public:

//	CONSTRUCTORS ----------------------------------------------------------------------------

			// default constructor, no arguments required
			explicit set(const Compare & comp = Compare(), const Allocator & = Allocator())
			: allocator_(Allocator)
			{
				#if DEBUG
					std::cout << SALMON1 << "Calling set default constructor" << RESET << std::endl;
				#endif
			};
			
			// range constructor - construct from other container using iterators
			template <class InputIterator>
				set(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator())
				: allocator_()
				{
					#if DEBUG
						std::cout << SALMON1 << "Calling set range constructor" << RESET << std::endl;
					#endif

					insert(first, last);
				};

			// copy constructor. Uses assignement overload operator
			set(const set<Key,Compare,Allocator>& src)
			: allocator_(src.get_allocator())
			{
				#if DEBUG
					std::cout << SALMON1 << "Calling copy constructor" << RESET << std::endl;
				#endif

				tree_ = new RedBlackTree<Key, Value, Compare, Allocator>();
				if (this != &original)
					*this = original;
			}

//	DESTRUCTORS --------------------------------------------------------------------------------------
			
			// destructor. Delete pointer of red black tree
			~set()
			{
				#if DEBUG
					std::cout << SALMON1 << "Calling set destructor" << RESET << std::endl;
				#endif

				if (tree_)
					delete tree_;
			};

//	MEMBER FUNCTIONS ---------------------------------------------------------------------------------

//		ASSIGNEMENT ----------------------------------------------------------------------------------------------------------------------------

			// assignement operator overload
			set<Key,Compare,Allocator>& operator=(const set<Key,Compare,Allocator>& x)
			{
				#if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling set assignement operator" << RESET << std::endl;
				#endif

				if (this != &rhs)
					*(this->tree_) = *(rhs.getTree());
				return (*this);
			};

//		GETTERS ----------------------------------------------------------------------------------------------------------------------------

			allocator_type get_allocator() const
			{
				return allocator_;
			};

//		ITERATORS --------------------------------------------------------------------------------------

			iterator begin()
			{
				return tree_->begin(;)
			};

			const_iterator	begin() const
			{
				return tree_->begin();
			};

			iterator	end()
			{
				return tree_->end();
			};

			const_iterator	end() const
			{
				return tree_->end();
			};

			reverse_iterator	rbegin()
			{
				return tree_->rbegin();
			};

			const_reverse_iterator rbegin() const
			{
				return tree_->rbegin();
			};

			reverse_iterator	rend()
			{
				return tree_->rend();
			};

			const_reverse_iterator rend() const
			{
				return tree_->rend();
			};

//		CAPACITY --------------------------------------------------------------------------------------

			bool	empty() const
			{
				return tree_->empty();
			};

			size_type	size() const
			{
				return tree_->size();
			};

			size_type	max_size() const
			{
				return tree_->max_size();
			};

//		MODIFIERS --------------------------------------------------------------------------------------

			// Extends the container by inserting new elements, effectively increasing the container
			// size by the number of elements inserted.
			// Because element keys in a set are unique, the insertion operation checks whether each
			// inserted element has a key equivalent to the one of an element already in the container,
			// and if so, the element is not inserted, returning an iterator to this existing element
			// (if the function returns a value).
			ft::pair<iterator, bool>	insert(const value_type & input_pair)
			{
				return tree_->insert(input_pair);
			};
			
			//  Extends the container by inserting new elements, effectively increasing 
			// the container size by the number of elements inserted.
			// This versions with a hint return an iterator pointing to either the 
			// newly inserted element or to the element that already had an equivalent key in the set.
			iterator	insert(iterator position, const value_type& input_pair)
			{
				return tree_->insert(position, input_pair);
			}

			// Iterators specifying a range of elements. Copies of the elements
			// in the range [first,last) are inserted in the container.
			// Notice that the range includes all the elements between first and
			// last, including the element pointed by first but not the one
			// pointed by last.
			template <class InputIterator>
				void 	insert(InputIterator first, InputIterator last)
				{
					return tree_->insert(first, last);
				};

			// Removes from the set container a single element.
			// This effectively reduces the container size by the number of elements
			// removed, which are destroyed.
			void	erase(iterator position)
			{
				tree_->remove(position->first);
			};

			// Removes from the set container a single element.
			// This effectively reduces the container size by the 
			// number of elements removed, which are destroyed.
			size_type	erase(const key_type& input_key)
			{
				return tree_->remove(input_key);
			};

			// Removes the elements in the range [first, last), 
			// which must be a valid range in *this.
			void	erase(iterator first, iterator last)
			{
				return tree_->remove(first, last);
			};
			
			// Exchanges the content of the container by the content of x, 
			// which is another set of the same type. Sizes may differ.
			void	swap(set<Key,Value,Compare,Allocator> & swapMe)
			{
				tree_->swap(*(swapMe.getTree()));
				return ;
			}

			// Erases all elements from the container. After this call, 
			// size() returns zero.
			// Invalidates any references, pointers, or iterators 
			// referring to contained elements. Any past-the-end 
			// iterator remains valid. 
			void	clear()
			{
				tree_->clear();
				return ;
			}

	//		OBSERVERS --------------------------------------------------------------------------------------
			
			// Returns a copy of the comparison object used by the container to compare keys.
			key_compare	key_comp() const
			{
				return key_compare();
			};

			value_compare	value_comp() const
			{
				return value_compare(key_compare());
			};

	//		SET OPERATIONS --------------------------------------------------------------------------------------

			// Searches the container for an element with a key equivalent to k
			// and returns an iterator to it if found, otherwise it returns an
			// iterator to set::end.
			iterator	find(const key_type & key)
			{
				return tree_->find(key);
			};

			// Returns the number of elements with key that compares equivalent 
			// to the specified argument. 
			// This is either 1 or 0 since this container does not allow duplicates.
			size_type	count(const key_type & k) const
			{
				return tree_->count(k);
			};

			// Returns an iterator pointing to the first element in
			// the container whose key is not considered to go before 
			// k (i.e., either it is equivalent or goes after).
			// The function returns an iterator to the first element 
			// whose key is not less than k.
			iterator	lower_bound(const key_type & k)
			{
				return tree_->lower_bound(k);
			};

			// A similar member function, lower_bound, has the same
			// behavior as upper_bound, except in the case that
			// the set contains an element with a key equivalent 
			// to k: In this case lower_bound returns an iterator 
			// pointing to that element, whereas upper_bound returns 
			// an iterator pointing to the next element.
			iterator	upper_bound(const key_type& k)
			{
				return tree_->upper_bound(k);
			};

			// Returns a range containing all elements with the given 
			// key in the container. The range is defined by two iterators, 
			// one pointing to the first element that is not less than key 
			// and another pointing to the first element greater than key. 
			// Alternatively, the first iterator may be obtained with 
			// lower_bound(), and the second with upper_bound(). 
			pair<iterator,iterator>	equal_range(const key_type & k)
			{
				return tree_->equal_range(k);
			}

	};

	template <typename Key, typename Compare, typename Allocator>
		bool operator==(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
		{
			if (x.size() == y.size())
				return (equal(x.begin(), x.end(), y.begin()));
			return (false);
		}

	template <typename Key, typename Compare, typename Allocator>
		bool operator< (const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
		{
			// Compare the contents of the two sets lexicographically
			return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());

		};

	template <typename Key, typename Compare, typename Allocator>
		bool operator!=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
		{
			return !(x == y);
		};

	template <typename Key, typename Compare, typename Allocator>
		bool operator> (const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
		{
			return y < x;
		};

	template <typename Key, typename Compare, typename Allocator>
		bool operator>=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
		{
			return(!(x < y));
		};

	template <typename Key, typename Compare, typename Allocator>
		bool operator<=(const set<Key,Compare,Allocator>& x, const set<Key,Compare,Allocator>& y)
		{
			return (!(y < x));
		};

	// specialized algorithms:
	template <typename Key, typename Compare, typename Allocator>
		void swap(set<Key,Compare,Allocator>& x, set<Key,Compare,Allocator>& y)
		{
			x.swap(y);
		};
}