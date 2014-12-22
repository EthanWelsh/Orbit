
class Point
{

public:
    int x;
    int y;

    Point(int x, int y);
    std::string toString();

    double distance(Point &p);

};