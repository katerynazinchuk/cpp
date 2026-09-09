#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <chrono>

class PmergeMe
{
	private:
		void pairUp_v(std::vector<int>& v, size_t block, size_t num_blocks);
		void splitChains_v(const std::vector<int>& v, size_t block, size_t num_blocks,
                   std::vector<int>& main, std::vector<int>& pend);
		std::vector<size_t> buildOrder(size_t numPend);
		void insertPend_v(std::vector<int>& main, std::vector<int>& pend, size_t block);
		size_t findPosition_v(const std::vector<int>& chain, int value, size_t limit, size_t block);
		void sortBlocks_v(std::vector<int>& v, size_t block);

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