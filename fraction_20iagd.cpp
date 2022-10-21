#include "fraction_20iagd.h"
#include <string.h>
#include <iostream>
using namespace std;

Fraction::Fraction() : num(0), den(1) {};

Fraction::Fraction(int n) : num(n), den(1) {};

Fraction::Fraction(int n, int d)
{
    if (d == 0)
    {
        throw FractionException("Denominator must be a non-zero integer");
    }
    if (n < 0) 
    {
        n = n*-1;
        temp++;
    }
    if (d < 0)
    {
        d = d*-1;
        temp++;
    }
    gcd = simplify(n, d);
    num = n/gcd * (-1 * ((temp%1)+1));
    den = d/gcd;
};

int Fraction::simplify(int n, int d)
{
    //Find the GCD of both the numerator & denominator, used recursive function from assignment 
    if((d <= n) && (n%d == 0)) return d;
    else if(n < d) return simplify(d, n);
    else return simplify(d, n%d);
}

int Fraction::numerator() const
{
    int n = num;
    return n;
};

int Fraction::denominator() const
{
    int d = den;
    return d;
};

//Fraction 

FractionException::FractionException(const string& message) : message(message){}

string FractionException::what()
{
    //returns message of the Fraction Exception
	return message;
}

Fraction operator+(const Fraction& l, const Fraction& r)
{
    return Fraction(l.numerator()*r.denominator()+l.denominator()*r.numerator(), l.numerator()*r.denominator());
}

//Outstream operator
ostream& operator<<(ostream& out, const Fraction& frac) {
   out << frac.numerator() << "/" << frac.denominator();
   return out;
}
