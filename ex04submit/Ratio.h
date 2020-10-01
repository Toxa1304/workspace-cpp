#ifndef DS_RATIO_H
#define DS_RATIO_H

#include <iostream>

// using namespace ... - DON'T DO THIS

// Here is stuff that is in header files
// Declarations only
namespace ds_course
{
    class Ratio
    {
    private:
        int num;
        int den;
        int gcd(int a, int b);

    public:
        Ratio(int nn = 0, int dd = 1);
        Ratio operator+(const Ratio &rhs);
        bool operator==(const Ratio &rhs);

        friend std::ostream &operator<<(std::ostream &oStream, const Ratio rat)
        {
            oStream << "[" << rat.num << "/" << rat.den << "]";
            return oStream;
        }

        friend std::istream &operator>>(std::istream &input, ds_course::Ratio &rat)
        {
            input >> rat.num;
            input.ignore(256, '/'); // ignore slash
            input >> rat.den;
            return input;
        }
    };

} // namespace ds_course

// Here comes stuff that you would normally put in a CPP file
// THe DEFINITIONS of your member functions and friends....
int ds_course::Ratio::gcd(int a, int b)
{
    return 1; // stubs,
}

ds_course::Ratio::Ratio(int nn, int dd) : num(nn), den(dd)
{
    int g = gcd(nn, dd);
    num = num / g;
    den = den / g;
    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}

// result of r1 + r2 (Return type)
ds_course::Ratio ds_course::Ratio::operator+(const Ratio &rhs)
{
    int upside = num * rhs.den + den * rhs.num;
    int downside = den * rhs.den;
    ds_course::Ratio result(upside, downside);
    return result;
}

bool ds_course::Ratio::operator==(const ds_course::Ratio& r) {    
    return (num * r.den == den * r.num);
}



#endif
