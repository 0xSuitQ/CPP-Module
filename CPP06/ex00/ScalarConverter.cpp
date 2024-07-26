#include "ScalarConverter.hpp"

bool isChar(std::string const &str) {
	return ((str.length() == 1 && !isdigit(str[0])) ? true : false);
}


bool isInt(std::string const &str) {
	std::stringstream ss(str);
	unsigned int i;

	ss >> i;
	return (ss.eof() && !ss.fail());
}

bool isDouble(std::string const &str) {
	std::stringstream ss(str);
	double d;

	ss >> d;
	return (ss.eof());
}

bool isFloat(std::string const &str) {
	std::stringstream ss(str);
	float f;

	ss >> f;
	return (ss.eof() && !ss.fail());
}

std::string str2int(int &i, char const *s, int base)
{
    char *end;
    long  l;
    errno = 0;
    l = strtol(s, &end, base);
    if ((errno == ERANGE && l == std::numeric_limits<long int>::max())
			|| l > std::numeric_limits<int>::max()) {
        return "OVERFLOW";
    }
    if ((errno == ERANGE && l == std::numeric_limits<long int>::min())
			|| l < std::numeric_limits<int>::min()) {
        return "UNDERFLOW";
    }
    if (*s == '\0' || *end != '\0') {
        return "INCONVERTIBLE";
    }
    i = l;
    return "OK";
}

void printType(int i) {
	std::cout << "Input is a ";
	switch (i)
	{
	case 0:
		std::cout << "char" << std::endl;
		break;
	case 1:
		std::cout << "int" << std::endl;
		break;
	case 2:
		std::cout << "float" << std::endl;
		break;
	case 3:
		std::cout << "double" << std::endl;
		break;
	default:
		std::cout << "funny error" << std::endl;
		break;
	}
		
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter  &src) {
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	_c = rhs._c;
	_i = rhs._i;
	_f = rhs._f;
	_d = rhs._d;
	_posChar = rhs._posChar;
	_posInt = rhs._posInt;
	return *this;
}

char ScalarConverter::_c;
int ScalarConverter::_i;
float ScalarConverter::_f;
double ScalarConverter::_d;
bool ScalarConverter::_posChar;
bool ScalarConverter::_posInt;

void ScalarConverter::convChar(std::string const &str) {
	_c = str[0];
	_i = static_cast<int>(_c);
	_f = static_cast<float>(_c);
	_d = static_cast<double>(_c);
}

void ScalarConverter::convInt(std::string const &str) {

	str2int(_i, str.c_str(), 0);
	if (_i < 0 || _i > 127)
		_posChar = false;
	_c = static_cast<char>(_i);
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
}

void ScalarConverter::convFloat(std::string const &str) {
	double dd = std::strtod(str.c_str(), NULL);

	if (dd >= std::numeric_limits<float>::max() || dd <= std::numeric_limits<float>::min())
		_f = 0;
	else
		_f = static_cast<float>(dd);
	if (_f < 0 || _f > 127)
		_posChar = false;
	_c = static_cast<char>(dd);
	if (_f < std::numeric_limits<int>::min() || _f > std::numeric_limits<int>::max())
		_posInt = false;
	_i = static_cast<int>(dd);
	_d = dd;
}

void ScalarConverter::convDouble(std::string const &str) {
	_d = std::strtod(str.c_str(), NULL);
	if (_d < 0 || _d > 127)
		_posChar = false;
	_c = static_cast<char>(_d);
	if (_d < std::numeric_limits<int>::min() || _d > std::numeric_limits<int>::max())
		_posInt = false;
	_i = static_cast<int>(_d);
	_f = static_cast<float>(_d);
}

void ScalarConverter::convert(std::string const &str) {
	int i;
	typeInput type[4] = {isChar, isInt, isDouble, isFloat};
	typeConv conv[4] = {ScalarConverter::convChar, ScalarConverter::convInt, ScalarConverter::convDouble, ScalarConverter::convFloat};
	
	_posChar = true;
	_posInt = true;
	if (std::string(str).compare("nan") == 0 || std::string(str).compare("nanf") == 0) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}

	for (i = 0; i < 4; i++) {
		if (type[i](str)) {
			conv[i](str);
			break ;
		}
	}

	if (i > 3)
		std::cout << "Error: invalid input" << std::endl;
	else {
		if (_posChar && std::isprint(_c))
			std::cout << "char: '" << _c << "'" << std::endl;
		else if (_posChar)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		if (_posInt)
			std::cout << "int: " << _i << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(4) << _f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(4) << _d << std::endl;
	}
}
