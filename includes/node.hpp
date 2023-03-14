#pragma once

#include <iostream>
#include "pair.hpp"
#include "remove_cv.hpp"

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
		private:
			Value						value;

		public:

			Key							key;
			Color						color;
			Node<Key, Value>			*left;
			Node<Key, Value>			*right;
			Node<Key, Value>			*parent;
			ft::pair<const Key, Value>	data;

			// default constructor
			Node()
			: value(0)
			, key(0)
			, color(RED)
			, left(0)
			, right(0)
			, parent(0)
			, data(0)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node default constructor" << RESET << std::endl;
				# endif
			};

			// constructor #1
			Node(const Key & key, Value & value)
			: value(value)
			, key(key)
			, color(RED)
			, left(0)
			, right(0)
			, parent(0)
			, data(ft::make_pair(key, value))
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node constructor #1" << RESET << std::endl;
				# endif


			};

			// copy constructor
			Node(const Node<Key, Value> & other)
				: value(other.value)
				, key(other.key)
				, color(other.color)
				, left(other.left)
				, right(other.right)
				, parent(other.parent)
				, data(ft::make_pair(const_cast<Key&>(other.key), other.value))
			{
				#if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node copy constructor" << RESET << std::endl;
				#endif
			}

			// destructor
			~Node()
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node destructor" << RESET << std::endl;
				# endif
			}

			// getter
			Value	getValue()
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node value getter" << RESET << std::endl;
				# endif
				
				if (data.second != value)
					setValue(data.second);
				return value;
			}

			// setter
			void	setValue(Value newValue)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node value setter" << RESET << std::endl;
				# endif

				value = newValue;
			}

			// assignement operator
			Node<Key, Value>&    operator=(const Node<Key, Value> & rhs)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node assignement operator" << RESET << std::endl;
				# endif

				if (this == &rhs)
					return *this;

				value = rhs.value;
				key = rhs.key;
				color = rhs.color;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
				data = ft::make_pair(const_cast<Key&>(rhs.key), rhs.value);

				return *this;
			};
	};

	template<typename Key, typename Value>
	bool operator==(Node<Key, Value> & lhs, Node<Key, Value> & rhs)
	{
		if (lhs.key == rhs.key && lhs.getValue() == rhs.getValue() && lhs.color == rhs.color 
			&& lhs.left == rhs.left && lhs.right == rhs.right && lhs.parent == rhs.parent
			&& lhs.data == rhs.data)
			return true;
		return false;
	}

	template<typename Key, typename Value>
	std::ostream & operator<<(std::ostream & o, Node<Key, Value> & rhs)
	{
		
		o << "Printing node..." << std::endl;
		o << DARKORANGE1 << "key = "
			<< rhs.key
			<< std::endl
			<< "value = "
			<< rhs.getValue()
			<< std::endl;
			if (rhs.color == RED)
			{
				o << "color = "
				<< RED1
				<< "RED"
				<< RESET;
			}
			else
			{
				o << "color = "
				<< ROSYBROWN
				<< "BLACK"
				<< RESET;
			}
			o << std::endl
			<< "data = "
			<< rhs.data.first
			<< " | "
			<< rhs.data.second
			<< RESET
			<< std::endl;
		if (rhs.left)
		{
			if (rhs.left)
			o << CYAN1
				<< rhs.left
				<< std::endl
				<< "left->key = "
				<< rhs.left->key
				<< std::endl
				<< "left->value = "
				<< rhs.left->getValue()
				<< std::endl;
				if (rhs.left->color == RED)
				{
					o << "color = "
					<< RED1
					<< "RED"
					<< RESET;
				}
				else
				{
					o << "color = "
					<< ROSYBROWN
					<< "BLACK"
					<< RESET;
				}
				o << RESET
				<< std::endl;
		}
		if (rhs.right)
		{
			o << CHARTREUSE5 
			<< rhs.right
			<< std::endl
			<< "right->key = "
			<< rhs.right->key
			<< std::endl
			<< "right->value = "
			<< rhs.right->getValue()
			<< std::endl;
			if (rhs.right->color == RED)
			{
				o << "color = "
				<< RED1
				<< "RED"
				<< RESET;
			}
			else
			{
				o << "color = "
				<< ROSYBROWN
				<< "BLACK"
				<< RESET;
			}
			o << RESET
			<< std::endl;
		}
		if (rhs.parent)
		{
			o << DEEPPINK1 
			<< rhs.parent
			<< std::endl
			<< "parent->key = "
			<< rhs.parent->key
			<< std::endl
			<< "parent->value = "
			<< rhs.parent->getValue()
			<< std::endl;
			if (rhs.parent->color == RED)
			{
				o << "color = "
				<< RED1
				<< "RED"
				<< RESET;
			}
			else
			{
				o << "color = "
				<< ROSYBROWN
				<< "BLACK"
				<< RESET;
			}
			o << RESET
			<< std::endl;
		}

		o << "-------------------------------------------------------------------------" << std::endl;
		return o;
	}
}