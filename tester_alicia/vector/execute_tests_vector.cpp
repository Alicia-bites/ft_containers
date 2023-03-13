#include "../../includes/vector.hpp"
#include "../../includes/pair.hpp"
#include "../../colors/colors.hpp"

#include <string>
#include <algorithm>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#include <vector>
#endif

using namespace NAMESPACE;

template <class T>
void	print(vector<vector<T> >& lst)
{
	for (typename vector<vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(vector<T>& lst)
{
	for (typename vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

template <typename T>
	void	print_vector(T vector)
	{
		std::cout << "vector size is " << vector.size() << std::endl;
		std::cout << "vector capacity is " << vector.capacity() << std::endl;
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " | ";
		std::cout << std::endl;
	}

template <typename T>
	void	print_vector(T vector, std::string vector_name)
	{
		std::cout << DODGERBLUE2 << "-----------------------------------------------------------------------------" << std::endl;
		std::cout << "Printing " << vector_name << std::endl;
		std::cout << "vector size is " << vector.size() << std::endl;
		std::cout << "vector capacity is " << vector.capacity() << std::endl;
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " | ";
		std::cout << std::endl;
		std::cout << DODGERBLUE2 << "-----------------------------------------------------------------------------" << RESET << std::endl;
	}

int execute_tests_vector(int test_number)
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
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;
			
			vector<int> bob;

			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 2)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing empty container constructor and fill constructor" 
				<< RESET << std::endl << std::endl;


			vector<int> myVector_0 (4);
			std::cout << "Printing content of myVector_0 :" << std::endl;
			std::cout << "- START -" << std::endl;
			for (size_t i = 0; i < myVector_0.size(); ++i)
    			std::cout << i << " : " << myVector_0[i] << std::endl;
			std::cout << "- END -" << std::endl;

			vector<int> myVector (4, 6);
			std::cout << "Printing content of myVector :" << std::endl;
			std::cout << "- START -" << std::endl;
			for (size_t i = 0; i < myVector.size(); ++i)
    			std::cout << i << " : " << myVector[i] << std::endl;
			std::cout << "- END -" << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 3)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing range constructor" 
				<< RESET << std::endl << std::endl;

			std::cout << "Constructing a vector with range using iterators" << std::endl;
			int myints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			vector<int> myVector(myints, myints+10);
			std::cout << "Printing content of myVector :" << std::endl;
			for (size_t i = 0; i < myVector.size(); ++i)
    			std::cout << myVector[i] << std::endl;
			std::cout << std::endl;

			vector<int> myVector_it_test (myVector.begin(), myVector.end());
			std::cout << "Printing content of myVector_it_test :" << std::endl;
			for (size_t i = 0; i < myVector_it_test.size(); ++i)
    			std::cout << myVector_it_test[i] << std::endl;
			std::cout << std::endl;

			std::cout << "Constructing a vector with range using front() and back()" << std::endl;
			vector<int> gandalf (myVector.front(), myVector.back());
			std::cout << "Printing content of gandalf :" << std::endl;
			for (size_t i = 0; i < gandalf.size(); ++i)
    			std::cout << gandalf[i] << std::endl;
			
			vector<int> frodo (myVector.front(), myVector.back());
			std::cout << "Printing content of frodo :" << std::endl;
			for (size_t i = 0; i < frodo.size(); ++i)
    			std::cout << frodo[i] << std::endl;
			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 4)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing copy constructor" 
				<< RESET << std::endl << std::endl;
			int myints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			vector<int> myVector(myints, myints+10);
			std::cout << "Printing content of myVector " << std::endl;
			for (size_t i = 0; i < myVector.size(); ++i)
				std::cout << myVector[i] << std::endl;
			std::cout << "Creating a copy of myVector..." << std::endl;
			vector<int> copy_myVector (myVector);
			std::cout << "Printing content of copy_myVector :" << std::endl;
			for (size_t i = 0; i < copy_myVector.size(); i++)
				std::cout << copy_myVector[i] << std::endl;
			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 5)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing swap member function" 
				<< RESET << std::endl << std::endl;

			int uneven_ints[] = {1, 3, 5};
			vector<int> gandalf(uneven_ints, uneven_ints+3);
			int even_ints[] = {2, 4, 6};
			vector<int> galadriel(even_ints, even_ints+3);
			std::cout << "gandalf" << " | " << "galadriel" << std::endl;
			for (size_t i = 0, j = 0; i < gandalf.size() && j < galadriel.size(); i++, j++)
				std::cout << gandalf[i] << "       | " << galadriel[j] << std::endl;
			gandalf.swap(galadriel);
			std::cout << "gandalf" << " | " << "galadriel" << std::endl;
			for (size_t i = 0, j = 0; i < gandalf.size() && j < galadriel.size(); i++, j++)
				std::cout << gandalf[i] << "       | " << galadriel[j] << std::endl;
			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 6)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing assignement operator, with 2 vectors of the same size" 
				<< RESET << std::endl << std::endl;

			int uneven_ints[] = {1, 3, 5};
			vector<int> gandalf(uneven_ints, uneven_ints+3);
			int even_ints[] = {2, 4, 6};
			vector<int> galadriel(even_ints, even_ints+3);
			std::cout << "gandalf" << " | " << "galadriel" << std::endl;
			for (size_t i = 0, j = 0; i < gandalf.size() && j < galadriel.size(); i++, j++)
				std::cout << gandalf[i] << "       | " << galadriel[j] << std::endl;
			gandalf = galadriel;
			std::cout << "gandalf" << " | " << "galadriel" << std::endl;
			for (size_t i = 0, j = 0; i < gandalf.size() && j < galadriel.size(); i++, j++)
				std::cout << gandalf[i] << "       | " << galadriel[j] << std::endl;
			
			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 7)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing assignement operator, with the src smaller than the recever" 
				<< RESET << std::endl << std::endl;

			int bigger[] = {1, 3, 5};
			vector<int> gandalf(bigger, bigger+3);
			int smaller[] = {2};
			vector<int> galadriel(smaller, smaller+1);
			std::cout << "gandalf" << " | " << "galadriel" << std::endl;
			for (size_t i = 0, j = 0; i < gandalf.size() || j < galadriel.size(); i++, j++)
			{
				if (i >= gandalf.size())
					std::cout << "N" << "       | " << galadriel[j] << std::endl;
				else if (j >= galadriel.size())
					std::cout << gandalf[i] << "       | " << "N" << std::endl;
				else
					std::cout << gandalf[i] << "       | " << galadriel[j] << std::endl;
			}
			gandalf = galadriel;
			std::cout << "gandalf" << " | " << "galadriel" << std::endl;
			for (size_t i = 0, j = 0; i < gandalf.size() || j < galadriel.size(); i++, j++)
				std::cout << gandalf[i] << "       | " << galadriel[j] << std::endl;
			
			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 8)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing assignement operator, with the src bigger than the recever"
				<< RESET << std::endl << std::endl;

			int bigger[] = {1, 3, 5};
			int smaller[] = {2};
			vector<int> gandalf(smaller, smaller+1);
			vector<int> galadriel(bigger, bigger+3);
			std::cout << "gandalf" << " | " << "galadriel" << std::endl;
			for (size_t i = 0, j = 0; i < gandalf.size() || j < galadriel.size(); i++, j++)
			{
				if (i >= gandalf.size())
					std::cout << "N" << "       | " << galadriel[j] << std::endl;
				else if (j >= galadriel.size())
					std::cout << gandalf[i] << "       | " << "N" << std::endl;
				else
					std::cout << gandalf[i] << "       | " << galadriel[j] << std::endl;
			}
			gandalf = galadriel;
			std::cout << "gandalf" << " | " << "galadriel" << std::endl;
			for (size_t i = 0, j = 0; i < gandalf.size() || j < galadriel.size(); i++, j++)
				std::cout << gandalf[i] << "       | " << galadriel[j] << std::endl;
			
			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 9)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing vector::assign, with 2 vectors of the same size" 
				<< RESET << std::endl << std::endl;

			int uneven_ints[] = {1, 3, 5};
			int even_ints[] = {2, 4, 6};

			vector<int> gandalf(uneven_ints, uneven_ints+3);
			vector<int> galadriel(even_ints, even_ints+3);

			vector<int> sauron(uneven_ints, uneven_ints+3);
			vector<int> saruman(even_ints, even_ints+3);

			std::cout << "sauron" << " | " << "saruman" << std::endl;
			for (size_t i = 0, j = 0; i < sauron.size() && j < saruman.size(); i++, j++)
				std::cout << sauron[i] << "      | " << saruman[j] << std::endl;
			sauron.assign(saruman.begin(), saruman.end());
			std::cout << std::endl;
			std::cout << "sauron" << " | " << "saruman" << std::endl;
			for (size_t i = 0, j = 0; i < sauron.size() && j < saruman.size(); i++, j++)
				std::cout << sauron[i] << "      | " << saruman[j] << std::endl;

			// std::cout << "gandalf" << " | " << "galadriel" << std::endl;
			// for (size_t i = 0, j = 0; i < gandalf.size() && j < galadriel.size(); i++, j++)
				// std::cout << gandalf[i] << "       | " << galadriel[j] << std::endl;
