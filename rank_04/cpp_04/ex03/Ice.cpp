#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << GREEN << "Ice constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << GREEN << "Ice copy constructor called" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	(void)other;
	return *this;
}

Ice::~Ice()
{
	std::cout << CYAN << "Ice destructor called" << RESET << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}