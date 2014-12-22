class Vector
{

public:
    int x;
    int y;

    Vector(int x, int y);
    Vector operator+(Vector& v);
    std::string toString();

};