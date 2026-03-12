#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN << "Cure constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << GREEN << "Cure copy constructor called" << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	(void)other;
	return *this;
}

Cure::~Cure()
{
	std::cout << CYAN << "Cure destructor called" << RESET << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}