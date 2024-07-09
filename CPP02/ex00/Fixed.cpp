#include "Fixed.hpp"

Fixed::Fixed(void) : _num(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &new_value) {
	std::cout << "Copy constructor called" << std::endl;
	*this = new_value;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_num);
}

void Fixed::setRawBits(int const raw) { _num = raw; }

Fixed &Fixed::operator=(const Fixed &value) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &value)
		_num = value.getRawBits();
	return (*this);
}