#pragma once
#include <iostream>
#include <string.h>

class Fraction
{
    public:
        Fraction();
        Fraction(int n);
        Fraction(int n, int d);
        int numerator() const;
        int denominator() const;
        int simplify(int n, int d);

    private:
        int num;
        int den;
        int gcd;
        int temp = 0;

    
    friend ostream& operator<<(ostream& out, const Fraction& frac);

    friend Fraction operator+(const Fraction& left, const Fraction& right);

};

class FractionException
{
    public:
        FractionException(const string& message);
        string what();
    
    private:
        string message;
};
//Overloading printing operator

//Fraction operator++(const Fraction& frac);
//Fraction operator++();
