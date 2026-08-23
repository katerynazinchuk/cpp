#ifndef RPN_HPP
#define RPN_HPP
#include <string>
#include <iostream>
#include <stdexcept>
#include <stack>

class RPN
{
	public:
		RPN();
		RPN(const RPN & other);
		RPN& operator=(const RPN & other);
		~RPN();

		static int calculate(const std::string& arg);
};

#endif