#include <iosfwd>
#include <iostream>
#include <sstream>
#include <math.h>
#include "Vector.h"

Vector::Vector(double x, double y): x(x), y(y)
{
}

std::string Vector::toString()
{
    std::stringstream strm;
    strm << "(" << x << ", " << y << ")";
    return strm.str();
}