#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		virtual void makeSound() const = 0;// means virtual and says that it doesnt have implementation here, so class that will inherite it should have an implementation
		std::string getType()const;
};

#endif