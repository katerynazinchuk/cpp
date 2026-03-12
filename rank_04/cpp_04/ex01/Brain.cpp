#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i < 100; i++)
		_ideas[i] = "default idea";
	std::cout << GREEN << "Brain default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
	for(int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << GREEN << "Brain copy constructor called"  << RESET << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if(this != &other)
	{
		for(int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << CYAN << "Brain destructor called" << RESET << std::endl;
}

