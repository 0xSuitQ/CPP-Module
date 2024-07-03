#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	void *memory = operator new[](N * sizeof(Zombie));

	Zombie *zombies = static_cast<Zombie *>(memory);
	for (int i = 0; i < N; i++) {
		new(zombies + i) Zombie(name);
	}
	
	return zombies;
}