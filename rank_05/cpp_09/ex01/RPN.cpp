#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void)other;
	return *this;
}

RPN::~RPN()
{}

int RPN::calculate(const std::string& arg)
{
	std::stack<int> rpn;
	for(size_t i = 0; i < arg.length(); ++i)
	{
		if (arg[i] == ' ')
			continue;
		if (isdigit(arg[i]))
		{
			rpn.push(arg[i] - '0');
			continue;
		}
		if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/')
		{
			if(rpn.size() < 2)
				throw std::runtime_error("Error: not enough operands");
			int b = rpn.top(); rpn.pop();
			int a = rpn.top(); rpn.pop();
			switch(arg[i])
			{
				case '+':
					rpn.push(a + b);
					break;
				case '-':
					rpn.push(a - b);
					break;
				case '*':
					rpn.push(a * b);
					break;
				case '/':
					if(b == 0)
						throw std::runtime_error("Error: impossible calculation");
					rpn.push(a / b);
					break;
			}
		}
		else 
			throw std::runtime_error("Error: unknown symbol");
	}
	if (rpn.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	return rpn.top();
}