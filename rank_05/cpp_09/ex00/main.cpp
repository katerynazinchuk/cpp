#include "BitcoinExchange.hpp"

int main ()
{
	BitcoinExchange exchange;
	exchange.loadDatabase("data.csv");
	try
	{
		std::cout << exchange.getRate("2011-01-03") << std::endl;
		std::cout << exchange.getRate("2011-01-09") << std::endl;
		std::cout << exchange.getRate("2000-01-01") << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << std::endl;
	}
	return 0;
}
