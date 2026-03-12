#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << GREEN << _type << " default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << GREEN << _type << " copy constructor called"  << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << _type << " copy assignment operator called" << std::endl;
	if(this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << CYAN << _type << " destructor called" << RESET << std::endl;
	delete _brain;
}

void Cat::makeSound () const
{
	std::cout << MAGENTA << "Meow!" << RESET << std::endl;
}

Brain* Cat::getBrain() const
{
	return _brain;
}