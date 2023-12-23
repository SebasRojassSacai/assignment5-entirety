//IMPLEMENTATION FILE
//Sebastian Rojas
//11/10/2023
//Assignment 5




#include "rationalsST.h"

namespace {
    // Helper function to find the greatest common divisor (GCD)
    int findGCD(int a, int b) {
        return b == 0 ? a : findGCD(b, a % b);
    }
}

using namespace std; // Add this line to use the std namespace

namespace ST {
    namespace GPT {
        // Constructors
        RationalNumber::RationalNumber() : numerator(0), denominator(1) {}

        RationalNumber::RationalNumber(int num) : numerator(num), denominator(1) {}

        RationalNumber::RationalNumber(int num, int denom) : numerator(num), denominator(denom) {
            simplify(); // Simplify the fraction during construction
        }

        // Overloaded input operator
        istream& operator>>(istream& in, RationalNumber& rational) {
            string input;
            in >> input;

            // Use stringstream to parse the input
            stringstream ss(input);
            char slash;
            ss >> rational.numerator >> slash >> rational.denominator;

            rational.simplify(); // Simplify the fraction after input

            return in;
        }

        // Overloaded output operator
        ostream& operator<<(ostream& out, const RationalNumber& rational) {
            out << rational.numerator << '/' << rational.denominator;
            return out;
        }

        // Overloaded comparison operators
        bool RationalNumber::operator==(const RationalNumber& other) const {
            return (numerator == other.numerator) && (denominator == other.denominator);
        }

        bool RationalNumber::operator<(const RationalNumber& other) const {
            return (numerator * other.denominator) < (other.numerator * denominator);
        }

        bool RationalNumber::operator<=(const RationalNumber& other) const {
            return (*this < other) || (*this == other);
        }

        bool RationalNumber::operator>(const RationalNumber& other) const {
            return !(*this <= other);
        }

        bool RationalNumber::operator>=(const RationalNumber& other) const {
            return !(*this < other);
        }

        bool RationalNumber::operator!=(const RationalNumber& other) const {
            return !(*this == other);
        }

        // Overloaded arithmetic operators
        RationalNumber RationalNumber::operator+(const RationalNumber& other) const {
            return RationalNumber(numerator * other.denominator + other.numerator * denominator,
                                  denominator * other.denominator);
        }

        RationalNumber RationalNumber::operator-(const RationalNumber& other) const {
            return RationalNumber(numerator * other.denominator - other.numerator * denominator,
                                  denominator * other.denominator);
        }

        RationalNumber RationalNumber::operator*(const RationalNumber& other) const {
            return RationalNumber(numerator * other.numerator, denominator * other.denominator);
        }

        RationalNumber RationalNumber::operator/(const RationalNumber& other) const {
            // Ensure division by zero is avoided
            if (other.numerator == 0) {
                cerr << "Error: Division by zero." << endl;
                return RationalNumber();
            }
            return RationalNumber(numerator * other.denominator, denominator * other.numerator);
        }

        // Unary minus operator
        RationalNumber RationalNumber::operator-() const {
            return RationalNumber(-numerator, denominator);
        }

        // Helper function to simplify the fraction
        void RationalNumber::simplify() {
            int gcd = findGCD(abs(numerator), abs(denominator));
            numerator /= gcd;
            denominator /= gcd;

            // Ensure the negative sign is in the numerator for consistency
            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
        }
    }
}