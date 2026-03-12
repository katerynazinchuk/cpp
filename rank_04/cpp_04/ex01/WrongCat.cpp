#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << GREEN << _type << " default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << GREEN << _type << " copy constructor called"  << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << _type << " copy assignment operator called" << std::endl;
	if(this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << CYAN << _type << " destructor called" << RESET << std::endl;
}

void WrongCat::makeSound () const
{
	std::cout << MAGENTA << "Meow!" << RESET << std::endl;
}
