#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;

		static void convert(const std::string& str);
};

#endif

//static method convert(std::string str)