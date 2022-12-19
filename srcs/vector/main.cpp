#include "vector.hpp"

#include <vector>
#include <stdlib.h>

int main(int argc, char **argv)
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
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << RESET;
			std::cout << DODGERBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;

			std::vector<int>	std_vector;
			ft::vector<int>		ft_vector;
			std::cout << OLIVE << sizeof(std_vector) << RESET << std::endl;
			std::cout << ORANGE1 << sizeof(ft_vector) << RESET << std::endl;


			std::cout << std::endl << DODGERBLUE1
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 2)
		{
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;
			std::cout << DODGERBLUE3 << "Testing param1 constructor and param 2 constructor" 
				<< RESET << std::endl << std::endl;

			std::vector<char> std_vector_0 (4);
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
			std::cout << std::endl << DODGERBLUE1
			<< "#########################################################"
			<< std::endl << RESET;
		}

		if (test_number == 3)
		{
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;

			int myints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			std::vector<int> std_vector (myints, myints+10);
			std::cout << "Printing content of std_vector :" << std::endl;
			for (size_t i = 0; i < std_vector.size(); ++i)
    		std::cout << std_vector[i] << ' ' << std::endl;

			std::cout << std::endl << DODGERBLUE1
			<< "#########################################################"
			<< std::endl << RESET;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	return 0;
}