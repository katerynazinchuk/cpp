#include "BitcoinExchange.hpp"
#include <cctype>

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool isValidDate(const std::string& date)
{
	if(date.length() != 10)
		return false;
	if(date[4] != '-' || date[7] != '-')
		return false;
	for(int i = 0; i < 10; ++i)
	{
		if(i == 4 || i == 7)
			continue;
		if(!isdigit(date[i]))
			return false;
	}
	int year  = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	if(month < 1 || month > 12)
		return false;
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[month - 1];
	if(month == 2 && isLeapYear(year))
		maxDay = 29;
	int day = std::stoi(date.substr(8, 2));
	if(day < 1 || day > maxDay)
		return false;
	return true;
}



void processInput(const BitcoinExchange& exchange, const std::string& line)
{
	size_t pos = line.find(" | ");
	if(pos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, pos);
	std::string amount = line.substr(pos + 3);
	if(!isValidDate(date))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	size_t idx;
	double amount_d;
	try
	{
    	amount_d = std::stod(amount, &idx);
	}
	catch (const std::exception&)
	{
    	std::cerr << "Error: bad input => " << line << std::endl;
    	return;
	}
	if (idx != amount.length())
	{
    	std::cerr << "Error: bad input => " << line << std::endl;
    	return;
	}
	if(amount_d < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return;
	}
	if(amount_d > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return;
	}
	try
	{
		double rate = exchange.getRate(date);
		std::cout << date << " => " << amount_d << " = " << amount_d * rate << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main (int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange exchange;
	try
	{
		exchange.loadDatabase("data.csv");
		std::string line;
		std::ifstream file(argv[1]);
		if (!file.is_open()) 
			throw std::runtime_error("Error: could not open file");
		std::getline(file, line);
		while (std::getline(file, line))
		{
			processInput(exchange, line);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
