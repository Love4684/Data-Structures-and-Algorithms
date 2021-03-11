
#include <iostream>

class Foo {
public:
    Foo( void )
    { std::cout << "Foo constructor called" << std::endl;};

    virtual ~Foo( void )
    { std::cout << "Foo destructor called" << std::endl;};
};

class Bar : public Foo {
public:
    Bar( void )
    { std::cout << "Bar constructor called" << std::endl;};

    ~Bar( void )
    { std::cout << "Bar destructor called" << std::endl;};
};

int main( int argc, char **argv )
{
    Foo * foo = new Bar();
    delete foo;

    return 0;
}
