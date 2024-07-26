#ifndef SCALACONVERTER_HPP
# define SCALACONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <limits>
# include <cstdlib>
# include <cerrno>
# include <iomanip>

class ScalarConverter {
public:
	static void convert(const std::string &str);
private:
	static char		_c;
	static int		_i;
	static float	_f;
	static double	_d;
	static bool		_posChar;
	static bool		_posInt;

	ScalarConverter();
	ScalarConverter(const ScalarConverter  &src);
	~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &rhs);
	
	static void convChar(const std::string &str);
	static void convInt(const std::string &str);
	static void convFloat(const std::string &str);
	static void convDouble(const std::string &str);
};

typedef bool (*typeInput)(const std::string &str);
typedef void (*typeConv)(const std::string &str);

std::string str2int(int &i, const char *s, int base);
bool isChar(std::string const &str);
bool isInt(std::string const &str);
bool isFloat(std::string const &str);
bool isDouble(std::string const &str);
void printType(int i);

#endif