#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _data()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &other)
{
	std::map<std::string, double>::iterator it_other;
	std::map<std::string, double>::iterator it_this;
	for (it_other = other._data.begin(); it_other != other._data.end(); ++it_other, ++it_this)
		it_this = it_other;
}

BitcoinExchange::~BitcoinExchange()
{
}

// helper
void print_map(std::map<std::string, double> &m)
{
	for (std::map<std::string, double>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << it->first << " = " << it->second << std::endl;
}

bool BitcoinExchange::_isValidDate(const std::string &date) const
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

std::string BitcoinExchange::_trim(const std::string& str) const {
    // 定义你认为的“空白字符”，通常包括空格、制表符等
    const std::string whitespace = " \t\r\n";
    
    // 1. 找到第一个不是空白字符的位置
    size_t first = str.find_first_not_of(whitespace);
    
    // 如果字符串全是空格，直接返回空字符串
    if (first == std::string::npos) {
        return "";
    }

    // 2. 找到最后一个不是空白字符的位置
    size_t last = str.find_last_not_of(whitespace);
    
    // 3. 截取并返回
    return str.substr(first, (last - first + 1));
}

void BitcoinExchange::_loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database file.");
    }

    std::string line;
    std::getline(file, line); // 跳过标题行 "date,exchange_rate"

    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            std::string rateStr = line.substr(commaPos + 1);
            
            std::stringstream ss(rateStr);
            double rate;
            if (ss >> rate) {
                this->_data[date] = rate; // 存入 std::map [cite: 148]
            }
        }
    }
    file.close();
}

void BitcoinExchange::_calculateAndPrint(const std::string& date, double amount) const {
    // upper_bound 返回第一个大于 date 的迭代器
    std::map<std::string, double>::const_iterator it = _data.upper_bound(date);

    // 如果返回的是 begin，说明没有任何日期比输入日期早
    if (it == _data.begin()) {
        std::cout << "Error: date too early => " << date << std::endl;
        return;
    }

    // 回退一位，得到的就是 <= date 的最接近日期
    --it;

    double result = amount * it->second;
    // 按照示例格式输出 [cite: 175-180]
    // 示例：2011-01-03 => 3 = 0.9
    std::cout << date << " => " << amount << " = " << result << std::endl;
}

// void BitcoinExchange::processInput(const std::string &inputPath)
// {
// 	std::ifstream file(inputPath.c_str());
// 	std::string line;
// 	std::getline(file, line);

// 	size_t pipePos = line.find('|');
// 	if (pipePos == std::string::npos)
// 	{
// 		std::cerr << "Error: bad input => " << line << std::endl;
// 		return;
// 	}
// 	std::string date = line.substr(0, pipePos - 1);
// 	std::string valStr = line.substr(pipePos + 2);

// 	if (!isValidDate(date))
// 	{
// 		std::cerr << "Error: not a valid date => " << date << std::endl;
// 		return;
// 	}
// 	std::map<std::string, float>::iterator it;
// 	it = std::upper_bound(_data.begin(),_data.end(), date);
// 	if (it == _data.begin())
// 	{
// 		std::cerr << "Error: date too early => " << date << std::endl;
// 		return;
// 	}
// 	else
// 	{
// 		it--;
// 	}

// 	float rate = it->second;
// }

void BitcoinExchange::processInput(const std::string& inputPath) 
	{
    	std::ifstream file(inputPath.c_str());
    	if (!file.is_open()) 
		{
    		std::cout << "Error: could not open file." << std::endl; // [cite: 173]
        	return;
    	}

    	std::string line;
    	std::getline(file, line); // 跳过标题行 "date | value" [cite: 154]

    	while (std::getline(file, line)) 
		{
        // 1. 查找分隔符 '|'
        	size_t pipePos = line.find('|');
        	if (pipePos == std::string::npos) 
			{
         		std::cout << "Error: bad input => " << line << std::endl; // [cite: 182]
            	continue;
        	}

        	// 2. 分割字符串
        	std::string datePart = line.substr(0, pipePos);
        	std::string valuePart = line.substr(pipePos + 1);

        // 去除日期前后的空格
        	datePart = _trim(datePart); 
        // 去除数值前后的空格
        	valuePart = _trim(valuePart);

        // 3. 校验日期合法性
        	if (!_isValidDate(datePart)) {
            	std::cout << "Error: bad input => " << datePart << std::endl; // [cite: 182]
            	continue;
        	}

        // 4. 解析并校验数值
        	std::stringstream ss(valuePart);
        	double val;
        	if (!(ss >> val)) {
            	std::cout << "Error: bad input => " << valuePart << std::endl;
            	continue;
        	}
        
        	if (val < 0) {
            	std::cout << "Error: not a positive number." << std::endl; // [cite: 181]
            	continue;
        	}
        	if (val > 1000) {
            	std::cout << "Error: too large a number." << std::endl; // [cite: 184]
            	continue;
        	}

        // 5. 查找汇率并计算输出 (使用 map 的 lower_bound 逻辑)
        	_calculateAndPrint(datePart, val);
    	}
	}