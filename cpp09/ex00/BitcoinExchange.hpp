#ifndef EXCHANGE_HPP
#define EXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> _data;
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
};

#endif