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
    Point h(30, 30);


    Planet planet(m, r, p, h);

    std::cout << planet.toString() << endl;

    return 0;
}
