#include "Span.hpp"
#include <iostream>
#include <list>
#include <climits>


int main()
{
	std::cout << "=== subject example ===" << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "[1] shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "[1] longest:  " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[1] unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "=== span is full ===" << std::endl;
	Span sp_F = Span(3);
	sp_F.addNumber(6);
	sp_F.addNumber(3);
	sp_F.addNumber(17);
	try
	{
		sp_F.addNumber(9);
		std::cout << "[2] ERROR: no exception thrown" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[2] exception: " << e.what() << std::endl;
	}

	std::cout << "=== not enough numbers ===" << std::endl;
	Span sp_E = Span(5);
	try
	{
		sp_E.shortestSpan();
		std::cout << "[3a] ERROR: no exception thrown" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[3a] empty, shortest: " << e.what() << std::endl;
	}
	try
	{
		sp_E.longestSpan();
		std::cout << "[3b] ERROR: no exception thrown" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[3b] empty, longest: " << e.what() << std::endl;
	}
	Span sp_one = Span(5);
	sp_one.addNumber(42);
	try
	{
		sp_one.shortestSpan();
		std::cout << "[3c] ERROR: no exception thrown" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[3c] one number, shortest: " << e.what() << std::endl;
	}
	try
	{
		sp_one.longestSpan();
		std::cout << "[3d] ERROR: no exception thrown" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[3d] one number, longest: " << e.what() << std::endl;
	}

	std::cout << "=== exactly two numbers ===" << std::endl;
	try
	{
		Span sp_two = Span(2);
		sp_two.addNumber(1);
		sp_two.addNumber(1000);
		
		std::cout << "[4] shortest: " << sp_two.shortestSpan() << std::endl;
		std::cout << "[4] longest:  " << sp_two.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[4] unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "=== duplicates ===" << std::endl;
	try
	{
		Span sp_two = Span(4);
		sp_two.addNumber(5);
		sp_two.addNumber(5);
		sp_two.addNumber(5);
		sp_two.addNumber(5);
		
		std::cout << "[5] shortest: " << sp_two.shortestSpan() << std::endl;
		std::cout << "[5] longest:  " << sp_two.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[5] unexpected exception: " << e.what() << std::endl;
	}
	std::cout << "=== negative numbers ===" << std::endl;
	try
	{
		Span sp_three = Span(3);
		sp_three.addNumber(-10);
		sp_three.addNumber(0);
		sp_three.addNumber(5);
		
		std::cout << "[6] shortest: " << sp_three.shortestSpan() << std::endl;
		std::cout << "[6] longest:  " << sp_three.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[6] unexpected exception: " << e.what() << std::endl;
	}
	std::cout << "=== extreme values (the overflow case) ===" << std::endl;
	try
	{
		Span sp_ext = Span(2);
		sp_ext.addNumber(INT_MIN);
		sp_ext.addNumber(INT_MAX);

		std::cout << "[7] shortest: " << sp_ext.shortestSpan() << std::endl;
		std::cout << "[7] longest:  " << sp_ext.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[7] unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "=== 10 000 random numbers ===" << std::endl;
	try
	{
		Span sp_known = Span(10000);
		for (int i = 0; i < 10000; ++i)
			sp_known.addNumber(i * 10);

		std::cout << "[9] shortest: " << sp_known.shortestSpan() << " (expected 10)" << std::endl;
		std::cout << "[9] longest:  " << sp_known.longestSpan() << " (expected 99990)" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[9] unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "=== addRange to vector===" << std::endl;
	std::vector<int> source;
	for(int i = 0; i < 10000; i++)
		source.push_back(i*10);
	try
	{
		Span sp_range = Span(10000);
		sp_range.addRange(source.begin(), source.end());

		std::cout << "[10a] shortest: " << sp_range.shortestSpan() << " (expected 10)" << std::endl;
		std::cout << "[10a] longest:  " << sp_range.longestSpan() << " (expected 99990)" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[10a] unexpected exception: " << e.what() << std::endl;
	}
	
	Span sp_small = Span(3);
	std::vector<int> big_source;
	for (int i = 0; i < 10; ++i)
		big_source.push_back(i);
	try
	{
		sp_small.addRange(big_source.begin(), big_source.end());
		std::cout << "[10b] ERROR: no exception thrown" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[10b] exception: " << e.what() << std::endl;
	}

	std::cout << "=== addRange to list===" << std::endl;
	std::list<int> l_source;
	for(int i = 0; i < 10000; i++)
		l_source.push_back(i+10);
	try
	{
		Span sp_range = Span(10000);
		sp_range.addRange(l_source.begin(), l_source.end());

		std::cout << "[11] shortest: " << sp_range.shortestSpan() << " (expected 1)" << std::endl;
		std::cout << "[11] longest:  " << sp_range.longestSpan() << " (expected 9999)" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[11] unexpected exception: " << e.what() << std::endl;
	}
	return 0;
}