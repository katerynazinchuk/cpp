#include "Zombie.hpp"

int main()
{
	randomChump("StackZombie");
	Zombie* z = newZombie("HeapZombie");
	z->announce();
	delete z;

	return (0);
}