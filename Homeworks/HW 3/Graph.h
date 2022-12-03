// Aarav Dev
// axd220001

#ifndef GRAPH_H // if Graph is not defined
#define GRAPH_H // define Graph

#include <string> // imports string library

class Graph // initializes class
{
private:
    int adjMatrix[10][10]; // adjacency matrix
    int curSize; // current size of graph
    int maxSize; // maximum size of graph
public:
    // accessor methods
    int getCurSize() {return curSize;}
    int getMaxSize() {return maxSize;}
    
    // mutator methods
    void setCurSize(int i) {curSize = i;}
    void setMaxSize(int i) {maxSize = i;}
    
    // constructors
    Graph(); // default constructor
    Graph(int i); // overloaded constructor
    
    // class methods
    bool isEmpty() {return curSize == 0;} // checks if current size is zero
    void createGraph(std::string filename); // reads file and creates adjacency matrix
    bool isConnected(); // determines if graph is connected or not
    void DFS(int i, bool visited[]); // performs a depth first traversal on the graph
};
#endif // ends definition of Graph.h
