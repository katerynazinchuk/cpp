#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << GREEN << _type << " default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << GREEN << _type << " copy constructor called"  << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << _type << " copy assignment operator called" << std::endl;
	if(this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << CYAN << _type << " destructor called" << RESET << std::endl;
}

void Dog::makeSound () const
{
	std::cout << MAGENTA << "Bark bark!" << RESET << std::endl;
}
