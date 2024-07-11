#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << this->_type << " constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete  this->_brain;
}

void	Cat::makeSound() const {
	std::cout << "Cat meows" << std::endl;
}

Cat::Cat(const Cat& src) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator=(const Cat& rhs) {
	std::cout << "Cat assignment operator called." << std::endl;
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}