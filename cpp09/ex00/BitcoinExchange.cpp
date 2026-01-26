#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
	std::map<std::string, float>::iterator it_other;
	std::map<std::string, float>::iterator it_this;
	for (it_other = other._data.begin(); it_other != other._data.end(); ++it_other, ++it_this)
		it_this = it_other;
}

BitcoinExchange::~BitcoinExchange()
{
}

// helper
void print_map(std::map<std::string, float> &m)
{
	for (std::map<std::string, float>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << it->first << " = " << it->second << std::endl;
}

bool isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (year < 2009 || year > 2026)
		return false;
	if (month < 1 || month > 12)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && year % 4 == 0)
	{
		daysInMonth[1] = 29;
	}

	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::loadDatabase(const std::string &dbPath)
{
	std::ifstream file(dbPath.c_str());
	if (!file.is_open())
		return false;
	std::string line;
	std::getline(file, line); // Skip the first line

	while (std::getline(file, line))
	{
		size_t commaPos = line.find(',');
		std::string date = line.substr(0, commaPos);
		float rate = std::atof(line.substr(commaPos + 1).c_str());
		_data[date] = rate;
	}
	print_map(_data); // purpose: testing
	return true;
}

void BitcoinExchange::processInput(const std::string &inputPath)
{
	std::ifstream file(inputPath.c_str());
	std::string line;
	std::getline(file, line);

	size_t pipePos = line.find('|');
	if (pipePos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, pipePos - 1);
	std::string valStr = line.substr(pipePos + 2);
}
