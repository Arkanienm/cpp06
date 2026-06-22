#include "../includes/Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& src) {*this = src;}
Serializer& Serializer::operator=(const Serializer& src)
{
	if (this != &src)
		*this = src;
	return *this;
}
Serializer::~Serializer() {}
