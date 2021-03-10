
#include <iostream>
#include <stdexcept>

class DivideByZero : public std::runtime_error {
public:
    DivideByZero( void ) : std::runtime_error("DivideByZero")
    { }
};

const double divide( const double a, const double b )
{
    if( b == 0 )
    {
        throw DivideByZero();
    }
    return a/b;
}

int main( int argc, char **argv )
{
    divide(5,3);
    divide(5,0);
    return 0;
}
