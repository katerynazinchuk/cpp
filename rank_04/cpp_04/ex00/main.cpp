#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main ()
{
	std::cout << "=== Animal ===" << std::endl;
	Animal* dog = new Dog;
	dog->makeSound();
	std::cout << dog->getType() << std::endl;
	Animal* cat = new Cat;
	cat->makeSound();
	std::cout << cat->getType() << std::endl;
	delete dog;
	delete cat;

	std::cout << "=== WrongAnimal ===" << std::endl;
	WrongAnimal* wa = new WrongCat;
	wa->makeSound();
	delete wa;

	std::cout << "=== Dog copy constructor ===" << std::endl;
	Dog d1;
	Dog d2(d1);
	d1.makeSound();
	d2.makeSound();

	std::cout << "=== Dog copy assighnment ===" << std::endl;
	Cat c1;
	Cat c2;
	c2 = c1;

	return 0;
}