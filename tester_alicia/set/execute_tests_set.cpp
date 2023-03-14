#include "../../colors/colors.hpp"

#include "../../includes/set.hpp"

#include <string>
#include <algorithm>
#include <iostream>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#include <set>
#endif

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

int	execute_tests_set(int test_number)
{
	// if (argc != 2)
	// {
	// 	std::cout << "Usage : ./ft_containers <test number>" << std::endl;
	// 	return 0;
	// }
	// int test_number = atoi(argv[1]);
	try
	{
		if (test_number == 1)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing constructors" 
				<< RESET << std::endl << std::endl;

			set<int> first;                           // empty set of ints
			print_set(first, "first");

			first.insert(2);						// inserting one element with key 2
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
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			set<int> myset;
			int * p;
			unsigned int i;
			
			// allocate an array of 5 elements using myset's allocator:
			p=myset.get_allocator().allocate(5);
			
			// assign some values to array
			for (i=0; i<5; i++) p[i]=(i+1)*10;
			
			std::cout << "The allocated array contains:";
			for (i=0; i<5; i++) std::cout << ' ' << p[i];
			std::cout << '\n';
			
			myset.get_allocator().deallocate(p,5);

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 3)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing begin()" 
				<< RESET << std::endl << std::endl;

			int myints[] = {75,23,65,42,13};
			set<int> myset (myints,myints+5);
			
			std::cout << "myset contains:";
			for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
			
			std::cout << '\n';

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 4)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing clear" 
				<< RESET << std::endl << std::endl;

			set<int> myset;
			
			myset.insert (100);
			myset.insert (200);
			myset.insert (300);
			
			std::cout << "myset contains:";
			for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
			
			myset.clear();
			myset.insert (1101);
			myset.insert (2202);
			
			std::cout << "myset contains:";
			for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 5)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 6)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 7)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 8)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 9)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 10)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
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