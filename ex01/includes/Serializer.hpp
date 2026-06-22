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

class Serializer
{
	typedef unsigned int* uintptr_t;
	typedef void Data;

	private :
		Serializer();

	public:
		Serializer(const Serializer&);
		Serializer& operator=(const Serializer&);
		virtual ~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif