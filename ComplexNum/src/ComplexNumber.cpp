
#include "ComplexNumber.hpp"
#include <cmath>
#include <string>
#include <limits>

ComplexNumber operator+(const ComplexNumber& lhv, const ComplexNumber& rhv) {
    return ComplexNumber(lhv.R+rhv.R, lhv.Im+rhv.Im);
}

ComplexNumber operator-(const ComplexNumber& lhv, const ComplexNumber& rhv) {
    return lhv + -rhv;
}

std::ostream& operator<<(std::ostream& out, const ComplexNumber& num) {
    if (num.exp) {
        double radius = num.abs(); 
        double angle = std::acos(num.R/radius);
        out << radius << " * exp^(" << angle << "i)";
    } else {
        if (doubleCmp(num.Im, 0))
            out << num.R;
        else if (doubleCmp(num.R, 0))
            if (doubleCmp(num.Im, 1))
                out << "i";
            else
                out << num.Im << "i";
        else {
            bool sign = std::signbit(num.Im);
            double Im_ = sign? -1*num.Im : num.Im;
            std::string signStr = sign? "-" : "+";
            if (doubleCmp(num.Im, 1))
                out << num.R <<" " << signStr << " "<<"i";
            else
                out << num.R <<" " << signStr << " " << Im_<<"i";
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, ComplexNumber& num) {
    in >> num.R >> num.Im;
    return in;
}

ComplexNumber operator*(const ComplexNumber& lhv, const ComplexNumber& rhv) {
    return ComplexNumber(lhv.R * rhv.R - lhv.Im * rhv.Im, lhv.R * rhv.Im + lhv.Im * rhv.R);
}

bool doubleCmp(const double &lhv, const double &rhv) {
	if (std::abs(lhv-rhv) < std::numeric_limits<double>::epsilon())
		return true;
	else return false;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other) {
    if (this == &other) {
        return *this;
    }
    this->Im = other.Im;
    this->R = other.R;
    return *this;
}

double ComplexNumber::abs() const {
    return std::sqrt(this->Im * this->Im + this->R * this->R);
}

ComplexNumber ComplexNumber::operator!() const {
    return ComplexNumber(R, -Im);
}

ComplexNumber operator/(const ComplexNumber& lhv, const ComplexNumber& rhv) {
    double denominator = rhv.Im * rhv.Im + rhv.R * rhv.R;
    if (doubleCmp(denominator, 0))
        return ComplexNumber(INFINITY, INFINITY);
    return ComplexNumber((lhv.R*rhv.R+lhv.Im*rhv.Im)/denominator, (rhv.R*lhv.Im-lhv.R*rhv.Im)/denominator); 
}

ComplexNumber ComplexNumber::operator+() const {
    return *this;
}

ComplexNumber ComplexNumber::operator-() const {
    return ComplexNumber(-R, -Im);
}

bool operator==(const ComplexNumber& lhv, const ComplexNumber& rhv) {
    return doubleCmp(lhv.R, rhv.R) and doubleCmp(lhv.Im, rhv.Im);
}

bool operator!=(const ComplexNumber& lhv, const ComplexNumber& rhv) {
    return !(lhv == rhv);
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other) {
    *this = *this - other;
    return *this;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other) {
    *this = *this + other;
    return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other) {
    *this = *this * other;
    return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other) {
    *this = *this / other;
    return *this;
}

ComplexNumber ComplexNumber::conj() const {
    return !(*this);
}

double ComplexNumber::norm() const {
    return R*R+Im*Im;
}

void ComplexNumber::setexp(bool val) {
    exp = val;
}

ComplexNumber powC(ComplexNumber num, int degree) {
    if (degree == 0)
        return ComplexNumber(1);
    else if (degree == 1)
        return num;
    else if (degree % 2 == 0)
        return powC(num, degree/2) * powC(num, degree/2);
    else return powC(num, degree/2) * powC(num, degree/2) * num;
}