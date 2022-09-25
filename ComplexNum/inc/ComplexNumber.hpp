#pragma once
#include <iostream>
struct ComplexNumber
{
    //data
    double R;
    double Im;
    bool exp;
    

    //ctors
    ComplexNumber(double R_, double Im_): R(R_), Im(Im_), exp(0){}
    explicit ComplexNumber(double R_): R(R_), Im(0), exp(0){}
    ComplexNumber(const ComplexNumber& other): R(other.R), Im(other.Im), exp(other.exp){}
    ComplexNumber(): R(0.0), Im(0.0), exp(0){};
    
    
    //operators
    ComplexNumber& operator=(const ComplexNumber& other);
    ComplexNumber& operator*=(const ComplexNumber& other);
    ComplexNumber& operator/=(const ComplexNumber& other);
    ComplexNumber& operator+=(const ComplexNumber& other);
    ComplexNumber& operator-=(const ComplexNumber& other);
    ComplexNumber& operator=(double other);
    ComplexNumber& operator*=(double other);
    ComplexNumber& operator/=(double other);
    ComplexNumber& operator+=(double other);
    ComplexNumber& operator-=(double other);
    ComplexNumber operator!() const; // returns number conjugate
    ComplexNumber operator+() const;
    ComplexNumber operator-() const;
    ComplexNumber operator+(const ComplexNumber& rhv) const;
    ComplexNumber operator-(const ComplexNumber& rhv) const;
    ComplexNumber operator*(const ComplexNumber& rhv) const;
    ComplexNumber operator/(const ComplexNumber& rhv) const;

    //methods
    double abs() const;
    double norm() const;
    ComplexNumber conj() const;
    void setexp(bool val);
};

bool doubleCmp(const double &lhv, const double &rhv);

std::ostream& operator<<(std::ostream& out, const ComplexNumber& num);

std::istream& operator>>(std::istream& in, ComplexNumber& num);

ComplexNumber powC(ComplexNumber num, int degree);

ComplexNumber operator+(double lhv, const ComplexNumber& rhv);

ComplexNumber operator+(const ComplexNumber& lhv, double rhv);

ComplexNumber operator-(double lhv, const ComplexNumber& rhv);

ComplexNumber operator-(const ComplexNumber& lhv, double rhv);

ComplexNumber operator*(double lhv, const ComplexNumber& rhv);

ComplexNumber operator*(const ComplexNumber& lhv, double rhv);

ComplexNumber operator/(double lhv, const ComplexNumber& rhv);

ComplexNumber operator/(const ComplexNumber& lhv, double rhv);

bool operator==(const ComplexNumber& lhv, const ComplexNumber& rhv);

bool operator!=(const ComplexNumber& lhv, const ComplexNumber& rhv);