// 
			// gandalf.assign(galadriel.begin(), galadriel.end());
			// std::cout << "gandalf" << " | " << "galadriel" << std::endl;
			// for (size_t i = 0, j = 0; i < gandalf.size() && j < galadriel.size(); i++, j++)
				// std::cout << gandalf[i] << "       | " << galadriel[j] << std::endl;
			
			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 10)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing vector::iterator" 
				<< RESET << std::endl << std::endl;

			int myints[] = {1, 3, 5};

			vector<int> myVector(myints, myints+3);

			vector<int>::iterator ft_it;
			ft_it = myVector.begin();
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			ft_it = myVector.end();
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			ft_it = myVector.begin() + 1;
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			ft_it = myVector.end() - 2;
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			ft_it = myVector.end()--;
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			ft_it = --myVector.end();
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			ft_it = myVector.begin()++;
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			ft_it = ++myVector.begin();
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 11)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing reverse_iterator" 
				<< RESET << std::endl << std::endl;

			std::cout << "Testing that reverse_iterator correctly iterates over a container in reverse order." << std::endl;
			int myints[] = { 1, 2, 3, 4, 5 };
			vector<int> v(myints, myints+5);

			reverse_iterator<vector<int>::iterator> it(v.end());
			
			for (int i = 5; i > 0; --i)
			{
				std::cout << "*it = " << *it << std::endl;
				std::cout << "i  = " << i << std::endl;
				++it;
			}
			std::cout << std::endl;

			std::cout << "Testing that the reverse_iterator supports comparison with the == operator" << std::endl;
			reverse_iterator<vector<int>::iterator> it1(v.end());
			reverse_iterator<vector<int>::iterator> it2(v.end());
			int res = it1 == it2;
			std::cout << "Is it1 == to it2 ? 1 for yes, 0 for no. --> " << std::endl;
			std::cout << "ANSWER = " << res << std::endl;
			std::cout << std::endl;

			std::cout << "Testing that the reverse_iterator supports the + and - operators for arithmetic operations" << std::endl;
			reverse_iterator<vector<int>::iterator> it3(v.end());
			reverse_iterator<vector<int>::iterator> it4 = it3 + 2;
			std:: cout << "*it4 + 2 --> *it4 should be equal to 3"
				<< std::endl << " *it4 = " << *it4 << std::endl;
			it4 = it4 - 1;
			std:: cout << "it4 = it4 - 1 --> *it4 should be equal to 4"
				<< std::endl << " *it4 = " << *it4 << std::endl;
			std::cout << std::endl;

			std::cout << "Testing that the reverse_iterator supports the < operator for comparison" << std::endl;
			reverse_iterator<vector<int>::iterator> it5(v.end());
			reverse_iterator<vector<int>::iterator> it6 = it5 + 2;
			std::cout << "*it5 is pointing at the last element" << std::endl;
			std::cout << "it6 is it5 + 2 " << std::endl;
			std::cout << " Is it5 < it6 ? The answer should be 1 --> " << (it5 < it6) << std::endl;
			std::cout << std::endl;

			std::cout << "Testing that the reverse_iterator works correctly with the [] operator" << std::endl;
			reverse_iterator<vector<int>::iterator> it7(v.end());
			std::cout << "it[0] = " << it7[0] << std::endl;
			std::cout << "it[1] = " << it7[1] << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 12)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing rbegin() and rend()" 
				<< RESET << std::endl << std::endl;

			std::string init[] = {"another","brick","on", "the", "wall"};
			vector<std::string> pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			vector<std::string>::reverse_iterator rit = pinkFloyd.rbegin();
			std::cout << "rit is : " << *rit << std::endl;
			std::cout << "rit + 1 is : " << *(rit + 1) << std::endl;
			vector<std::string>::reverse_iterator rit_rend = pinkFloyd.rend();
			std::cout << "rit_rend - 1 is : " << *(rit_rend - 1) << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 13)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing vector::size and vector::capacity" 
				<< RESET << std::endl << std::endl;

			std::string init[] = {"another","brick","on", "the", "wall"};
			vector<std::string> pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << "In pinkFloyd : " << std::endl;
			for(size_t i = 0; i <= 4; i++)
				std::cout << pinkFloyd[i] << " | ";
			std::cout << std::endl;

			for(size_t i = 0; i <= 4; i++)
				std::cout << pinkFloyd[i] << " | ";
			std::cout << std::endl;

			std::cout << "pinkFloyd.size() = " << pinkFloyd.size() << std::endl;

			std::cout << "pinkFloyd.capacity() = " << pinkFloyd.capacity() << std::endl;

			std::cout << "---------------------------------------------------" << std::endl;

			vector<int> gandalf(10);
			std::cout << "In gandalf : " << std::endl;
			for(size_t i = 0; i < gandalf.size(); i++)
				std::cout << gandalf[i] << " | ";
			std::cout << std::endl;
			gandalf.push_back(2);
			gandalf.push_back(3);
			gandalf.push_back(4);
			std::cout << "gandalf size is : " << gandalf.size() << std::endl;
			std::cout << "gandalf capacity is : " << gandalf.capacity() << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 14)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing vector::resize and vector::reserve" 
				<< RESET << std::endl << std::endl;

			vector<int> myVector(10, 1);
			std::cout << "In myVector : " << std::endl;
			for(size_t i = 0; i < myVector.size(); i++)
				std::cout << myVector[i] << " | ";
			std::cout << std::endl;
			std::cout << AQUAMARINE2 << "resizing to 15" << RESET << std::endl;
			myVector.resize(15);
			std::cout << "In myVector : " << std::endl;
			for(size_t i = 0; i < myVector.size(); i++)
				std::cout << myVector[i] << " | ";
			std::cout << std::endl;
			std::cout << "myVector size is : " << myVector.size() << std::endl;
			std::cout << "myVector capacity is : " << myVector.capacity() << std::endl;
			std::cout << AQUAMARINE2 << "resizing to 5" << RESET << std::endl;
			myVector.resize(5);
			for(size_t i = 0; i < myVector.size(); i++)
				std::cout << myVector[i] << " | ";
			std::cout << std::endl;
			std::cout << "myVector size is : " << myVector.size() << std::endl;
			std::cout << "myVector capacity is : " << myVector.capacity() << std::endl;
			std::cout << AQUAMARINE2 << "resizing to 5 again" << RESET << std::endl;
			myVector.resize(5);
			for(size_t i = 0; i < myVector.size(); i++)
				std::cout << myVector[i] << " | ";
			std::cout << std::endl;
			std::cout << "myVector size is : " << myVector.size() << std::endl;
			std::cout << "myVector capacity is : " << myVector.capacity() << std::endl;
			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 15)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing vector::empty"
				<< RESET << std::endl << std::endl;

			std::cout << AQUAMARINE2 << "Creating std_vector with one element." << RESET << std::endl;
			vector<int> myVector(1, 5);
			std::cout << "Is empty? 1 for yes, 0 for no --> " << myVector.empty() << std::endl;
			std::cout << AQUAMARINE2 << "removing that element with pop_back()" << RESET << std::endl;
			myVector.pop_back();
			std::cout << "Is empty? 1 for yes, 0 for no --> " << myVector.empty() << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 16)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing at(), front() and back()"
				<< RESET << std::endl << std::endl;

			std::string init[] = {"another", "brick", "on", "the", "wall"};
			vector<std::string> pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << "In pinkFloyd  :";
			for (size_t i = 0; i < pinkFloyd.size(); i++)
				std::cout << pinkFloyd[i] << " | ";
			std::cout << std::endl;

			std::cout << "front() --> " << pinkFloyd.front() << std::endl;
			std::cout << "back() --> " << pinkFloyd.back() << std::endl;
			std::cout << "at(4) --> " << pinkFloyd.at(4) << std::endl;
			// std::cout << "at(5) --> " << pinkFloyd.at(5) << std::endl;
			// std::cout << "YOU SHOULD NOT SEE ME (0____0)";

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 17)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing push_back()"
				<< RESET << std::endl << std::endl;

			std::string init[] = {"another", "brick", "on", "the"};
			vector<std::string> pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << "------------------------------------------" << std::endl << std::endl;
			std::cout << "In pinkFloyd :";
			print_vector(pinkFloyd);
			std::cout << std::endl;
			std::cout << AQUAMARINE2 << "This is how pinkFloyd behaves : " << RESET << std::endl << std::endl;
			std::cout << "pinkFloyd size is : " << pinkFloyd.size() << std::endl;
			std::cout << "pinkFloyd capacity is : " << pinkFloyd.capacity() << std::endl << std::endl;
			std::cout << AQUAMARINE2 << "using push_back() --> " << RESET << std::endl;
			pinkFloyd.push_back("wall");
			print_vector(pinkFloyd);
			std::cout << std::endl;
			std::cout << "pinkFloyd size is : " << pinkFloyd.size() << std::endl;
			std::cout << "pinkFloyd capacity is : " << pinkFloyd.capacity() << std::endl << std::endl;

			std::cout << "------------------------------------------" << std::endl << std::endl;
			
			std::cout << AQUAMARINE2 << "Let's check how push_back() behaves when starting from an empty vector." << std::endl;
			
			vector<int> myVector(1, 5);
			myVector.pop_back();
			print_vector(myVector);
			myVector.push_back(42);
			print_vector(myVector);
			std::cout << "myVector size is : " << myVector.size() << std::endl;
			std::cout << "myVector capacity is : " << myVector.capacity() << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 18)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing insert() with one element"
				<< RESET << std::endl << std::endl;

			std::string init[] = {"another", "brick", "on", "the", "wall"};
			vector<std::string> pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			vector<std::string>::iterator ft_position = pinkFloyd.begin() + 2;
			pinkFloyd.insert(ft_position, "peanuts");
			print_vector(pinkFloyd);
			std::cout << "pinkFloyd size is : " << pinkFloyd.size() << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 19)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing insert() with n elements"
				<< RESET << std::endl << std::endl;

			std::string init[] = {"another", "brick", "on", "the", "wall"};
			vector<std::string> pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			vector<std::string>::iterator ft_position = pinkFloyd.begin() + 2;
			pinkFloyd.insert(ft_position, 3, "peanuts");
			print_vector(pinkFloyd);
			std::cout << "pinkFloyd size is : " << pinkFloyd.size() << std::endl;
			std::cout << "pinkFloyd capacity is : " << pinkFloyd.capacity() << std::endl << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 20)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing insert() with sequence"
				<< RESET << std::endl << std::endl;

			vector<int> myVector;
			myVector.push_back(1);
			myVector.push_back(2);
			myVector.push_back(3);
		
			vector<int> toInsert;
			toInsert.push_back(4);
			toInsert.push_back(5);
		
			vector<int>::iterator it = myVector.begin() + 1;

			myVector.insert(it, toInsert.begin(), toInsert.end());
			print_vector(myVector);

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 21)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing erase() with one element"
				<< RESET << std::endl << std::endl;
		
			std::string init[] = {"gonna", "make", "you", "groove"};
			vector<std::string> ft_ledzep(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << "In ft_ledzep : " << std::endl;
			print_vector(ft_ledzep);
			vector<std::string>::iterator ft_pos = ft_ledzep.begin() + 3;
			vector<std::string>::iterator output = ft_ledzep.erase(ft_pos);
			std::cout << ORANGERED1 << "In ft_ledzep : " << std::endl;
			print_vector(ft_ledzep);
			std::cout << RESET << std::endl;
			std::cout << "output = " << *output << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 22)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing erase() with sequence"
				<< RESET << std::endl << std::endl;
		
			std::string init[] = {"gonna", "make", "you", "groove"};
			vector<std::string> ft_ledzep(init, init + sizeof(init) / sizeof(init[0]));
			std::cout << "In ft_ledzep : " << std::endl;
			print_vector(ft_ledzep);
			vector<std::string>::iterator ft_first = ft_ledzep.begin() + 2;
			vector<std::string>::iterator ft_last = ft_ledzep.begin() + 4;
			vector<std::string>::iterator output = ft_ledzep.erase(ft_first, ft_last);
			std::cout << ORANGERED1 << "In ft_ledzep : " << std::endl;
			print_vector(ft_ledzep);
			std::cout << RESET << std::endl;
			std::cout << "output = " << *output << std::endl;
			std::cout << "ft_ledzep size is : " << ft_ledzep.size() << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 23)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing clear() function"
				<< RESET << std::endl << std::endl;
		
			int myInts[] = {1, 2, 3, 4, 5};
			vector<int> myVector(myInts, myInts + sizeof(myInts) / sizeof(myInts[0]));

			std::cout << "In myVector : " << std::endl;
			print_vector(myVector);
			std::cout << std::endl;
			myVector.clear();
			std::cout << "In myVector : " << std::endl;
			print_vector(myVector);
			std::cout << std::endl;
			std::cout << "myVector size is " << myVector.size() << std::endl;
			std::cout << "myVector capacity is " << myVector.capacity() << std::endl;


			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 24)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing assign() member function"
				<< RESET << std::endl << std::endl;
		
			int myInts[] = {1, 2, 3, 4, 5};
			vector<int> myVector(myInts, myInts + sizeof(myInts) / sizeof(myInts[0]));

			int toAssign[] = {42, 43, 44};

			vector<int> ft_toAssign(toAssign, toAssign + 3);
			vector<int>::iterator ft_first = ft_toAssign.begin() + 1;
			vector<int>::iterator ft_last = ft_toAssign.begin() + 3;
			std::cout << "In myVector : " << std::endl;
			print_vector(myVector);
			std::cout << std::endl;
			myVector.assign(ft_first, ft_last);
			std::cout << "In myVector : " << std::endl;
			print_vector(myVector);
			std::cout << std::endl;
			std::cout << "myVector size is " << myVector.size() << std::endl;
			std::cout << "myVector capacity is " << myVector.capacity() << std::endl;
			std::cout << std::endl;
			std::cout << CHARTREUSE5 << "Testing assign(n, val)" << RESET << std::endl;
			myVector.assign(0, 1);
			std::cout << "In myVector : " << std::endl;
			print_vector(myVector);
			std::cout << std::endl;
			std::cout << "myVector size is " << myVector.size() << std::endl;
			std::cout << "myVector capacity is " << myVector.capacity() << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 25)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing comparators"
				<< RESET << std::endl << std::endl;

			vector<int> ft_potatoes(4, 1);
			vector<int> ft_carrots(1, 1);

			std::cout << " ft_potatoes == ft_carrots : " << (ft_potatoes == ft_carrots) << std::endl;
			std::cout << " ft_potatoes < ft_carrots : " << (ft_potatoes < ft_carrots) << std::endl;
			std::cout << " ft_potatoes != ft_carrots : " << (ft_potatoes != ft_carrots) << std::endl;
			std::cout << " ft_potatoes > ft_carrots : " << (ft_potatoes > ft_carrots) << std::endl;
			std::cout << " ft_potatoes >= ft_carrots : " << (ft_potatoes >= ft_carrots) << std::endl;
			std::cout << " ft_potatoes <= ft_carrots : " << (ft_potatoes <= ft_carrots) << std::endl;
			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 26)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing pair and make_pair"
				<< RESET << std::endl << std::endl;
			
			pair<int, std::string> myPair(1, "Aie Aie");
			pair<int, std::string> myPair2(2, "Captain");

			std::cout << myPair.first << std::endl;
			std::cout << myPair.second << std::endl;

			std::cout << myPair2.first << std::endl;
			std::cout << myPair2.second << std::endl;

			std::cout << "myPair == myPair2 = " << (myPair == myPair2) << std::endl;
			std::cout << "myPair != myPair2 = " << (myPair != myPair2) << std::endl;
			std::cout << "myPair < myPair2 = " << (myPair < myPair2) << std::endl;
			std::cout << "myPair > myPair2 = " << (myPair > myPair2) << std::endl;
			std::cout << "myPair <= myPair2 = " << (myPair <= myPair2) << std::endl;
			std::cout << "myPair >= myPair2 = " << (myPair >= myPair2) << std::endl;

			std::cout << std::endl;

			pair<int, std::string> bilbo = make_pair<int, std::string>(42, "what's up");

			std::cout << bilbo.first << std::endl;
			std::cout << bilbo.second << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 27)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing max_size()"
				<< RESET << std::endl << std::endl;

			vector<int> kirikou;
			std::cout << "kirikou = " << kirikou.max_size() << std::endl;
			
			// std::vector<int> karaba;
			// std::cout << "karaba  = " << karaba.max_size() << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 28)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing swap_main"
				<< RESET << std::endl << std::endl;
		
			vector<std::string> bob(3, "what's up");
			print_vector(bob, "bob");

			bob.insert(bob.begin(), 0, "");
			print_vector(bob, "bob");

			vector<std::string> bobby(3, "what's up");
			print_vector(bobby, "bobby");

			bobby.insert(bobby.begin(), 0, "");
			print_vector(bobby, "bobby");

			vector<int> louis(2, 7000);
			print_vector(louis, "louis");
			louis.insert(louis.begin(), 0, 56);

			vector<int> louison(2, 7000);
			print_vector(louison, "louison");
			louison.insert(louison.begin(), 0, 56);

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 29)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing push_back"
				<< RESET << std::endl << std::endl;
			
			vector<std::string> one(2, "one");
			vector<std::string> two(5, "two");
			for (size_t i = 0; i < 15; i++)
				two.push_back("heey");
			print_vector(two, "two");

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 30)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing "
				<< RESET << std::endl << std::endl;
			
			vector<int> gandalf(10, 10);
			vector<int> frodo(3, 4);
			print_vector(gandalf);
			print_vector(frodo);
			frodo = gandalf;
			print_vector(frodo);
			

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 31)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "--"
				<< RESET << std::endl << std::endl;

			std::cout << std::endl;
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

// int main()
// {
// 	for (int n = 0; n < 30; n++)
// 		execute_tests_vector(n);
// }