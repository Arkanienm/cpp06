#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP
#include <string>
#include <cstddef>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iostream>

class ScalarConverter
{
public:
	ScalarConverter();// a mettre en privée//
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	virtual ~ScalarConverter();
	static void convert(std::string input);
};

#endif