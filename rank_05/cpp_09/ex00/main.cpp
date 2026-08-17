#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>

int main ()
{
	std::map<std::string, double> rates;
	std::string line;
	std::ifstream file("data.csv");
	if (!file.is_open()) 
		throw std::runtime_error("cant open a file");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if(pos == std::string::npos)
			continue;
		std::string date = line.substr(0, pos);
		std::string rate = line.substr(pos + 1);
		rates[date] = std::stod(rate);
		// std::cout << "[" << date << "]" << "[" << rate << "]" << std::endl;
	}
	std::cout << rates.size() << std::endl;
	return 0;
}