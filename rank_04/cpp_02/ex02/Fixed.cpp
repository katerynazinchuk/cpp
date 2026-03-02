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

//------------------------------------------------------------------//
float Fixed::toFloat(void) const
{
	return (float)_value  / (1 << _bits);
}

int Fixed::toInt( void ) const
{
	return (_value >> _bits);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

//-------------------comparison operators---------------------------//
bool Fixed::operator>(const Fixed& other) const
{
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_value != other._value);
}

//----------------------arithmetic operators------------------------//

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(_value + other._value);
	return (result);	
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(_value - other._value);
	return (result);	
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long result_raw = (long)_value * other._value; //(a/256)*(b/256)
	result.setRawBits(result_raw >> _bits);
	return (result);	
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long result_raw = ((long)_value << _bits) / other._value;
	result.setRawBits(result_raw);
	return (result);	
}

//----------------------increment / decrement-----------------------//
Fixed& Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed  Fixed::operator++(int)
{
	Fixed old(*this);
	_value++;
	return (old);
}

Fixed& Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed  Fixed::operator--(int)
{
	Fixed old(*this);
	_value--;
	return (old);
}

//----------------------------min / max----------------------------//
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if(a < b)
		return(a);
	return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if(a < b)
		return(a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if(a > b)
		return(a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if(a > b)
		return(a);
	return (b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
