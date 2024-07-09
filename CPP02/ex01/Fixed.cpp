#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _num(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int &new_value) : _num(new_value << _fractionalPart) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &new_value) {
	std::cout << "Copy constructor called" << std::endl;
	*this = new_value;
}

Fixed::Fixed(const float &new_value) : _num((int)roundf((new_value * (1 << _fractionalPart)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) { std::cout << "Destructor called" << std::endl; }

void Fixed::setRawBits(int const raw) { _num = raw; }

float Fixed::toFloat(void) const { return ((float)_num / (1 << _fractionalPart)); }

int Fixed::toInt(void) const { return (_num >> _fractionalPart); }

int Fixed::getRawBits(void) const {
    return (_num);
}

Fixed &Fixed::operator=(const Fixed &value) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &value)
        _num = value.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &oStream, const Fixed &value) {
    oStream << value.toFloat();
    return (oStream);
}