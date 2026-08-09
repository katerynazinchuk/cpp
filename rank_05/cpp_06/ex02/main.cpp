#include "Base.hpp"
#include <ctime>

int main()
{
	srand(time(NULL));

	Base* p = generate();
	identify(p);
	identify(*p);
	delete p;
	return 0;
}