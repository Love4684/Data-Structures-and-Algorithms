
#include <iostream>

class Foo { Foo ( void )  { }; };
struct Bar { Bar ( void ) { }; };

int main( int argc, char **argv )
{
    // Foo foo; // WRONG, constuctor is private
    Bar bar;    // OK, constructor is public

    return 0;
}
