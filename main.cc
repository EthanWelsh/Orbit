#include <iostream>
#include <deque>
#include "Planet.h"

using namespace std;

int main()
{
    int mass = 4;
    int radius = 1;
    Point origin(200, 100);
    Vector heading(25, 25);

    Planet planet(mass, radius, origin, heading);

    int mass1 = 100000;
    int radius1 = 30;
    Point origin1(100,500);
    Vector heading1(0, 0);

    Planet sun(mass1, radius1, origin1, heading1);


    std::cout << planet.toString() << endl;
    std::cout << sun.toString()<< endl;

    std:cout << "Force between: " << planet.calculateGravity(sun) << endl;

    Vector v = planet.findVector(sun);

    printf("X: %f\nY: %f", v.x, v.y);


    return 0;
}
