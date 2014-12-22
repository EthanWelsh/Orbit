#include <iosfwd>
#include <iostream>
#include "Point.h"

Point::Point(int x, int y): x(x), y(y)
{
}

Point Point::operator+(Point& p)
{
    Point ret(0,0);
    ret.x = x + p.x;
    ret.y = y + p.y;

    return ret;
}

std::ostream& Point::operator<<(std::ostream &strm) const
{
    return strm << "(" << x << ", " << y << ")\n";
}