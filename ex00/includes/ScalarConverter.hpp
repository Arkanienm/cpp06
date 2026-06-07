#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP
#include <string>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();
		static void convert(std::string input);
}

#endif