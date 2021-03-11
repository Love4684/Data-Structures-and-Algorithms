
#include <cmath>
#include <iostream>
 
class Point {
public:
    Point( void ) : _x(0.0), _y(0.0) { };

    static Point cartesian( const float x, const float y )
    { return Point( x, y ); }

    static Point polar( const float rho, const float theta )
    { return Point( rho*std::cos(theta), rho*std::sin(theta) ); }
    
    friend std::istream & operator >> (std::istream & input, Point & that)
    { return input >> that._x >> that._y; }

    friend std::ostream & operator << (std::ostream & output, Point & that)
    { return output << "(" << that._x << ", " << that._y << ")"; }

private:
    Point( const float x, const float y ) : _x(x), _y(y)  { };
    float _x;
    float _y;
};
 

int main( int argc, char **argv )
{
    Point p;
    std::cout << "Enter a new point x y: ";
    std::cin >> p;
    std::cout << "p  = " << p << std::endl;
    
    return 0;
}
