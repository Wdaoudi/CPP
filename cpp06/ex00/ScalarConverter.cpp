#include "./ScalarConverter.hpp"

//declaration
bool	isChar(const std::string &str);
bool	isInt(const std::string &str);
bool	isFloat(const std::string &str);
bool	isDouble(const std::string &str);
bool	needToBeConverted(std::string to_convert);
void	convertInt(std::string to_convert);
void	convertFloat(std::string to_convert);
void	convertDouble(std::string to_convert);
void	impossibleToConvert(void);
void	printChar(char to_convert);
void	printInt(int to_convert);
void	printFloat(float to_convert);
void	printDouble(double to_convert);

//canonical
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

//handle exception
bool	needToBeConverted(std::string to_convert)
{
	const std::string positive_inf[] = {"+inf", "inf", "+inff", "inff"};
	const std::string negative_inf[] = {"-inf", "-inff"};
	const std::string nan_values[] = {"nan", "nanf"};
	for (int i = 0; i < 2; i++)
	{
		if (to_convert == nan_values[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return (false);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (to_convert == positive_inf[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			return (false);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (to_convert == negative_inf[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			return (false);
		}
	}
	return (true);
}

//converting function
void	convertInt(std::string to_convert)
{
	long long	result;
	int			int_value;

	try
	{
		result = std::atoll(to_convert.c_str());
		if (result > INT_MAX || result < INT_MIN)
		{
			std::cout << "int: impossible (overflow)" << std::endl;
			printChar(static_cast<char>(result));
			printDouble(static_cast<double>(result));
			printFloat(static_cast<float>(result));
		}
		else
		{
			int_value = static_cast<int>(result);
			printInt(int_value);
			printChar(static_cast<char>(int_value));
			printDouble(static_cast<double>(int_value));
			printFloat(static_cast<float>(int_value));
		}
	}
	catch (const std::invalid_argument &)
	{
		impossibleToConvert();
	}
	catch (const std::out_of_range &)
	{
		std::cout << "int: impossible (out of range)" << std::endl;
	}
}

void	convertFloat(std::string to_convert)
{
	float	result;

	std::stringstream ss(to_convert);
	if (!(ss >> result))
	{
		impossibleToConvert();
		return ;
	}
	else
	{
		printInt(static_cast<int>(result));
		printChar(static_cast<char>(result));
		printDouble(static_cast<double>(result));
		printFloat((result));
	}
	return ;
}

void	convertDouble(std::string to_convert)
{
	double	result;

	std::stringstream ss(to_convert);
	if (!(ss >> result))
	{
		impossibleToConvert();
		return ;
	}
	else
	{
		printInt(static_cast<int>(result));
		printChar(static_cast<char>(result));
		printDouble(result);
		printFloat(static_cast<float>(result));
	}
	return ;
}

//fonctions for printing
void	impossibleToConvert(void)
{
	std::cout << "int : impossible" << std::endl;
	std::cout << "char : impossible" << std::endl;
	std::cout << "double : impossible" << std::endl;
	std::cout << "float : impossible" << std::endl;
}

void	printChar(char to_convert)
{
	std::cout << "char: ";
	if (static_cast<unsigned char>(to_convert) > 127)
		std::cout << "impossible (hors plage ASCII)" << std::endl;
	else if (!std::isprint(to_convert))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << to_convert << "'" << std::endl;
}

void	printInt(int to_convert)
{
	std::cout << "int: " << to_convert << std::endl;
}

void	printFloat(float to_convert)
{
	std::cout << "float: ";
	if (std::floor(to_convert) == to_convert)
	{
		// Afficher avec une décimale si c'est un nombre entier
		std::cout << std::fixed << std::setprecision(1) << to_convert << "f" << std::endl;
	}
	else
	{
		std::cout << to_convert << "f" << std::endl;
	}
}
void	printDouble(double to_convert)
{
	std::cout << "double: ";
	if (std::floor(to_convert) == to_convert)
	{
		std::cout << std::fixed << std::setprecision(1) << to_convert << std::endl;
	}
	else
	{
		std::cout << to_convert << std::endl;
	}
}

//Main function
void ScalarConverter::convert(std::string to_convert)
{
	char	c;

	if (!needToBeConverted(to_convert))
		return ;
	if (isChar(to_convert))
	{
		c = to_convert[0];
		printChar(c);
		printInt(static_cast<int>(c));
		printFloat(static_cast<float>(c));
		printDouble(static_cast<double>(c));
	}
	else if (isInt(to_convert))
		convertInt(to_convert);
	else if (isFloat(to_convert))
		convertFloat(to_convert);
	else if (isDouble(to_convert))
		convertDouble(to_convert);
	else
	{
		std::cout << "Format d'entrée non reconnu." << std::endl;
		impossibleToConvert();
	}
}

//detect
bool	isChar(const std::string &str)
{
	return (str.length() == 1 && std::isprint(str[0]));
}

bool	isInt(const std::string &str)
{
	size_t	i;

	if (str.empty())
		return (false);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (i == str.length())
		return (false);
	for (; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	isFloat(const std::string &str)
{
	bool	hasDecimalPoint;
	size_t	i;

	if (str.empty() || str[str.length() - 1] != 'f')
		return (false);
	if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return (true);
	std::string numPart = str.substr(0, str.length() - 1);
	hasDecimalPoint = false;
	i = 0;
	if (numPart[0] == '-' || numPart[0] == '+')
		i = 1;
	for (; i < numPart.length(); i++)
	{
		if (numPart[i] == '.')
		{
			if (hasDecimalPoint)
				return (false);
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(numPart[i]))
			return (false);
	}
	return (true);
}

bool	isDouble(const std::string &str)
{
	bool	hasDecimalPoint;
	size_t	i;

	if (str.empty())
		return (false);
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return (true);
	hasDecimalPoint = false;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	for (; i < str.length(); i++)
	{
		if (str[i] == '.')
		{
			if (hasDecimalPoint)
				return (false);
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(str[i]))
			return (false);
	}
	return (hasDecimalPoint);
}
