#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Fraction
{
    public:
        Fraction();
        Fraction(int n);
        Fraction(int n, int d);
        int numerator() const;
        int denominator() const;
        int gcdGet(int n, int d);

        int num;    //In certain functions I acted as if these were private
        int den;    //I could not solve istream with private values

        //---------------------------- Unary Operators ----------------------------
        Fraction& operator-();
        Fraction& operator++();
        Fraction operator++(int trash);

        //----------------------- Binary Assignment Operators -----------------------
        Fraction& operator+=(const Fraction& frac);


    private:
        void simplify();
        int gcd;
        int temp;

    
    //--------------------- Input/Output Operators ---------------------
    friend ostream& operator<<(ostream& out, const Fraction& frac);
    friend istream& operator>>(istream& out, const Fraction& frac);

    //---------------------- Binary Artithmateic Operators ----------------------
    friend Fraction operator+(const Fraction& l, const Fraction& r);
    friend Fraction operator-(const Fraction& l, const Fraction& r);
    friend Fraction operator*(const Fraction& l, const Fraction& r);
    friend Fraction operator/(const Fraction& l, const Fraction& r);

    //------------------- Binary Relational/Logical Operators -------------------
    friend bool operator>(const Fraction& l, const Fraction& r);
    friend bool operator>=(const Fraction& l, const Fraction& r);
    friend bool operator==(const Fraction& l, const Fraction& r);
    friend bool operator&&(const Fraction& l, const Fraction& r);
    friend bool operator!=(const Fraction& l, const Fraction& r);
    friend bool operator<=(const Fraction& l, const Fraction& r);
    friend bool operator<(const Fraction& l, const Fraction& r);

    //----------------------- Binary Assignment Operators -----------------------
    //friend Fraction& operator+=(const Fraction& frac);


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

