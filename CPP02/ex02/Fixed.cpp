#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _num(0) {}

Fixed::Fixed(const int &new_value) : _num(new_value << _fractionalPart) {}

Fixed::Fixed(const Fixed &new_value) { *this = new_value; }

Fixed::Fixed(const float &new_value) : _num((int)roundf((new_value * (1 << _fractionalPart)))) {}

Fixed::~Fixed(void) {}

void Fixed::setRawBits(int const raw) { _num = raw; }

float Fixed::toFloat(void) const {
    return ((float)_num / (1 << _fractionalPart));
}

int Fixed::toInt(void) const { return (_num >> _fractionalPart); }

int Fixed::getRawBits(void) const { return (_num); }

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return ((a.toFloat() > b.toFloat()) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return ((a.toFloat() > b.toFloat()) ? a : b);
}

Fixed &Fixed::operator=(const Fixed &value) {
    if (this != &value)
        _num = value.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &oStream, const Fixed &value) {
    oStream << value.toFloat();
    return (oStream);
}

bool Fixed::operator>(const Fixed &second) const {
    return (this->getRawBits() > second.getRawBits());
}

bool Fixed::operator<(const Fixed &second) const {
    return (this->getRawBits() < second.getRawBits());
}

bool Fixed::operator>=(const Fixed &second) const {
    return (this->getRawBits() >= second.getRawBits());
}

bool Fixed::operator<=(const Fixed &second) const {
    return (this->getRawBits() <= second.getRawBits());
}

bool Fixed::operator==(const Fixed &second) const {
    return (this->getRawBits() == second.getRawBits());
}

bool Fixed::operator!=(const Fixed &second) const {
    return (this->getRawBits() != second.getRawBits());
}

float Fixed::operator+(const Fixed &second) const {
    return (this->toFloat() + second.toFloat());
}

float Fixed::operator-(const Fixed &second) const {
    return (this->toFloat() - second.toFloat());
}

float Fixed::operator*(const Fixed &second) const {
    return (this->toFloat() * second.toFloat());
}

float Fixed::operator/(const Fixed &second) const {
    return (this->toFloat() / second.toFloat());
}

Fixed &Fixed::operator--(void) {
    _num--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed old = *this;
    _num--;
    return (old);
}

Fixed &Fixed::operator++(void) {
    _num++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed old = *this;
    _num++;
    return (old);
}