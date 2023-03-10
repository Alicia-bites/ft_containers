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
#include <list>

// change default namespace
# define NAMESPACE ft
// # define NAMESPACE std

using namespace NAMESPACE;

template <typename Key, typename Value, typename Compare>
	void	print_map(const ::map<Key, Value, Compare> & map, std::string map_name)
	{
		std::cout << DODGERBLUE2 << "-----------------------------------------------------------------------------" << std::endl;
		std::cout << "Printing " << map_name << std::endl;
		std::cout << DEEPSKYBLUE1 << "map size is " << map.size() << std::endl;

		typename ::map<Key, Value, Compare>::const_iterator it;
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

template <typename T1>
struct myComp {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo

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

			map<int, std::string> mappy;
			pair<map<int, std::string>::iterator, bool> res;
			
			res = mappy.insert(make_pair(7, "first"));

			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;

			res = mappy.insert(make_pair(7, "error"));
			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;
			
			res = mappy.insert(make_pair(4, "second"));
			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;

			res = mappy.insert(make_pair(10, "third"));
			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;

			res = mappy.insert(make_pair(15, "fourth"));
			if (res.second == true)
				std::cout << "Inserted " << res.first->second << " into the map with key "
					<< res.first->first << std::endl;
			else
				std::cout << "Key " << res.first->first << " already has the value "
					<< res.first->second << " in the map" << std::endl;
			
			std::cout << std::endl << std::endl;
			print_map(mappy, "mappy");

			std::cout << "Testing copy constructor" << std::endl;
			map<int, std::string> coppy(mappy);
			print_map(coppy, "coppy");
			std::cout << "Removing one node with key 10 " << std::endl;
			size_t output = mappy.erase(10);
			std::cout << "output = " << output << std::endl;


			std::cout << "Removing one node with key 15 " << std::endl;
			output = mappy.erase(15);
			std::cout << "output = " << output << std::endl;

			std::cout << "Removing one node with key 7 " << std::endl;
			output = mappy.erase(7);
			std::cout << "output = " << output << std::endl;
			std::cout << std::endl << std::endl;
			print_map(mappy, "mappy");

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
			std::cout << STEELBLUE3 << "More insert tests" 
				<< RESET << std::endl << std::endl;

			map<int, std::string> mp, mp2;

			pair<int, std::string> input_pair;
			pair<map<int, std::string>::iterator, bool> output;
			input_pair = make_pair(42, "lol");
			output = mp.insert(input_pair);
			if (output.second)
				std::cout << "output = " << output.first->first << " | " << output.first->second << std::endl;
			print_map(mp, "mp");
			input_pair = make_pair(42, "mdr");
			output = mp.insert(input_pair);
			if (output.second)
				std::cout << "output = " << output.first->first << " | " << output.first->second << std::endl;
			print_map(mp, "mp");
			input_pair = make_pair(50, "mdr");
			output = mp.insert(input_pair);
			if (output.second)
				std::cout << "output = " << output.first->first << " | " << output.first->second << std::endl;
			print_map(mp, "mp");
			input_pair = make_pair(35, "funny");
			output = mp.insert(input_pair);
			if (output.second)
				std::cout << "output = " << output.first->first << " | " << output.first->second << std::endl;
			print_map(mp, "mp");
			input_pair = make_pair(45, "bunny");
			output = mp.insert(input_pair);
			if (output.second)
				std::cout << "output = " << output.first->first << " | " << output.first->second << std::endl;
			print_map(mp, "mp");
			input_pair = make_pair(21, "fizz");
			output = mp.insert(input_pair);
			if (output.second)
				std::cout << "output = " << output.first->first << " | " << output.first->second << std::endl;
			print_map(mp, "mp");
			input_pair = make_pair(38, "buzz");
			output = mp.insert(input_pair);
			if (output.second)
				std::cout << "output = " << output.first->first << " | " << output.first->second << std::endl;
			print_map(mp, "mp");

			map<int, std::string>::iterator res;
			res = mp.insert(mp.begin(), make_pair(55, "fuzzy"));
			std::cout << res->first << " | " << res->second << std::endl;
			print_map(mp, "mp");

			res = mp2.insert(mp2.begin(), make_pair(1337, "beauty"));
			std::cout << res->first << " | " << res->second << std::endl;
			print_map(mp2, "mp2");
			res = mp2.insert(mp2.end(), make_pair(1000, "Hello"));
			std::cout << res->first << " | " << res->second << std::endl;
			print_map(mp2, "mp2");
			res = mp2.insert(mp2.end(), make_pair(1500, "World"));
			std::cout << res->first << " | " << res->second << std::endl;
			print_map(mp2, "mp2");

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
			
			print_map(mymap, "mymap");
			// mymap.getTree()->printRBTree(mymap.getTree()->getRoot());

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
			std::cout << STEELBLUE3 << "Testing lower_bound and upper_bound" 
				<< RESET << std::endl << std::endl;

			map<char,int> mymap;
			map<char,int>::iterator itlow,itup;
			
			// mymap.getTree()->printRBTree(mymap.getTree()->getRoot());
			// std::cout << "----------------------------------------------" << std::endl;

			mymap['a']=20;
			mymap['b']=40;
			mymap['c']=60;
			mymap['d']=80;
			mymap['e']=100;
			
			itlow=mymap.lower_bound('b');  // itlow points to b
			itup=mymap.upper_bound('d');   // itup points to e (not d!)

			std::cout << itlow->first << std::endl;
			std::cout << itup->first << std::endl;
			
			mymap.erase(itlow,itup);        // erases [itlow,itup)
			
			// print content:
			for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		
		if (test_number == 18)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
					std::cout << STEELBLUE3 << "Testing lower_bound and upper_bound (const)" 
				<< RESET << std::endl << std::endl;

			// Create a map with some key-value pairs
			map<int, std::string> myMap;
			myMap[1] = "one";
			myMap[3] = "three";
			myMap[5] = "five";
		
			// Call the lower_bound function with a key that's in the map
			map<int, std::string>::const_iterator it = myMap.lower_bound(3);
		
			// Check if the iterator points to the correct element
			if (it != myMap.end() && it->first == 3 && it->second == "three")
				std::cout << "Test 1 passed" << std::endl;
			else
				std::cout << "Test 1 failed" << std::endl;
		
			// Call the lower_bound function with a key that's not in the map
			it = myMap.lower_bound(4);
		
			// Check if the iterator points to the correct element
			if (it != myMap.end() && it->first == 5 && it->second == "five")
				std::cout << "Test 2 passed" << std::endl;
			else
				std::cout << "Test 2 failed" << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		
		if (test_number == 19)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing count member function" 
				<< RESET << std::endl << std::endl;

			// Create a map with some key-value pairs
			map<int, std::string> myMap;
			myMap[1] = "one";
			myMap[2] = "two";
			myMap[3] = "three";
			myMap[3] = "four";
		
			// Call the count function with a key that's in the map
			size_t count1 = myMap.count(2);
		
			// Check if the count is correct
			if (count1 == 1)
				std::cout << "Test 1 passed" << std::endl;
			else
				std::cout << "Test 1 failed" << std::endl;
		
			// Call the count function with a key that's not in the map
			size_t count2 = myMap.count(5);
		
			// Check if the count is correct
			if (count2 == 0)
				std::cout << "Test 2 passed" << std::endl;
			else
				std::cout << "Test 2 failed" << std::endl;
		
			// Add a new key-value pair to the map
			myMap[2] = "new two";
		
			// Call the count function again with the same key
			size_t count3 = myMap.count(2);
		
			// Check if the count is still 1
			if (count3 == 1)
				std::cout << "Test 3 passed" << std::endl;
			else
				std::cout << "Test 3 failed" << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		
		if (test_number == 20)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing equal_range" 
				<< RESET << std::endl << std::endl;

			map<int, int> fufu;

			fufu.insert(make_pair(5, 555));
			fufu.insert(make_pair(9, 999));
			fufu.insert(make_pair(2, 888));

			pair<map<int, int>::iterator, map<int, int>::iterator> res;
			res = fufu.equal_range(9);

			if(res.first != fufu.end())
				std::cout << res.first->first << std::endl;
			if (res.second != fufu.end())
				std::cout << res.second->first<< std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		
		if (test_number == 21)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing equal_range const" 
				<< RESET << std::endl << std::endl;

			map<int, int> fufu;

			fufu.insert(make_pair(5, 555));
			fufu.insert(make_pair(9, 999));
			fufu.insert(make_pair(2, 888));

			pair<map<int, int>::const_iterator, map<int, int>::const_iterator> res;
			res = fufu.equal_range(9);

			if(res.first != fufu.end())
				std::cout << res.first->first << std::endl;
			if (res.second != fufu.end())
				std::cout << res.second->first<< std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		
		if (test_number == 22)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing compare operators" 
				<< RESET << std::endl << std::endl;

			map<int, int> tom;
			map<int, int> jerry;

			std::cout << "Testing == " << std::endl;
			std::cout << "tom and jerry are the SAME - they contains NOTHING." << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "1" << RESET << ", got : ";
			std::cout << (tom == jerry) << std::endl;

			std::cout << "Testing < " << std::endl;
			std::cout << "tom and jerry are the SAME - they contains NOTHING." << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : ";
			std::cout << (tom < jerry) << std::endl;

			std::cout << "Testing <= " << std::endl;
			std::cout << "tom and jerry are the SAME - they contains NOTHING." << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "1" << RESET << ", got : ";
			std::cout << (tom <= jerry) << std::endl;

			std::cout << "Testing > " << std::endl;
			std::cout << "tom and jerry are the SAME - they contains NOTHING." << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : ";
			std::cout << (tom != jerry) << std::endl;

			std::cout << "Testing >= " << std::endl;
			std::cout << "tom and jerry are SAME - they contains NOTHING." << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "1" << RESET << ", got : ";
			std::cout << (tom != jerry) << std::endl;

			std::cout << "------------------------------------------------------------" << std::endl;


			map<int, int> bob;
			bob.insert(make_pair(4, 444));
			bob.insert(make_pair(7, 777));
			bob.insert(make_pair(12, 121212));

			map<int, int> ron;
			ron.insert(make_pair(4, 444));
			ron.insert(make_pair(7, 777));

			map<int, int> fred;
			fred.insert(make_pair(5, 555));
			fred.insert(make_pair(9, 999));
			fred.insert(make_pair(2, 888));

			map<int, int> george;
			george.insert(make_pair(5, 555));
			george.insert(make_pair(9, 999));
			george.insert(make_pair(2, 888));

			std::cout << "Testing == " << std::endl;
			std::cout << "Bob and Ron and DIFFERENT" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : ";
			std::cout << (bob == ron) << std::endl;

			std::cout << "Testing == " << std::endl;
			std::cout << "bob and fred are DIFFERENT" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : ";
			std::cout << (bob == fred) << std::endl;

			std::cout << "Testing == " << std::endl;
			std::cout << "george and fred are EQUAL" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "1" << RESET << ", got : "; 
			std::cout << (george == fred) << std::endl;

			std::cout << "------------------------------------------------------------" << std::endl;
			std::cout << "Testing < " << std::endl;
			std::cout << "bob and ron and SAME" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : ";
			std::cout << (bob < ron) << std::endl;

			std::cout << "Testing < " << std::endl;
			std::cout << "bob and fred are DIFFERENT" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : ";
			std::cout << (bob < fred) << std::endl;

			std::cout << "Testing < " << std::endl;
			std::cout << "george and fred are EQUAL" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : "; 
			std::cout << (george < fred) << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;

			std::cout << "Testing <= " << std::endl;
			std::cout << "bob and ron and SAME" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "1" << RESET << ", got : ";
			std::cout << (bob <= ron) << std::endl;

			std::cout << "Testing <= " << std::endl;
			std::cout << "bob and fred are DIFFERENT" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "1" << RESET << ", got : ";
			std::cout << (bob <= fred) << std::endl;

			std::cout << "Testing <= " << std::endl;
			std::cout << "george and fred are EQUAL" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "1" << RESET << ", got : "; 
			std::cout << (george <= fred) << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;

			std::cout << "Testing > " << std::endl;
			std::cout << "bob and ron and SAME" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : ";
			std::cout << (bob != ron) << std::endl;

			std::cout << "Testing > " << std::endl;
			std::cout << "bob and fred are DIFFERENT" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "1" << RESET << ", got : ";
			std::cout << (bob > fred) << std::endl;

			std::cout << "Testing > " << std::endl;
			std::cout << "george and fred are EQUAL" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "1" << RESET << ", got : "; 
			std::cout << (george > fred) << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;

			std::cout << "Testing >= " << std::endl;
			std::cout << "bob and ron and SAME" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : ";
			std::cout << (bob != ron) << std::endl;

			std::cout << "Testing >= " << std::endl;
			std::cout << "bob and ron and SAME" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : ";
			std::cout << (bob != ron) << std::endl;

			std::cout << "Testing >= " << std::endl;
			std::cout << "bob and ron and SAME" << std::endl;
			std::cout << "Expected " << STEELBLUE2 << "0" << RESET << ", got : ";
			std::cout << (bob != ron) << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		
		if (test_number == 23)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing swap" 
				<< RESET << std::endl << std::endl;

			map<char,int> foo, bar;
			
			foo['x']=100;
			foo['y']=200;
			
			bar['a']=11;
			bar['b']=22;
			bar['c']=33;
			
			swap(foo,bar);
			
			std::cout << "foo contains:\n";
			for (map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';
			
			std::cout << "bar contains:\n";
			for (map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << "foo size is " << foo.size() << std::endl;
			std::cout << "bar size is " << bar.size() << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		
		if (test_number == 24)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing mazoise" 
				<< RESET << std::endl << std::endl;

			map<char,int> mymap;
			
			mymap['x'] = 100;
			mymap['y'] = 200;
			mymap['z'] = 300;
			
			// show content:
			map<char,int>::reverse_iterator rit;
			for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			{
				std::cout << rit->first << " => " << rit->second << '\n';
			}
			
			
			for (map<char,int>::const_reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); it++)
				std::cout << it->first << " => " << it->second << '\n';
		
			map<char, int>::const_reverse_iterator it = mymap.rbegin();
			map<char, int>::const_reverse_iterator ti = mymap.rend();
		
			it++;
			++it;
			it--;
			--it;
		
			ti--;
			--ti;
			++ti;
			ti++;
		
			ti = it;
		
			map<char, int>::reverse_iterator end = mymap.rend();
			while(it != end)
			{
				std::cout << it->first << " => " << it->second << '\n';
				it++;
			}
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 25)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing operator[]" 
				<< RESET << std::endl << std::endl;

			map<std::string, int> bob;

			bob["xD"] = 123;
			// bob.getTree()->printTree(bob.getTree()->getRoot());
			// std::cout << bob["xD"] << std::endl;

			// std::cout << "root_ = " << bob.getTree()->getRoot()->data.second << std::endl;
			bob["uch"] = 23;
			bob["lol"] = 8;

			print_map(bob, "bob");
			// bob.getTree()->printTree(bob.getTree()->getRoot());


			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 26)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing " 
				<< RESET << std::endl << std::endl;

			ft::map<int, int> kirikou;
			std::cout << "kirikou = " << kirikou.max_size() << std::endl;
			
			std::map<int, int> karaba;
			std::cout << "karaba  = " << karaba.max_size() << std::endl;


			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 27)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing with my own custom compare struct" 
				<< RESET << std::endl << std::endl;
			
			typedef map<int, std::string, myComp<int> > myCompMap;
			myCompMap mp;

			mp[42] = "fgzgxfn";
			mp[25] = "funny";
			mp[80] = "hey";
			mp[12] = "no";
			mp[27] = "bee";
			mp[90] = "8";
			print_map(mp, "mp");


			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 28)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing reverse_iterator constructor" 
				<< RESET << std::endl << std::endl;
			
			map<int, int> mp;
			map<int, int>::iterator it = mp.begin();
			map<int, int>::const_iterator cit = mp.begin();

			map<int, int>::reverse_iterator rit(it);
		
			map<int, int>::const_reverse_iterator crit(rit);
			
			map<int, int>::const_reverse_iterator crit_(it);
			map<int, int>::const_reverse_iterator crit_2(cit);
		
			// error expected -- cannot compile this
			// map<int, int>::reverse_iterator rit_(crit);
			// map<int, int>::reverse_iterator rit2(cit);
			// map<int, int>::iterator it2(rit);
			// map<int, int>::const_iterator cit2(crit);
			//

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 29)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing mli" 
				<< RESET << std::endl << std::endl;

			std::list<pair<char, int> > lst;
			unsigned int lst_size = 5;
			for (unsigned int i = 0; i < lst_size; ++i)
				lst.push_back(pair<char, int>('a' + i, (i + 1) * 7));
		
			map<char, int> mp(lst.begin(), lst.end());
			map<char, int>::iterator iterator = mp.begin();
			map<char, int>::reverse_iterator rev_it(iterator), rev_end;
			print_map(mp, "map");
			
			std::cout << "rev_it - 1 = " << printPair(inc(rev_it.base(), 1));

			std::cout << "TEST OFFSET" << std::endl;
			--rev_it;
			printPair(rev_it);
			printPair(rev_it.base());

			rev_it = mp.rbegin(); rev_end = mp.rend();
			std::cout << "rev_it = " << printPair(rev_it);
			while (rev_it != rev_end)
				std::cout << "[rev] " << printPair(rev_it++, false) << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 30)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing inserting elements from custom class" 
				<< RESET << std::endl << std::endl;

			map<char, foo<std::string> > mp;

			mp['a'] = "an element";
			mp['b'] = "another element";
			mp['c'] = mp['b'];
			mp['b'] = "old element";

			print_map(mp, "map");

			std::cout << "insert a new element via operator[]: " << mp['d'] << std::endl;

			print_map(mp, "map");

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 30)
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