#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>

double getRate(const std::map<std::string, double>& rates, const std::string& date)
{
	auto it = rates.upper_bound(date);
	if(it == rates.begin())
		throw std::runtime_error ("No rate exist for this date");
	--it;
	return it->second;
}

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
	// std::cout << rates.size() << std::endl;
	try
	{
		std::cout << getRate(rates, "2000-01-03") << std::endl;
		std::cout << getRate(rates, "2000-01-09") << std::endl;
		std::cout << getRate(rates, "2000-01-01") << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << std::endl;
	}
	return 0;
}
