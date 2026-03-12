#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << GREEN << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	std::cout << GREEN << "WrongAnimal copy constructor called"  << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if(this != &other)
	{
		_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << CYAN << "WrongAnimal destructor called" << RESET << std::endl;
}

void WrongAnimal::makeSound () const
{
	std::cout << MAGENTA << "WrongAnimal sound" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

	