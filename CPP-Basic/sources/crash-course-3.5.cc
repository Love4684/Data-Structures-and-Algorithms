
#include <iostream>

class Foo {
public:
    Foo ( void )
    { };

    Foo & method1( void )
    { return *this; }

    void method2( void )
    {  }
};


int main( int argc, char **argv )
{
    Foo foo;
    foo.method1().method2();

    return 0;
}
