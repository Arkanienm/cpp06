#include <iostream>
#include <ostream>
#include "../includes/Serializer.hpp"

int main()
{
	Data data;
	std::cout << "data adresse : " << &data << std::endl;
	uintptr_t ptr = Serializer::serialize(&data);
	Data *data1 = Serializer::deserialize(ptr);
	std::cout << "data1 adresse : " << data1 << std::endl;

}