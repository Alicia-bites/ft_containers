/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmartin_main.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:07:06 by hbaudet           #+#    #+#             */
/*   Updated: 2023/03/03 12:33:59 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FOR DEBUG
#include "test_utils.hpp"
// #include "MAP_UC.HPP"
#include "map.hpp"
#include <map>
#include <cstdio>
#include <iomanip>

/*
** This is a minimal set of ANSI/VT100 color codes
*/
# define _END			"\x1b[0m"
# define _BOLD			"\x1b[1m"
# define _UNDER			"\x1b[4m"
# define _REV			"\x1b[7m"

/*
** Colors
*/
# define _GREY			"\x1b[30m"
# define _RED			"\x1b[31m"
# define _GREEN			"\x1b[32m"
# define _YELLOW		"\x1b[33m"
# define _BLUE			"\x1b[34m"
# define _PURPLE		"\x1b[35m"
# define _CYAN			"\x1b[36m"
# define _WHITE			"\x1b[37m"

/*
** Inverted, i.e. colored backgrounds
*/
# define _IGREY			"\x1b[40m"
# define _IRED			"\x1b[41m"
# define _IGREEN		"\x1b[42m"
# define _IYELLOW		"\x1b[43m"
# define _IBLUE			"\x1b[44m"
# define _IPURPLE		"\x1b[45m"
# define _ICYAN			"\x1b[46m"
# define _IWHITE		"\x1b[47m"

// change
#ifndef STD
# define NAMESPACE ft
// #else
// # define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	cout << "printing a map : \n";
	// cout << SLATEBLUE1 << "lst.size() = " << lst.size() << RESET << std::endl;
	// if (lst.getTree()->getRoot())
		// cout << SLATEBLUE1 << "lst.getTree()->getRoot() = " << lst.getTree()->getRoot()->key << RESET << std::endl;

	// std::cout << SLATEBLUE1 << lst.begin()->first << std::endl;
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << it->first << " => " << it->second << '\n';
}

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

int main()
{
	cout << _WHITE << "# test_map" << _END << std::endl;
	cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
	cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
	cout << "/* ********************************************************************** */" << _END << std::endl;
	cout << std::endl;


	map<string, int> mymap;
	print(mymap);


	cout << "mymap<" << _PURPLE << "string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap;" << std::endl;

	cout << std::endl;
	cout << "mymap.max_size(): " << (mymap.max_size() > 10000) << std::endl;
	print(mymap);
	cout << std::endl;


	mymap.insert(pair<string, int>("ft", 42));
	print(mymap);

	mymap.insert(pair<string, int>("one", 1));
	print(mymap);


	cout << _WHITE << "# testing upper/lower_bound" << _END << std::endl;
	map<string, int>::iterator mit;
	map<string, int>::iterator it;
	print(mymap);
	it = mymap.lower_bound("aaa");
	print(mymap);
	cout << std::setw(40) << "mymap.lower_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;
	cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("one");
	print(mymap);
	cout << std::setw(40) << "mymap.lower_bound(\"one\"): " << it->first << ":" << it->second << std::endl;
	cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("oae");
	print(mymap);
	cout << std::setw(40) << "mymap.lower_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;
	cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("ft");
	print(mymap);
	cout << std::setw(40) << "mymap.lower_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;
	cout << std::endl;
	print(mymap);
	it = mymap.lower_bound("zzz");
	print(mymap);
	
	if (it == mymap.end())
		cout << std::setw(40) << "mymap.lower_bound(\"zzz\"): mymap.end()" << std::endl;
	cout << std::endl;
	print(mymap);
	it = mymap.upper_bound("aaa");
	
	print(mymap);
	// mymap.getTree()->printRBTree(mymap.getTree()->getRoot());
	// map<string, int>::key_compare comp = mymap.key_comp();
	// std::cout << CADETBLUE2 << "Is aaa smaller than aaa? --> " << comp("aaa", "aaa") << RESET << std::endl;
	cout << std::setw(40) << "mymap.upper_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;;
	cout << std::endl;
	

	print(mymap);
	it = mymap.upper_bound("oae");
	// std::cout << CADETBLUE2 << "Is oae smaller than one? --> " << comp("oae", "one") << RESET << std::endl;
	cout << std::setw(40) << "mymap.upper_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;;
	cout << std::endl;

	print(mymap);
	it = mymap.upper_bound("one");
	// std::cout << RED3 << it->first << RESET << std::endl;
	if (it == mymap.end())
		cout << std::setw(40) << "mymap.upper_bound(\"one\"): mymap.end()" << std::endl;
	print(mymap);
	cout << std::endl;
	it = mymap.upper_bound("ft");
	print(mymap);
	cout << std::setw(40) << "mymap.upper_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;;
	cout << std::endl;
	print(mymap);
	it = mymap.upper_bound("zzz");
	
	if (it == mymap.end())
		cout << std::setw(40) << "mymap.upper_bound(\"zzz\"): mymap.end()" << std::endl;
	print(mymap);
	cout << std::endl;

	print(mymap);
	mymap.erase("undefined");
	print(mymap);
	mymap.erase("ft");
	print(mymap);
	cout << _WHITE << "# double clear" << _END << std::endl;
	mymap.clear();

	print(mymap);
	mymap.clear();
	print(mymap);
	// mymap["lol"];
	print(mymap);
	mymap.insert(pair<string, int>("xD", 123));
	print(mymap);
	mymap.insert(mymap.end(), pair<string, int>("uch", 442));
	print(mymap);
	mymap.insert(mymap.begin(), pair<string, int>("uch", 22));
	print(mymap);
	mymap.insert(mymap.end(), pair<string, int>("uch", 23));
	print(mymap);
	mymap.insert(pair<string, int>("uch", 23));
	print_map(mymap, "mymap");

	mymap["lol"]=8;
	
	print_map(mymap, "mymap");

	// print(mymap);
	map<string, int> map2;
	print_map(mymap, "mymap");
	
	print(mymap);
	print(map2);
	cout << "mymap<" << _PURPLE << "string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap2;" << std::endl;
	print(mymap);
	cout << "empty line\n";
	print(map2);
	cout << "empty line2\n";

	print_map(mymap, "mymap");

	// mymap.getTree()->printTree(mymap.getTree()->getRoot());

	std::cout << PINK3 << "SWAPPING" << RESET << std::endl;
	swap(mymap, map2);
	print_map(mymap, "mymap");
	print_map(map2, "map2");


	// cout << "empty line3\n";
	// print(mymap);
	// cout << "empty line4\n";
	// print(map2);
	// cout << "empty line5\n";
	
	// print(mymap);
	// std::cout << PINK1 << "Printing mymap : " << RESET << std::endl;
	// mymap.getTree()->printRBTree(mymap.getTree()->getRoot());
	// mymap.getTree()->printTree(mymap.getTree()->getRoot());

	// std::cout << "-------------------------" << std::endl;
	// print(map2);
	// std::cout << PINK1 << "Printing map2 : " << RESET << std::endl;
	// map2.getTree()->printRBTree(map2.getTree()->getRoot());
	// map2.getTree()->printTree(map2.getTree()->getRoot());
	// std::cout << "-------------------------" << std::endl;

	mymap = map2;
	print(mymap);
	// mymap.getTree()->printRBTree(mymap.getTree()->getRoot());
	print(map2);
	// map2.getTree()->printRBTree(map2.getTree()->getRoot());


	cout << std::setw(40) << "map == map2: " << (mymap == map2) << std::endl;
	print(mymap);
	print(map2);
	cout << std::endl;

	mymap.clear();
	print(mymap);
	print(map2);

	mymap["satan"] = 666;
	print(mymap);
	print(map2);
	cout << std::setw(40) << "mymap == map2: " << (mymap == map2) << std::endl;
	print(mymap);
	print(map2);
	cout << std::endl;
	cout << std::setw(40) << "mymap <= map2: " << (mymap <= map2) << std::endl;
	print(mymap);
	print(map2);
	cout << std::endl;
	cout << std::setw(40) << "mymap >= map2: " << (mymap >= map2) << std::endl;
	print(mymap);
	print(map2);
	cout << std::endl;
	cout << std::setw(40) << "mymap > map2: " << (mymap > map2) << std::endl;
	print(mymap);
	print(map2);
	cout << std::endl;
	cout << std::setw(40) << "mymap < map2: " << (mymap > map2) << std::endl;
	print(mymap);
	print(map2);
	cout << std::endl;

	return 0;
}
