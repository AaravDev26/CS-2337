// Aarav Dev
// axd220001

#include "Term.h" // includes header file for term class
#include <string> // imports string library
#include <cmath> // imports math library for math functions, needed for power function
#include <cstdlib> // needed for absolute value function

Term::Term(std::string s) // overloaded constructor with string parameter 
{
    if (s.find("x") == std::string::npos) // if "x" is not in the parameter
    {
        exponent = 0; // set exponent to zero
        long unsigned int b; // index of first digit
        int n = 0;  // number of digits in number
        for (long unsigned int i = 0; i < s.length(); i++) // looping through parameter
        {
            if (isdigit(s.at(i))) // if current character is a number
            {
                b = i; // first digit found, update variable
                break; // break out of loop
            }
        }
        for (long unsigned int i = 0; i < s.length(); i++) // looping through parameter
        {
            if (isdigit(s.at(i))) // if current character is a number
            {
                n++; // increment number of digits
            }
        }
        coefficient = stoi(s.substr(b, n)); // set coefficient
        if (s.find("-") != std::string::npos) // if negative sign is found in parameter
        {
            coefficient *= -1; // make coefficient negative
        }
    }
    else
    {
        long unsigned int b; // index of first digit
        int n = 0; // number of digits
        size_t x = s.find("x"); // holds index of "x"
        // loop to find first digit
        for (long unsigned int i = 0; i < x; i++)
        {
            if (isdigit(s.at(i)))
            {
                b = i;
                break;
            }
        }
        // loop to find number of digits
        for (long unsigned int i = 0; i < x; i++)
        {
            if (isdigit(s.at(i)))
            {
                n++;
            }
        }
        if (n == 0) // if no digits
        {
            if ((x > 1 && s.at(x-1) == '-') || (x > 2 && s.at(x-2) == '-')) // if negative, make variable negative, else keep positive
            {
                coefficient = -1; // update variable
            }
            else
            {
                coefficient = 1; // update variable
            }
        }
        else // if digits exist
        {
            coefficient = stoi(s.substr(b, n)); // set coefficient
            if ((b > 1 && s.at(b-1) == '-') || (b > 2 && s.at(b-2) == '-')) // checking for negative
            {
                coefficient *= -1; // update variable
            }
        }
        if (s.find("^") == std::string::npos) // if no exponent sign
        {
            exponent = 1; // set exponent to 1
        }
        else // if there is an exponent sign
        {
            size_t carrat = s.find("^"); // index of carrat
            int c = 0; // number of digits in exponent
            // finding number of digits in exponent
            for (long unsigned int i = carrat; i < s.length(); i++)
            {
                if (isdigit(s.at(i)))
                {
                    c++; // update variable
                }
            }
            if (s.at(carrat+1) == '-') // if exponent is negative
            {
                exponent = stoi(s.substr(carrat+2, c));
                exponent *= -1; // update variable
            }
            else
            {
                exponent = stoi(s.substr(carrat+1, c)); // update variable
            }
        }
    }
}

// overloaded less than operator
bool Term::operator < (const Term& f)
{
   return (exponent < f.exponent); // returns comparison of exponents (less than)
}

// overloaded greater than operator
bool Term::operator > (const Term& f)
{
   return (exponent > f.exponent); // returns comparison of exponents (greater than)
}

// overloaded equal operator
bool Term::operator == (const Term& f)
{
   return (exponent == f.exponent); // returns comparison of exponents (eaual to)
}

// overloaded addition operator
Term Term::operator + (const Term& f)
{
   coefficient += f.coefficient; // adds coefficients
   return *this; // returns object
}

std::string Term::toString() // converts term into integrated string representation
{
    if (coefficient == 0) // checking for zero coefficient
    {
        return "0"; // returns "0"
    }
    std::string ans; // holds answer
    int ex = exponent + 1; // new exponent
    if (coefficient % ex == 0)
    {
        int newc = coefficient / ex; // new coefficient
        if (newc == 1) // if coefficient is 1
        {
            if (ex == 1) // if exponent is one
            {
                ans = "x"; // update variable
            }
            else // if exponent is not one
            {
                ans = "x^" + std::to_string(ex); // update variable
            }
        }
        else if (newc == -1)
        {
            if (ex == 1)
            {
                ans = "-x"; // update variable
            }
            else
            {
                ans = "-x^" + std::to_string(ex); // update variable
            }
        }
        else
        {
            if (ex == 1) // if exponent is one
            {
                ans = std::to_string(newc) + "x";  // update variable
            }
            else
            {
                ans = std::to_string(newc) + "x^" + std::to_string(ex);  // update variable
            }
        }
    }
    else
    {
        // making negative varibles positive to avoid errors
        int gcf;
        int lmfao = coefficient;
        if (coefficient < 0)
        {
            lmfao *= -1; // update variable
        }
        int wtf = ex;
        if (wtf < 0)
        {
            wtf *= -1; // update variable
        }
        // loop to find greatest common factor
        for (int i = 1; i <= lmfao && i <= wtf; i++) 
        {
            if (lmfao % i == 0 && wtf % i == 0) 
            {
                gcf = i; // update variable
            }
        }
        if (coefficient * ex > 0) // if fraction is positive
        {
            if (ex == 1) // if exponent is one
            {
                ans = "(" + std::to_string(abs(coefficient/gcf)) + "/" + std::to_string(abs(ex/gcf)) + ")x"; // update variable, positive fraction with no exponent
            }
            else // if exponent is not one
            {
                ans = "(" + std::to_string(abs(coefficient/gcf)) + "/" + std::to_string(abs(ex/gcf)) + ")x^" + std::to_string(ex); // update variable, positive fraction with exponent
            }
        }
        else // if fraction is negative
        {
            if (ex == 1) // if exponent is one
            {
                ans = "-(" + std::to_string(abs(coefficient/gcf)) + "/" + std::to_string(abs(ex/gcf)) + ")x"; // update variable, fraction with negative sign and no exponent
            }
            else
            {
                ans = "-(" + std::to_string(abs(coefficient/gcf)) + "/" + std::to_string(abs(ex/gcf)) + ")x^" + std::to_string(ex); // update variable, fraction with negative sign and exponent
            }
        }
    }
    return ans; // return final answer
}

double Term::integrate(int a, int b) // finds result of definite integral
{
    double ex = exponent + 1; // new exponent
    double newc = coefficient/ex; // new coefficient
    // finds upper and lower bound's result for the function
    double upper = newc * (pow(b, ex));
    double lower = newc * (pow(a, ex));
    return upper - lower; // returns answer
}

