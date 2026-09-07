#include "PmergeMe.hpp"

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

void PmergeMe::sortVector(std::vector<int>& v)
{
	std::vector<Pair> pairs;

	for(size_t i = 0; i + 1 < v.size(); i += 2)
	{
		int a = v[i];
		int b = v[i + 1];
		Pair p;
		if(a > b)
		{
			p.big = a;
			p.small = b;
		}
		else
		{
			p.big = b;
			p.small = a;
		}
		pairs.push_back(p);
	}

	bool hasOdd = (v.size() % 2 != 0);
	int odd = 0;
	if (hasOdd)
		odd = v.back();
	for(size_t i = 0; i < pairs.size() ; ++i)
	{
		std::cout << "[" << pairs[i].big << ", " << pairs[i].small << "] ";
	}
	if (hasOdd)
    		std::cout << "odd: " << odd;
	std::cout << std::endl;
}