#include <iostream>
#include <ostream>
#include <exception>
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

static Base *generate(void)
{
	int n = rand() % 3;
	switch (n)
	{
	case 0:
		A* a = new A;
		return a;
	case 1:
		B* b = new B;
		return b;
	case 2:
		C* c = new C;
		return c;
	default:
		break;
	}
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
		dynamic_cast<A*>(&p);
		std::cout << "The base type is A" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		dynamic_cast<B*>(&p);
		std::cout << "The base type is B" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		dynamic_cast<C*>(&p);
		std::cout << "The base type is C" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	Base *b = generate();
	identify(b);
	identify(*b);
}