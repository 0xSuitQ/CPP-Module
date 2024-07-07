#include "Harl.hpp"

Harl::Harl(void) {
	functionMap["debug"] = &Harl::debug;
	functionMap["info"] = &Harl::info;
	functionMap["warning"] = &Harl::warning;
	functionMap["error"] = &Harl::error;
}

Harl::~Harl(void) {}

void Harl::debug() { std::cout << "Debug: I love having extra bacon.\n"; }

void Harl::info() { std::cout << "Info: I cannot believe adding extra bacon costs more money.\n"; }

void Harl::warning() { std::cout << "Warning: I'm not feeling so good.\n"; }

void Harl::error() { std::cout << "Error: This is unacceptable! I want to speak to the manager now.\n"; }

void Harl::complain(std::string level) {
	level = tolower(level);
	if (functionMap.count(level) > 0) {
		(this->*functionMap[level])();
	} else {
		std::cout << "Invalid level\n";
	}
}

std::string	tolower( std::string str) {
	for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    return str;
}