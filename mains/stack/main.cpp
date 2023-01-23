
#include "stack.hpp"
#include "../../tools/colors/colors.hpp"
#include <stack>
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
			std::cout << "Creating two empty stacks..." << std::endl;
			std::stack<int>	std_stack;
			ft::stack<int>	ft_stack;
	
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;
	
			std::cout << GREEN3 << "Testing .empty() --> " << std::endl << RESET;
			std::cout << OLIVE << "std_stack returns : ";
			std::cout << std_stack.empty() << std::endl << RESET;
			std::cout << ORANGE1 << "ft_stack returns : ";
			std::cout << ft_stack.empty() << std::endl << RESET;
			std::cout << std::endl << DODGERBLUE1
				<< "#########################################################"
				<< std::endl << RESET;
		}
		if (test_number == 2)
		{
			std::stack<int>	std_stack;
			ft::stack<int>	ft_stack;
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;

			std::cout << GREEN3 << "Testing .size() --> " << std::endl << RESET;
			std::cout << OLIVE << "std_stack returns : ";
			std::cout << std_stack.size() << std::endl << RESET;
			std::cout << ORANGE1 << "ft_stack returns : ";
			std::cout << ft_stack.size() << std::endl << RESET;
			std::cout << std::endl << DODGERBLUE1
				<< "#########################################################"
				<< std::endl << RESET;
		}
		if (test_number == 3)
		{
			std::stack<int>	std_stack;
			ft::stack<int>	ft_stack;
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;
	
			std::cout << GREEN3 << "Testing .push() and .top() --> " << std::endl << RESET;
			std::cout << OLIVE << "std_stack returns : ";
			std_stack.push(3);
			std::cout << std_stack.top() << std::endl << RESET;
			ft_stack.push(3);
			std::cout << ORANGE1 << "ft_stack returns : ";
			std::cout << ft_stack.top() << std::endl << RESET;
			std::cout << std::endl << DODGERBLUE1
				<< "#########################################################"
				<< std::endl << RESET;
		}
		if (test_number == 4)
		{
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;

			std::cout << "Creating two containers stack with 'vector' as underlying container."
					<< " The vector's name is 'gandalf' and it contains 2 elements of type "
					<< "'int' and of value '4'..." << std::endl;
			std::vector<int> gandalf(2, 4);
			std::stack<int, std::vector<int> >	std_stack(gandalf);
			ft::stack<int>	ft_stack(gandalf);
			std::cout << std::endl;
			std::cout << "Pushing 1 element of value 1." << std::endl;
			std::cout << OLIVE << "std_stack returns : ";
			std_stack.push(1);
			std::cout << std_stack.top() << std::endl << RESET;
			ft_stack.push(1);
			std::cout << ORANGE1 << "ft_stack returns : ";
			std::cout << ft_stack.top() << std::endl << RESET;
			std::cout << std::endl;
			std::cout << GREEN3 << "Testing .pop() --> " << std::endl << RESET;
			std::cout << OLIVE << "std_stack returns : ";
			std_stack.pop();
			std::cout << std_stack.top() << std::endl << RESET;
			ft_stack.pop();
			std::cout << ORANGE1 << "ft_stack returns : ";
			std::cout << ft_stack.top() << std::endl << RESET;
			std::cout << std::endl << DODGERBLUE1
				<< "#########################################################"
				<< std::endl << RESET;
		}
			if (test_number == 5)
		{
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;

			std::cout << "Creating two containers stack with 'vector' as underlying container."
					<< " The vector's name is 'gandalf' and it contains 2 elements of type "
					<< "'int' and of value '4'..." << std::endl;
			std::vector<int> gandalf(2, 4);
			std::stack<int, std::vector<int> >	std_frodo(gandalf);
			ft::stack<int>	ft_frodo(gandalf);
			std::cout << std::endl;

			std::cout << "Creating 2 more vectors std_samwise and ft_samwise..."
				<< std::endl;
			std::stack<int, std::vector<int> >	std_samwise(gandalf);
			ft::stack<int>	ft_samwise(gandalf);

			std::cout << "Pushing 1 element of value 1 in std_stack." << std::endl;
			std::cout << OLIVE << "std_stack returns : ";
			std_frodo.push(1);
			std::cout << std_frodo.top() << std::endl << RESET;

			std::cout << "Pushing 1 element of value 1 in std_stack." << std::endl;
			ft_frodo.push(1);
			std::cout << ORANGE1 << "ft_stack returns : ";
			std::cout << ft_frodo.top() << std::endl << RESET;
			std::cout << std::endl;
			
			std::cout << GREEN3 << "Testing operator < --> " << std::endl << RESET;
			std::cout << OLIVE << "std_frodo < std_samwise : " << (std_frodo < std_samwise) << std::endl << RESET;
			std::cout << ORANGE1 << "ft_frodo < ft_samwise : " << (ft_frodo < ft_samwise);
			std::cout << std::endl << std::endl;
			
			std::cout << GREEN3 << "Testing operator > --> " << std::endl << RESET;
			std::cout << OLIVE << "std_frodo > std_samwise : " << (std_frodo > std_samwise) << std::endl << RESET;
			std::cout << ORANGE1 << "ft_frodo > ft_samwise : " << (ft_frodo > ft_samwise);
			std::cout << std::endl << std::endl;

			std::cout << GREEN3 << "Testing operator <= --> " << std::endl << RESET;
			std::cout << OLIVE << "std_frodo <= std_samwise : " << (std_frodo <= std_samwise) << std::endl << RESET;
			std::cout << ORANGE1 << "ft_frodo <= ft_samwise : " << (ft_frodo <= ft_samwise);
			std::cout << std::endl << std::endl;

			std::cout << GREEN3 << "Testing operator >= --> " << std::endl << RESET;
			std::cout << OLIVE << "std_frodo >= std_samwise : " << (std_frodo >= std_samwise) << std::endl << RESET;
			std::cout << ORANGE1 << "ft_frodo >= ft_samwise : " << (ft_frodo >= ft_samwise);
			std::cout << std::endl << std::endl;

			std::cout << GREEN3 << "Testing operator == --> " << std::endl << RESET;
			std::cout << OLIVE << "std_frodo == std_samwise : " << (std_frodo == std_samwise) << std::endl << RESET;
			std::cout << ORANGE1 << "ft_frodo == ft_samwise : " << (ft_frodo == ft_samwise);
			std::cout << std::endl << std::endl;

			std::cout << GREEN3 << "Testing operator != --> " << std::endl << RESET;
			std::cout << OLIVE << "std_frodo != std_samwise : " << (std_frodo != std_samwise) << std::endl << RESET;
			std::cout << ORANGE1 << "ft_frodo != ft_samwise : " << (ft_frodo != ft_samwise);
			std::cout << std::endl << std::endl;

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