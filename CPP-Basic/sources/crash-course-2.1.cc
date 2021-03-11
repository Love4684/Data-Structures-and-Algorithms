
int main( int argc, char **argv )
{
    // Pointer to a char
    char * p1 = new char;

    // A constant pointer to a char
    char * const p2 = p1;

    // A pointer to a constant char
    const char * p3 = p1;

    // A constant pointer to a constant char
    const char * const p4 = p2;
    
    // A reference to a char
    char & r1 = *p2;

    // A reference to a constant char:
    const char & r2 = *p4;

    // To have no warning at compilation for unused variables
    if( *p3 == r1 ) { }
    if( *p3 == r2 ) { }

}
