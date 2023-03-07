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

	template <typename Pair>
	class Node
	{
		public:

			Pair						data;
			Color						color;
			Node<Key, Value>			*left;
			Node<Key, Value>			*right;
			Node<Key, Value>			*parent;

			// default constructor
			Node()
			: data(0)
			, color(RED)
			, left(0)
			, right(0)
			, parent(0)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node default constructor" << RESET << std::endl;
				# endif
			};

			// constructor #1
			Node(cont Pair & pair)
			: data(pair)
			, color(RED)
			, left(0)
			, right(0)
			, parent(0)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node constructor #1" << RESET << std::endl;
				# endif
			};

			// copy constructor
			Node(const Node<typename remove_cv<Pair>::type & original)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node copy constructor" << RESET << std::endl;
				# endif

				if (this != &original)
					*this = original;
			}

			// destructor
			~Node()
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node destructor" << RESET << std::endl;
				# endif
			}

			// assignement operator
			Node<Key, Value>&    operator=(const Node<typename remove_cv<Pair>::type> & rhs)
			{
				# if DEBUG
					std::cout << LIGHTSEAGREEN << "Calling Node assignement operator" << RESET << std::endl;
				# endif

				if (this == &rhs)
					return *this;

				data = rhs.data;
				color = rhs.color;
				left = rhs.left;
				right = rhs.right;
				parent = rhs.parent;
				
				return *this;
			};
			

	};

	template<typename Pair>
	bool operator==(Node<Pair> & lhs, Node<Pair> & rhs)
	{
		if (lhs.data.first == rhs.data.first && lhs.data.second == rhs.data.second && lhs.color == rhs.color 
			&& lhs.left == rhs.left && lhs.right == rhs.right && lhs.parent == rhs.parent
			&& lhs.data == rhs.data)
			return true;
		return false;
	}

	template<typename Pair>
	std::ostream & operator<<(std::ostream & o, Node<Pair> & rhs)
	{
		
		o << "Printing node..." << std::endl;
		o << DARKORANGE1
			<< "data = "
			<< rhs.data.first
			<< " | "
			<< rhs.data.second
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
			o << RESET
			<< std::endl;
		if (rhs.left)
		{
			if (rhs.left)
			o << CYAN1
				<< rhs.left
				<< std::endl
				<< "data = "
				<< rhs.left->data.first
				<< " | "
				<< rhs.left->data.second
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
			<< "data = "
			<< rhs.right->data.first
			<< " | "
			<< rhs.right->data.second
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
			<< "data = "
			<< rhs.parent->data.first
			<< " | "
			<< rhs.parent->data.second
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