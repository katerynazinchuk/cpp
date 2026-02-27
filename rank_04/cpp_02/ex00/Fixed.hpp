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
    Fixed(const Fixed& other);//copy constructor
    Fixed& operator=(const Fixed& other);//copy assignment operator overload
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);

};

#endif