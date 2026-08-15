#include "Span.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int n) : _n(n)
{
	_numbers.reserve(n);
}

Span::Span(const Span& other) : _n(other._n), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_n = other._n;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}
