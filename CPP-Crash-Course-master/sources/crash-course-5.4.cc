
#include <iostream>
#include <stdexcept>
#include <cmath>

struct DivideByZero : public std::runtime_error
{ DivideByZero( void ) : std::runtime_error("DivideByZero") { } };

struct OverflowError : public std::runtime_error
{ OverflowError( void ) : std::runtime_error("OverflowError") { } };

struct UnderflowError : public std::runtime_error
{ UnderflowError( void ) : std::runtime_error("UnderflowError") { } };


class Integer {
public:
    Integer( int value = 0 ) : _value(value) { };

    virtual Integer operator+(Integer &other)
    {
        unsigned char result = _value+other._value;
        if( result < _value )
        { throw new OverflowError; }
        return Integer(result);
    }

    virtual Integer operator-(Integer &other)
    {
        unsigned char result = _value-other._value;
        if( result > _value )
        { throw new UnderflowError; }
        return Integer(result);
    }

    virtual Integer operator*(Integer &other)
    {
        unsigned char result = _value * other._value;
        if((_value > 1) and (other._value >1 ) and ( result < _value ))
        { throw new OverflowError; }
        return Integer(result);
    }

    virtual Integer operator/(Integer &other)
    {
        if( other._value == 0 )
        { throw new DivideByZero; }

        return Integer(_value / other._value);
    }

    friend std::ostream& operator<< ( std::ostream& output, Integer const & that )
    { return output << that._value; }
protected:
    unsigned char _value;
};

int main( int argc, char **argv )
{
    Integer a(129), b(128), zero(0);

    Integer c(a+b); // overflow
    Integer c(b-a); // underflow
    Integer c(a/zeor); // divide by zero

    return 0;
}
