#include "BitcoinExchange.hpp"
#include <unistd.h>

BitcoinExchange::BitcoinExchange() {
	parseDB();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		_data = rhs._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::_validateDate(const std::string &date) const {
	std::regex	pattern("^(19|20)\\d\\d-(0[1-9]|1[012])-(0[1-9]|[12][0-9]|3[01])$");

	if (std::regex_match(date, pattern))
		return ;
	else {
		throw (BitcoinExchange::invalidDateException());
	}
}

double BitcoinExchange::_validatePrice(const std::string &price, bool flag) const {
	// if (isInt(date))
	// 	_validateInt(date);
	// else if (isDouble(date))
	// 	_validateDouble(date);
	// else throw(BitcoinExchange::invalidInputException);

	char	*end;
	double	dd = std::strtod(price.c_str(), &end);

	if (*end != '\0') {
		throw(BitcoinExchange::invalidDateException());
	} else if (dd < 0) {
		throw (BitcoinExchange::negativeValueException());
	} else if (flag == 1 && dd > 1000) {
		throw (BitcoinExchange::largeValueException());
	}

	return dd;
}

void	BitcoinExchange::_validateLine(const std::string &line) {
	size_t	delimiter = line.find(',');
	// if (delimiter == std::string::npos) {
	// 	return;
	// }
	std::string date = line.substr(0, delimiter);
	std::string	price = line.substr(delimiter + 1);

	if (date.empty() || price.empty()) {
        throw std::runtime_error("Empty date or price");
    }

	_validateDate(date);
	_data[date] = _validatePrice(price, 0);
}

void	BitcoinExchange::parseDB() {
	std::ifstream	file;
	std::string		line = "";
	int 			i = 0;

	file.open("data.csv");

	if (file.is_open()) {
		while (getline(file, line)) {
			if (i == 0) {
				i++;
				line = "";
				continue;
			}
			if (!line.empty()) { 
				try {
					_validateLine(line);
				} catch (const std::exception& e) {
					std::cerr << "Error processing line: " << " - " << e.what() << std::endl;
				}
        	}
			line = "";
		}
		file.close();
	} else {
		std::cout << "Error: could not open file." << std::endl;
	}
}

double BitcoinExchange::_calculatePrice(const std::string &date, double amount) {
	std::map<std::string, double>::iterator it = _data.lower_bound(date);
	if (it != _data.begin()) {
		--it;
		return amount * it->second;
	} else {
	// } else if (it != _data.end()) {
		return amount * it->second;
	}
}

void	BitcoinExchange::_validateUserLine(const std::string &line) {
	size_t	delimiter = line.find(" | ");
	std::string date = line.substr(0, delimiter);
	std::string	value = line.substr(delimiter + 3);
	double		amount;
	double		calculated_price;
	
	try {
		_validateDate(date);
		amount = _validatePrice(value, 1);
		calculated_price = _calculatePrice(date, amount);
		std::cout << date << " => ";
		if (amount == static_cast<int>(amount)) {
			std::cout << static_cast<int>(amount);
		} else {
			std::cout << amount;
		}
		std::cout << " = ";
		if (calculated_price == static_cast<int>(calculated_price)) {
			std::cout << static_cast<int>(calculated_price) << std::endl;
		} else {
			std::cout << calculated_price << std::endl;
		}
	} catch (const BitcoinExchange::invalidDateException &e) {
		std::cerr << e.what() << " => " << date << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void	BitcoinExchange::parseInput(const char *filename) {
	std::ifstream	file;
	std::string		line = "";
	int				i = 0;

	file.open(filename);
	if (file.is_open()) {
		while (getline(file, line)) {
			if (i == 0) {
				i++;
				line = "";
				continue;
			}
			if (!line.empty()) { 
				try {
					_validateUserLine(line);
				} catch (const std::exception& e) {
					std::cerr << e.what() << std::endl;
				}
        	}
			line = "";
		}
		file.close();
	}
}