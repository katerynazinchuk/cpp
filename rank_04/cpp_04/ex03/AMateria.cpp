#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria (std::string const& type) : _type(type)
{
	std::cout << GREEN << "AMateria " << _type <<  " constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	std::cout << GREEN << "AMateria copy constructor called" << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if(this != &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria ()
{
	std::cout << CYAN << "AMateria "  << _type << " destructor called" << RESET << std::endl;
}

std::string const& AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses materia on " <<target.getName() << " *" << std::endl;
}
