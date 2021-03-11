
#include <iostream>
#include <stdexcept>

class FooException : public std::runtime_error {
public:
    FooException( void ) : std::runtime_error("FooException")
    { }
};

class Foo {
public:
    Foo( void )
    { throw new FooException; }
};

int main( int argc, char **argv )
{
    Foo *foo = new Foo;
    return 0;
}
