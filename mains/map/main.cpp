#include "../../colors/colors.hpp"

#include "../../includes/map.hpp"
// #include "../../includes/pair.hpp"
// #include "../../includes/RedBlackTree.hpp"
// #include "../../mapReverseIterator.hpp"


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
		it = map.begin();
		while (it != map.end())
		{
			std::cout << ORANGERED1 << it->first << "    =    " << DARKTURQUOISE << it->second << std::endl;
			it++;
		}
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
			std::cout << STEELBLUE3 << "--" 
				<< RESET << std::endl << std::endl;


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
			mappy.getTree()->printTree(mappy.getTree()->getRoot());

			std::cout << "Testing copy constructor" << std::endl;
			ft::map<int, std::string> coppy(mappy);
			std::cout << DODGERBLUE2 << "PRINTING COPPY  : " << RESET << std::endl;
			mappy.getTree()->printTree(coppy.getTree()->getRoot());

			std::cout << "Removing one node with key 10 " << std::endl;
			size_t output = mappy.erase(10);
			std::cout << "output = " << output << std::endl;
			std::cout << "root_ is : " << *(mappy.getTree()->getRoot()) << std::endl;


			std::cout << "Removing one node with key 15 " << std::endl;
			output = mappy.erase(15);
			std::cout << "output = " << output << std::endl;
			std::cout << "root_ is : " << *(mappy.getTree()->getRoot()) << std::endl;

			std::cout << "Removing one node with key 7 " << std::endl;
			output = mappy.erase(7);
			std::cout << "output = " << output << std::endl;
			std::cout << "root_ is : " << *(mappy.getTree()->getRoot()) << std::endl;
			std::cout << std::endl << std::endl;
			std::cout << DODGERBLUE2 << "PRINTING MAPPY : " << RESET << std::endl;
			mappy.getTree()->printTree(mappy.getTree()->getRoot());

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

			// june.getTree()->printRBTree(june.getTree()->getRoot());
			std::cout << "------------------------------------------------------------------" << std::endl;

			// std::cout << "nil_ is = " << *(june.getTree()->getNil()) << std::endl;

			std::cout << "June's begin is = " << june.begin()->first << std::endl;

			std::cout << AQUAMARINE3 << "Testing incrementation of iterator --> " << "First with i++ : "
				<< RESET << std::endl; 
			map<int, int>::iterator it = june.begin();
			for(; it != june.end(); it++)
				std::cout << it->first << std::endl;

			std::cout << std::endl;

			std::cout << AQUAMARINE3 << "Then with ++i : "
				<< RESET << std::endl; 

			it = june.begin();
			for(; it != june.end(); ++it)	
				std::cout << it->first << std::endl;
			
			it = june.begin();
			int n = 16;
			while (n--)
				it++;
			std::cout << "it = " << it->first << std::endl;

			map<int, int>::iterator it1 = june.begin();
			n = 16;
			while (n--)
				it1++;
			std::cout << "it1 = " << it1->first << std::endl;

			if (it != it1)
				std::cout << "YIHAAAA" << std::endl;
			

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
			
			// june.getTree()->printTree(june.getTree()->getRoot());
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

			// joe.getTree()->printTree(joe.getTree()->getRoot());
			// joe.getTree()->printRBTree(joe.getTree()->getRoot());

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 7)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing insert range" 
				<< RESET << std::endl << std::endl;

			map<char, int> lily;
			// lily.insert(make_pair('a', 777));
			// lily.insert(make_pair('b', 777));
			// lily.insert(make_pair('c', 777));

  			map<char,int> anothermap;
  			anothermap.insert(lily.begin(), lily.find('c'));
			print_map(anothermap, "anothermap");

			map<char, int>::iterator first = anothermap.begin();
			map<char, int>::iterator last = anothermap.end();

			lily.insert(make_pair('z', 777));
			lily.insert(first, last);

			print_map(lily, "lily");

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		
		if (test_number == 8)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing find" 
				<< RESET << std::endl << std::endl;

			map<char, int> lily;

			map<char, int>::iterator res = lily.find('c');
			if (res != lily.end())
				std::cout << "res = " << res->first << " -- " << res->second << std::endl;
			else
				std::cout << "No key found" << std::endl;

			lily.insert(make_pair('a', 777));
			lily.insert(make_pair('b', 777));
			lily.insert(make_pair('c', 777));
			print_map(lily, "lily");


			res = lily.find('c');
			if (res != lily.end())
				std::cout << "res = " << res->first << " -- " << res->second << std::endl;
			else
				std::cout << "No key found" << std::endl;


			res = lily.find('d');
			if (res != lily.end())
				std::cout << "res = " << res->first << " -- " << res->second << std::endl;
			else
				std::cout << "No key found" << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 9)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing find -- const version" 
				<< RESET << std::endl << std::endl;

			map<char, int> lily;

			map<char, int>::const_iterator res = lily.find('c');

			if (res != lily.end())
				std::cout << "res = " << res->first << " -- " << res->second << std::endl;
			else
				std::cout << "No key found" << std::endl;

			lily.insert(make_pair('a', 777));
			lily.insert(make_pair('b', 777));
			lily.insert(make_pair('c', 777));
			print_map(lily, "lily");

			res = lily.find('c');
			if (res != lily.end())
				std::cout << "res = " << res->first << " -- " << res->second << std::endl;
			else
				std::cout << "No key found" << std::endl;

			res = lily.find('d');
			if (res != lily.end())
				std::cout << "res = " << res->first << " -- " << res->second << std::endl;
			else
				std::cout << "No key found" << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 10)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing key_comp" 
				<< RESET << std::endl << std::endl;

			map<char, int> mymap;
			
			map<char, int>::key_compare mycomp = mymap.key_comp();
			
			mymap['a'] = 100;
			mymap['b'] = 200;
			mymap['c'] = 300;
			
			std::cout << "mymap contains:\n";
			
			char highest = mymap.rbegin()->first; // key value of last element
			map<char,int>::iterator it = mymap.begin();
			do
			{
				std::cout << it->first << " => " << it->second << '\n';
			} while ( mycomp((*it++).first, highest) );
			
			std::cout << '\n';

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 11)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing value_comp" 
				<< RESET << std::endl << std::endl;

			map<char,int> mymap;

			mymap['x']=1001;
			mymap['y']=2002;
			mymap['z']=3003;
			
			std::cout << "mymap contains:\n";
			
			pair<char,int> highest = *mymap.rbegin();          // last element
			
			map<char,int>::iterator it = mymap.begin();
			do {
				std::cout << it->first << " => " << it->second << '\n';
			} while ( mymap.value_comp()(*it++, highest) );

			pair<char, int> fifi = *mymap.begin();
			pair<char, int> fafa = *mymap.rbegin();
			std::cout << mymap.value_comp()(fifi, fafa) << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 12)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing operator[]" 
				<< RESET << std::endl << std::endl;

			map<char,std::string> mymap;

			mymap['a']="an element";
			mymap['b']="another element";
			mymap['c']=mymap['b'];
			
			std::cout << "mymap['a'] is " << mymap['a'] << '\n';
			std::cout << "mymap['b'] is " << mymap['b'] << '\n';
			std::cout << "mymap['c'] is " << mymap['c'] << '\n';
			std::cout << "mymap['d'] is " << mymap['d'] << '\n';
			
			std::cout << "mymap now contains " << mymap.size() << " elements.\n";

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 13)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing replaced < by custom comp function" 
				<< RESET << std::endl << std::endl;

			map<int, int> bob;
			bob.insert(make_pair(8, 777));
			bob.insert(make_pair(2, 777));
			bob.insert(make_pair(4, 777));
			bob.insert(make_pair(12, 777));
			bob.insert(make_pair(6, 777));
			bob.insert(make_pair(14, 777));
			bob.insert(make_pair(1, 777));
			bob.insert(make_pair(3, 777));
			bob.insert(make_pair(5, 777));
			bob.insert(make_pair(7, 777));
			bob.insert(make_pair(9, 777));
			bob.insert(make_pair(10, 777));
			bob.insert(make_pair(11, 777));
			bob.insert(make_pair(13, 777));
			bob.insert(make_pair(15, 777));

			print_map(bob, "bob");

			// std::cout << bob.getTree()->getBiggestNode(bob.getTree()->getRoot())->key << std::endl;
			// std::cout << bob.getTree()->getSmallestNode(bob.getTree()->getRoot())->key << std::endl;
			
			map<int, int>::iterator it = bob.find(8);
			std::cout << it->first << " = " << it->second << std::endl;

			// bob.getTree()->printRBTree(bob.getTree()->getRoot());

			bob.erase(it);

			// bob.getTree()->printRBTree(bob.getTree()->getRoot());


			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 14)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing erase functions" 
				<< RESET << std::endl << std::endl;

			map<int, int> bob;
			bob.insert(make_pair(8, 777));
			bob.insert(make_pair(2, 777));
			bob.insert(make_pair(4, 777));
			bob.insert(make_pair(12, 777));
			bob.insert(make_pair(6, 777));
			bob.insert(make_pair(14, 777));
			bob.insert(make_pair(1, 777));
			bob.insert(make_pair(3, 777));
			bob.insert(make_pair(5, 777));
			bob.insert(make_pair(7, 777));
			bob.insert(make_pair(9, 777));
			bob.insert(make_pair(10, 777));
			bob.insert(make_pair(11, 777));
			bob.insert(make_pair(13, 777));
			bob.insert(make_pair(15, 777));

			// print_map(bob, "bob");

			std::cout << "Testing erase #1" << std::endl;
			bob.erase(8);
			bob.erase(9);
			bob.erase(10);
			bob.erase(15);

			// print_map(bob, "bob");

			std::cout << std::endl;

			std::cout << "Testing erase #2" << std::endl;
			map<int, int>::iterator it = bob.find(2);
			bob.erase(it);
			it = bob.find(14);
			bob.erase(it);
			it = bob.find(1);
			bob.erase(it);
			it = bob.find(3);
			bob.erase(it);

			// print_map(bob, "bob");

			std::cout << std::endl;

			std::cout << "Testing erase #3" << std::endl;
			map<int, int>::iterator first = bob.begin();
			std::cout << BLUEVIOLET << "Removing from " << bob.begin()->first;
			map<int, int>::iterator last = bob.find(13);
			std::cout << " to " << last->first << RESET << std::endl;

			bob.erase(first, last);

			std::cout << "Tree should only have 13 left : " << std::endl;

			// print_map(bob, "bob");

			bob.erase(13);

			// print_map(bob, "bob");

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 15)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing swap function" 
				<< RESET << std::endl << std::endl;

			map<char, int> foo , bar;
			
			foo['x']=100;
			foo['y']=200;
			// foo.getTree()->printRBTree(foo.getTree()->getRoot());
			// std::cout << "----------------------------------------------" << std::endl;
			
			bar['a']=11;
			bar['b']=22;
			bar['c']=33;
			// bar.getTree()->printRBTree(bar.getTree()->getRoot());
			// std::cout << "----------------------------------------------" << std::endl;
			
			foo.swap(bar);
			
			std::cout << "foo contains:\n";
			for (map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			
			std::cout << "bar contains:\n";
			for (map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
				
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 16)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing clear member function" 
				<< RESET << std::endl << std::endl;

			map<char,int> mymap;
			
			mymap['x']=100;
			mymap['y']=200;
			mymap['z']=300;
			
			// mymap.getTree()->printRBTree(mymap.getTree()->getRoot());
			// std::cout << "----------------------------------------------" << std::endl;

			std::cout << "mymap contains:\n";
			for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			
			mymap.clear();
			mymap['a']=1101;
			mymap['b']=2202;

			// mymap.getTree()->printRBTree(mymap.getTree()->getRoot());
			// std::cout << "----------------------------------------------" << std::endl;

			std::cout << "mymap contains:\n";
			for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 17)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing " 
				<< RESET << std::endl << std::endl;


			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		
		if (test_number == 18)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing " 
				<< RESET << std::endl << std::endl;


			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		
		if (test_number == 19)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing " 
				<< RESET << std::endl << std::endl;


			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		
		if (test_number == 20)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing " 
				<< RESET << std::endl << std::endl;


			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		
		if (test_number == 21)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing " 
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