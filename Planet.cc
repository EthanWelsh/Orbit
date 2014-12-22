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

double Planet::calculateGravity(Planet &p)
{
    int mass1 = mass;
    int mass2 = p.mass;
    double distanceBetween = position.distance(p.position);

    return ((mass1 * mass2) / pow(distanceBetween, 2));
}