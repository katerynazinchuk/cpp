#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::string line;
	std::ifstream file(filename);
	if (!file.is_open()) 
		throw std::runtime_error("Error: could not open file.");
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if(pos == std::string::npos)
			continue;
		std::string date = line.substr(0, pos);
		std::string rate = line.substr(pos + 1);
		_rates[date] = std::stod(rate);
	}
}

double BitcoinExchange::getRate(const std::string& date) const
{
	auto it = _rates.upper_bound(date);
	if(it == _rates.begin())
		throw std::runtime_error ("Error: No rate exist for this date");
	--it;
	return it->second;
}


