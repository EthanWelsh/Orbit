#include <iosfwd>
#include "Color.h"
#include "Point.h"

class Planet
{

public:
    int mass;
    int radius;
    Color color;

    Point position;
    Point heading;

    std::ostream& operator<<(std::ostream &strm);

    Planet(int mass, int radius, Point position, Point heading);




};