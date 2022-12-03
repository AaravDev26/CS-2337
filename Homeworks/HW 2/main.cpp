// Aarav Dev
// axd220001

#include <iostream> // common import
#include <string> // imports string library
#include <vector> // imports vector library
#include "VectorTemplate.h" // imports VectorTemplate class

using namespace std; // used to avoid putting "std::" in front of things in the std namespace

int main()
{
    // testing VectorTemplate class with ints
    vector<int> v {5, 2, 8, 4}; // initializing vector of ints
    cout << "Testing with int" << endl;
    VectorTemplate<int> ex(v); // initializing VectorTemplate class with int as the type
    ex.InsertionSort(); // tests InsertionSort method
    // prints contents of vector
    for (unsigned int i = 0; i < ex.getVector().size(); i++) // loops through vector
    {
        // print a comma between elements of list
        if (i != 0) {
            cout << ", ";
        }
        cout << ex.getVector().at(i); // prints vector content at current index
    }
    cout << endl; // goes to next line
    // testing binary search
    bool b = ex.BinarySearch(2); // initializing boolean variable to hold if parameter found in sorted vector
    if (b) // if found
    {
        cout << "Item found" << endl;
    }
    else // if not found 
    {
        cout << "Item not found" << endl;
    }
    cout << endl;
    
    // testing with other data types, same logic with different data types (double and string)
    
    vector<double> v2 {7.4, 1.4, 6.5, 0.1};
    cout << "Testing with double" << endl;
    VectorTemplate<double> ex2(v2);
    ex2.InsertionSort();
    for (unsigned int i = 0; i < ex2.getVector().size(); i++)
    {
        if (i != 0) {
            cout << ", ";
        }
        cout << ex2.getVector().at(i);
    }
    cout << endl;
    bool b2 = ex2.BinarySearch(7.4);
    if (b2) {
        cout << "Item found" << endl;
    }
    else {
        cout << "Item not found" << endl;
    }
    cout << endl;
    
    vector<string> v3 {"Bob", "James", "Aaron", "Zack"};
    cout << "Testing with string" << endl;
    VectorTemplate<string> ex3(v3);
    ex3.InsertionSort();
    for (unsigned int i = 0; i < ex3.getVector().size(); i++)
    {
        if (i != 0) {
            cout << ", ";
        }
        cout << ex3.getVector().at(i);
    }
    cout << endl;
    bool b3 = ex3.BinarySearch("Robert");
    if (b3) {
        cout << "Item found" << endl;
    }
    else {
        cout << "Item not found" << endl;
    }
    return 0; // signifies end of main method
}
