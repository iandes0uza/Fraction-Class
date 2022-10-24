#include "fraction_20iagd.h"
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

Fraction::Fraction() : num(0), den(1) {};

Fraction::Fraction(int n) : num(n), den(1) {};

Fraction::Fraction(int n, int d)
{
    temp = 0;
    gcd = 1;
    if (d == 0)
    {
        throw FractionException("Denominator must be a non-zero integer");
    }
    num = n;
    den = d;
    simplify();
};

void Fraction::simplify()
{
    if (num < 0 && den < 0) 
    {
        num = num * (-1);
        den = den * (-1);
        gcd = gcdGet(num, den);
        num = num/gcd;
        den = den/gcd;
    }
    else if (den < 0)
    {
        den = den * (-1);
        gcd = gcdGet(num, den);
        num = num/gcd * (-1);
        den = den/gcd;
    }
    else if (num < 0)
    {

        num = num * (-1);
        gcd = gcdGet(num, den);
        num = num/gcd * (-1);
        den = den/gcd;
    }
    else
    {
        gcd = gcdGet(num, den);
        num = num/gcd;
        den = den/gcd;
    }
}

int Fraction::gcdGet(int n, int d)
{
    //Find the GCD of both the numerator & denominator, used recursive function from assignment 
    if((d <= n) && (n%d == 0)) return d;
    else if(n < d) return gcdGet(d, n);
    else return gcdGet(d, n%d);
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



//-------------------------------------------------- Unary Operators --------------------------------------------------
//Unary Negation Operator
Fraction& Fraction::operator-()
{
    num = num * (-1);
    return *this;
}

//Pre-increment Operator
Fraction& Fraction::operator++() 
{
	num += den;
	return *this;
}

//Post-increment Operator
Fraction Fraction::operator++(int trash)
{
    Fraction clone(num, den);
    num += den;
    return clone;
}



//------------------------------------------ Binary Artithmateic Operators ------------------------------------------
//Addition Operator
Fraction operator+(const Fraction& l, const Fraction& r)
{
    return Fraction(l.numerator()*r.denominator()+l.denominator()*r.numerator(), l.denominator()*r.denominator());
}

//Subtraction Operator
Fraction operator-(const Fraction& l, const Fraction& r)
{
    return Fraction(l.numerator()*r.denominator()-l.denominator()*r.numerator(), l.denominator()*r.denominator());
}

//Multiplication Operator
Fraction operator*(const Fraction& l, const Fraction& r)
{
    return Fraction(l.numerator()*r.numerator(), l.denominator()*r.denominator());
}

//Division Operator
Fraction operator/(const Fraction& l, const Fraction& r)
{
    return Fraction(l.numerator()*r.denominator(), l.denominator()*r.numerator());
}



//------------------------------------------- Binary Relationial Operators -------------------------------------------
//Greater Than Operator
bool operator>(const Fraction& l, const Fraction& r)
{
    if ((double)l.num/(double)l.den > (double)r.num/(double)r.den) return true;
    else return false;
}

//Greater Than/Equal Operator
bool operator>=(const Fraction& l, const Fraction& r)
{
    if ((double)l.num/(double)l.den >= (double)r.num/(double)r.den) return true;
    else return false;
}

//Equal Operator
bool operator==(const Fraction& l, const Fraction& r)
{
    if ((double)l.num/(double)l.den == (double)r.num/(double)r.den) return true;
    else return false;
}

//Logically Equal Operator
bool operator&&(const Fraction& l, const Fraction& r)
{
    if ((double)l.num/(double)l.den == (double)r.num/(double)r.den) return true;
    else return false;
}

//Not Equal Operator
bool operator!=(const Fraction& l, const Fraction& r)
{
    if ((double)l.num/(double)l.den != (double)r.num/(double)r.den) return true;
    else return false;
}

//Less Than/Equal Operator
bool operator<=(const Fraction& l, const Fraction& r)
{
    if ((double)l.num/(double)l.den <= (double)r.num/(double)r.den) return true;
    else return false;
}

//Less Than Operator
bool operator<(const Fraction& l, const Fraction& r)
{
    if ((double)l.num/(double)l.den < (double)r.num/(double)r.den) return true;
    else return false;
}



//-------------------------------------------- Binary Assignment Operators --------------------------------------------
//Addition and Assignment Operator
Fraction& Fraction::operator+=(const Fraction& frac) 
{
    this->num = this->numerator()*frac.denominator()+this->denominator()*frac.numerator();
    this->den = this->denominator()*frac.denominator();
    return *this;
}



//-------------------------------------------- whfiubekhbdqkbqcbqkjbqclass --------------------------------------------
//Outstream operator
ostream& operator<<(ostream& out, const Fraction& frac)
{
    out << frac.numerator() << "/" << frac.denominator();
    return out;
}

//Instream operator
istream& operator>>(istream& in, const Fraction& frac) 
{
    string first,last, S;
    getline(in, S);
    stringstream X(S);
    getline(X,first,'/');
    if (stoi(first)== 0)
    {
        return in;
    }
    else
    {
        getline(X,last,'/');
        Fraction(stoi(first),stoi(last));
        return in;
    }
}



//-------------------------------------------- Fraction Exception Class --------------------------------------------
FractionException::FractionException(const string& message) : message(message){}
string FractionException::what()
{
    //returns message of the Fraction Exception
	return message;
}


