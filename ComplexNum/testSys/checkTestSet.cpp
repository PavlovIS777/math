#include "ComplexNumber.hpp"
#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <cmath>
#include <complex>
#include <iomanip>
#include <random>
#include <ctime>

const double MAX_DOUBLE_DIFF = 1e-5;

double randDouble(double fMin, double fMax)
{
    double num = (double)rand() / RAND_MAX;
    return fMin + num * (fMax - fMin);
}

bool testDoubleCmp(double lhv, double rhv) {
    return (std::abs(lhv - rhv) < MAX_DOUBLE_DIFF);
}

bool checkAssignmentOperator(int cnt) {
    int unsuccesCnt = cnt;
    std::cout << "Assignment block" << std::endl;
    std::map<int, std::string> operations = {{0, "="}, {1, "*="}, {2, "/="}, {3, "+="}, {4, "-="}}; 
    for (int i = 0; i < cnt; ++i) {
        double c1r = randDouble(0, 1000), c1i = randDouble(0, 1000);
        double resr = randDouble(0, 1000), resi = randDouble(0, 1000);
        std::complex<double> num(c1r, c1i), res(resr, resi);
        ComplexNumber mynum(c1r, c1i), myRes(resr, resi);
        std::complex<double> resCpy(res);
        int operation = rand() % 5;
        switch (operation) {
                case 0:
                myRes = mynum;
                res = num;
                break;
            case 1:
                myRes *= mynum;
                res *= num;
                break;
            case 2:
                myRes /= mynum;
                res /= num;
                break;
            case 3:
                myRes += mynum;
                res += num;
                break;
            case 4:
                myRes -= mynum;
                res -= num;
            default:
                break;
        }
        if (testDoubleCmp(myRes.R, res.real()) and testDoubleCmp(myRes.Im, res.imag())) {
            std::cout << "  Test #" << std::to_string(i+1) << ": Success" << std::endl;
            --unsuccesCnt;
        } else {
            std::string gottenResStr = "("+std::to_string(myRes.R) + "," + std::to_string(myRes.Im) + ")";
            std::cout << "  Test #" << std::to_string(i+1) << ": Error" << std::endl;
            std::cout << "  Expected: " << res << " | Gotten: " << gottenResStr << std::endl;
            std::cout << "  First op.: " << resCpy << " | Second op.: " << num << " | Operation: " << operations[operation] << std::endl;
        }
    }
    return (double(unsuccesCnt)/double(cnt) < 0.01);  
}


bool checkArithmeticOperator(int cnt) {
    std::cout << "Arithmetic block" << std::endl;
    int unsuccesCnt = cnt;
    std::map<int, std::string> operations = {{0, "+"}, {1, "-"}, {2, "*"}, {3, "/"}}; 
    for (int i = 0; i < cnt; ++i) {
        double c1r = randDouble(0, 1000), c1i = randDouble(0, 1000), c2r = randDouble(0, 1000), c2i = randDouble(0, 1000);
        std::complex<double> c1(c1r, c1i), c2(c2r, c2i), res;
        ComplexNumber myc1(c1r, c1i), myc2(c2r, c2i), myRes;
        int operation = rand() % 4;
        switch (operation) {
            case 0:
                myRes = myc1 + myc2;
                res = c1 + c2;
                break;
            case 1:
                myRes = myc1 - myc2;
                res = c1 - c2;
                break;
            case 2:
                myRes = myc1 * myc2;
                res = c1 * c2;
                break;
            case 3:
                myRes = myc1 / myc2;
                res = c1 / c2;
                break;
            default:
                break;
            }
        if (testDoubleCmp(myRes.R, res.real()) and testDoubleCmp(myRes.Im, res.imag())) {
            std::cout << "  Test #" << std::to_string(i+1) << ": Success" << std::endl;
            --unsuccesCnt;
        } else {
            std::string gottenResStr = "("+std::to_string(myRes.R) + "," + std::to_string(myRes.Im) + ")";
            std::cout << "  Test #" << std::to_string(i+1) << ": Error" << std::endl;
            std::cout << "  Expected: " << res << " | Gotten: " << gottenResStr << std::endl;
            std::cout << "  First op.: " << myc1 << " | Second op.: " << myc2 << " | Operation: " << operations[operation] << std::endl;
        }
    }
    return (double(unsuccesCnt)/double(cnt) < 0.01);
}


int main(int argc, char* argv[]) {
    std::srand(std::time(0));
    int testCnt = std::stoi(argv[1]);
    if (!checkAssignmentOperator(testCnt)) {
        std::cerr << "Assignment block failed" << std::endl;
    }
    std::cout << std::endl << std::endl;
    if (!checkArithmeticOperator(testCnt)) {
        std::cerr << "Arithmetic block failed" << std::endl;
    }
    return 0;
}