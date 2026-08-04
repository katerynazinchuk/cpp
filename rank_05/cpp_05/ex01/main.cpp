#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Valid form ===" << std::endl;
    try
    {
        Form f("Budget", 50, 25);
        std::cout << f << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Invalid form grade ===" << std::endl;
    try
    {
        Form f("Tax", 0, 25);
        std::cout << f << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Bureaucrat can sign ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 10);
        Form f("Budget", 50, 25);
        std::cout << alice << std::endl;
        std::cout << f << std::endl;
        alice.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Bureaucrat cannot sign ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 140);
        Form f("Budget", 50, 25);
        std::cout << bob << std::endl;
        std::cout << f << std::endl;
        bob.signForm(f);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "=== Sign form twice ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 10);
        Form f("Budget", 50, 25);
        alice.signForm(f);
        std::cout << f << std::endl;
        alice.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
