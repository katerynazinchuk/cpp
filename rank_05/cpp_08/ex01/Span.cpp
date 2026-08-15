#include "Span.hpp"

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
	_numbers.reserve(N);
}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if(_numbers.size() >= _N)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

long Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("not enough numbers to find a span");
	const std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	const std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
	return static_cast<long>(*maxIt) - static_cast<long>(*minIt);
}


long Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("not enough numbers to find a span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	long shortest = LONG_MAX;
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		long diff = static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]);
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

