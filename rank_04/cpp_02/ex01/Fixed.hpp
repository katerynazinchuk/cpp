#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>

class Fixed
{
    private:
        int _value;
        static const int _bits;//same across all fixed objects

    public:
        Fixed();
        Fixed(const int i);
        Fixed(const float i);
        Fixed(const Fixed& other);//copy constructor
        Fixed& operator=(const Fixed& other);//copy assignment operator overload
        ~Fixed();

        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif