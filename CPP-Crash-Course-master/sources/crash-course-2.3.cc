
#include <iostream>

void swap_ref( int & a, int & b )
{
    int c = a;
    a = b;
    b = c;
}

void swap_ptr( int * a, int * b )
{
    int c = *a;
    *a = *b;
    *b = c;
}

void swap_ref_ptr( int * & a, int * & b )
{
    int *c = a;
    a = b;
    b = c;
}

int main( int argc, char **argv )
{
    int i1 = 1;
    int i2 = 2;
    int * p1 = &i1;
    int * p2 = &i2;

    std::cout << "i1 = " << i1 << ", " << "i2 = " << i2 << std::endl;
    swap_ref(i1,i2);
    std::cout << "i1 = " << i1 << ", " << "i2 = " << i2 << std::endl;
    std::cout << std::endl;

    std::cout << "*p1 = " << *p1 << ", " << "*p2 = " << *p2 << std::endl;
    swap_ptr(p1,p2);
    std::cout << "*p1 = " << *p1 << ", " << "*p2 = " << *p2 << std::endl;
    std::cout << std::endl;

    std::cout << "*p1 = " << *p1 << ", " << "*p2 = " << *p2 << std::endl;
    swap_ref_ptr(p1,p2);
    std::cout << "*p1 = " << *p1 << ", " << "*p2 = " << *p2 << std::endl;

    return 0;
}
