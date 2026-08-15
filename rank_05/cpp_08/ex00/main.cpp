#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::cout << "=== container type: std::vector ===" << std::endl;
	std::vector<int> v = {10, 20, 30};
	try
	{
		auto it = easyfind(v, 10);
		std::cout << "[1] found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
	}

	std::cout << "=== iterator points into the container, not a copy ===" << std::endl;
	try
	{
		auto it = easyfind(v, 20);
		*it = 999;
		std::cout << "[2] v[1] = " << v[1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
	}

	std::cout << "=== container type: std::list ===" << std::endl;
	std::list<int> l = {100, 200};
	try
	{
		auto it = easyfind(l, 200);
		std::cout << "[3] found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
	}

	std::cout << "=== absent value in vector ===" << std::endl;
	try
	{
		easyfind(v, 300);
		std::cout << "[4] ERROR: no exception thrown" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
	}

	std::cout << "=== empty container ===" << std::endl;
	std::vector<int> empty = {};
	try
	{
		easyfind(empty, 300);
		std::cout << "[5] ERROR: no exception thrown" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
	}

	std::cout << "=== duplicates ===" << std::endl;
	std::vector<int> d = {5, 7, 5, 8};
	try
	{
		auto it = easyfind(d, 5);
		*it = 0;
		std::cout << "[6] ";
		for (auto i = d.begin(); i != d.end(); ++i)
		{
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
	}
	return 0;
}