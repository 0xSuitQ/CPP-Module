#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac != 2 || av[1][0] == '\0') {
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}