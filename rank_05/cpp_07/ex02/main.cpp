#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	Array<int> empty;
	std::cout << "empty size: " << empty.size() << std::endl;

	Array<int> nums(5);
	std::cout << "nums size:  " << nums.size() << std::endl;
	std::cout << "nums[0]:    " << nums[0] << std::endl;

	for (unsigned int i = 0; i < nums.size(); i++)
		nums[i] = (i + 1) * 10;
	std::cout << "nums[2]:    " << nums[2] << std::endl;

	Array<int> copy(nums);
	copy[2] = 999;
	std::cout << "copy[2]:    " << copy[2] << std::endl;
	std::cout << "nums[2]:    " << nums[2] << std::endl;

	Array<int> assigned;
	assigned = nums;
	assigned[0] = 111;
	std::cout << "assigned[0]: " << assigned[0] << std::endl;
	std::cout << "nums[0]:     " << nums[0] << std::endl;

	try
	{
		nums[100];
		std::cout << "NOT REACHED" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "exception:  " << e.what() << std::endl;
	}

	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "codam";
	std::cout << words[0] << " " << words[1] << std::endl;

	Array<int> const frozen(nums);
	std::cout << "frozen[1]:  " << frozen[1] << std::endl;
	// frozen[1] = 5;  

	return 0;
}