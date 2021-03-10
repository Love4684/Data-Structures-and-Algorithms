
#include <iostream>

int add( int a, int b )
{
    return a+b;
}

int add( int a, int b, int c=0 )
{
    return a+b+c;
}

int main( int argc, char **argv )
{
    // int value = add(1,2); // WRONG because this is ambiguous
    return 0;
}
