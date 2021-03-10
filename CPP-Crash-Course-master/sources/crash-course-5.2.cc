
#include <iostream>
#include <typeinfo>
#include <exception>

class Foo
{ virtual void method( void ) { } };

class Bar : public Foo
{ };

void unexpected( void )
{ throw; }

void function( void ) throw( int, std::bad_exception )
{ throw 'x'; }


int main( int argc, char **argv )
{

    // Bad alloc
    try
    {
        int * array = new int[-1];
        int i = 0;
        i = array[0];
    }
    catch( std::bad_alloc & e )
    {
        std::cerr << "bad_alloc caught: " << e.what() << std::endl;
    }

    // Bad cast
    try
    {
        Foo f;
        Bar & b = dynamic_cast<Bar &>( f );
    }
    catch( std::bad_cast & e )
    {
        std::cerr << "bad_cast caught: " << e.what() << std::endl;
    }

    // Bad exception
    std::set_unexpected( unexpected );
    try {
        function();
    }
    catch( int )
    {
        std::cerr << "caught int" << std::endl;
    }
    catch( std::bad_exception e )
    {
        std::cerr << "bad_exception caught " << e.what() << std::endl;
    }

    return 0;
}
