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

int Span::longestSpan() const
{
}

int Span::shortestSpan() const
{

}
