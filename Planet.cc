#include <ostream>
#import "Planet.h"

Planet::Planet(int mass, int radius, Point position, Point heading): mass(mass), radius(radius), position(position), heading(heading)
{
}

std::ostream& Planet::operator<<(std::ostream &strm)
{
    return strm << "Mass: "     << mass     << "\n"
                << "Radius: "   << radius   << "\n"
                << "Position: " << position << "\n"
                << "Heading: "  << heading  << "\n";
}