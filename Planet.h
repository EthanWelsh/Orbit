#include <iosfwd>
#include "Color.h"
#include "Point.h"

class Planet
{

public:
    int mass;
    int radius;

    Point position;
    Point heading;

    std::string Planet::toString();

    Planet(int mass, int radius, Point position, Point heading);




};