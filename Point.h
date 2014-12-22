
class Point
{

public:
    int x;
    int y;

    Point(int x, int y);
    Point operator+(Point& p);
    std::string toString();

    double distance(Point &p);

};