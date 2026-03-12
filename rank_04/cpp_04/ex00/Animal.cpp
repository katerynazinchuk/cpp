#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << GREEN << "Animal copy constructor called"  << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if(this != &other)
	{
		_type = other._type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << CYAN << "Animal destructor called" << RESET << std::endl;
}

void Animal::makeSound () const
{
	std::cout << MAGENTA << "..." << RESET << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}

	