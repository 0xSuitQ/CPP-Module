#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	
	if (ac == 2) {
		BitcoinExchange exchange;

		exchange.parseInput(av[1]);
	}
}