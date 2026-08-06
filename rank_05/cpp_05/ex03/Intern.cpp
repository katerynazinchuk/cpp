#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
	{

	}
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			if (i == 0) return new ShrubberyCreationForm(target);
			if (i == 1) return new RobotomyRequestForm(target);
			if (i == 2) return new PresidentialPardonForm(target);
		}
	}
	std::cout << "Intern: unknown form: " << formName << std::endl;
	return NULL;
}