#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

// helper
void print_map(std::map<std::string, float> &m)
{
	for (std::map<std::string, float>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << it->first << " = " << it->second << "; ";

	std::cout << '\n';
}

bool BitcoinExchange::loadDatabase(const std::string &dbPath)
{
	std::ifstream file("data.csv");
	std::string line;
	std::getline(file, line); // Skip the first line

	while (std::getline(file, line))
	{
		size_t commaPos = line.find(',');
		std::string date = line.substr(0, commaPos);
		float rate = std::atof(line.substr(commaPos + 1).c_str());
		_data[date] = rate;
	}
	print_map(_data);
}

void BitcoinExchange::processInput(const std::string &inputPath)
{
	std::ifstream file("input.txt");
	std::string line;
	std::getline(file, line); // Skip the first line

	size_t pipePos = line.find('|');
	if (pipePos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = line.substr(0, pipePos - 1);
	std::string valStr = line.substr(pipePos + 2);
}
