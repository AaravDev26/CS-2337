// Aarav Dev
// axd220001

#ifndef TERM_H // if Term is not defined
#define TERM_H // define Term

#include <string> // imports string library

class Term // declares term class, used to hold a term's data including the coefficient and exponent
{
private: // private variables, can only be accessed inside class
    int coefficient; // holds value of coefficient
    int exponent; // holds value of exponent
public: // public methods, can be accessed from any class or method
    Term() {}; // empty default constructor
    Term(std::string s); // overloaded constructor with string parameter
    
    // accessor methods
    int getCoefficient() {return coefficient;} // returns coefficient
    int getExponent() {return exponent;} // returns exponent
    
    // mutator methods
    void setCoefficient(int i) {coefficient = i;} // sets coefficient to value in parameter
    void setExponent(int i) {exponent = i;} // sets exponent to value in parameter
    
    // overloaded operators
    bool operator < (const Term& f); // overloaded less than operator
    bool operator > (const Term& f); // overloaded greater than operator
    bool operator == (const Term& f); // overloaded equals operator
    Term operator + (const Term& f); // overlaoded addition operator
    
    // class methods
    std::string toString(); // converts term into integrated string representation
    double integrate(int a, int b); // returns result of definite integration from first parameter to second parameter
};
#endif // ends if statement after defining class
