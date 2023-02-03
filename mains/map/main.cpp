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

			BinarySearchTree<int, std::string> tree;

			tree.insert(8, "first");
			tree.insert(2, "second");
			tree.insert(6, "third");
			tree.insert(4, "fourth");

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

			std::string std_string_1("first");
			std::string std_string_2("second");
			std::string std_string_3("third");

			std_map.insert(std_string_1);
			std::cout << std_map.begin()->first << std::endl;
			std_map.insert(std_string_2);
			std::cout << std_map.begin()->first << std::endl;
			std_map.insert(std_string_3);
			std::cout << std_map.begin()->first << std::endl;

			std::map<int, std::string>::iterator std_it = std_map.begin();

			for(; std_it != std_map.end(); std_it++)
				std::cout << std_it->first << " ";
			std::cout << std::endl;

			ft::map<int, std::string> ft_map;

			std::string string_1("first");
			std::string string_2("second");
			std::string string_3("third");
			

			ft_map.insert(string_1);
			std::cout << ft_map.begin()->first << std::endl;
			ft_map.insert(string_2);
			std::cout << ft_map.begin()->first << std::endl;
			ft_map.insert(string_3);
			std::cout << ft_map.begin()->first << std::endl;

			std::map<int, std::string>::iterator std_it = ft_map.begin();

			for(; std_it != ft_map.end(); std_it++)
				std::cout << std_it->first << " ";
			std::cout << std::endl;


			// ft::pair<int, std::string> ft_pair(3, "first");
			// ft_map.insert(ft_pair);

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 3)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;



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