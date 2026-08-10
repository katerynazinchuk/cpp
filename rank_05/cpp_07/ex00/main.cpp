#include "whatever.hpp"
#include <string>
#include <iostream>

int main( void ) {
std::cout << "=== int test ===" << std::endl;
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

std::cout << "=== double test ===" << std::endl;
double dd = 2.2;
double bb = 3.3;
::swap( dd, bb );
std::cout << "dd = " << dd << ", bb = " << bb << std::endl;
std::cout << "min( dd, bb ) = " << ::min( dd, bb ) << std::endl;
std::cout << "max( dd, bb ) = " << ::max( dd, bb ) << std::endl;

std::cout << "=== char test ===" << std::endl;
char e = 'a';
char f = 'z';
::swap( e, f );
std::cout << "e = " << e << ", f = " << f << std::endl;
std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

std::cout << "=== string test ===" << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}