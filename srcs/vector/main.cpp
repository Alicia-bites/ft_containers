#include "vector.hpp"
#include "../../cool_tools/colors/colors.hpp"
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
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;
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