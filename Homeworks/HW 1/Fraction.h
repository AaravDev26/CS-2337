// Aarav Dev
// axd22001

#ifndef FRACTION_H // if fraction is not defined
#define FRACTION_H // define fraction

#include <iostream> // includes istream and ostream for the overloaded insertion and extraction operators

class Fraction
{
private:
   int numerator; // private numerator variable, holds numerator
   int denominator; // private denominator variable, holds denominator
public:
   // constructors
   Fraction(); // default constructor
   Fraction(int num, int den); // overloaded constructor which specifies numerator and denominator
   Fraction(int num); // overloaded constructor which specifies numerator
   
   // accessors
   int getNumerator() {return numerator;} // accesses numerator variable
   int getDenominator() {return denominator;} // accesses denominator variable
   
   // mutators
   void setNumerator(int num) {numerator = num;} // sets numerator variable to specified number
   void setDenominator(int num) {denominator = num;} // sets denominator variable to specified number
   
   // method to simplify fraction
   void simplify(); // reduces fraction to lowest terms
   
   // overloaded operators
   Fraction operator + (const Fraction& f); // overlaoded addition operator
   Fraction operator - (const Fraction& f); // overloaded subtraction operator
   Fraction operator * (const Fraction& f); // overloaded multiplication operator
   Fraction operator / (const Fraction& f); // overloaded division operator
   bool operator < (const Fraction& f); // overloaded less than operator
   bool operator > (const Fraction& f); // overloaded greater than operator
   bool operator == (const Fraction& f); // overloaded equals operator
   friend std::ostream& operator << (std::ostream& out, const Fraction& f); // overloaded insertion operator
   friend std::istream& operator >> (std::istream& in, Fraction& f); // overloaded extraction operator
};
#endif // FRACTION_H, ends if statement
