#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));

    std::cout << "=== Shrubbery success ===" << std::endl;
    try
    {
        Bureaucrat B("B", 130);
		ShrubberyCreationForm f("f");
		B.signForm(f);
		B.executeForm(f);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Execute unsigned form ===" << std::endl;
    try
    {
		Bureaucrat alice("Alice", 1);
		ShrubberyCreationForm f("garden");
		alice.executeForm(f);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Grade too low to execute ===" << std::endl;
    try
    {
		Bureaucrat bob("Bob", 140);
		ShrubberyCreationForm f("park");
		bob.signForm(f);
		bob.executeForm(f);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Robotomy ===" << std::endl;
    try
    {
		Bureaucrat alice("Alice", 45);
		RobotomyRequestForm f("Bender");
		alice.signForm(f);
		alice.executeForm(f);
		alice.executeForm(f);
		alice.executeForm(f);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Presidential pardon ===" << std::endl;
    try
    {
		Bureaucrat president("President", 5);
		PresidentialPardonForm f("Alice");
		president.signForm(f);
		president.executeForm(f);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
