#include <iosfwd>
#include <iostream>
#include <sstream>
#include <math.h>
#include "Vector.h"

Vector::Vector(int x, int y): x(x), y(y)
{
}

Vector Vector::operator+(Vector& v)
{
    Vector ret(0,0);
    ret.x = x + v.x;
    ret.y = y + v.y;

    return ret;
}

std::string Vector::toString()
{
    std::stringstream strm;
    strm << "(" << x << ", " << y << ")\n";
    return strm.str();
}