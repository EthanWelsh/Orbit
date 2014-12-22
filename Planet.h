#include <iosfwd>
#include "Point.h"

class Planet
{

public:
    int mass;
    int radius;

    Point position;
    Point heading;

    std::string toString();

    Planet(int mass, int radius, Point position, Point heading);




};