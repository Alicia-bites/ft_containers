
#include "../../includes/stack.hpp"
#include "../../colors/colors.hpp"

#include <stdlib.h>
#include <iostream>


#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#include <stack>
#include <vector>
#endif

using namespace NAMESPACE;

int execute_tests_stack(int test_number)
{
	// if (argc != 2)
	// {
		// std::cout << "Usage : ./containers <test number>" << std::endl;
		// return 0;
	// }
	// int test_number = atoi(argv[1]);
	try
	{
		if (test_number == 1)
		{
			std::cout << "Creating two empty stacks..." << std::endl;
			stack<int>	myStack;
	
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;
	
			std::cout << GREEN3 << "Testing .empty() --> " << std::endl << RESET;
			std::cout << ORANGE1 << "myStack returns : ";
			std::cout << myStack.empty() << std::endl << RESET;
			std::cout << std::endl << DODGERBLUE1
				<< "#########################################################"
				<< std::endl << RESET;
		}
		if (test_number == 2)
		{
			stack<int>	myStack;
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;

			std::cout << GREEN3 << "Testing .size() --> " << std::endl << RESET;
			std::cout << ORANGE1 << "myStack returns : ";
			std::cout << myStack.size() << std::endl << RESET;
			std::cout << std::endl << DODGERBLUE1
				<< "#########################################################"
				<< std::endl << RESET;
		}
		if (test_number == 3)
		{
			stack<int>	myStack;
			std::cout << DODGERBLUE1 << "TEST #" << test_number << std::endl << std::endl << RESET;
	
			std::cout << GREEN3 << "Testing .push() and .top() --> " << std::endl << RESET;
			myStack.push(3);
			std::cout << ORANGE1 << "myStack returns : ";
			std::cout << myStack.top() << std::endl << RESET;
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
			vector<int> gandalf(2, 4);
			stack<int, vector<int> >	myStack(gandalf);
			std::cout << std::endl;
			std::cout << "Pushing 1 element of value 1." << std::endl;
			myStack.push(1);
			std::cout << ORANGE1 << "myStack returns : ";
			std::cout << myStack.top() << std::endl << RESET;
			std::cout << std::endl;
			std::cout << GREEN3 << "Testing .pop() --> " << std::endl << RESET;
			myStack.pop();
			std::cout << ORANGE1 << "myStack returns : ";
			std::cout << myStack.top() << std::endl << RESET;
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
			vector<int> gandalf(2, 4);
			stack<int, vector<int> >	frodo(gandalf);
			std::cout << std::endl;
			std::cout << "Pushing one element in frodo" << std::endl;
			frodo.push(1);

			std::cout << "Creating 1 more vector samwise with nothing in it..."
				<< std::endl;
			stack<int, vector<int> >	samwise(gandalf);

			std::cout << ORANGE1 << "frodo.top() : ";
			std::cout << frodo.top() << std::endl << RESET;
			std::cout << std::endl;
			
			std::cout << GREEN3 << "Testing operator < --> " << std::endl << RESET;
			std::cout << ORANGE1 << "frodo < samwise : " << (frodo < samwise);
			std::cout << std::endl << std::endl;
			
			std::cout << GREEN3 << "Testing operator > --> " << std::endl << RESET;
			std::cout << ORANGE1 << "frodo > samwise : " << (frodo > samwise);
			std::cout << std::endl << std::endl;

			std::cout << GREEN3 << "Testing operator <= --> " << std::endl << RESET;
			std::cout << ORANGE1 << "frodo <= samwise : " << (frodo <= samwise);
			std::cout << std::endl << std::endl;

			std::cout << GREEN3 << "Testing operator >= --> " << std::endl << RESET;
			std::cout << ORANGE1 << "frodo >= samwise : " << (frodo >= samwise);
			std::cout << std::endl << std::endl;

			std::cout << GREEN3 << "Testing operator == --> " << std::endl << RESET;
			std::cout << ORANGE1 << "frodo == samwise : " << (frodo == samwise);
			std::cout << std::endl << std::endl;

			std::cout << GREEN3 << "Testing operator != --> " << std::endl << RESET;
			std::cout << ORANGE1 << "frodo != samwise : " << (frodo != samwise);
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

int main(int argc, char **argv)
{
	static_cast<void>(argc);
	int test_number = atoi(argv[1]);
	execute_tests_stack(test_number);
	return 0;
}