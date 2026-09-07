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
}

void PmergeMe::sortVector(std::vector<int>& v)
{
	sortBlocks(v, 1);
}