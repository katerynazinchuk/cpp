#include "Base.hpp"
#include <ctime>

int main()
{
	srand(time(NULL));

	Base* p = generate();
	(void)p;
	return 0;
}