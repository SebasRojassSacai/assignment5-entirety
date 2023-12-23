//Sebastian Rojas
//11/10/2023
//Assignment 5


#include "rationalsST.h"
#include <iostream>

using namespace std; // Add this line to use the std namespace

using namespace ST::GPT;

int main() {
    RationalNumber a, b;

    // Input rational numbers
    cout << "Enter the first rational number: ";
    cin >> a;

    cout << "Enter the second rational number: ";
    cin >> b;

    // Output rational numbers
    cout << "First rational number: " << a << endl;
    cout << "Second rational number: " << b << endl;

    // Perform arithmetic operations
    cout << "Sum: " << a + b << endl;
    cout << "Difference: " << a - b << endl;
    cout << "Product: " << a * b << endl;
    cout << "Quotient: " << a / b << endl;

    // Perform comparison operations
    cout << "Comparison: " << (a < b ? "a < b" : "a >= b") << endl;

    // Unary minus
    cout << "Unary Minus of a: " << -a << endl;

    return 0;
}