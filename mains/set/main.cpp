#include "../../colors/colors.hpp"

#include "../../includes/set.hpp"
// #include "../../includes/pair.hpp"
// #include "../../includes/RedBlackTree.hpp"
// #include "../../setReverseIterator.hpp"


#include <string>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <ctime>

// change default namespace
# define NAMESPACE ft
// # define NAMESPACE std

using namespace NAMESPACE;

template <typename Key, typename Value>
	void	print_set(const ::set<Key, Value> & set, std::string set_name)
	{
		std::cout << DODGERBLUE2 << "-----------------------------------------------------------------------------" << std::endl;
		std::cout << "Printing " << set_name << std::endl;
		std::cout << DEEPSKYBLUE1 << "set size is " << set.size() << std::endl;

		typename ::set<Key, Value>::const_iterator it;
		std::cout << "Key " << " = " << "Value" << std::endl;
		it = set.begin();
		while (it != set.end())
		{
			std::cout << DARKTURQUOISE << *it << "    =    " << std::endl;
			it++;
		}
		std::cout << std::endl;
		std::cout << NAVY << "-----------------------------------------------------------------------------" << RESET << std::endl;
	}

bool fncomp (int lhs, int rhs)
{
	return lhs<rhs;
}
	
struct classcomp
{
	bool operator() (const int & lhs, const int & rhs) const
	{
		return lhs<rhs;
	}
};

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
			std::cout << STEELBLUE3 << "Testing constructors" 
				<< RESET << std::endl << std::endl;

			set<int> first;                           // empty set of ints
			print_set(first, "first");

			first.insert(2);
			print_set(first, "first");

			int myints[]= {10,20,30,40,50};
			set<int> second (myints,myints+5);        // range
			print_set(second, "second");

			set<int> third (second);                  // a copy of second
			print_set(third, "third");
// 
			set<int,classcomp> fifth;                 // class as Compare
			print_set(fifth, "fifth");

			bool(*fn_pt)(int,int) = fncomp;
			set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
			print_set(sixth, "sixth");

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 2)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "--" 
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