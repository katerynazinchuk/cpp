#ifndef POINT_HPP
#define POINT_HPP
# include <string>
# include <iostream>
# include "Fixed.hpp"


class Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);//copy constructor
		Point& operator=(const Point& other);//copy assignment operator overload
		~Point();

		Fixed getX(void) const;
		Fixed getY(void) const;
};

#endif