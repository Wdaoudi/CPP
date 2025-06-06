#pragma once

#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <string>

class ScalarConverter
{
  private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
  public:
	static void convert(std::string to_convert);
	//static allow to use the method without instancing the class
};