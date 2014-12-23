#include <ostream>
#include <sstream>
#include <math.h>
#import "Planet.h"

Planet::Planet(int mass, int radius, Point position, Vector heading): mass(mass), radius(radius), position(position), heading(heading)
{
}

std::string Planet::toString()
{
    std::stringstream x;

    x << "Mass: "     << mass     << "\n"
      << "Radius: "   << radius   << "\n"
      << "Position: " << position.toString() << "\n"
      << "Heading: "  << heading.toString() << "\n";

    return x.str();
}

// Calculates the gravitational pull from this planet to a given planet P
double Planet::calculateGravity(Planet &p)
{
    int mass1 = mass;
    int mass2 = p.mass;
    double distanceBetween = position.distance(p.position);

    return ((mass1 * mass2) / pow(distanceBetween, 2));
}

// Calculates the horizontal and vertical distance to another given planet P.
void Planet::distance(Planet &p, double &horizontalDistance, double &verticalDistance)
{
    horizontalDistance = abs(abs(position.x) - p.position.x);
    verticalDistance = abs(abs(position.y) - p.position.y);
}

// Given a planet, calculates a gravitational vector towards that planet.
Vector Planet::findVector(Planet &p)
{
    double forceBetween = calculateGravity(p);

    double horizontalDistance = 0;
    double verticalDistance = 0;
    distance(p, horizontalDistance, verticalDistance);

    double xComponent = (forceBetween/(horizontalDistance + verticalDistance)) * horizontalDistance;
    double yComponent = (forceBetween/(horizontalDistance + verticalDistance)) * verticalDistance;

    printf("~~~~~~~~~~~~~~\nX: %f\nY: %f\n~~~~~~~~~~~~~~\n", xComponent, yComponent);

    Vector toReturn(xComponent, yComponent);

    return toReturn;
}