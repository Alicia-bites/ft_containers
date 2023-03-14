#pragma once

#include <iostream>
#include "remove_cv.hpp"
#include "node.hpp"

namespace ft
{
	// enum Color
	// {
		// RED,
		// BLACK
	// };

	template <typename Key, typename Value>
	class setNode
	{
		private:
			Value						value;

		public:

			Key							key;
			Color						color;
			setNode<Key, Value>			*left;
			setNode<Key, Value>			*right;
			setNode<Key, Value>			*parent;
			Key							data;

			// default constructor
			setNode()
			: value(0)
			, key(0)
			, color(RED)
			, left(0)
			, right(0)
			, parent(0)
			, data(0)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling setNode default constructor" << RESET << std::endl;
				# endif
			};

			// constructor #1
			setNode(const Key & key, Value & value)
			: value(value)
			, key(key)
			, color(RED)
			, left(0)
			, right(0)
			, parent(0)
			, data(key)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling setNode constructor #1" << RESET << std::endl;
				# endif
			};

			// copy constructor
			setNode(const setNode<Key, Value> & src)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling setNode copy constructor" << RESET << std::endl;
				# endif

				if (this != &src)
					*this = src;
			}

			// destructor
			~setNode()
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling setNode destructor" << RESET << std::endl;
				# endif
			}

			// getter
			Value	getValue()
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling setNode value getter" << RESET << std::endl;
				# endif
				
				if (data != value)
					setValue(data);
				return value;
			}

			// setter
			void	setValue(Value newValue)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling setNode value setter" << RESET << std::endl;
				# endif

				value = newValue;
			}

			// assignement operator
			setNode<Key, Value>&    operator=(const setNode<Key, Value> & rhs)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling setNode assignement operator" << RESET << std::endl;
				# endif

				if (this == &rhs)
					return *this;

				value = rhs.value;
				key = rhs.key;
				color = rhs.color;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
				data = rhs.data;

				return *this;
			};
			

	};

	template<typename Key, typename Value>
	bool operator==(setNode<Key, Value> & lhs, setNode<Key, Value> & rhs)
	{
		if (lhs.key == rhs.key && lhs.getValue() == rhs.getValue() && lhs.color == rhs.color 
			&& lhs.left == rhs.left && lhs.right == rhs.right && lhs.parent == rhs.parent
			&& lhs.data == rhs.data)
			return true;
		return false;
	}

	template<typename Key, typename Value>
	std::ostream & operator<<(std::ostream & o, setNode<Key, Value> & rhs)
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
			<< rhs.data
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