#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP
#include <string>
#include <cstddef>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);
	virtual ~ScalarConverter();
public:
	static void convert(std::string input);
};

#endif