#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap " << _name << " is spawned!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called." << std::endl;
	return;
}

void    FragTrap::highFivesGuys(void) {
	if (_energyPoints <= 0) {
		std::cout << "FragTrap " << _name << " is out of energy!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " high fives!" << std::endl;
	_energyPoints -= 1;
}