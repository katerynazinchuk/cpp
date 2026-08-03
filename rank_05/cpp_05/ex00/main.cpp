#include "Bureaucrat.hpp"

int main()
{
	std::cout << "===Valid bureaucrat===" << std::endl;
	try
	{
		Bureaucrat b("B", 5);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "===Grade exceptions===" << std::endl;
	try
	{
		Bureaucrat b("B", 0);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("B", 151);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "===Increment===" << std::endl;
	try
	{
		Bureaucrat b("B", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "===Decrement===" << std::endl;
	try
	{
		Bureaucrat b("B", 150);
		std::cout << b << std::endl;
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}