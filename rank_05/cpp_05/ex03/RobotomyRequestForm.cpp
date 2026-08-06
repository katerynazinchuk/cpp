#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
:AForm("RobotomyRequest", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
	{
        AForm::operator = (other);
		_target = other._target;
	}
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	std::cout << "SOME DRILLING NOISES" << std::endl;
	if(rand() % 2)
		std::cout << _target << " has been robotomized!" << std::endl;
	else
		std::cout << _target << " robotomy failed!" << std::endl;
}


