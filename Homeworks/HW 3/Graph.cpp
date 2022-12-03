// Aarav Dev
// axd220001

#include "Graph.h" // imports header file
#include <string> // imports string library
#include <fstream> // used for file reading
#include <sstream> // used for stringstream separation of strings

Graph::Graph() // default constructor
{
    maxSize = 10;
    // loop to initialize all elements to zero
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            adjMatrix[r][c] = 0;
        }
    }
}

Graph::Graph(int i) // overloaded constructor
{
    maxSize = i;
    // loop to initialize all elements to zero
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            adjMatrix[r][c] = 0;
        }
    }
}


void Graph::createGraph(std::string filename) // reads file and creates adjacency matrix
{
    std::ifstream inFile;
    inFile.open(filename); // opens file
    if (inFile.is_open()) // if the file is open
    {
        std::string s; // string to hold line
        getline(inFile, s); // stores first line in variable
        curSize = stoi(s.substr(0, 1)); // setting current size based on first line of input
        for (int r = 0; r < curSize; r++) // looping through input
        {
            std::string str; // string to hold current line
            getline(inFile, str); // stores line in variable
            if (str.length() > 2) // if edges exist for node
            {
                std::string temp = str.substr(2, str.length() - 1);
                std::stringstream check1(temp);
                std::string intermediate;
                while(getline(check1, intermediate, ' ')) // separating by spaces
                {
                    if (intermediate.find("r") != std::string::npos)
                    {
                       int col = std::stoi(intermediate);
                       adjMatrix[r][col-1] = 1; // updates adjacency matrix
                    }
                }
            }
        }
    }
    inFile.close(); // closes the file
}

void Graph::DFS(int r, bool visited[]) // performs a depth first traversal on the graph
{
    visited[r] = true;
    for (int i = 0; i < curSize; i++) // looping through array
    {
        if (adjMatrix[r][i]) // if edge exists
        {
            if (!visited[i]) // if not visited
            {
                DFS(i, visited); // recursive call
            }
        }
    }
}

bool Graph::isConnected() // determines if graph is connected or not
{
    // Mark all the vertices as not visited
    bool *visited = new bool[curSize];
    for (int i = 0; i < curSize; i++)
        visited[i] = false;
 
    // Do DFS traversal starting from first vertex.
    DFS(0, visited);
 
     // If DFS traversal doesn't visit all vertices, return false.
    for (int i = 0; i < curSize; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    delete [] visited; // delete pointers
    return true;
}
