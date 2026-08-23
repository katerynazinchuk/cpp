#include "RPN.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error: provide numbers for calculation" << std::endl;
		return 1;
	}
	try
	{
		std::cout << RPN::calculate(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}