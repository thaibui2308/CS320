#include "fraction.h"
#include "fraction_exception.h"

Fraction::Fraction(): num(0), den(1){}

Fraction::Fraction(int n, int d) : num(n) , den(d){
    if (d==0){
        throw FractionException("ZeroDivisonError");
    }
    reduceFraction();
}

void Fraction::setNumbers(int n, int d){
    if (d==0)
        throw FractionException("ZeroDivisonError");
    num = n;
    den = d;
    reduceFraction();
}

Fraction& Fraction::operator =(Fraction const &f){
    num = f.num;
    den = f.den;
    reduceFraction();
    return *this;
}

//Overloaded arithmetic operators
Fraction Fraction::operator + (Fraction const &f){
    return Fraction(num*f.den + den*f.num, den*f.den);
}

Fraction Fraction::operator - (Fraction const &f){
    return Fraction(num*f.den - den*f.num, den*f.den);   
}

Fraction Fraction::operator * (Fraction const &f){
    return Fraction(num*f.num, den*f.den);     
}

Fraction Fraction::operator / (Fraction const &f){
    if (f.num == 0)
        throw FractionException("ZeroDivisonError");
    return Fraction(num*f.den, den*f.num);   ;    
}


Fraction& Fraction::operator += (Fraction const &f){
    num = f.num*den + f.den*num;
    den = f.den*den;
    reduceFraction();
    return *this;
}

Fraction& Fraction::operator -= (Fraction const &f){
    num = f.num*den - f.den*num;
    den = f.den*den;
    reduceFraction();
    return *this;
}

Fraction& Fraction::operator *= (Fraction const &f){
    num = f.num*num;
    den = f.den*den;
    reduceFraction();
    return *this;
}

Fraction& Fraction::operator /= (Fraction const &f){
    if (f.num == 0)
        throw FractionException("ZeroDivisonError");
    num = f.den*num;
    den = f.num*den;
    reduceFraction();
    return *this;
}


//Overloaded relational operators
int Fraction::operator == (Fraction const &f) const{
    if (num*f.den == den*f.num) 
        return true;
    return false;
}

int Fraction::operator != (Fraction const &f) const{
    if (num*f.den != den*f.num) 
        return true;
    return false;
}

int Fraction::operator >= (Fraction const &f) const{
    if (num*f.den >= den*f.num) 
        return true;
    return false;
}

int Fraction::operator > (Fraction const &f) const{
    if (num*f.den > den*f.num)
        return true;
    return false;
}

int Fraction::operator <= (Fraction const &f) const{
    if (num*f.den <= den*f.num) 
        return true;
    return false;
}

int Fraction::operator < (Fraction const &f) const{
    if (num*f.den < den*f.num) 
        return true;
    return false;
}

istream& operator >> (istream& left, Fraction& f){
    cout << "Numerator: ";
    left >> f.num;
    cout << "Denominator: ";
    left >> f.den;
    return left;
}

ostream& operator << (ostream& left, const Fraction& f){
    if (f.num == 0 || f.den == 1)
        left << f.num ;
    else
        left << f.num << "/" << f.den ;
    return left;
}

float Fraction::getFloat(){
    float numer = static_cast <float> (num);
    return (numer/den);
}

//Helper Function
int gcd(int a, int b){
    while (b!=0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void Fraction::reduceFraction(){
    int god = gcd(num,den);
    num /= god;
    den /= god;
    if (den < 0){
        num = -num;
        den = -den;
    }
}
