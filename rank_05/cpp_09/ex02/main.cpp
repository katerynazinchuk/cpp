#include "PmergeMe.hpp"
#include <cctype>

int main (int argc, char** argv)
{
	if(argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::vector<int> input;

	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		if(arg.length() == 0)
			return 1;
		for(size_t k = 0; k < arg.length(); k++)
		{
			if(!isdigit(arg[k]))
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
		int num;
		try
		{
			num = std::stoi(arg);
		}
		catch(const std::exception&)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		input.push_back(num);
	}

	std::cout << "Before: ";
	for(size_t i = 0; i < input.size(); ++i)
		std::cout << input[i] << " ";
	std::cout << std::endl;
	PmergeMe sorted;
	sorted.sortVector(input);
	
	return 0;
}