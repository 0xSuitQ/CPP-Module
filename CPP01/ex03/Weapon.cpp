#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {}

Weapon::~Weapon() {}

const std::string	&Weapon::getType() const {
	return _type;
}

void	Weapon::setType(const std::string &newType) {
	this->_type = newType;
}