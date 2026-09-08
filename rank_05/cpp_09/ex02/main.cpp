#include "PmergeMe.hpp"
#include <cctype>
#include "colors.hpp"

int main (int argc, char** argv)
{
	if(argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::vector<int> input_v;
	std::deque<int> input_d;

	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		if(arg.length() == 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
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
		input_v.push_back(num);
		input_d.push_back(num);

	}

	PmergeMe sorter;
	std::cout << GREEN << "Before: " << RESET;
	for(size_t i = 0; i < input_v.size(); ++i)
		std::cout << input_v[i] << " ";
	std::cout << std::endl;

	auto startV = std::chrono::high_resolution_clock::now();
	sorter.sortVector(input_v);
	auto endV = std::chrono::high_resolution_clock::now();
	double timeV = std::chrono::duration<double, std::micro>(endV - startV).count();

	auto startD = std::chrono::high_resolution_clock::now();
	sorter.sortDeque(input_d);
	auto endD = std::chrono::high_resolution_clock::now();
	double timeD = std::chrono::duration<double, std::micro>(endD - startD).count();

	std::cout << GREEN << "After: "<< RESET;
	for (size_t i = 0; i < input_v.size(); ++i)
		std::cout << input_v[i] << " ";
	std::cout << std::endl;

	std::cout << YELLOW << "Time to process a range of " << input_v.size() << " elements with std::vector : " << timeV << " us" << std::endl;
	std::cout << "Time to process a range of " << input_d.size() << " elements with std::deque : " << timeD << " us" << RESET << std::endl;

	return 0;
}