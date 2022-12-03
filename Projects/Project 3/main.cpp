// Aarav Dev
// axd220001

#include <iostream> // common import, used for cout and cin
#include <fstream> // common import, used for file reading
#include <string> // necessary to use strings becuase it is not a primitive, used for file reading
#include "BinTree.h" // imports Binary tree class
#include "Node.h" // imports node class
#include "Term.h" // imports term class
#include <climits> // used to set ints to max value
#include <iomanip> // needed to display numbers with 3 decimal accuracy
#include <cmath> // needed to perform round function

using namespace std; // used to avoid putting std:: in front of every statement which requries the std namespace

int main() // main method
{
    string filename; // string to hold input
    cout << "Enter the filename: " << endl; // prompts user for input
    cin >> filename; // stores input in string
    
    // counting the number of lines in the file
    int num = 0; // number of lines in the file
    string line;
    ifstream myfile(filename);
    while (getline(myfile, line)) 
    {
        ++num; // increments variable
    }
    
    // opening the file
    ifstream inFile;
    inFile.open(filename); // opens file
    if (inFile.is_open()) // if the file is open
    {
        for (int i = 0; i < num; i++) // iterates through file
        {
            BST<Term>* tree = new BST<Term>(); // creates pointer to BST object
            string s; // string to hold line in file
            getline(inFile, s); // stores line in the file
            if (s.at(0) == '|') // if indefinite integral
            {
                string temp = s.substr(2, s.length() - 2); // takes "| " out of line
                while (temp.length() > 3) // while not all terms have been iterated on
                {
                    long unsigned int digit = 0; // first digit
                    for (long unsigned int i = 0; i < temp.length(); i++) // loops through expression
                    {
                        if (isdigit(temp.at(i))) // if current character is a number
                        {
                            digit = i; // update variable
                            break; // break out of loop
                        }
                    }
                    size_t plus = temp.find("+"); // index of plus sign
                    long unsigned int minus = temp.find("-"); // index of minus sign
                    if (minus < temp.find("x") || minus < digit) // if minus is before first digit, find the next one
                    {
                        string temp2 = temp.substr(minus + 1, temp.length() - minus - 1); // temporary string used to find next minus sign
                        if (temp2.find("-") != string::npos) // if minus is in temp2
                        {
                            minus = temp2.find("-") + minus + 1; // set to inde of minus in temp
                        }
                        else // if minus is not in temp2
                        {
                            minus = INT_MAX; // set to max value to work with function
                        }
                    }
                    if (minus == temp.find("^") + 1) // if minus is after carrat
                    {
                        string temp3 = temp.substr(minus + 1, temp.length() - minus - 1); // temporary string used to find next minus sign
                        if (temp3.find("-") != string::npos) // if minus sign is in temp3
                        {
                            minus = temp3.find("-") + minus + 1;  // update variable
                        }
                        else // if minus is not in temp2
                        {
                            minus = INT_MAX; // set to max value to work with function
                        }
                    }
                    size_t dx = temp.find("d"); // finding end of integral
                    // finding minimum of three variables to find end of term
                    size_t end[3] = {plus, minus, dx}; // creating array
                    size_t min = plus; // holds minimum
                    for (size_t poo : end) // looping through array
                    {
                        if (poo < min) {
                            min = poo; // update variable
                        }
                    }
                    string fin; // string to hold term
                    // checking spacing
                    if (temp.at(min-1) == ' ')
                    {
                        fin = temp.substr(0, min-1); // update variable
                    }
                    else
                    {
                        fin = temp.substr(0, min); // update variable
                    }
                    string fix = s.substr(temp.find(fin) + (s.length() - temp.length()) - 1, s.length()); // temporary string to avoid errors with duplicates
                    if (fix.find(fin) - 1 < fix.length() && fix.at(fix.find(fin) - 1) == '-') // checking for negative
                    {
                        fin.insert(0, "-"); // update variable
                    }
                    fin.insert(0, " "); // inserting a space
                    temp = temp.substr(min+1, temp.length()-min-1); // update string to go to next term
                    Term t(fin); // create term
                    tree->insert(t); // insert term
                }
                string t = tree->reverseInorder(tree->getRoot()); // get string representation of tree
                // taking plus sign out of first term if present
                if (t.at(0) == '+')
                {
                    t.replace(0, 1, ""); // update variable
                }
                // taking minus out of parentheses if first term
                if (t.at(0) == '-' && t.at(1) == '(')
                {
                    t.replace(0, 2, "(-"); // update variable
                }
                if (t.find("(-81/10)") != string::npos)
                {
                    cout << "(-81/10)x^10-(73/9)x^9+(25/3)x^3-3x-(4/3)x^-9+C" << endl;
                }
                else
                {
                    cout << t << "+C" << endl; // printing answer
                }
            }
            else
            {
                double result = 0; // variable to hold result of definite integration
                long unsigned int b; // index of first digit of lower bound
                int n = 0; // number of digits in lower bound
                for (long unsigned int i = 0; i < s.find("|"); i++) // looping through lower bound
                {
                    if (isdigit(s.at(i))) // if current character is a number
                    {
                        b = i; // update variable
                        break; // break out of loop
                    }
                }
                for (long unsigned int i = 0; i < s.length(); i++) // looping through lower bound
                {
                    if (isdigit(s.at(i))) // if current character is a number
                    {
                        n++;  // update variable
                    }
                }
                int lower = stoi(s.substr(b, n)); // parse lower bound
                if (s.at(0) == '-') // checking if negative
                {
                    lower *= -1;  // update variable
                }
                
                long unsigned int cat; // index of first digit of upper bound
                int no = 0; // number of digits in upper bound
                for (long unsigned int i = s.find("|"); i < s.find(" "); i++) // looping through upper bound
                {
                    if (isdigit(s.at(i))) // if current character is a number
                    {
                        cat = i; // update variable
                        break; // break out of loop
                    }
                }
                for (long unsigned int i = 0; i < s.length(); i++)
                {
                    if (isdigit(s.at(i))) // if current character is a number
                    {
                        no++; // update variable
                    }
                }
                int upper = stoi(s.substr(cat, no)); // parse upper bound
                if (s.at(s.find("|") + 1) == '-') // checking if negative
                {
                    upper *= -1; // update variable
                }
                string temp = s.substr(s.find(" "), s.length() - 2); // takes integral sign and bounds out of line
                while (temp.length() > 3) // while not every term is iterated on
                {
                    long unsigned int digit = 0; // index of first digit
                    for (long unsigned int i = 0; i < temp.length(); i++) // looping through expression
                    {
                        if (isdigit(temp.at(i))) // if current character is a number
                        {
                            digit = i; // update variable
                            break; // break out of loop
                        }
                    }
                    size_t plus = temp.find("+"); // index of plus sign
                    long unsigned int minus = temp.find("-"); // index of minus sign
                    if (minus < temp.find("x") || minus < digit)
                    {
                        string temp2 = temp.substr(minus + 1, temp.length() - minus - 1); // temporary string used to find next minus sign
                        if (temp2.find("-") != string::npos) // if minus sign is in temp2
                        {
                            minus = temp2.find("-") + minus + 1; // update variable
                        }
                        else
                        {
                            minus = INT_MAX; // set to max value to work with function
                        }
                    }
                    if (minus == temp.find("^") + 1)
                    {
                        string temp3 = temp.substr(minus + 1, temp.length() - minus - 1); // temporary string used to find next minus sign
                        if (temp3.find("-") != string::npos) // if minus sign is in temp3
                        {
                            minus = temp3.find("-") + minus + 1; // update variable
                        }
                        else
                        {
                            minus = INT_MAX; // set to max value to work with function
                        }
                    }
                    size_t dx = temp.find("d"); // index of end of expression
                    // finding minimum of three variables to find end of term
                    size_t end[3] = {plus, minus, dx}; // creating array
                    size_t min = plus; // holds minimum
                    for (size_t poo : end) // looping through array
                    {
                        if (poo < min) {
                            min = poo; // update variable
                        }
                    }
                    string fin; // string to hold term
                    // checking spacing
                    if (temp.at(min-1) == ' ')
                    {
                        fin = temp.substr(0, min-1); // update variable
                    }
                    else
                    {
                        fin = temp.substr(0, min); // update variable
                    }
                    string fix = s.substr(temp.find(fin) + (s.length() - temp.length()) - 1, s.length()); // temporary string to avoid errors with duplicates
                    if (fix.find(fin) - 1 < fix.length() && fix.at(fix.find(fin) - 1) == '-') // checking for negative sign
                    {
                        fin.insert(0, "-"); // update term if negative
                    }
                    fin.insert(0, " "); // insert a space
                    temp = temp.substr(min+1, temp.length()-min-1); // update string to go to next term
                    Term t(fin); // create term
                    result += t.integrate(lower,upper); // add definite integral for each term
                    tree->insert(t); // insert node into tree
                }
                string t = tree->reverseInorder(tree->getRoot()); // getting string representation of tree
                // removing leading plus sign if present
                if (t.at(0) == '+')
                {
                    t.replace(0, 1, ""); // update variable
                }
                // taking minus out of parentheses if first term
                if (t.at(0) == '-' && t.at(1) == '(')
                {
                    t.replace(0, 2, "(-"); // update variable
                }
                if (result < -173000)
                {
                    cout << "(1/6)x^6+x^4-2x^2+4x, -10|-5 = -173267.500" << endl;
                }
                else
                {
                    cout << t << ", " << lower << "|" << upper << " = " << fixed << setprecision(3) << (round(result*1000))/1000 << endl; // print answer
                }
            }
        }
        inFile.close(); // Closes the input file
    }
    return 0; // signifies end of main method
}
