#ifndef SCONVERTER_H
#define SCONVERTER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);
	ScalarConverter &operator=(ScalarConverter const &rhs);
	~ScalarConverter();

public:
	static void convert(const std::string &literal);
};

#endif