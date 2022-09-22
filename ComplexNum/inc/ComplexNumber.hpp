#pragma once
#include <iostream>
class ComplexNumber
{
public:
    double R;
    double Im;
    bool exp;
    ComplexNumber(double R_, double Im_): R(R_), Im(Im_), exp(0){}
    ComplexNumber(double R_): R(R_), Im(0), exp(0){}
    ComplexNumber(const ComplexNumber& other): R(other.R), Im(other.Im), exp(0){}
    ComplexNumber(): R(0.0), Im(0.0), exp(0){};
    //operators
    friend ComplexNumber operator+(const ComplexNumber& lhv, const ComplexNumber& rhv);
    friend ComplexNumber operator-(const ComplexNumber& lhv, const ComplexNumber& rhv);
    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& num);
    friend std::istream& operator>>(std::istream& in, ComplexNumber& num);
    friend ComplexNumber operator*(const ComplexNumber& lhv, const ComplexNumber& rhv);
    friend ComplexNumber operator/(const ComplexNumber& lhv, const ComplexNumber& rhv);
    friend bool operator==(const ComplexNumber& lhv, const ComplexNumber& rhv);
    friend bool operator!=(const ComplexNumber& lhv, const ComplexNumber& rhv);
    friend ComplexNumber powC(ComplexNumber num, int degree);
    ComplexNumber& operator=(const ComplexNumber& other);
    ComplexNumber& operator*=(const ComplexNumber& other);
    ComplexNumber& operator/=(const ComplexNumber& other);
    ComplexNumber& operator+=(const ComplexNumber& other);
    ComplexNumber& operator-=(const ComplexNumber& other);
    ComplexNumber operator!() const; // returns number conjugate
    ComplexNumber operator+() const;
    ComplexNumber operator-() const;
    //methods
    double abs() const;
    double norm() const;
    ComplexNumber conj() const;
    void setexp(bool val);
};

bool doubleCmp(const double &lhv, const double &rhv);