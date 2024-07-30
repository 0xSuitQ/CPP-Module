#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <regex>
# include <map>
# include <sstream>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		void	parseDB();
		void	parseInput(const char *filename);

		class negativeValueException : public std::exception {
			virtual const char *what() const throw() {
				return "Error: not a positive number.";
			}
		};
		class largeValueException : public std::exception {
			virtual const char *what() const throw() {
				return "Error: too large a number.";
			}
		};
		class invalidDateException : public std::exception {	
			public: 
			virtual const char *what() const throw() {
				return "Error: bad input";
			}
		};

	private:
		std::map<std::string, double>	_data;

		void	_validateLine(const std::string &line);
		void	_validateDate(const std::string &date) const;
		void	_validateUserLine(const std::string &line);
		double	_validatePrice(const std::string &price, bool flag) const;
		double	_calculatePrice(const std::string &date, double amount);
};

#endif