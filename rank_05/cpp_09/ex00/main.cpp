#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

int main ()
{
	std::string line;
	std::ifstream file("data.csv");
	if (!file.is_open()) 
		throw std::runtime_error("cant open a file");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
	return 0;
}