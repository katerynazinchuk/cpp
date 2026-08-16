#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

int main()
{
	std::cout << "=== subject example ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

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

	std::cout << "=== test with std::list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;

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
	std::cout << "=== empty stack ===" << std::endl;
	MutantStack<int> empty;
	std::cout << empty.size() << std::endl;
	if (empty.begin() == empty.end())
		std::cout << "begin == end, nothing to iterate" << std::endl;

	std::cout << "=== copy constructor ===" << std::endl;
	MutantStack<int> copy(mstack);
	MutantStack<int>::iterator itt = copy.begin();
	MutantStack<int>::iterator itte = copy.end();
	while (itt != itte)
	{
		std::cout << *itt << std::endl;
		++itt;
	}
	copy.push(999);
	std::cout << mstack.size() << std::endl;
	std::cout << copy.size() << std::endl;

	std::cout << "=== assignment operator ===" << std::endl;


	std::cout << "=== another type: std::string ===" << std::endl;


	return 0;
}
