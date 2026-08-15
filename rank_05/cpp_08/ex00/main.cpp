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
		std::cout << "[2] found: " << *it << std::endl;
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

    // ---- 2. value absent in vector ------------------------------
    // same vector, search 99
    // expected: exception message from e.what()


    // ---- 3. empty container -------------------------------------
    // empty vector, search anything
    // expected: exception message


	
    // expected: 200
    // (proof the template is really generic)


    // ---- 5. duplicates: must return FIRST occurrence ------------
    // vector {5, 7, 5, 7}, search 7
    // expected: index 1
    // hint: std::distance(v.begin(), it) gives the position

    return 0;
}