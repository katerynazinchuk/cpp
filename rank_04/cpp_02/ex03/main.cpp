#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    std::cout << std::boolalpha;//change 1 and 0 into true and false

    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);
	std::cout << "Triangle: A(0,0) B(4,0) C(2,4)" << std::endl;
	std::cout << "─────────────────────────────" << std::endl;

    Point p1(2.0f, 1.0f);
    std::cout << "P1(2,1) inside:    " << bsp(a, b, c, p1) << std::endl;

    Point p2(5.0f, 5.0f);
    std::cout << "P2(5,5) outside:   " << bsp(a, b, c, p2) << std::endl;

    Point p3(2.0f, 0.0f);
    std::cout << "P3(2,0) on edge:   " << bsp(a, b, c, p3) << std::endl;

    Point p4(0.0f, 0.0f);
	std::cout << "P4(0,0) on vertex: " << bsp(a, b, c, p4) << std::endl;

    return 0;
}