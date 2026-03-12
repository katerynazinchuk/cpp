//specific spell class inherited from AMateria
#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include <iostream>
#include "colors.hpp"
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		virtual ~Ice();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};


#endif