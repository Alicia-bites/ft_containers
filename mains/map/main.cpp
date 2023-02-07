#include "../../includes/map.hpp"
#include "../../includes/pair.hpp"
#include "../../includes/RBTree.hpp"
#include "../../includes/BST.hpp"
#include "../../colors/colors.hpp"

#include <string>
#include <algorithm>
#include <utility>
#include <map>

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

			std::map<int, std::string> std_map;
			std::pair<std::map<int, std::string>::iterator, bool> std_result;

			std_result = std_map.insert(std::make_pair(1, "one"));
			if (std_result.second == true)
				std::cout << "Inserted " << std_result.first->second << " into the map with key "
					<< std_result.first->first << std::endl;
			else
				std::cout << "Key " << std_result.first->first << " already has the value "
					<< std_result.first->second << " in the map" << std::endl;

			// ft::map<int, std::string> ft_map;
			// ft::pair<ft::map<int, std::string>::iterator, bool> ft_result;

			// ft::pair<int, std::string> ft_inputpair =ft::make_pair(1, "one");
			// ft_result = ft_map.insert(ft_inputpair);
			// if (ft_result.second == true)
			// 	std::cout << "Inserted " << std_result.first->second << " into the map with key "
			// 		<< ft_result.first->first << std::endl;
			// else
			// 	std::cout << "Key " << ft_result.first->first << " already has the value "
			// 		<< ft_result.first->second << " in the map " << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 3)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;

			// ft::Node<int, int> node;
			// ft::map<int, int>::iterator it;
			ft::BinarySearchTree<int, int> tree;

			ft::pair<ft::Node<int, int> *, bool> res;
			ft::pair<int, int> input =ft::make_pair(1, 2);
			res = tree.insert(input);
			ft::Node<int, int> * node = res.first;
			if (node)
				std::cout << *node << std::endl;

			ft::map<int, int> mappy;
			ft::map<int, int>::iterator it;

			mappy.insert(input);

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