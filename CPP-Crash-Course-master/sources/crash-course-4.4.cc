
#include <iostream>

class Singleton
{

public:
   static Singleton * instance( void )
   {
	   if( !_instance )
       {
           _instance = new Singleton;
       }
       return _instance;
   }

private:
   Singleton( void )
   { };

   Singleton( Singleton const & other )
   { };

   Singleton & operator=( Singleton const & other )
   {
       return *this;
   };

   static Singleton* _instance;
};

Singleton *Singleton::_instance = 0;

int main( int argc, char **argv )
{
    Singleton *singleton = Singleton::instance();

    delete singleton;
    return 0;
}
