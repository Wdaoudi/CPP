#include "BitcoinExchange.hpp"

//forme canonique
BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const std::string &csv)
{
	(void)csv;
	loadDatabase(csv);
} //load database
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _map(other._map)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_map = other._map;
	return (*this);
}
BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string &csv)
{
	float	value;

	std::ifstream file(csv.c_str());
	//c_str() converti un std::string en const char *
	// ifstream n accepte pas les string en c++98
	if (!file.is_open())
	{
		std::cout << "Error: could not open database file" << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		//preparation remplissage de la map
		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		// verif format et remplissage des valeurs
		if (std::getline(iss, date, ',') && std::getline(iss, valueStr))
		{
			std::istringstream valueStream(valueStr);
			if (!(valueStream >> value))
			{
				std::cout << "Error converting value : " << valueStr << " for date: " << date;
				continue ;
			}
			// l envois dans value permet de parser les espaces
			//injection
			_map[date] = value;
			// std::cout << "Added to database: " << date << " => " << value << std::endl;
		}
		else
			std::cout << "Error parsing line: " << line << std::endl;
	}
	// std::map<std::string, float>::iterator it;
	// for (it = _map.begin(); it != _map.end();it++)
	//     std::cout << "key = "<< it->first << " value= "<< it->second << std::endl;
	//it->first (iterator sur la cle de la map) second la value
	// std::cout << "Database loaded with " << _map.size() << " entries" << std::endl;
	// if (!_map.empty())
	// {
	// 	std::cout << "First entry: " << _map.begin()->first << " => " << _map.begin()->second << std::endl;
	// 	std::cout << "Last entry: " << (--_map.end())->first << " => " << (--_map.end())->second << std::endl;
	// }
	// else
	// {
	// 	std::cout << "WARNING: Database is empty!" << std::endl;
	// }
	return ;
}

bool BitcoinExchange::processInput(const std::string &inputFile)
{
	float	value;
	float	rate;
	float	result;

	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not open the input file" << std::endl;
		return (false);
	}
	std::string line;
	//saut de ligne
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string dateStr;
		std::string valueStr;
		if (std::getline(iss, dateStr, '|') && std::getline(iss, valueStr))
		{
			dateStr.erase(0, dateStr.find_first_not_of(" \t"));
			// effaces de 0 jusqu au premier caractere different whitespace
			dateStr.erase(dateStr.find_last_not_of(" \t") + 1);
			valueStr.erase(0, valueStr.find_first_not_of(" \t"));
			valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
			//check le format date
			if (!isValidDate(dateStr))
			{
				std::cout << "Error: bad Input => " << dateStr << std::endl;
				//esquiver les mauvaises dates et avancer jusqu au prochain
				continue ;
			}
			//transforme la chaine de caractere en flux d entre
			std::istringstream valueStream(valueStr);
			if (!(valueStream >> value))
			{
				std::cout << "Error : not a valid number." << std::endl;
				continue ;
			}
			if (value < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue ;
			}
			if (value > 1000)
			{
				std::cout << "Error: too large number." << std::endl;
				continue ;
			}
			rate = getExchangeRate(dateStr);
			result = value * rate;
			std::cout << dateStr << " => " << value << " = " << result << std::endl;
		}
		else
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	return (true);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	//check le format et les numeros partout
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!isdigit(date[i]))
			return (false);
	}
	//verifier les valeurs
	int year, month, day;
	std::istringstream yss(date.substr(0, 4));
	std::istringstream mss(date.substr(5, 2));
	std::istringstream dss(date.substr(8, 2));
	if (!(yss >> year) || !(mss >> month) || !(dss >> day))
		return (false);
	if (month < 1 || month > 12)
		return (false);
	int dayInTheMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day < 1 || day > dayInTheMonth[month])
		return (false);
	return (true);
}

float BitcoinExchange::getExchangeRate(const std::string &date)
{
	std::map<std::string, float>::iterator it = _map.find(date);
	if (it != _map.end())
	{
		return (it->second);
	}
	//methode de std::map qui retourne it sur le premier superieur
	// ou map.end() si pas trouve
	it = _map.lower_bound(date);
	if (it == _map.begin() && date < it->first)
	{
		//date avant la premiere dans la data
		std::cout << "The requested date is before the first one in our database" << std::endl;
		return (0);
	}
	if (it == _map.end() || date < it->first)
	{
		//reculee pour prendre la derniere date de la table
		it--;
	}
	// std::cout << "Database loaded with " << _map.size() << " entries" << std::endl;
	// if (!_map.empty()) {
	//     std::cout << "First date in database: " << _map.begin()->first << std::endl;
	//     std::cout << "Last date in database: " << (--_map.end())->first << std::endl;
	// }
	return (it->second);
}