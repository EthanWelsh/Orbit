#include <iosfwd>
#include <iostream>
#include <sstream>
#include <math.h>
#include "Point.h"

Point::Point(double x, double y): x(x), y(y)
{
}

std::string Point::toString()
{
    std::stringstream strm;
    strm << "(" << x << ", " << y << ")";
    return strm.str();
}

double Point::distance(Point &p)
{
    double x1 = x;
    double x2 = p.x;
    double y1 = y;
    double y2 = p.y;

    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}