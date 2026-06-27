#include <iostream>
#include <ostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/Base.hpp"

static Base *generate(void)
{
	int n = rand() % 3;
	switch (n)
	{
	case 0:
	{
		A* a = new A;
		return a;
	}
	case 1:
	{
		B* b = new B;
		return b;
	}
	case 2:
	{
		C* c = new C;
		return c;
	}
	default:
		break;
	}
	return new Base;
}

static void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The base type is A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "The base type is B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "The base type is C" << std::endl;
}
static void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "The base type is A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "The base type is B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "The base type is C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int main()
{
	srand(time(NULL));
	for (size_t i = 0; i < 10; i++)
	{
		Base *b = generate();
		identify(b);
		identify(*b);
		delete b;
	}
	identify(NULL);
}