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
/*
static void displayConvert(double d, bool isFloat)
{

}

static bool isChar(const std::string& input)
{
	if (input.length() != 1 || isdigit(input.at(0)))
		return false;
	return true;
}

static bool isInt(const std::string& input)
{
	size_t i = 0;
	if (input.length() == 1 && input.at(0) == '-')
		return false;
	if (input.at(0) == '-')
		i++;
	while (i < input.length())
	{
		if (!isdigit(input.at(i)))
			return false;
		i++;
	}
	return true;
}

static bool isDouble(const std::string& input)
{
	size_t i = 0;
	int point = 0;
	if (input.length() == 1 && input.at(0) == '-')
		return false;
	if (input.at(0) == '-')
		i++;
	if (input == "nan" || input == "+inf" || input == "-inf")
		return true;
	while (i < input.length())
	{
		if (!isdigit(input.at(i)) && input.at(i) != '.')
			return false;
		if (input.at(i) == '.')
			point++;
		i++;
	}
	if (point != 1)
		return false;
	if (input.at(input.length() - 1) == '.')
		return false;
	return true;
}

static bool isFloat(const std::string& input)
{
	if (input.at(input.length() - 1) != 'f')
		return false;
	if (!isDouble(input.substr(0, input.length() - 1)))
		return false;
	return true;
}
*/
void ScalarConverter::convert(std::string input)
{
	if (input.empty())
		std::cout << "Error : empty input ." << std::endl;
	for (size_t i = 0; i < input.length(); i++)
	{
		if ((input.at(i) >= 9 && input.at(i) <= 13 ) || input.at(i) == 32)
		{
			std::cerr << "Error : You can't convert a whitespace" << std::endl;
			return;
		}
	}
}
