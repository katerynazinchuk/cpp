#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::sortBlocks(std::vector<int>& v, size_t block)
{
	size_t num_blocks = v.size() / block;
	if(num_blocks < 2)
		return;
	
	for (size_t i = 0; i + 1 < num_blocks; i += 2)
	{
		size_t endA = i * block + block - 1;
		size_t endB = (i + 1) * block + block - 1;
		if(v[endA] > v[endB])
			std::swap_ranges(v.begin() + i * block, v.begin() + i * block + block, v.begin() + (i + 1) * block);
	}
	std::cout << "level " << block << ", blocks " << num_blocks << std::endl;

	sortBlocks(v, block * 2);

	std::vector<int> main;
	std::vector<int> pend;
	for (size_t j = 0; j < block; ++j)
		main.push_back(v[j]);
	for (size_t i = 1; i < num_blocks; ++i)
	{
		for (size_t j = 0; j < block; ++j)
		{
			if (i % 2 == 1)
				main.push_back(v[i * block + j]);
			else
				pend.push_back(v[i * block + j]);
		}
	}
	std::cout << "main: ";
	for (size_t i = 0; i < main.size(); ++i)
		std::cout << main[i] << " ";
	std::cout << " | pend: ";
	for (size_t i = 0; i < pend.size(); ++i)
		std::cout << pend[i] << " ";
	std::cout << std::endl;

	//Jacobstal + insertion 2ᵏ − 1
	//binary search for a place with left limit. b < a
	//after inserrt a position mooved tto the right
	std::cout << "pos for 5: " << findPosition(main, 5, 3, block) << std::endl;
	// size_t prev = 1;
	// size_t curr = 3;
	// size_t next = curr + 2 * prev;
	// prev = curr;
	// curr = next;
	//sorted main chain
	//write back
	//sorted v for this level
}

size_t PmergeMe::findPosition(const std::vector<int>& chain, int value, size_t limit, size_t block)
{
	size_t left = 0;
	size_t right = limit;

	while(left < right)
	{
		size_t mid = (left + right)/2;
		if(value < chain[mid * block + block - 1])
		{
			right  = mid;
		}
		else
			left = mid + 1;
	}
	return left;
}

void PmergeMe::sortVector(std::vector<int>& v)
{
	sortBlocks(v, 1);
}