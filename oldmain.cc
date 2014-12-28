using namespace std;

int main()
{
    int mass = 4;
    int radius = 1;
    Point origin(-10, -15);
    Vector heading(-3, 1);

    Planet planet(mass, radius, origin, heading);

    int mass1 = 100;
    int radius1 = 30;
    Point origin1(1, 1);
    Vector heading1(0, 0);

    Planet sun(mass1, radius1, origin1, heading1);

    //std::cout << planet.toString() << endl;
    //std::cout << sun.toString()<< endl;

    //std:cout << "Force between: " << planet.calculateGravity(sun) << endl;

    std::deque <Planet> solarSystem;

    solarSystem.push_front(sun);

    for (int i = 0; i < 30; i++)
    {
        planet.sumVector(solarSystem);
        cout << planet.origin.toString() << endl;
    }

    cin.clear();
    cin.ignore(255, '\n');
    cin.get();
    return 0;
}
