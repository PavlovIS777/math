
#include "ComplexNumber.hpp"
#include <cmath>
#include <string>
#include <limits>

ComplexNumber ComplexNumber::operator+(const ComplexNumber& rhv) const{
    return ComplexNumber(R+rhv.R, Im+rhv.Im);
}

ComplexNumber operator+(double lhv, const ComplexNumber& rhv) {
    return ComplexNumber(lhv+rhv.R, rhv.Im);
}

ComplexNumber operator+(const ComplexNumber& lhv, double rhv) {
    return rhv + lhv;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& rhv) const{
    return *this + -rhv;
}

ComplexNumber operator-(double lhv, const ComplexNumber& rhv) {
    return ComplexNumber(lhv) - rhv;
}

ComplexNumber operator-(const ComplexNumber& lhv, double rhv) {
    return lhv - ComplexNumber(rhv);
}

ComplexNumber operator*(double lhv, const ComplexNumber& rhv) {
    return ComplexNumber(lhv) * rhv;
}

ComplexNumber operator*(const ComplexNumber& lhv, double rhv) {
    return lhv * ComplexNumber(rhv);
}

ComplexNumber operator/(double lhv, const ComplexNumber& rhv) {
    return ComplexNumber(lhv) / rhv;
}

ComplexNumber operator/(const ComplexNumber& lhv, double rhv) {
    return lhv / ComplexNumber(rhv);
}

std::ostream& operator<<(std::ostream& out, const ComplexNumber& num) {
    if (num.exp) {
        double radius = num.abs(); 
        double angle = std::acos(num.R/radius);
        out << radius << " * exp^(" << angle << "i)";
    } else {
        if (doubleCmp(num.Im, 0)) {
            out << num.R;
        }
        else if (doubleCmp(num.R, 0)) {
            if (doubleCmp(num.Im, 1)) {
                out << "i";
            } else {
                out << num.Im << "i";
            }
        } else {
            bool sign = std::signbit(num.Im);
            double Im_ = sign? -1*num.Im : num.Im;
            std::string signStr = sign? "-" : "+";
            if (doubleCmp(num.Im, 1)) {
                out << num.R <<" " << signStr << " "<<"i";
            } else {
                out << num.R <<" " << signStr << " " << Im_<<"i";
            }
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, ComplexNumber& num) {
    in >> num.R >> num.Im;
    return in;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& rhv) const{
    return ComplexNumber(R * rhv.R - Im * rhv.Im, R * rhv.Im + Im * rhv.R);
}

bool doubleCmp(const double &lhv, const double &rhv) {
	if (std::abs(lhv-rhv) < std::numeric_limits<double>::epsilon())
		return true;
	return false;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other) {
    if (this == &other) {
        return *this;
    }
    this->Im = other.Im;
    this->R = other.R;
    this->exp = other.exp;
    return *this;
}

double ComplexNumber::abs() const {
    return std::sqrt(this->Im * this->Im + this->R * this->R);
}

ComplexNumber ComplexNumber::operator!() const {
    return ComplexNumber(R, -Im);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& rhv) const {
    double denominator = rhv.Im * rhv.Im + rhv.R * rhv.R;
    if (doubleCmp(denominator, 0))
        return ComplexNumber(INFINITY, INFINITY);
    return ComplexNumber((R*rhv.R+Im*rhv.Im)/denominator, (rhv.R*Im-R*rhv.Im)/denominator); 
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

ComplexNumber& ComplexNumber::operator/=(double other) {
    *this = *this / ComplexNumber(other);
    return *this;
}

ComplexNumber& ComplexNumber::operator*=(double other) {
    *this = *this * ComplexNumber(other);
    return *this;
}

ComplexNumber& ComplexNumber::operator-=(double other) {
    *this = *this - ComplexNumber(other);
    return *this;
}

ComplexNumber& ComplexNumber::operator+=(double other) {
    *this = *this + ComplexNumber(other);
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
    if (degree == 0) {
        return ComplexNumber(1);
    } else if (degree == 1) {
        return num;
    } else if (degree % 2 == 0) {
        return powC(num, degree/2) * powC(num, degree/2);
    }
    return powC(num, degree/2) * powC(num, degree/2) * num;
}