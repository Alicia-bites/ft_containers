// #pragma once

// #include <iostream>
// #include <cstddef>
// //FOR DEBUG
// #include <stack>

// // #include "stack.hpp"
// #include "node.hpp"
// #include "iterator.hpp"
// #include "pair.hpp"
// #include "utils.hpp"

// namespace ft
// {
// 	template <typename Key, typename Value>
// 	class mapIterator
// 	{
// 		public:
// 			typedef ft::pair<const Key, Value >     value_type;
// 			typedef value_type&                     reference;
// 			typedef value_type*                     pointer;
// 			typedef std::bidirectional_iterator_tag iterator_category;
// 			typedef std::ptrdiff_t                  difference_type;

// 			typedef Node<Key, Value>  *  node_ptr;

// 			mapIterator()
// 			{}

// 			mapIterator(node_ptr node)
// 			{
// 				if (node)
// 				{
// 					pointer_ = &node->data;
// 					node_stack.push(ft::make_pair(node, false));
// 					increment();
// 				}
// 			}

// 			reference operator*() const
// 			{
// 				return pointer_;
// 			}

// 			pointer operator->() const
// 			{
// 				return pointer_;
// 			}

// 			mapIterator& operator++()
// 			{
// 				increment(); return *this;
// 			}

// 			mapIterator operator++(int)
// 			{
// 				mapIterator<Key, Value> tmp(*this);
// 				increment();
// 				return tmp;
// 			}

// 			mapIterator& operator--()
// 			{
// 				decrement();
// 				return *this;
// 			}
			
// 			mapIterator operator--(int)
// 			{
// 				mapIterator<Key, Value> tmp(*this);
// 				decrement();
// 				return tmp;
// 			}
		
// 			bool operator==(const mapIterator& other) const
// 			{
// 				return node_stack == other.node_stack;
// 			}
			
// 			bool operator!=(const mapIterator& other) const
// 			{
// 				return !(*this == other);
// 			}


// 		private:
// 			std::stack<ft::pair<node_ptr, bool> > node_stack;
// 			pointer	pointer_;

// 			void increment()
// 			{
// 				if (node_stack.empty())
// 					return;
// 				node_ptr node = node_stack.top().first;
// 				bool visited = node_stack.top().second;
// 				node_stack.pop();
// 				if (!visited)
// 				{
// 					if (node->right)
// 						node_stack.push(ft::make_pair(node->right, false));
// 					node_stack.push(ft::make_pair(node, true));
// 					pointer_ = &node->data;
// 					if (node->left)
// 						node_stack.push(ft::make_pair(node->left, false));
// 					increment();
// 				}
// 			}

// 			void decrement()
// 			{
// 				if (node_stack.empty())
// 					return;
// 				node_ptr node = node_stack.top().first;
// 				bool visited = node_stack.top().second;
// 				node_stack.pop();
// 				if (visited)
// 				{
// 					if (node->left)
// 						node_stack.push(ft::make_pair(node->left, true));
// 					node_stack.push(ft::make_pair(node, false));
// 					if (node->right)
// 						node_stack.push(ft::make_pair(node->right, true));
// 					decrement();
// 				}
// 			}
// 	};
// }