#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include <iostream>
#include "colors.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _templates[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		virtual ~MateriaSource();
	
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif