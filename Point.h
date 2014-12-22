
class Point
{

public:
    int x;
    int y;

    Point(int x, int y);
    Point operator+(Point& p);
    std::string Point::toString();
};