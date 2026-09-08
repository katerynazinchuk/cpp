#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <chrono>

class PmergeMe
{
	private:
		void sortBlocks_v(std::vector<int>& v, size_t block);
		size_t findPosition_v(const std::vector<int>& chain, int value, size_t limit, size_t block);

		void sortBlocks_d(std::deque<int>& d, size_t block);
		size_t findPosition_d(const std::deque<int>& chain, int value, size_t limit, size_t block);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void sortVector(std::vector<int>& v);
		void sortDeque(std::deque<int>& d);
};