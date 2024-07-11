#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << this->_type << " constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Dog barks" << std::endl;
}