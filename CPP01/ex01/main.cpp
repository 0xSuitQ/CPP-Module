#include "Zombie.hpp"
#include <iostream>

int	main( void ) {
	int n = 10;

	Zombie *zombies = zombieHorde(n, "Zombie Horde");
	for (int i = 0; i < n; i++) {
		std::cout << i + 1 << ".";
		zombies->announce();
		std::cout << "\n";
	}

	for (int i = 0; i < n; i++) {
		zombies[i].~Zombie();
	}
	operator delete[](zombies);

	return 0;
}