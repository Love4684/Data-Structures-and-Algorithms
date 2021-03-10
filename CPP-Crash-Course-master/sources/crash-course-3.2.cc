
#include <iostream>

class Foo {
private:
    int _value;


public:
    Foo( int value = 0 ) : _value(value) 
    {
        std::cout << "Foo default constructor called" << std::endl;
    }

    Foo( const Foo & other )
    {
        std::cout << "Foo copy constructor called" << std::endl;
    }

    Foo & operator= ( const Foo &other )
    {
        std::cout << "Foo operator = called" << std::endl;

        // Gracefully handle self assignment
        if( this == &other ) return *this;
        
        _value = other._value;
        return *this;
    }
 
   ~Foo( void )
    {
        std::cout << "Foo destructor called" << std::endl;
    }
};

int main( int argc, char **argv )
{
    Foo foo_1(2);
    Foo foo_2(foo_1);
    Foo foo_3;
    foo_3 = foo_1;
    
    return 0;
}
