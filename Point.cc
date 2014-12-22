#include <iosfwd>
#include <iostream>
#include <sstream>
#include <math.h>
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

double Point::distance(Point &p)
{
    int x1 = x;
    int x2 = p.x;
    int y1 = y;
    int y2 = p.y;

    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}