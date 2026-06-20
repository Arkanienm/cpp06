#include <iostream>
#include <ostream>
#include "../includes/ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
int main(int ac, char **av)
{

	if (ac != 2 || av[1][0] == 0)
	{
		// float n = 1.42;
		std::cout << std::fixed << std::setprecision(1) << 4.2 << std::endl;
   		std::cout << std::fixed << std::setprecision(1) << 42.0 << std::endl;
   		std::cout << std::fixed << std::setprecision(1) << 1234.5678 << std::endl;
		std::cout << std::fixed << std::setprecision(1) << std::numeric_limits<double>::quiet_NaN() << std::endl;
		// std::cerr << "Error : you need one arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
}