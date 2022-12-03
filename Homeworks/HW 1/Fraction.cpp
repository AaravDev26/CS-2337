// Aarav Dev
// axd220001

#include <iostream> // includes istream and ostream for the overloaded insertion and extraction operators
#include "Fraction.h" // includes fraction header file to implement its methods and operators

// default constructor
Fraction::Fraction()
{
   numerator = 0;
   denominator = 1;
}

// overloaded constructor
Fraction::Fraction(int num, int den)
{
   numerator = num;
   denominator = den;
}

// second overloaded constructor
Fraction::Fraction(int num)
{
   numerator = num;
   denominator = 1;
}

// method to simplify fraction into lowest terms
void Fraction::simplify()
{
   int gcd;
   // loop to find greatest common denominator
   for (int i = 1; i <= numerator && i <= denominator; i++) 
   {
      if (numerator % i == 0 && denominator % i == 0) 
      {
         gcd = i;
      }
   }
   numerator /= gcd;
   denominator /= gcd;
}

// overloaded addition operator
Fraction Fraction::operator + (const Fraction& f)
{
   numerator = (numerator * f.denominator) + (f.numerator * denominator);
   denominator *= f.denominator;
   simplify();
   return *this;
}

// overloaded subtraction operator
Fraction Fraction::operator - (const Fraction& f)
{
   numerator = (numerator * f.denominator) - (f.numerator * denominator);
   denominator *= f.denominator;
   simplify();
   return *this;
}

// overloaded multiplication operator
Fraction Fraction::operator * (const Fraction& f)
{
   numerator *= f.numerator;
   denominator *= f.denominator;
   simplify();
   return *this;
}

// overloaded division operator
Fraction Fraction::operator / (const Fraction& f)
{
   numerator *= f.denominator;
   denominator *= f.numerator;
   simplify();
   return *this;
}

// overloaded less than operator
bool Fraction::operator < (const Fraction& f)
{
   double a = ((double) numerator) / ((double) denominator);
   double b = ((double) f.numerator) / ((double) f.denominator);
   return a < b;
}

// overloaded greater than operator
bool Fraction::operator > (const Fraction& f)
{
   double a = ((double) numerator) / ((double) denominator);
   double b = ((double) f.numerator) / ((double) f.denominator);
   return a > b;
}

// overloaded equal operator
bool Fraction::operator == (const Fraction& f)
{
   double a = ((double) numerator) / ((double) denominator);
   double b = ((double) f.numerator) / ((double) f.denominator);
   return a == b;
}

// overloaded insertion operator
std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
   out << f.numerator << " / " << f.denominator;
   return out;
}

// overloaded extraction operator
std::istream& operator >> (std::istream& in, Fraction& f)
{
   in >> f.numerator >> f.denominator;
   return in;
}
