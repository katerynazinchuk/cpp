#pragma once
#include <vector>
#include <string>
#include <iostream>

class PmergeMe
{
	private:
		struct Pair
		{
			int big;
			int small;
		}; 
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void sortVector(std::vector<int>& v);
};