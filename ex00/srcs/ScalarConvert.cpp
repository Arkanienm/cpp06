#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstdlib>
#include <iostream>

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) {*this = src;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	if (this != &src)
		*this = src;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if ((input.at(i) >= 9 && input.at(i) <= 13 ) || input.at(i) == 32)
		{
			std::cerr << "Error : You can't convert a whitespace" << std::endl;
			return;
		}
	}
	if (input.length() == 1)
	{
		if (isascii(input.at(0)) && !isdigit(input.at(0)))
		{
			std::cout << "char :" << input << std::endl;
			std::cout << "int :" << static_cast<int>(input.at(0)) << std::endl;
			std::cout << "float :" << static_cast<float>(input.at(0)) << ".0f" <<std::endl;
			std::cout << "double :" << static_cast<double>(input.at(0))<< ".0" << std::endl;
			return;
		}
		if (isascii(input .at(0)) && isdigit(input.at(0)))
		{
			std::cout << "char : non displayable" << std::endl;
			std::cout << "int :" << input.at(0) - 48 << std::endl;
			std::cout << "float :" << static_cast<float>(input.at(0) - 48) << ".0f" <<std::endl;
			std::cout << "double :" << static_cast<double>(input.at(0) - 48)<< ".0" << std::endl;
			return;
		}
	}
	if (isdigit(input.at(0)) || input.at(0) == '-')
	{
		for (size_t i = 1; i < input.length(); i++)
			if (input.at(i) < 48 && input.at(i) > 57)
				std::cerr << "Error : You can't convert a wrong input" << std::endl;
		int n = atoi(input.c_str());
		std::cout << "int :" << n << std::endl;
		if (!isprint(n))
			std::cout << "char : non displayable" << std::endl;
		else
			std::cout << "char :" << static_cast<char>(n) << std::endl;
		std::cout << "int :" << n << std::endl;
		std::cout << "float :" << static_cast<float>(n) << ".0f" <<std::endl;
		std::cout << "double :" << static_cast<double>(n) << ".0" << std::endl;
		return;
	}


}
