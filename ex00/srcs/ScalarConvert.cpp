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

static int checkDecimal(std::string input)
{
	int dec = 0;
	size_t i = 0;
	for (i = 0; i < input.length(); i++)
	{
		if (input.at(i) == '.')
		{
			i++;
			break;
		}
	}
	for (size_t a = i; a < input.length(); a++)
	{
		if (isdigit(input.at(a)))
			dec++;
	}
	return dec;
}

static void displayALL(double d, std::string input)
{
	int dec = checkDecimal(input);
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char :" << "impossible" << std::endl;
	else if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127 || !isprint(static_cast<unsigned char>(d)))
		std::cout << "char :" << "not displayable" << std::endl;
	else
		std::cout << "char :" << static_cast<unsigned char>(d) << std::endl;
	if (std::isnan(d) || std::isinf(d))
		std::cout << "int : impossible" << std::endl;
	else if (d > 2147483647 || d < -2147483648)
		std::cout << "int : out of limits" << std::endl;
	else
		std::cout << "int :" << static_cast<int>(d) << std::endl;
	if (std::isnan(d) || std::isinf(d))
	{
		if (input.at(0) == '+')
		{
			std::cout << "double :" << "+" << d << std::endl;
			std::cout << "float :" << "+" << d << "f" << std::endl;
		}
		else
		{
			std::cout << "double :" << d << std::endl;
			std::cout << "float :" << d << "f" << std::endl;
		}
	}
	else if (std::floor(d) - d == 0)
	{
		std::cout << "double :" << std::fixed << std::setprecision(1) << d << std::endl;
		std::cout << "float :" << std::setprecision(1) << d << "f" << std::endl;
	}
	else
	{
		std::cout << std::showpoint << std::setprecision(dec + 1) << "double :" << d << std::endl;
		std::cout << std::showpoint << std::setprecision(dec + 1) << "float :" << static_cast<float>(d) << "f" <<  std::endl;
	}
}

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
	char *endptr;
	double d = strtod(input.c_str(), &endptr);
	if (isChar(input))
	{
		d = static_cast<double>(input.at(0));
		displayALL(d, input);
		return ;
	}
	if (isInt(input) || isDouble(input) || isFloat(input))
	{
		displayALL(d, input);
		return ;
	}
	std::cout << "Error : You can't convert a wrong input" << std::endl;
}
