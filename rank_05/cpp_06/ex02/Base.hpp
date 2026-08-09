#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <string>
#include <iostream>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif

// for polimorph classes only dynamic_cast