//Sebastian Rojas
//header file
//11/10/2023
//Assignment 5




#ifndef RATIONALSST_H
#define RATIONALSST_H

#include <iostream>
#include <sstream>

using namespace std; // Add this line to use the std namespace

namespace ST {
    namespace GPT {
        class RationalNumber {
        private:
            int numerator;
            int denominator;

        public:
            // Constructors
            RationalNumber();
            RationalNumber(int num);
            RationalNumber(int num, int denom);

            // Overloaded input and output operators
            friend istream& operator>>(istream& in, RationalNumber& rational);
            friend ostream& operator<<(ostream& out, const RationalNumber& rational);

            // Overloaded comparison operators
            bool operator==(const RationalNumber& other) const;
            bool operator<(const RationalNumber& other) const;
            bool operator<=(const RationalNumber& other) const;
            bool operator>(const RationalNumber& other) const;
            bool operator>=(const RationalNumber& other) const;
            bool operator!=(const RationalNumber& other) const;

            // Overloaded arithmetic operators
            RationalNumber operator+(const RationalNumber& other) const;
            RationalNumber operator-(const RationalNumber& other) const;
            RationalNumber operator*(const RationalNumber& other) const;
            RationalNumber operator/(const RationalNumber& other) const;

            // Unary minus operator
            RationalNumber operator-() const;

        private:
            // Helper function to simplify the fraction
            void simplify();
        };
    }
}

#endif // RATIONALSST_H
