#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << GREEN << _type << " default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << GREEN << _type << " copy constructor called"  << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << _type << " copy assignment operator called" << std::endl;
	if(this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << CYAN << _type << " destructor called" << RESET << std::endl;
	delete _brain;
}

void Dog::makeSound () const
{
	std::cout << MAGENTA << "Bark bark!" << RESET << std::endl;
}

Brain* Dog::getBrain() const
{
	return _brain;
}