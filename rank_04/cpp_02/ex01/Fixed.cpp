#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : _value(i << _bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float i) : _value(roundf(i *(1 << _bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        _value = other._value;
    }
    return *this;//return object not pointer
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (float)_value  / (1 << _bits);
}

int Fixed::toInt( void ) const
{
    return (_value >> _bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}