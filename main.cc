#include <iostream>
#include <deque>
#include "Planet.h"

using namespace std;

int main()
{
    //deque<Planet> dq();

    int m = 500;
    int r = 20;
    Point p(25, 25);
    Vector h(30, 30);


    Planet planet(m, r, p, h);

    Point p1(50, 75);
    Vector h1(40,40);

    Planet planet1(m + 100, r, p1, h1);


    std::cout << planet.toString() << endl;
    std::cout << planet1.toString()<< endl;

    std:cout << "Force between: " << planet.calculateGravity(planet1) << endl;


    return 0;
}
