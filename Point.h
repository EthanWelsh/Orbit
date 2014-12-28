class Point
{

public:
    double x;
    double y;

    Point(double x, double y);

    std::string toString();

    double distance(Point &p);

};