#include "ScavTrap.hpp"

int main() {
	ScavTrap st1("Scavy1");
    ScavTrap st2("Scavy2");

    st1.attack("target");
    st1.takeDamage(5);
    st1.beRepaired(5);
    st1.guardGate();

    return 0;
}