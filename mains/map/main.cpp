#include "../../includes/map.hpp"
#include "../../includes/pair.hpp"
#include "../../includes/RedBlackTree.hpp"
#include "../../includes/BST.hpp"
#include "../../colors/colors.hpp"

#include <string>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <ctime>


// change default namespace
#ifndef STD
# define NAMESPACE ft
// #else
// # define NAMESPACE std
#endif

using namespace NAMESPACE;

template <typename Key, typename Value>
	void	print_map(const ::map<Key, Value> & map, std::string map_name)
	{
		std::cout << DODGERBLUE2 << "-----------------------------------------------------------------------------" << std::endl;
		std::cout << "Printing " << map_name << std::endl;
		std::cout << DEEPSKYBLUE1 << "map size is " << map.size() << std::endl;

		typename ::map<Key, Value>::const_iterator it;
		std::cout << "Key " << " = " << "Value" << std::endl;
		for (it = map.begin(); it != map.end(); it++)
			std::cout << ORANGERED1 << it->first << "    =    " << DARKTURQUOISE << it->second << std::endl;

		std::cout << std::endl;
		std::cout << NAVY << "-----------------------------------------------------------------------------" << RESET << std::endl;
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

			std::cout << DARKTURQUOISE << "Creating tree..." << RESET << std::endl;
			ft::BinarySearchTree<int, std::string> tree;

			std::cout << DEEPPINK1 << "Inserting stuff in tree..." << RESET << std::endl;
			tree.insert(ft::make_pair(8, "first"));
			tree.insert(ft::make_pair(1, "second"));
			tree.insert(ft::make_pair(6, "third"));
			tree.insert(ft::make_pair(4, "fourth"));
			tree.insert(ft::make_pair(4, "fifth"));

			std::cout << "tree.root = " << tree.getRoot()->key << std::endl;
			tree.printTree(tree.getRoot());

			std::cout << MEDIUMTURQUOISE << "Testing accessor" << RESET << std::endl;
			std::cout << "tree[4] = " << tree[4] << std::endl;

			std::cout << LIGHTSEAGREEN << "Testing copy constructor" << RESET << std::endl;
			ft::BinarySearchTree<int, std::string> tree_copy(tree);
			std::cout << "Printing copy_tree : " << RESET << std::endl;
			tree_copy.printTree(tree_copy.getRoot());
			std::cout << CYAN3 << "Testing remove function" << RESET << std::endl;
			tree_copy.remove(tree.getRoot(), 4);

			std::cout << TURQUOISE2 << "Checking if deep copy has been done properly : " << RESET << std::endl;
			std::cout << "Printing copy_tree : " << RESET << std::endl;
			tree_copy.printTree(tree_copy.getRoot());
			std::cout << "Printing tree : " << RESET << std::endl;
			tree.printTree(tree.getRoot());
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 2)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing insert(const value_type & input_pair)" 
				<< RESET << std::endl << std::endl;

			ft::map<int, std::string> mappy;
			ft::pair<ft::map<int, std::string>::iterator, bool> res;

			res = mappy.insert(ft::make_pair(7, "first"));
			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;

			res = mappy.insert(ft::make_pair(7, "error"));
			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;
			
			res = mappy.insert(ft::make_pair(4, "second"));
			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;

			res = mappy.insert(ft::make_pair(10, "third"));
			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;

			res = mappy.insert(ft::make_pair(15, "fourth"));
			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;
			
			std::cout << std::endl << std::endl;
			std::cout << DODGERBLUE2 << "PRINTING MAPPY : " << RESET << std::endl;
			mappy.getTree().printTree(mappy.getTree().getRoot());

			std::cout << "Testing copy constructor" << std::endl;
			ft::map<int, std::string> coppy(mappy);
			std::cout << DODGERBLUE2 << "PRINTING COPPY  : " << RESET << std::endl;
			mappy.getTree().printTree(coppy.getTree().getRoot());

			std::cout << "Removing one node with key 10 " << std::endl;
			size_t output = mappy.erase(10);
			std::cout << "output = " << output << std::endl;
			std::cout << "root_ is : " << *(mappy.getTree().getRoot()) << std::endl;


			std::cout << "Removing one node with key 15 " << std::endl;
			output = mappy.erase(15);
			std::cout << "output = " << output << std::endl;
			std::cout << "root_ is : " << *(mappy.getTree().getRoot()) << std::endl;

			std::cout << "Removing one node with key 7 " << std::endl;
			output = mappy.erase(7);
			std::cout << "output = " << output << std::endl;
			std::cout << "root_ is : " << *(mappy.getTree().getRoot()) << std::endl;
			std::cout << std::endl << std::endl;
			std::cout << DODGERBLUE2 << "PRINTING MAPPY : " << RESET << std::endl;
			mappy.getTree().printTree(mappy.getTree().getRoot());

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 3)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing iterator" << std::endl 
				<< RESET << std::endl << std::endl;

			map<int, int> june;
			june.insert(make_pair(8, 777));
			june.insert(make_pair(4, 333));
			june.insert(make_pair(12, 101010));
			june.insert(make_pair(2, 555));
			june.insert(make_pair(6, 888));
			june.insert(make_pair(10, 888));
			june.insert(make_pair(14, 888));
			june.insert(make_pair(1, 888));
			june.insert(make_pair(3, 888));
			june.insert(make_pair(5, 888));
			june.insert(make_pair(7, 888));
			june.insert(make_pair(9, 888));
			june.insert(make_pair(11, 888));
			june.insert(make_pair(13, 888));
			june.insert(make_pair(15, 888));

			std::cout << "June's begin is = " << june.begin()->first << std::endl;

			std::cout << AQUAMARINE3 << "Testing incrementation of iterator --> " << "First with i++ : "
				<< RESET << std::endl; 
			map<int, int>::iterator it = june.begin();
			for(; it != june.end(); it++)
				std::cout << it->first << std::endl;

			std::cout << AQUAMARINE3 << "Then with ++i : "
				<< RESET << std::endl; 

			map<int, int>::iterator it1 = june.begin();
			for(; it1 != june.end(); ++it1)
				std::cout << it1->first << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 4)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing reverse_iterator" 
				<< RESET << std::endl << std::endl;

			map<int, int> june;
			june.insert(make_pair(8, 777));
			june.insert(make_pair(4, 333));
			june.insert(make_pair(12, 101010));
			june.insert(make_pair(2, 555));
			june.insert(make_pair(6, 888));
			june.insert(make_pair(10, 888));
			june.insert(make_pair(14, 888));
			june.insert(make_pair(1, 888));
			june.insert(make_pair(3, 888));
			june.insert(make_pair(5, 888));
			june.insert(make_pair(7, 888));
			june.insert(make_pair(9, 888));
			june.insert(make_pair(11, 888));
			june.insert(make_pair(13, 888));
			june.insert(make_pair(15, 888));
			
			std::cout << AQUAMARINE3 << "Testing incrementation of reverse_iterator --> " << "First with i++ : "
				<< RESET << std::endl; 
			map<int, int>::reverse_iterator rit1 = june.rbegin();
			std::cout << rit1->first << std::endl << std::endl;
			for (; rit1 != june.rend(); rit1++)
				std::cout << rit1->first << std::endl;

			std::cout << AQUAMARINE3 << "Then with ++i : "
				<< RESET << std::endl; 
			map<int, int>::reverse_iterator rit = june.rbegin();
			for (; rit != june.rend(); ++rit)
				std::cout << rit->first << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 5)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing RedBlackTree insert node function" 
				<< RESET << std::endl << std::endl;

			map<int, int> june;
			june.insert(make_pair(8, 777));
			june.insert(make_pair(4, 333));
			june.insert(make_pair(12, 101010));
			june.insert(make_pair(2, 555));
			june.insert(make_pair(6, 888));
			june.insert(make_pair(10, 888));
			june.insert(make_pair(14, 888));
			june.insert(make_pair(1, 888));
			june.insert(make_pair(3, 888));
			june.insert(make_pair(5, 888));
			june.insert(make_pair(7, 888));
			june.insert(make_pair(9, 888));
			june.insert(make_pair(11, 888));
			june.insert(make_pair(13, 888));
			june.insert(make_pair(15, 888));
			// june.insert(make_pair(5, 888));
			
			// june.getTree().printTree(june.getTree().getRoot());
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 6)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing second insert function version (with hint position)" 
				<< RESET << std::endl << std::endl;

			map<int, int> joe;
			joe.insert(make_pair(8, 777));
			// joe.insert(make_pair(2, 777));
			joe.insert(make_pair(4, 777));
			// joe.insert(make_pair(12, 777));
			joe.insert(make_pair(6, 777));
			joe.insert(make_pair(14, 777));
			joe.insert(make_pair(1, 777));
			joe.insert(make_pair(3, 777));
			joe.insert(make_pair(5, 777));
			joe.insert(make_pair(7, 777));
			joe.insert(make_pair(9, 777));
			joe.insert(make_pair(10, 777));
			joe.insert(make_pair(11, 777));
			joe.insert(make_pair(13, 777));
			joe.insert(make_pair(15, 777));

			print_map(joe, "joe");

			map<int,int>::iterator it = joe.begin();
			int n = 9;
			while (n--)
				it++;
			std::cout << "We create a iterator that points to node with key " << it->first << "." << std::endl;

			map<int,int>::iterator res;

			std::cout << "Inserting element with key 12 (max efficiency inserting)... " << std::endl;
			res = joe.insert (it, make_pair(12, 1010101010));  // max efficiency inserting
			std::cout << "RES = " << res->first << " -- " << res->second << std::endl;

			std::cout << "Inserting element with key 2 (no max efficiency inserting)... " << std::endl;
			res = joe.insert (it, make_pair(2, 33333333));  // no max efficiency inserting
			std::cout << "RES = " << res->first << " -- " << res->second << std::endl;

			std::cout << "Inserting element with key that is already taken" << std::endl;
			res = joe.insert (it, make_pair(2, 33333333));  // no max efficiency inserting
			std::cout << "RES = " << res->first << " -- " << res->second << std::endl;

			print_map(joe, "joe");

			// joe.getTree().printTree(joe.getTree().getRoot());
			// joe.getTree().printRBTree(joe.getTree().getRoot());

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