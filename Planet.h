#include <iosfwd>
#include <deque>

#include "Point.h"
#include "Vector.h"

class Planet
{

public:
    int mass;
    int radius;

    Point origin;
    Vector heading;
	int color;

    std::string toString();

    Planet(int mass, int radius, Point position, Vector heading, int color);
    void distance(Planet &p, double &horizontalDistance, double &verticalDistance);
    double calculateGravity(Planet &p);
    Vector findVector(Planet &p);

    void sumVector(std::deque<Planet> dq);
	void setupPlanets(std::deque<Planet> planets);



};