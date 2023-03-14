#include "../../colors/colors.hpp"

#include "../../includes/set.hpp"

#include <string>
#include <algorithm>
#include <iostream>
#include <list>

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

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "value: " << *iterator;
	if (nl)
		o << std::endl;
	return ("");
}

static int iter = 0;

template <typename SET>
void	ft_bound(SET &st, const int &param)
{
	set<int>::iterator ite = st.end(), it[2];
	pair<set<int>::iterator, set<int>::iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = st.lower_bound(param); it[1] = st.upper_bound(param);
	ft_range = st.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename SET>
void	ft_const_bound(const SET &st, const int &param)
{
	set<int>::const_iterator ite = st.end(), it[2];
	pair<set<int>::const_iterator, set<int>::const_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = st.lower_bound(param); it[1] = st.upper_bound(param);
	ft_range = st.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
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
			std::cout << STEELBLUE3 << "Testing end()" 
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

		if (test_number == 6)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing count" 
				<< RESET << std::endl << std::endl;

			set<int> myset;

			// set some initial values:
			for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12
			
			for (int i=0; i<10; ++i)
			{
				std::cout << i;
				if (myset.count(i)!=0)
					std::cout << " is an element of myset.\n";
				else
					std::cout << " is not an element of myset.\n";
			}

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 7)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing empty()" 
				<< RESET << std::endl << std::endl;

			set<int> myset;
			
			myset.insert(20);
			myset.insert(30);
			myset.insert(10);
			
			std::cout << "myset contains:";
			while (!myset.empty())
			{
				std::cout << ' ' << *myset.begin();
				myset.erase(myset.begin());
			}
			std::cout << '\n';

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 8)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing equal_range" 
				<< RESET << std::endl << std::endl;

			set<int> myset;
			
			for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50
			
			pair<set<int>::const_iterator, set<int>::const_iterator> ret;
			ret = myset.equal_range(30);
			
			std::cout << "the lower bound points to: " << *ret.first << '\n';
			std::cout << "the upper bound points to: " << *ret.second << '\n';

			std::cout << "What happens if no matches are found?" << std::endl;

			ret = myset.equal_range(15);
			
			std::cout << "the lower bound points to: " << *ret.first << '\n';
			std::cout << "the upper bound points to: " << *ret.second << '\n';

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 9)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing erase()" 
				<< RESET << std::endl << std::endl;

			set<int> myset;
			set<int>::iterator it;
			
			// insert some values:
			for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90
			
			it = myset.begin();
			++it;                                         // "it" points now to 20
			
			myset.erase (it);
			
			myset.erase (40);
			
			it = myset.find (60);
			myset.erase (it, myset.end());
			
			std::cout << "myset contains:";
			for (it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 10)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing insert()" 
				<< RESET << std::endl << std::endl;

			set<int> myset;
			set<int>::iterator it;
			pair<set<int>::iterator,bool> ret;
			
			// set some initial values:
			for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50
			
			ret = myset.insert(20);               // no new element inserted
			
			if (ret.second==false) it=ret.first;  // "it" now points to element 20

			std::cout << "ret points to = " << *(ret.first) << std::endl;
			
			myset.insert (it,25);                 // max efficiency inserting
			myset.insert (it,24);                 // max efficiency inserting
			myset.insert (it,26);                 // no max efficiency inserting
			
			int myints[]= {5,10,15};              // 10 already in set, not inserted
			myset.insert (myints,myints+3);
			
			std::cout << "myset contains:";
			for (it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 11)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing lower_bound() and upper_bound()" 
				<< RESET << std::endl << std::endl;

			std::list<int> lst;
			unsigned int lst_size = 10;
			for (unsigned int i = 0; i < lst_size; ++i)
				lst.push_back((i + 1) * 3);
			set<int> st(lst.begin(), lst.end());
			print_set(st, "st");
		
			ft_const_bound(st, -10);
			ft_const_bound(st, 1);
			ft_const_bound(st, 5);
			ft_const_bound(st, 10);
			ft_const_bound(st, 50);
		
			print_set(st, "st");
		
			ft_bound(st, 5);
			ft_bound(st, 7);
		
			print_set(st, "st");
			
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 12)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 13)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 14)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 15)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 16)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 17)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 18)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing allocator getter" 
				<< RESET << std::endl << std::endl;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 19)
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

int main(int argc, char **argv)
{
	static_cast<void>(argc);
	int test_number = atoi(argv[1]);
	execute_tests_set(test_number);
	return 0;
}