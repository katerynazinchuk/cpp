#pragma once
#include <vector>
#include <string>
#include <iostream>

class PmergeMe
{
	private:
		void sortBlocks(std::vector<int>& v, size_t block);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void sortVector(std::vector<int>& v);
};