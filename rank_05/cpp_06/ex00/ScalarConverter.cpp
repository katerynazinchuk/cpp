#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>

static bool isPseudo(const std::string& str)
{
	if(str == "nan" || str == "+inf" || str == "-inf" || str == "nanf" || str == "+inff" || str == "-inff")
	{
		return true;
	}
	return false;
}

static bool isChar(const std::string& str)
{
	if(str.length() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		return true;
	}
	return false;
}

static bool isInt(const std::string& str)
{
	size_t i = 0;

	if (str.empty())
		return false;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (i == str.length())
		return false;
	while (i < str.length())
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

static bool isDouble(const std::string& str)
{
	size_t i = 0;
	bool isDot = false;
	int digits = 0;

	if (str.empty())
		return false;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (i == str.length())
		return false;
	while (i < str.length())
	{
		if (isdigit(str[i]))
			digits++;
		else if (str[i] == '.')
		{
			if(isDot)
				return false;
			isDot = true;
		}
		else
			return false;
		i++;
	}
	return (isDot && digits > 0);
}

static bool isFloat(const std::string & str)
{
	if(str.length() <= 1)
		return false;
	if(str[str.length() - 1] != 'f')
		return false;
	if(!isDouble(str.substr(0, str.length() - 1)))
		return false;
	return true;
}

static void printChar(double d)
{
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<int>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

void ScalarConverter::convert(const std::string & str)
{
	if(isPseudo(str))
		std::cout << "detected: pseudo" << std::endl;
	else if(isChar(str))
		printChar(str[1]);
	else if(isInt(str))
		std::cout << "detected: int" << std::endl;
	else if(isFloat(str))
		std::cout << "detected: float" << std::endl;
	else if(isDouble(str))
		std::cout << "detected: double" << std::endl;
	else
		std::cout << "detected: unknown" << std::endl;
}


