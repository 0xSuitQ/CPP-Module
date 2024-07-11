#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << this->_type << " constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain; 
}

void	Dog::makeSound() const {
	std::cout << "Dog barks" << std::endl;
}

Dog::Dog(const Dog& src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << "Dog assignment operator called." << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}