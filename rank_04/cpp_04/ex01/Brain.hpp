#ifndef BRAIN_HPP
#define BRAIN_HPP
# include <string>
# include <iostream>
# include "colors.hpp"

class Brain 
{
	private:
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		std::string _ideas[100];
};

#endif