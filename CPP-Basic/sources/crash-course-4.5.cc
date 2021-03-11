
#include <iostream>

class Functor
{
    int _value;
public:
    Functor( const int value ) : _value( value ) { }
    int operator()( const int value ) { return _value+value; }
};

int main( int argc, char **argv )
{
    Functor functor(1);
    std::cout << "functor(3) = " << functor(3) << std::endl;

    return 0;
}
