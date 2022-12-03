// Aarav Dev
// axd220001


#include <iostream> // common import
#include <fstream> // common import
#include "Fraction.h" // includes fraction header file to use its methods and operators
using namespace std; // used to avoid using "std::" in many instances, shortens code

// driver program
int main()
{
   Fraction f(5, 8); // constructs first fraction object
   Fraction f2; // constructs second fraction object
   cout << "Enter the numerator and denominator" << endl; // prompts user for numerator and denominator
   cin >> f2; // stores user input in second fraction object
   cout << "Addition " << f + f2 << endl; // prints sum of fractions
   cout << "Subtraction " << f - f2 << endl; // prints difference of fractions
   cout << "Multiplication " << f * f2 << endl; // prints product of fractions
   cout << "Division " << f / f2 << endl; // prints quotient of fractions
   bool lessThan = f < f2; // checks to see if first fraction is less than second fraction, stores in variable
   cout << "Less than " << lessThan << endl; // prints result of less than operator for fractions
   bool greaterThan = f > f2; // checks to see if first fraction is greater than second fraction, stores in variable
   cout << "Greater than " << greaterThan << endl; // prints result of greater than operator for fractions
   bool equals = f == f2; // checks to see if first fraction is equal to second fraction, stores in variable
   cout << "Equal " << equals << endl; // prints result of equal to operator for fractions
   return 0; // returns zero to end main method
}
