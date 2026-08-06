#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
:AForm("ShrubberyCreation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
	{
        AForm::operator = (other);
		_target = other._target;
	}
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	std::ofstream file(_target + "_shrubbery");
	file << "    @@@@@    " << std::endl;
	file << "   @@@@@@@    " << std::endl;
	file << "  @@@@@@@@@   " << std::endl;
	file << " @@@@@@@@@@@  " << std::endl;
	file << "  @@@@@@@@@   " << std::endl;
	file << "     |||      " << std::endl;
	file << "     |||      " << std::endl;
}


