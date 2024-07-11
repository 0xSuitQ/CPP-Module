#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type( "WrongAnimal" ) {
	std::cout << this->_type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal " << this->_type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if ( this != &rhs ) {
		this->_type = rhs._type;
	}
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string    WrongAnimal::getType() const {
	return this->_type;
}