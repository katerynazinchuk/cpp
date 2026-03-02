#include "Point.hpp"

static Fixed cross(Point const a, Point const b, Point const p)
{
	Fixed abx = b.getX() - a.getX();  // vector AB x
	Fixed aby = b.getY() - a.getY();  // vector AB y
	Fixed apx = p.getX() - a.getX();  // vector AP x
	Fixed apy = p.getY() - a.getY();  // vector AP y

	Fixed result = (abx * apy) - (aby * apx);
	return (result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = cross(a, b, point);
	Fixed d2 = cross(b, c, point);
	Fixed d3 = cross(c, a, point);
	
	bool same_sign = ((d1 > Fixed(0)) == (d2 > Fixed(0))) && ((d2 > Fixed(0)) == (d3 > Fixed(0)));
	if (same_sign)
		return (true);
	else
		return (false);
}


