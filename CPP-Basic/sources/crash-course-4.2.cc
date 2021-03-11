
#include <iostream>

void foo( void )
{ std::cout << "::foo() called" << std::endl;}

class Foo {
public:
    Foo( void )
        { ::foo(); foo(); }

    void foo( void )
    { std::cout << "Foo::foo() called" << std::endl;};

};

int main( int argc, char **argv )
{
    Foo foo;
    return 0;
}
