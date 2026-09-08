#pragma once
#include <vector>
#include <string>
#include <iostream>

class PmergeMe
{
	private:
		void sortBlocks(std::vector<int>& v, size_t block);
		size_t findPosition(const std::vector<int>& chain, int value, size_t limit, size_t block);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void sortVector(std::vector<int>& v);
};