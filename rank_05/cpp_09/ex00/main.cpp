#include "BitcoinExchange.hpp"

void processInput(const BitcoinExchange& exchange, const std::string& line)
{
	size_t pos = line.find(" | ");
	if(pos == std::string::npos)
		return;
	std::string date = line.substr(0, pos);
	std::string amount = line.substr(pos + 3);
	double amount_d = std::stod(amount);
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
