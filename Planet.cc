#include <ostream>
#include <sstream>
#import "Planet.h"

Planet::Planet(int mass, int radius, Point position, Point heading): mass(mass), radius(radius), position(position), heading(heading)
{
}

std::string Planet::toString()
{
    std::stringstream x;

    x << "Mass: "     << mass     << "\n"
      << "Radius: "   << radius   << "\n"
      << "Position: " << position << "\n"
      << "Heading: "  << heading  << "\n";

    return x.str();
}