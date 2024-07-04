#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void	HumanB::attack(void) const {
    if (this->_weapon)
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << _name << " doesn't have a weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }