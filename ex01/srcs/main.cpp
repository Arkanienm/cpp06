#include <iostream>
#include <ostream>
#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av)
{

	if (ac != 2 || av[1][0] == 0)
	{
		std::cerr << "Error : you need one arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
}