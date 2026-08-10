#include <iostream>
#include <string>
#include "iter.hpp"


template <typename T>
void printAny(T const & x)
{
	std::cout << x << " ";
}

void printInt(int const & n)
{
	std::cout << n << " ";
}

void doubleInt(int & n)
{
	n = n * 2;
}

int main()
{
	int arr [] = {1, 2, 3};
	const int carr[] = {11, 22, 33};
	std::string sarr[] = {"one", "two", "three"};

	std::cout << "arr:     ";
	::iter(arr, 3, printInt);
	std::cout << std::endl;

	std::cout << "arr const:     ";
	::iter(carr, 3, printInt);
	std::cout << std::endl;

	std::cout << "string:     ";
	::iter(sarr, 3, printAny<std::string>);
	std::cout << std::endl;

	std::cout << "doubled:     ";
	::iter(arr, 3, doubleInt);
	::iter(arr, 3, printInt);
	std::cout << std::endl;

	// std::cout << "doubled const:     ";
	// ::iter(carr, 3, doubleInt);
	// std::cout << std::endl;
	return 0;
}
