#ifndef DS_RATIO_H
#define DS_RATIO_H

#include <iostream>
#include <algorithm>
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
        Ratio operator-(const Ratio &rhs);
        Ratio operator*(const Ratio &rhs);
        Ratio operator=(const Ratio &rhs);
        friend std::ostream &operator<<(std::ostream &oStream, const Ratio rat)
        {
            if(rat.num == 0){
                oStream  << rat.num;
                return oStream;
            }
            oStream  << rat.num << "/" << rat.den;
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
// int ds_course::Ratio::gcd(int a, int b)
// {
//     int n1 = a;
//     int n2 = b;
//     int hcf;
//     if ( n2 > n1) {   
//         int temp = n2;
//         n2 = n1;
//         n1 = temp;
//     }
    
//     for (int i = 1; i <=  n2; ++i) {
//         if (n1 % i == 0 && n2 % i ==0) {
//             hcf = i;
//         }
//     }
//     std::cout << "HCF = " << hcf << std::endl;
//     return hcf;

// }

ds_course::Ratio::Ratio(int nn, int dd) : num(nn), den(dd)
{
    int g = std::__gcd(nn, dd);
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
ds_course::Ratio ds_course::Ratio::operator-(const Ratio &rhs)
{
    int upside = num * rhs.den - den * rhs.num;
    int downside = den * rhs.den;
    ds_course::Ratio result(upside, downside);
    return result;
}
ds_course::Ratio ds_course::Ratio::operator*(const Ratio &rhs)
{
    int upside = num * rhs.num;
    int downside = den * rhs.den;
    ds_course::Ratio result(upside, downside);
    return result;
}
ds_course::Ratio ds_course::Ratio::operator=(const Ratio &rhs)
{
    num = rhs.num;
    den = rhs.den;
    int upside = rhs.num;
    int downside = rhs.den;
    ds_course::Ratio result(upside, downside);
    return result;
}


bool ds_course::Ratio::operator==(const ds_course::Ratio& r) {    
    return (num * r.den == den * r.num);
}



#endif
