#include <iosfwd>
#include <deque>

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
    void distance(Planet &p, double &horizontalDistance, double &verticalDistance);
    double calculateGravity(Planet &p);
    Vector findVector(Planet &p);

    Vector sumVector(std::deque<Planet> dq);




};