#include <iosfwd>
#include <iostream>
#include <sstream>
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

std::string Point::toString()
{
    std::stringstream strm;

    strm << "(" << x << ", " << y << ")\n";

    return strm.str();
}