#include "vector.hpp"
#include <string>
#include <algorithm>

#include <vector>

// void	exit_if_EOF_detected()
// {
// 	if (!std::cin)
// 	{
// 		std::cout << "failure\n";
// 		exit(-1);
// 	}
// }

template <typename T>
	void	print_vector(T vector)
	{
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " | ";
		std::cout << std::endl;
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
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;

			std::vector<int>	std_vector;
			ft::vector<int>		ft_vector;
			std::cout << MEDIUMORCHID3 << sizeof(std_vector) << RESET << std::endl;
			std::cout << MEDIUMPURPLE << sizeof(ft_vector) << RESET << std::endl;


			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 2)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing empty container constructor and fill constructor" 
				<< RESET << std::endl << std::endl;

			std::vector<int> std_vector_0 (4);
			std::cout << "Printing content of std_vector_0 :" << std::endl;
			std::cout << "- START -" << std::endl;
			for (size_t i = 0; i < std_vector_0.size(); ++i)
    			std::cout << i << " : " << std_vector_0[i] << std::endl;
			std::cout << "- END -" << std::endl;

			ft::vector<int> ft_vector_0 (4);
			std::cout << "Printing content of ft_vector_0 :" << std::endl;
			std::cout << "- START -" << std::endl;
			for (size_t i = 0; i < ft_vector_0.size(); ++i)
    			std::cout << i << " : " << ft_vector_0[i] << std::endl;
			std::cout << "- END -" << std::endl;

			std::vector<int> std_vector (4, 6);
			ft::vector<int> ft_vector (4, 6);
			
			std::cout << "Printing content of std_vector :" << std::endl;
			std::cout << "- START -" << std::endl;
			for (size_t i = 0; i < std_vector.size(); ++i)
    			std::cout << i << " : " << std_vector[i] << std::endl;
			std::cout << "- END -" << std::endl;
			
			std::cout << "Printing content of ft_vector :" << std::endl;
			std::cout << "- START -" << std::endl;
			for (size_t i = 0; i < ft_vector.size(); ++i)
    			std::cout << i << " : " << ft_vector[i] << std::endl;
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
			std::cout << "Constructing a vector with range using vectors" << std::endl;
			int myints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			std::vector<int> std_vector (myints, myints+10);
			std::cout << "Printing content of std_vector :" << std::endl;
			for (size_t i = 0; i < std_vector.size(); ++i)
    			std::cout << std_vector[i] << std::endl;
			std::cout << std::endl;

			ft::vector<int> ft_vector(myints, myints+10);
			std::cout << "Printing content of ft_vector :" << std::endl;
			for (size_t i = 0; i < ft_vector.size(); ++i)
    			std::cout << ft_vector[i] << std::endl;
			std::cout << std::endl;

			std::cout << "Constructing a vector with range using iterators" << std::endl;
			ft::vector<int> ft_vector_it_test (std_vector.begin(), std_vector.end());
			std::cout << "Printing content of ft_vector_it_test :" << std::endl;
			for (size_t i = 0; i < ft_vector_it_test.size(); ++i)
    			std::cout << ft_vector_it_test[i] << std::endl;
			std::cout << std::endl;

			std::cout << "Constructing a vector with range using front() and end()" << std::endl;
			std::vector<int> gandalf (std_vector.front(), std_vector.back());
			std::cout << "Printing content of gandalf :" << std::endl;
			for (size_t i = 0; i < gandalf.size(); ++i)
    			std::cout << gandalf[i] << std::endl;
			
			ft::vector<int> frodo (std_vector.front(), std_vector.back());
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
			ft::vector<int> ft_vector(myints, myints+10);
			std::cout << "Printing content of ft_vector " << std::endl;
			for (size_t i = 0; i < ft_vector.size(); ++i)
				std::cout << ft_vector[i] << std::endl;
			std::cout << "Creating a copy of ft_vector..." << std::endl;
			ft::vector<int> copy_ft_vector (ft_vector);
			std::cout << "Printing content of copy_ft_vector :" << std::endl;
			for (size_t i = 0; i < copy_ft_vector.size(); i++)
				std::cout << copy_ft_vector[i] << std::endl;
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
			ft::vector<int> gandalf(uneven_ints, uneven_ints+3);
			int even_ints[] = {2, 4, 6};
			ft::vector<int> galadriel(even_ints, even_ints+3);
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
			ft::vector<int> gandalf(uneven_ints, uneven_ints+3);
			int even_ints[] = {2, 4, 6};
			ft::vector<int> galadriel(even_ints, even_ints+3);
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
			ft::vector<int> gandalf(bigger, bigger+3);
			int smaller[] = {2};
			ft::vector<int> galadriel(smaller, smaller+1);
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
			ft::vector<int> gandalf(smaller, smaller+1);
			ft::vector<int> galadriel(bigger, bigger+3);
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
			std::cout << STEELBLUE3 << "Testing ft::vector::assign, with 2 vectors of the same size" 
				<< RESET << std::endl << std::endl;

			int uneven_ints[] = {1, 3, 5};
			int even_ints[] = {2, 4, 6};

			ft::vector<int> gandalf(uneven_ints, uneven_ints+3);
			ft::vector<int> galadriel(even_ints, even_ints+3);

			std::vector<int> sauron(uneven_ints, uneven_ints+3);
			std::vector<int> saruman(even_ints, even_ints+3);

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
			std::cout << STEELBLUE3 << "Testing ft::vector::iterator" 
				<< RESET << std::endl << std::endl;

			int myints[] = {1, 3, 5};

			std::vector<int> std_vector(myints, myints+3);
			ft::vector<int> ft_vector(myints, myints+3);

			std::vector<int>::iterator std_it;
			std_it = std_vector.begin();
			std::cout << "std : " << *std_it << std::endl;

			ft::vector<int>::iterator ft_it;
			ft_it = ft_vector.begin();
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			std_it = std_vector.end();
			std::cout << "std : " << *std_it << std::endl;

			ft_it = ft_vector.end();
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			std_it = std_vector.begin() + 1;
			std::cout << "std : " << *std_it << std::endl;

			ft_it = ft_vector.begin() + 1;
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			std_it = std_vector.end() - 2;
			std::cout << "std : " << *std_it << std::endl;

			ft_it = ft_vector.end() - 2;
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			std_it = std_vector.end()--;
			std::cout << "std : " << *std_it << std::endl;

			ft_it = ft_vector.end()--;
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			std_it = --std_vector.end();
			std::cout << "std : " << *std_it << std::endl;

			ft_it = --ft_vector.end();
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			std_it = std_vector.begin()++;
			std::cout << "std : " << *std_it << std::endl;

			ft_it = ft_vector.begin()++;
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			std_it = ++std_vector.begin();
			std::cout << "std : " << *std_it << std::endl;

			ft_it = ++ft_vector.begin();
			std::cout << "ft  : " << *ft_it << std::endl << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 11)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing ft::reverse_iterator" 
				<< RESET << std::endl << std::endl;

			std::cout << "Testing that ft::reverse_iterator correctly iterates over a container in reverse order." << std::endl;
			int myints[] = { 1, 2, 3, 4, 5 };
			std::vector<int> v(myints, myints+5);

			ft::reverse_iterator<std::vector<int>::iterator> it(v.end());
			
			for (int i = 5; i > 0; --i)
			{
				std::cout << "*it = " << *it << std::endl;
				std::cout << "i  = " << i << std::endl;
				++it;
			}
			std::cout << std::endl;

			std::cout << "Testing that the reverse_iterator supports comparison with the == operator" << std::endl;
			ft::reverse_iterator<std::vector<int>::iterator> it1(v.end());
			ft::reverse_iterator<std::vector<int>::iterator> it2(v.end());
			int res = it1 == it2;
			std::cout << "Is it1 == to it2 ? 1 for yes, 0 for no. --> " << std::endl;
			std::cout << "ANSWER = " << res << std::endl;
			std::cout << std::endl;

			std::cout << "Testing that the reverse_iterator supports the + and - operators for arithmetic operations" << std::endl;
			ft::reverse_iterator<std::vector<int>::iterator> it3(v.end());
			ft::reverse_iterator<std::vector<int>::iterator> it4 = it3 + 2;
			std:: cout << "*it4 + 2 --> *it4 should be equal to 3"
				<< std::endl << " *it4 = " << *it4 << std::endl;
			it4 = it4 - 1;
			std:: cout << "it4 = it4 - 1 --> *it4 should be equal to 4"
				<< std::endl << " *it4 = " << *it4 << std::endl;
			std::cout << std::endl;

			std::cout << "Testing that the reverse_iterator supports the < operator for comparison" << std::endl;
			ft::reverse_iterator<std::vector<int>::iterator> it5(v.end());
			ft::reverse_iterator<std::vector<int>::iterator> it6 = it5 + 2;
			std::cout << "*it5 is pointing at the last element" << std::endl;
			std::cout << "it6 is it5 + 2 " << std::endl;
			std::cout << " Is it5 < it6 ? The answer should be 1 --> " << (it5 < it6) << std::endl;
			std::cout << std::endl;

			std::cout << "Testing that the reverse_iterator works correctly with the [] operator" << std::endl;
			ft::reverse_iterator<std::vector<int>::iterator> it7(v.end());
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
			ft::vector<std::string> pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));
			std::vector<std::string> std_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			ft::vector<std::string>::reverse_iterator rit = pinkFloyd.rbegin();
			std::cout << "rit is : " << *rit << std::endl;
			std::cout << "rit + 1 is : " << *(rit + 1) << std::endl;
			ft::vector<std::string>::reverse_iterator rit_rend = pinkFloyd.rend();
			std::cout << "rit_rend - 1 is : " << *(rit_rend - 1) << std::endl;

			std::cout << std::endl;
			
			std::vector<std::string>::reverse_iterator std_rit = std_pinkFloyd.rbegin();
			std::cout << "std_rit is : " << *std_rit << std::endl;
			std::cout << "std_rit + 1 is : " << *(std_rit + 1) << std::endl;
			std::vector<std::string>::reverse_iterator std_rit_rend = std_pinkFloyd.rend();
			std::cout << "std_rit_rend - 1 is : " << *(std_rit_rend - 1) << std::endl;

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 13)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing ft::vector::size and ft::vector::capacity" 
				<< RESET << std::endl << std::endl;

			std::string init[] = {"another","brick","on", "the", "wall"};
			ft::vector<std::string> ft_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));
			std::vector<std::string> std_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << "In ft_pinkFloyd : " << std::endl;
			for(size_t i = 0; i <= 4; i++)
				std::cout << ft_pinkFloyd[i] << " | ";
			std::cout << std::endl;

			std::cout << "In std_pinkFloyd : " << std::endl;
			for(size_t i = 0; i <= 4; i++)
				std::cout << ft_pinkFloyd[i] << " | ";
			std::cout << std::endl;

			std::cout << "std_pinkFloyd.size() = " << std_pinkFloyd.size() << std::endl;
			std::cout << "ft_pinkFloyd.size() = " << ft_pinkFloyd.size() << std::endl;

			std::cout << "std_pinkFloyd.capacity() = " << std_pinkFloyd.capacity() << std::endl;
			std::cout << "ft_pinkFloyd.capacity() = " << ft_pinkFloyd.capacity() << std::endl;

			std::cout << "---------------------------------------------------" << std::endl;

			std::vector<int> std_gandalf(10);
			std::cout << "In std_gandalf : " << std::endl;
			for(size_t i = 0; i < std_gandalf.size(); i++)
				std::cout << std_gandalf[i] << " | ";
			std::cout << std::endl;
			std_gandalf.push_back(2);
			std_gandalf.push_back(3);
			std_gandalf.push_back(4);
			std::cout << "std_gandalf size is : " << std_gandalf.size() << std::endl;
			std::cout << "std_gandalf capacity is : " << std_gandalf.capacity() << std::endl;


			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}
		if (test_number == 14)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing ft::vector::resize and ft::vector::reserve" 
				<< RESET << std::endl << std::endl;

			std::vector<int> std_vector(10, 1);
			std::cout << "In std_vector : " << std::endl;
			for(size_t i = 0; i < std_vector.size(); i++)
				std::cout << std_vector[i] << " | ";
			std::cout << std::endl;
			std::cout << AQUAMARINE2 << "resizing to 15" << RESET << std::endl;
			std_vector.resize(15);
			std::cout << "In std_vector : " << std::endl;
			for(size_t i = 0; i < std_vector.size(); i++)
				std::cout << std_vector[i] << " | ";
			std::cout << std::endl;
			std::cout << "std_vector size is : " << std_vector.size() << std::endl;
			std::cout << "std_vector capacity is : " << std_vector.capacity() << std::endl;
			std::cout << AQUAMARINE2 << "resizing to 5" << RESET << std::endl;
			std_vector.resize(5);
			for(size_t i = 0; i < std_vector.size(); i++)
				std::cout << std_vector[i] << " | ";
			std::cout << std::endl;
			std::cout << "std_vector size is : " << std_vector.size() << std::endl;
			std::cout << "std_vector capacity is : " << std_vector.capacity() << std::endl;
			std::cout << AQUAMARINE2 << "resizing to 5 again" << RESET << std::endl;
			std_vector.resize(5);
			for(size_t i = 0; i < std_vector.size(); i++)
				std::cout << std_vector[i] << " | ";
			std::cout << std::endl;
			std::cout << "std_vector size is : " << std_vector.size() << std::endl;
			std::cout << "std_vector capacity is : " << std_vector.capacity() << std::endl;

			std::cout << std::endl;

			ft::vector<int> ft_vector(10, 1);
			std::cout << "In ft_vector : " << std::endl;
			for(size_t i = 0; i < ft_vector.size(); i++)
				std::cout << ft_vector[i] << " | ";
			std::cout << std::endl;
			std::cout << AQUAMARINE2 << "resizing to 15" << RESET << std::endl;
			ft_vector.resize(15);
			std::cout << "In ft_vector : " << std::endl;
			for(size_t i = 0; i < ft_vector.size(); i++)
				std::cout << ft_vector[i] << " | ";
			std::cout << std::endl;
			std::cout << "ft_vector size is : " << ft_vector.size() << std::endl;
			std::cout << "ft_vector capacity is : " << ft_vector.capacity() << std::endl;
			std::cout << AQUAMARINE2 << "resizing to 5" << RESET << std::endl;
			ft_vector.resize(5);
			for(size_t i = 0; i < ft_vector.size(); i++)
				std::cout << ft_vector[i] << " | ";
			std::cout << std::endl;
			std::cout << "ft_vector size is : " << ft_vector.size() << std::endl;
			std::cout << "ft_vector capacity is : " << ft_vector.capacity() << std::endl;
			std::cout << AQUAMARINE2 << "resizing to 5 again" << RESET << std::endl;
			ft_vector.resize(5);
			for(size_t i = 0; i < ft_vector.size(); i++)
				std::cout << ft_vector[i] << " | ";
			std::cout << std::endl;
			std::cout << "ft_vector size is : " << ft_vector.size() << std::endl;
			std::cout << "ft_vector capacity is : " << ft_vector.capacity() << std::endl;
			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 15)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing ft::vector::empty"
				<< RESET << std::endl << std::endl;

			std::cout << AQUAMARINE2 << "Creating std_vector with one element." << RESET << std::endl;
			std::vector<int> std_vector(1, 5);
			std::cout << "Is empty? 1 for yes, 0 for no --> " << std_vector.empty() << std::endl;
			std::cout << AQUAMARINE2 << "removing that element with pop_back()" << RESET << std::endl;
			std_vector.pop_back();
			std::cout << "Is empty? 1 for yes, 0 for no --> " << std_vector.empty()  << std::endl;

			std::cout << AQUAMARINE2 << "Creating std_vector with one element." << RESET << std::endl;
			ft::vector<int> ft_vector(1, 5);
			std::cout << "Is empty? 1 for yes, 0 for no --> " << ft_vector.empty() << std::endl;
			std::cout << AQUAMARINE2 << "removing that element with pop_back()" << RESET << std::endl;
			ft_vector.pop_back();
			std::cout << "Is empty? 1 for yes, 0 for no --> " << ft_vector.empty() << std::endl;

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
			ft::vector<std::string> ft_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));
			std::vector<std::string> std_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << "In std_pinkFloyd :";
			for (size_t i = 0; i < std_pinkFloyd.size(); i++)
				std::cout << std_pinkFloyd[i] << " | ";
			std::cout << std::endl;

			std::cout << "In ft_pinkFloyd  :";
			for (size_t i = 0; i < ft_pinkFloyd.size(); i++)
				std::cout << ft_pinkFloyd[i] << " | ";
			std::cout << std::endl;

			std::cout << std::endl;

			std::cout << AQUAMARINE2 << "This is how std_vector behaves : " << RESET << std::endl;
			std::cout << "front() --> " << std_pinkFloyd.front() << std::endl;
			std::cout << "back() --> " << std_pinkFloyd.back() << std::endl;
			std::cout << "at(4) --> " << std_pinkFloyd.at(4) << std::endl;
			// std::cout << "at(5) --> " << std_pinkFloyd.at(5) << std::endl;
			std::cout << std::endl;

			std::cout << AQUAMARINE2 << "Let's see for our ft_vector now : " << RESET << std::endl;
			std::cout << "front() --> " << ft_pinkFloyd.front() << std::endl;
			std::cout << "back() --> " << ft_pinkFloyd.back() << std::endl;
			std::cout << "at(4) --> " << ft_pinkFloyd.at(4) << std::endl;
			std::cout << "at(5) --> " << ft_pinkFloyd.at(5) << std::endl;
			std::cout << "YOU SHOULD NOT SEE ME (0____0)";

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
			ft::vector<std::string> ft_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));
			std::vector<std::string> std_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << "In std_pinkFloyd :";
			print_vector(std_pinkFloyd);
			std::cout << std::endl;
			std::cout << AQUAMARINE2 << "This is how std_pinkFloyd behaves : " << RESET << std::endl << std::endl;
			std::cout << "std_pinkFloyd size is : " << std_pinkFloyd.size() << std::endl;
			std::cout << "std_pinkFloyd capacity is : " << std_pinkFloyd.capacity() << std::endl << std::endl;
			std::cout << AQUAMARINE2 << "using push_back() --> " << RESET << std::endl;
			std_pinkFloyd.push_back("wall");
			print_vector(std_pinkFloyd);
			std::cout << std::endl;
			std::cout << "std_pinkFloyd size is : " << std_pinkFloyd.size() << std::endl;
			std::cout << "std_pinkFloyd capacity is : " << std_pinkFloyd.capacity() << std::endl << std::endl;

			std::cout << "------------------------------------------" << std::endl << std::endl;
			std::cout << "In ft_pinkFloyd :";
			print_vector(ft_pinkFloyd);
			std::cout << std::endl;
			std::cout << AQUAMARINE2 << "This is how ft_pinkFloyd behaves : " << RESET << std::endl << std::endl;
			std::cout << "ft_pinkFloyd size is : " << ft_pinkFloyd.size() << std::endl;
			std::cout << "ft_pinkFloyd capacity is : " << ft_pinkFloyd.capacity() << std::endl << std::endl;
			std::cout << AQUAMARINE2 << "using push_back() --> " << RESET << std::endl;
			ft_pinkFloyd.push_back("wall");
			print_vector(ft_pinkFloyd);
			std::cout << std::endl;
			std::cout << "ft_pinkFloyd size is : " << ft_pinkFloyd.size() << std::endl;
			std::cout << "ft_pinkFloyd capacity is : " << ft_pinkFloyd.capacity() << std::endl << std::endl;

			std::cout << "------------------------------------------" << std::endl << std::endl;
			
			std::cout << AQUAMARINE2 << "Let's check how push_back() behaves when starting from an empty vector." << std::endl;

			std::cout << AQUAMARINE2 << "This is how std_pinkFloyd behaves : " << RESET << std::endl;
			std::vector<int> std_vector(1, 5);
			std_vector.pop_back();
			std::cout << "In std_pinkFloyd :";
			print_vector(std_vector);
			std::cout << "In std_pinkFloyd :";
			std_vector.push_back(42);
			print_vector(std_vector);
			std::cout << "std_vector size is : " << std_vector.size() << std::endl;
			std::cout << "std_vector capacity is : " << std_vector.capacity() << std::endl << std::endl;
			
			std::cout << AQUAMARINE2 << "This is how ft_pinkFloyd behaves : " << RESET << std::endl;
			ft::vector<int> ft_vector(1, 5);
			ft_vector.pop_back();
			std::cout << "In ft_pinkFloyd :";
			print_vector(ft_vector);
			ft_vector.push_back(42);
			std::cout << "In ft_pinkFloyd :";
			print_vector(ft_vector);
			std::cout << "ft_vector size is : " << ft_vector.size() << std::endl;
			std::cout << "ft_vector capacity is : " << ft_vector.capacity() << std::endl;

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
			ft::vector<std::string> ft_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));
			std::vector<std::string> std_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << AQUAMARINE2 << "This is how std_pinkFloyd behaves :" << RESET << std::endl;
			std::vector<std::string>::iterator std_position = std_pinkFloyd.begin() + 2;
			std_pinkFloyd.insert(std_position, "peanuts");
			print_vector(std_pinkFloyd);
			std::cout << "std_pinkFloyd size is : " << std_pinkFloyd.size() << std::endl;
			std::cout << "std_pinkFloyd capacity is : " << std_pinkFloyd.capacity() << std::endl << std::endl;

			std::cout << std::endl;

			std::cout << AQUAMARINE2 << "This is how ft_pinkFloyd behaves :" << RESET << std::endl;
			ft::vector<std::string>::iterator ft_position = ft_pinkFloyd.begin() + 2;
			ft_pinkFloyd.insert(ft_position, "peanuts");
			print_vector(ft_pinkFloyd);
			std::cout << "ft_pinkFloyd size is : " << ft_pinkFloyd.size() << std::endl;
			std::cout << "ft_pinkFloyd capacity is : " << ft_pinkFloyd.capacity() << std::endl << std::endl;


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
			ft::vector<std::string> ft_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));
			std::vector<std::string> std_pinkFloyd(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << AQUAMARINE2 << "This is how std_pinkFloyd behaves :" << RESET << std::endl;
			std::vector<std::string>::iterator std_position = std_pinkFloyd.begin() + 2;
			std_pinkFloyd.insert(std_position, 3, "peanuts");
			print_vector(std_pinkFloyd);
			std::cout << "std_pinkFloyd size is : " << std_pinkFloyd.size() << std::endl;
			std::cout << "std_pinkFloyd capacity is : " << std_pinkFloyd.capacity() << std::endl << std::endl;

			std::cout << std::endl;

			std::cout << AQUAMARINE2 << "This is how ft_pinkFloyd behaves :" << RESET << std::endl;
			ft::vector<std::string>::iterator ft_position = ft_pinkFloyd.begin() + 2;
			ft_pinkFloyd.insert(ft_position, 3, "peanuts");
			print_vector(ft_pinkFloyd);
			std::cout << "ft_pinkFloyd size is : " << ft_pinkFloyd.size() << std::endl;
			std::cout << "ft_pinkFloyd capacity is : " << ft_pinkFloyd.capacity() << std::endl << std::endl;

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
		

			std::cout << AQUAMARINE2 << "This is how std_vector behaves : " << RESET << std::endl;
			std::vector<int> std_vector;
			std_vector.push_back(1);
			std_vector.push_back(2);
			std_vector.push_back(3);
		
			std::vector<int> std_toInsert;
			std_toInsert.push_back(4);
			std_toInsert.push_back(5);
		
			std::vector<int>::iterator std_it = std_vector.begin() + 1;
			std_vector.insert(std_it, std_toInsert.begin(), std_toInsert.end());
			print_vector(std_vector);
			
			std::cout << std::endl;

			std::cout << AQUAMARINE2 << "This is how ft_vector behaves :" << RESET << std::endl;
			ft::vector<int> ft_vector;
			ft_vector.push_back(1);
			ft_vector.push_back(2);
			ft_vector.push_back(3);
		
			ft::vector<int> toInsert;
			toInsert.push_back(4);
			toInsert.push_back(5);
		
			ft::vector<int>::iterator it = ft_vector.begin() + 1;

			ft_vector.insert(it, toInsert.begin(), toInsert.end());
			print_vector(ft_vector);

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
			ft::vector<std::string> ft_ledzep(init, init + sizeof(init) / sizeof(init[0]));
			std::vector<std::string> std_ledzep(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << "In std_ledzep : " << std::endl;
			print_vector(std_ledzep);
			std::vector<std::string>::iterator std_pos = std_ledzep.begin() + 3;
			std::vector<std::string>::iterator std_output = std_ledzep.erase(std_pos);
			std::cout << ORANGERED1 << "In std_ledzep : " << std::endl;
			print_vector(std_ledzep);
			std::cout << RESET << std::endl;
			std::cout << "std_output = " << *std_output << std::endl;

			std::cout << std::endl;

			std::cout << "In ft_ledzep : " << std::endl;
			print_vector(ft_ledzep);
			ft::vector<std::string>::iterator ft_pos = ft_ledzep.begin() + 3;
			ft::vector<std::string>::iterator output = ft_ledzep.erase(ft_pos);
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
			ft::vector<std::string> ft_ledzep(init, init + sizeof(init) / sizeof(init[0]));
			std::vector<std::string> std_ledzep(init, init + sizeof(init) / sizeof(init[0]));

			std::cout << "In std_ledzep : " << std::endl;
			print_vector(std_ledzep);
			std::vector<std::string>::iterator std_first = std_ledzep.begin() + 2;
			std::vector<std::string>::iterator std_last = std_ledzep.begin() + 4;
			std::vector<std::string>::iterator std_output = std_ledzep.erase(std_first, std_last);
			std::cout << ORANGERED1 << "In ft_ledzep : " << std::endl;
			print_vector(std_ledzep);
			std::cout << RESET << std::endl;
			std::cout << "std_output = " << *std_output << std::endl;
			std::cout << "std_ledzep size is : " << std_ledzep.size() << std::endl;

			std::cout << std::endl;

			std::cout << "In ft_ledzep : " << std::endl;
			print_vector(ft_ledzep);
			ft::vector<std::string>::iterator ft_first = ft_ledzep.begin() + 2;
			ft::vector<std::string>::iterator ft_last = ft_ledzep.begin() + 4;
			ft::vector<std::string>::iterator output = ft_ledzep.erase(ft_first, ft_last);
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
			ft::vector<int> ft_vector(myInts, myInts + sizeof(myInts) / sizeof(myInts[0]));
			std::vector<int> std_vector(myInts, myInts + sizeof(myInts) / sizeof(myInts[0]));

			std::cout << "In std_vector : " << std::endl;
			print_vector(std_vector);
			std::cout << std::endl;
			std_vector.clear();
			std::cout << "In std_vector : " << std::endl;
			print_vector(std_vector);
			std::cout << std::endl;
			std::cout << "std_vector size is " << std_vector.size() << std::endl;
			std::cout << "std_vector capacity is " << std_vector.capacity() << std::endl;

			std::cout << std::endl;

			std::cout << "In ft_vector : " << std::endl;
			print_vector(ft_vector);
			std::cout << std::endl;
			ft_vector.clear();
			std::cout << "In ft_vector : " << std::endl;
			print_vector(ft_vector);
			std::cout << std::endl;
			std::cout << "ft_vector size is " << ft_vector.size() << std::endl;
			std::cout << "ft_vector capacity is " << ft_vector.capacity() << std::endl;


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
			ft::vector<int> ft_vector(myInts, myInts + sizeof(myInts) / sizeof(myInts[0]));
			std::vector<int> std_vector(myInts, myInts + sizeof(myInts) / sizeof(myInts[0]));

			int toAssign[] = {42, 43, 44};

			std::vector<int> std_toAssign(toAssign, toAssign + 3);
			std::vector<int>::iterator std_first = std_toAssign.begin() + 1;
			std::vector<int>::iterator std_last = std_toAssign.begin() + 3;
			std::cout << "In std_vector : " << std::endl;
			print_vector(std_vector);
			std::cout << std::endl;
			std_vector.assign(std_first, std_last);
			std::cout << "In std_vector : " << std::endl;
			print_vector(std_vector);
			std::cout << std::endl;
			std::cout << "std_vector size is " << std_vector.size() << std::endl;
			std::cout << "std_vector capacity is " << std_vector.capacity() << std::endl;
			std::cout << std::endl;
			std::cout << CHARTREUSE5 << "Testing assign(n, val)"<< RESET << std::endl;
			std_vector.assign(0, 1);
			std::cout << "In std_vector : " << std::endl;
			print_vector(std_vector);
			std::cout << std::endl;
			std::cout << "std_vector size is " << std_vector.size() << std::endl;
			std::cout << "std_vector capacity is " << std_vector.capacity() << std::endl;

			std::cout << std::endl;

			ft::vector<int> ft_toAssign(toAssign, toAssign + 3);
			ft::vector<int>::iterator ft_first = ft_toAssign.begin() + 1;
			ft::vector<int>::iterator ft_last = ft_toAssign.begin() + 3;
			std::cout << "In ft_vector : " << std::endl;
			print_vector(ft_vector);
			std::cout << std::endl;
			ft_vector.assign(ft_first, ft_last);
			std::cout << "In ft_vector : " << std::endl;
			print_vector(ft_vector);
			std::cout << std::endl;
			std::cout << "ft_vector size is " << ft_vector.size() << std::endl;
			std::cout << "ft_vector capacity is " << ft_vector.capacity() << std::endl;
			std::cout << std::endl;
			std::cout << CHARTREUSE5 << "Testing assign(n, val)" << RESET << std::endl;
			ft_vector.assign(0, 1);
			std::cout << "In ft_vector : " << std::endl;
			print_vector(ft_vector);
			std::cout << std::endl;
			std::cout << "ft_vector size is " << ft_vector.size() << std::endl;
			std::cout << "ft_vector capacity is " << ft_vector.capacity() << std::endl;

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

			std::vector<int> std_potatoes(4, 1);
			std::vector<int> std_carrots(1, 1);

			std::cout << " std_potatoes == std_carrots : " << (std_potatoes == std_carrots) << std::endl;
			std::cout << " std_potatoes < std_carrots : " << (std_potatoes < std_carrots) << std::endl;
			std::cout << " std_potatoes != std_carrots : " << (std_potatoes != std_carrots) << std::endl;
			std::cout << " std_potatoes > std_carrots : " << (std_potatoes > std_carrots) << std::endl;
			std::cout << " std_potatoes >= std_carrots : " << (std_potatoes >= std_carrots) << std::endl;
			std::cout << " std_potatoes <= std_carrots : " << (std_potatoes <= std_carrots) << std::endl;

			std::cout << std::endl << CHARTREUSE5 << "Now, our ft::vector --> " << std::endl;
			ft::vector<int> ft_potatoes(4, 1);
			ft::vector<int> ft_carrots(1, 1);

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
			std::cout << STEELBLUE3 << "Testing "
				<< RESET << std::endl << std::endl;
		


			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 27)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing "
				<< RESET << std::endl << std::endl;
		

			std::cout << std::endl;
			std::cout << std::endl << STEELBLUE2
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 28)
		{
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing "
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