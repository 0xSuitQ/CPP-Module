#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name){
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;

    std::cout << "ScavTrap " << _name << " is spawned!" << std::endl;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap destructor called." << std::endl;
    return;
}

void    ScavTrap::attack( std::string const& target ) {
	if (_energyPoints <= 0) {
		std::cout << "ScavTrap " << _name << " is out of energy!" << std::endl;
		return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
}

void    ScavTrap::guardGate() const{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}