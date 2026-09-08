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

void PmergeMe::sortBlocks_v(std::vector<int>& v, size_t block)
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

	sortBlocks_v(v, block * 2);

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

	//Jacobstal + insertion 2ᵏ − 1
	//binary search for a place with left limit. b < a
	//after inserrt a position mooved tto the right

	std::vector<size_t> aPosition;
	for (size_t i = 0; i < pend.size() / block; ++i)
		aPosition.push_back(i + 2);

	size_t numPend = pend.size() / block;
	std::vector<size_t> jacobstalOrder;
	size_t prev = 1;
	size_t curr = 3;
	while(jacobstalOrder.size() < numPend )
	{
		for (size_t j = curr; j > prev; --j)
		{
			if (j - 2 < numPend)
				jacobstalOrder.push_back(j - 2);
		}
		size_t next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	
	for(size_t n = 0; n < jacobstalOrder.size(); ++n)
	{
		size_t k = jacobstalOrder[n];
		int value = pend[k * block + block - 1];
		size_t pos = findPosition_v(main, value, aPosition[k], block);
		
		size_t insertAt   = pos * block;
		size_t pendStart  = k * block;
		size_t pendEnd    = pendStart + block;
		main.insert(main.begin() + insertAt, pend.begin() + pendStart, pend.begin() + pendEnd);	
	
		for (size_t i = 0; i < aPosition.size(); ++i)
		{
			if (aPosition[i] >= pos)
				aPosition[i] += 1;
		}
	}
	for (size_t i = 0; i < main.size(); ++i)
		v[i] = main[i];
}

size_t PmergeMe::findPosition_v(const std::vector<int>& chain, int value, size_t limit, size_t block)
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
	sortBlocks_v(v, 1);
}

void PmergeMe::sortBlocks_d(std::deque<int>& d, size_t block)
{
	size_t num_blocks = d.size() / block;
	if(num_blocks < 2)
		return;
	
	for (size_t i = 0; i + 1 < num_blocks; i += 2)
	{
		size_t endA = i * block + block - 1;
		size_t endB = (i + 1) * block + block - 1;
		if(d[endA] > d[endB])
			std::swap_ranges(d.begin() + i * block, d.begin() + i * block + block, d.begin() + (i + 1) * block);
	}
	
	sortBlocks_d(d, block * 2);

	std::deque<int> main;
	std::deque<int> pend;
	for (size_t j = 0; j < block; ++j)
		main.push_back(d[j]);
	for (size_t i = 1; i < num_blocks; ++i)
	{
		for (size_t j = 0; j < block; ++j)
		{
			if (i % 2 == 1)
				main.push_back(d[i * block + j]);
			else
				pend.push_back(d[i * block + j]);
		}
	}

	//Jacobsthal + insertion 2ᵏ − 1
	//binary search for a place with left limit. b < a
	//after insert a position moved to the right

	std::deque<size_t> aPosition;
	for (size_t i = 0; i < pend.size() / block; ++i)
		aPosition.push_back(i + 2);

	size_t numPend = pend.size() / block;
	std::deque<size_t> jacobstalOrder;
	size_t prev = 1;
	size_t curr = 3;
	while(jacobstalOrder.size() < numPend )
	{
		for (size_t j = curr; j > prev; --j)
		{
			if (j - 2 < numPend)
				jacobstalOrder.push_back(j - 2);
		}
		size_t next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	
	for(size_t n = 0; n < jacobstalOrder.size(); ++n)
	{
		size_t k = jacobstalOrder[n];
		int value = pend[k * block + block - 1];
		size_t pos = findPosition_d(main, value, aPosition[k], block);
		
		size_t insertAt   = pos * block;
		size_t pendStart  = k * block;
		size_t pendEnd    = pendStart + block;
		main.insert(main.begin() + insertAt, pend.begin() + pendStart, pend.begin() + pendEnd);	
	
		for (size_t i = 0; i < aPosition.size(); ++i)
		{
			if (aPosition[i] >= pos)
				aPosition[i] += 1;
		}
	}
	for (size_t i = 0; i < main.size(); ++i)
		d[i] = main[i];
}

size_t PmergeMe::findPosition_d(const std::deque<int>& chain, int value, size_t limit, size_t block)
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

void PmergeMe::sortDeque(std::deque<int>& d)
{
	sortBlocks_d(d, 1);
}