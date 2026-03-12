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
	// Animal* animal = new Animal;
	
	delete dog;
	delete cat;

	std::cout << "=== WrongAnimal ===" << std::endl;
	WrongAnimal* wa = new WrongCat;
	wa->makeSound();
	delete wa;

	std::cout << "=== Deep copy test ===" << std::endl;
	Dog d1;
	d1.makeSound();
	d1.getBrain()->_ideas[0] = "I love bones";

	Dog d2(d1);
	d2.makeSound();
	std::cout << d1.getBrain()->_ideas[0] << std::endl;
	std::cout << d2.getBrain()->_ideas[0] << std::endl;
	d2.getBrain()->_ideas[0] = "I love cats";
	std::cout << d1.getBrain()->_ideas[0] << std::endl;
	std::cout << d2.getBrain()->_ideas[0] << std::endl;

	std::cout << "=== Dog copy assighnment ===" << std::endl;
	Cat c1;
	Cat c2;
	c2 = c1;

	std::cout << "=== Animal array ===" << std::endl;
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();
	for(int i = 0; i < 4; i++)
		animals[i]->makeSound();
	
	for(int i = 0; i < 4; i ++)
		delete animals[i];

	return 0;
}