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
	bool _isValidDate(const std::string& date) const;
	std::string _trim(const std::string& str) const;
	void _calculateAndPrint(const std::string& date, double amount) const;
    void _loadDatabase(const std::string& filename);

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange &other);
	~BitcoinExchange();
	BitcoinExchange &operator=(BitcoinExchange &other);

    void processInput(const std::string &inputPath);
};

#endif