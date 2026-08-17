
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    
    Intern someRandomIntern;
    AForm* form;

    std::cout << "=== Shrubbery Creation ===" << std::endl;
    try
    {
        form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form)
        {
            Bureaucrat alice("Alice", 130);
            alice.signForm(*form);
            alice.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Robotomy Request ===" << std::endl;
    try
    {
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form)
        {
            Bureaucrat alice("Alice", 45);
            alice.signForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);
            alice.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Presidential Pardon ===" << std::endl;
    try
    {
        form = someRandomIntern.makeForm("presidential pardon", "Alice");
        if (form)
        {
            Bureaucrat president("President", 5);
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Unknown form ===" << std::endl;
    try
    {
        form = someRandomIntern.makeForm("unknown form", "target");
        if (form)
            delete form;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}