#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "=== Full inventory test ===" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());

	ICharacter* alice = new Character("alice");
	AMateria* tmp2;
	tmp2 = src2->createMateria("ice");
	alice->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	alice->equip(tmp2);
	tmp2 = src2->createMateria("ice");
	alice->equip(tmp2);
	tmp2 = src2->createMateria("cure");
	alice->equip(tmp2);

	alice->use(0, *alice);
	alice->use(3, *alice);

	delete alice;
	

	std::cout << "=== Unknown type test ===" << std::endl;
	AMateria* unknown = src2->createMateria("fire");
	if(!unknown)
		std::cout << "Unknown materia type!" << std::endl;
	delete src2;
	return 0;
}