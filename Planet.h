#include <iosfwd>
#include "Point.h"
#include "Vector.h"

class Planet
{

public:
    int mass;
    int radius;

    Point position;
    Vector heading;

    std::string toString();

    Planet(int mass, int radius, Point position, Vector heading);
    double calculateGravity(Planet &p);





};