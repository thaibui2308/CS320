//OPERATOR OVERLOADING
/*
File: Fraction.h
Author: P Kraft
Description: Header file for class Fraction
*/
#ifndef FRACTION_H
#define FRACTION_H
#include <cstdlib> // stdlib.h for C++
#include <iomanip>
#include <iostream>
#include <string>
#include "fraction_exception.h"

using namespace std;

class Fraction{

    //Overload stream insertion and extraction operators
    friend ostream& operator << (ostream&, const Fraction&);
    friend istream& operator >> (istream&, Fraction&);

    public:
        Fraction(int, int=1);

        Fraction();

        void setNumbers(int, int);
        float getFloat(void);

        //Overloaded assignment operator
        Fraction& operator =(Fraction const &);

        //Overloaded realtional operators
        int operator == (Fraction const &) const;
        int operator != (Fraction const &) const;
        int operator > (Fraction const &) const;
        int operator >= (Fraction const &) const;
        int operator < (Fraction const &) const;
        int operator <= (Fraction const &) const;

        //Overloaded arithmetic operators
        Fraction operator + (Fraction const &);
        Fraction operator - (Fraction const &);
        Fraction operator * (Fraction const &);
        Fraction operator / (Fraction const &);
        Fraction& operator += (Fraction const &);
        Fraction& operator -= (Fraction const &);
        Fraction& operator *= (Fraction const &);
        Fraction& operator /= (Fraction const &);


    private:
        int num, den;
        void reduceFraction();
};

#endif
// ***** END OF FILE fraction.H *****

