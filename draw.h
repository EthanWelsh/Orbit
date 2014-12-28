#include "Planet.h"

/* define index constants into the colors array */
#define BLACK   0
#define RED     1
#define YELLOW  2
#define ORANGE  3
#define GREEN   4
#define BLUE    5
#define WHITE   6
#define MAGENTA 7
#define CYAN    8
#define GREY    9
#define OPAL    10
#define BRICKRED 11
#define DARKGREEN 12
#define PURPLE 13
#define GOLD 14

void lighting_setup();

//void drawPlanet(Planet p);
void drawSolarSystem(std::deque<Planet> planets);