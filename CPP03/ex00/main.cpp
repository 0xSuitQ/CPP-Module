#include "ClapTrap.hpp"

int main() {
	ClapTrap ct("Clappy");

    ct.attack("target");
    ct.takeDamage(5);
    ct.beRepaired(5);

    return 0;
}