#include "ScalarConverter.hpp"
#include <iostream>

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


void ScalarConverter::convert(const std::string & str)
{
	if(isPseudo(str))
		std::cout << "detected: pseudo" << std::endl;
	else  

	std::cout << str << std::endl;
}


