#ifndef EXCHANGE_HPP
#define EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, double> _data;
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange &other);

	bool loadDatabase(const std::string &dbPath);
    void processInput(const std::string &inputPath);

	// helpers
	bool isValidDate(const std::string &date);
    float getRate(const std::string &date);
	void print_map(std::map<std::string, double> &m);
};

#endif