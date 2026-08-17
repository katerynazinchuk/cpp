#include "MutantStack.hpp"
#include "colors.hpp"
#include <iostream>
#include <list>
#include <string>

int main()
{
	std::cout << YELLOW << "=== subject example ===" << RESET << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << YELLOW << "=== test with std::list ===" << RESET << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "size: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::cout << YELLOW << "=== empty stack ===" << RESET << std::endl;
	MutantStack<int> empty;
	std::cout << "size: " << empty.size() << std::endl;
	if (empty.begin() == empty.end())
		std::cout << "begin == end, nothing to iterate" << std::endl;

	std::cout << YELLOW << "=== copy constructor ===" << RESET << std::endl;
	MutantStack<int> copy(mstack);
	MutantStack<int>::iterator itt = copy.begin();
	MutantStack<int>::iterator itte = copy.end();
	while (itt != itte)
	{
		std::cout << *itt << std::endl;
		++itt;
	}
	copy.push(999);
	std::cout << "last added: " << copy.top() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;
	std::cout << "size: " << copy.size() << std::endl;
	return 0;
}
