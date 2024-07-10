#include "FragTrap.hpp"

int main() {
	FragTrap ft1("Frag1");
    FragTrap ft2(ft1);

    ft1.attack("target");
    ft1.takeDamage(5);
    ft1.beRepaired(5);
    ft1.highFivesGuys();

    return 0;
}