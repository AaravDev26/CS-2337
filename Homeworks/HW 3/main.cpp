// Aarav Dev
// axd220001

#include <iostream> // common import, used for cout and cin
#include <fstream> // common import, used for file reading
#include <string> // necessary to use strings becuase it is not a primitive, used for file reading
#include "Graph.h" // imports graph class

using namespace std; // used to avoid putting std:: in front of every statement which requries the std namespace

int main() // main method
{
    // getting name of file from input and storing it in a string
    string filename; // string to hold filename
    cout << "Enter the filename: " << endl; // prompting user for input filename
    cin >> filename; // storing filename in variable
    Graph g; // constructing graph using default constructor
    g.createGraph(filename); // creating graph
    if (g.isConnected()) // if connected, print connected, else print not connected
    {
        cout << "connected"; // printing answer
    }
    else
    {
        cout << "not connected";
    }
    return 0; // signifies end of main method
}
