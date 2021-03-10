
#include <iostream>

int main( int argc, char **argv )
{
    const size_t n = 2;
    int **array = new int *[n]; 

    for( size_t i=0; i<n; ++i )
        array[i] = new int[n];

    for( size_t i=0; i<n; ++i )
        for( size_t j=0; j<n; ++j )
            array[i][j] = i*n+j;

    for( size_t i=0; i<n; ++i )
        for( size_t j=0; j<n; ++j )
            std::cout << "array[" << i << "," << j << "] = "
                      << array[i][j] << std::endl;

    for( size_t i=0; i<n; ++i )
        delete [] array[i];
    delete [] array;
}
