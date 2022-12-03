// Aarav Dev
// axd220001

#ifndef NODE_H // if Node is not defined
#define NODE_H // define Node

template<typename T> // signifies templated class
class Node // declares node class, used to hold data in a binary tree
{
private:
    T data; // data to be held in node
    Node *right, *left; // left and right pointers for each node
public:
    Node(); // default constructor
    Node(T t); // overloaded constructor with data as parameter
    Node(Node* c); // overloaded constructor with pointer to node as parameter

    // accessor methods
    T getData(){return data;} // returns data
    Node* getLeft(){return left;} // returns left pointer
    Node* getRight(){return right;} // returns right pointer
    
    // mutator methods
    void setData(T t){data=t;} // sets data to object in parameter
    void setLeft(Node* n){left=n;} // sets left pointer to parameter
    void setRight(Node* n){right=n;} // sets right pointer to parameter
};

template<typename T> // signifies templated method
Node<T>::Node() // default constructor
{
    // sets left and right pointers to null
    left = nullptr;
    right = nullptr;
}

template<typename T> // signifies templated method
Node<T>::Node(T t) // overloaded constructor with data as parameter
{
    // sets data to parameter and left and right pointer to null
    data = t;
    left = nullptr;
    right = nullptr;
}

template<typename T> // signifies templated method
Node<T>::Node(Node* c) // overloaded constructor with pointer to node as parameter
{
    // sets data to parameter's data and left and right pointer to null
    this->data=c->data;
    left = nullptr;
    right = nullptr;
}

#endif // ends if statement after defining class
