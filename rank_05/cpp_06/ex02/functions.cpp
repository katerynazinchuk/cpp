#include "Base.hpp"

Base* generate(void)
{
	switch(rand() % 3)
	{
		case 0: return new A;
		case 1: return new B;
		default: return new C;
	}
}