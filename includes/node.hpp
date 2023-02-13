#pragma once

#include <iostream>
#include "pair.hpp"

namespace ft
{
	enum Color
	{
		RED,
		BLACK
	};

	template <typename Key, typename Value>
	class Node
	{
		public:

			Key					key;
			Value				value;
			Color				color;
			Node<Key, Value>	*left;
			Node<Key, Value>	*right;
			Node<Key, Value>	*parent;

			// default constructor
			Node()
			: key(0)
			, value(0)
			, color(RED)
			, left(0)
			, right(0)
			, parent(0)
			{};

			// constructor #1
			Node(const Key & key, const Value & value)
			: key(key)
			, value(value)
			, color(RED)
			, left(0)
			, right(0)
			, parent(0)
			{};

			// copy constructor
			Node(const Node & original)
			{
				if (this != &original)
				{
					key = original.key;
					value = original.value;
					color = original.color;
					left = original.left;
					right = original.right;
					parent = original.parent;
				}
			}
	};

	template<typename Key, typename Value>
	std::ostream & operator<<(std::ostream & o, const Node<Key, Value> & rhs)
	{
		
		o << "Printing node..." << std::endl;
		o << DARKORANGE1 << "key = "
			<< rhs.key
			<< std::endl
			<< "value = "
			<< rhs.value
			<< std::endl
			<< "color = "
			<< rhs.color
			<< RESET
			<< std::endl;
		if (rhs.left)
		{
			o << CYAN1 << "left->key = "
				<< rhs.left->key
				<< std::endl
				<< "left->value = "
				<< rhs.left->value
				<< std::endl
				<< "color = "
				<< rhs.color
				<< RESET
				<< std::endl;
		}
		if (rhs.right)
		{
			o << CHARTREUSE5 << "right->key = "
			<< rhs.right->key
			<< std::endl
			<< "right->value = "
			<< rhs.right->value
			<< std::endl
			<< "color = "
			<< rhs.color
			<< RESET
			<< std::endl;
		}
		if (rhs.parent)
		{
			o << DEEPPINK1 << "parent->key = "
			<< rhs.parent->key
			<< std::endl
			<< "parent->value = "
			<< rhs.parent->value
			<< std::endl
			<< "color = "
			<< rhs.color
			<< RESET
			<< std::endl;
		}

		o << "-------------------------------------------------------------------------" << std::endl;
		return o;
	}
}