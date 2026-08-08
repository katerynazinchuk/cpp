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

static void printInt(double d)
{
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double d)
{
	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (!std::isnan(f) && !std::isinf(f) && f == static_cast<long>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void printDouble(double d)
{
	std::cout << "double: " << d;
	if (!std::isnan(d) && !std::isinf(d) && d == static_cast<long>(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
	bool pseudo = isPseudo(str);
	bool pseudoF = pseudo && str[str.length() - 1] == 'f';

	if (isChar(str))
	{
		char c = str[1];
		printChar(c);
		printInt(c);
		printFloat(c);
		printDouble(c);
	}
	else if (isInt(str))
	{
		long l = strtol(str.c_str(), NULL, 10);
		printChar(l);
		printInt(l);
		printFloat(l);
		printDouble(l);
	}
	else if (isFloat(str) || pseudoF)
	{
		float f = strtof(str.c_str(), NULL);
		printChar(f);
		printInt(f);
		printFloat(f);
		printDouble(f);
	}
	else if (isDouble(str) || pseudo)
	{
		double d = strtod(str.c_str(), NULL);
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}