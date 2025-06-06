#pragma once

#include <algorithm>
#include <climits>
#include <deque>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <vector>

class BitcoinExchange
{
  private:
	std::map<std::string, float> _map;

  public:
	BitcoinExchange();
	BitcoinExchange(const std::string &csv);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();


	//declaration annex function
	void	loadDatabase(const std::string &csv);
	bool processInput(const std::string &inputFile);
	bool isValidDate(const std::string &date);
	float getExchangeRate(const std::string &date);
};


/*
 dans le cas du csv definir un separateur pour gerer les lignes et les donnees apres parsing
*/
