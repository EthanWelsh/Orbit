#include <ostream>
#include <sstream>
#include <math.h>
#include <iostream>
#include "Planet.h"

Planet::Planet(int mass, int radius, Point origin, Vector heading): mass(mass), radius(radius), origin(origin), heading(heading)
{
}

std::string Planet::toString()
{
    std::stringstream x;

    x << "Mass: "     << mass     << "\n"
      << "Radius: "   << radius   << "\n"
      << "Position: " << origin.toString() << "\n"
      << "Heading: "  << heading.toString() << "\n";

    return x.str();
}

// Calculates the gravitational pull from this planet to a given planet P
double Planet::calculateGravity(Planet &p)
{
    int mass1 = mass;
    int mass2 = p.mass;
    double distanceBetween = origin.distance(p.origin);

    return ((mass1 * mass2) / pow(distanceBetween, 2));
}

// Calculates the horizontal and vertical distance to another given planet P.
void Planet::distance(Planet &p, double &horizontalDistance, double &verticalDistance)
{
    horizontalDistance = p.origin.x - origin.x;
    verticalDistance =   p.origin.y - origin.y;

    //printf("H: %f V: %f\n", horizontalDistance, verticalDistance);
}

// Given a planet, calculates a gravitational vector towards that planet.
Vector Planet::findVector(Planet &p)
{
    double forceBetween = calculateGravity(p);

    double horizontalDistance = 0;
    double verticalDistance = 0;
    distance(p, horizontalDistance, verticalDistance);

    //printf("HDIS: %f\n", horizontalDistance);

    double totalDistance = abs(horizontalDistance) + abs(verticalDistance);

    double xComponent = (forceBetween/totalDistance) * horizontalDistance;
    double yComponent = (forceBetween/totalDistance) * verticalDistance;

    //printf("H: %f \t V: %f \t X: %f\t Y: %f HEAD: ", horizontalDistance, verticalDistance, xComponent, yComponent);
    //std::cout << heading.toString() << std::endl;

    Vector toReturn(xComponent, yComponent);

    return toReturn;
}

// Given a deque of planets, sums them into a final heading vector which will be its orbital path
void Planet::sumVector(std::deque<Planet> dq)
{
    Vector final(heading.x,heading.y);

    Vector temp(0,0);

    for(int i = 0; i < dq.size(); i++)
    {
        temp = findVector(dq.at(i));
        final.x = final.x + temp.x;
        final.y = final.y + temp.y;
    }

    heading = final;
    origin.x += heading.x;
    origin.y += heading.y;
}