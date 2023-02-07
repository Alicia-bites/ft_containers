#include "../../includes/map.hpp"
#include "../../includes/pair.hpp"
#include "../../includes/RBTree.hpp"
#include "../../includes/BST.hpp"
#include "../../colors/colors.hpp"

#include <string>
#include <algorithm>

#include <utility>
#include <map>

#ifndef STD
# define NAMESPACE ft
// #else
// # define NAMESPACE std
#endif

using namespace NAMESPACE;

template <typename T>
	void	print_map(T map)
	{
		std::cout << "map size is " << map.size() << std::endl;
		std::cout << "map capacity is " << map.capacity() << std::endl;
		for (size_t i = 0; i < map.size(); i++)
			std::cout << map[i] << " | ";
		std::cout << std::endl;
	}

template <typename T>
	void	print_map(T map, std::string map_name)
	{
		std::cout << DODGERBLUE2 << "-----------------------------------------------------------------------------" << std::endl;
		std::cout << "Printing " << map_name << std::endl;
		std::cout << "map size is " << map.size() << std::endl;
		std::cout << "map capacity is " << map.capacity() << std::endl;
		for (size_t i = 0; i < map.size(); i++)
			std::cout << map[i] << " | ";
		std::cout << std::endl;
		std::cout << DODGERBLUE2 << "-----------------------------------------------------------------------------" << RESET << std::endl;
	}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage : ./ft_containers <test number>" << std::endl;
		return 0;
	}
	int test_number = atoi(argv[1]);
	try
	{
		if (test_number == 1)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing binary search tree" 
				<< RESET << std::endl << std::endl;

			ft::BinarySearchTree<int, std::string> tree;

			tree.insert(ft::make_pair(8, "first"));
			tree.insert(ft::make_pair(1, "second"));
			tree.insert(ft::make_pair(6, "third"));
			tree.insert(ft::make_pair(4, "fourth"));

			std::cout << "tree.root = " << tree.getRoot()->key << std::endl;
			tree.printTree(tree.getRoot());

			std::cout << tree[4] << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 2)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;

			map<int, std::string> mappy;
			pair<map<int, std::string>::iterator, bool> res;

			res = mappy.insert(make_pair(1, "one"));
			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 3)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;

			ft::BinarySearchTree<int, int> tree;

			ft::pair<ft::Node<int, int> *, bool> res;
			ft::pair<int, int> input =ft::make_pair(1, 2);
			res = tree.insert(input);
			ft::Node<int, int> * node = res.first;
			if (node)
				std::cout << *node << std::endl;

			ft::map<int, int> mappy;
			ft::map<int, int>::iterator it;
			ft::pair<ft::mapIterator<int, int>, bool> output;

			output = mappy.insert(input);

			it = output.first;
			std::cout << *(it.getPointer()) << std::endl;


			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 4)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;



			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 5)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;



			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 6)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;



			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 7)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;



			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << STEELBLUE2 << "All tests done!" << RESET << std::endl;
	return 0;
}