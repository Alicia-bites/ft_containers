#include "vector.hpp"

#include <vector>

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
			std::cout << STEELBLUE2 << "TEST #" << test_number << std::endl << RESET;
			std::cout << STEELBLUE3 << "Testing default constructor" 
				<< RESET << std::endl << std::endl;

			std::vector<int>	std_vector;
			ft::vector<int>		ft_vector;
			std::cout << OLIVE << sizeof(std_vector) << RESET << std::endl;
			std::cout << ORANGE1 << sizeof(ft_vector) << RESET << std::endl;


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
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << STEELBLUE2 << "All tests done!" << RESET << std::endl;
	return 0;
}