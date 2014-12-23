class Vector
{

public:
    double x;
    double y;

    Vector(double x, double y);
    Vector operator+(Vector& v);
    std::string toString();

};