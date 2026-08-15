#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
//std::runtime_error

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int number);
		long		shortestSpan() const;
		long		longestSpan() const;
		template<typename It>
		void addRange(It first, It last)
		{
			if(_numbers.size() + std::distance(first, last) > _N)
				throw std::runtime_error("out of size");
			_numbers.insert(_numbers.end(), first, last);
		}
};

#endif
