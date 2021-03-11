
#include <cmath>
 
class Point {
public:
    Point( void ) : _x(0.0), _y(0.0) { };

    static Point cartesian( const float x, const float y )
    { return Point( x, y ); }

    static Point polar( const float rho, const float theta )
    { return Point( rho*std::cos(theta), rho*std::sin(theta) ); }

private:
    Point( const float x, const float y ) : _x(x), _y(y)  { };
    float _x;
    float _y;
};
 

int main( int argc, char **argv )
{
    Point p1 = Point::cartesian(5.7, 1.2);
    Point p2 = Point::polar(5.7, 1.2);   
    return 0;
}
