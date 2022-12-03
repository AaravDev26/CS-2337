// Aarav Dev
// axd220001

#ifndef BST_H // if VectorTemplate is not defined
#define BST_H // define VectorTemplate

#include "Node.h" // imports node class

template<typename T> // signifies templated class
class BST // initializes class
{
private:
    Node<T>* root; // private root pointer
    
public:
    Node<T>* getRoot() {return root;} // accessor method for root
    void setRoot(Node<T>* n) {root = n;} // mutator method for root
    BST() {}; // empty default constructor
    BST(T t) {root = new Node<T>(t);} // overloaded constructor which takes root as parameter
    ~BST(); // destructor
    Node<T>* recursiveSearch(Node<T>* r, T key); // recursive helper method for search
    bool search(T t); // returns whether or not parameter is in the tree
    Node<T>* insertRecursive(Node<T>* r, Node<T>* n); // recursive helper method for insert
    void insert(T t); // inserts node into tree containing data in paramter
    T replacementNode(Node<T>* r); // helper method to find replacement of a removed node when the node has two children
    Node<T>* removeRecursive(Node<T>* r, T key); // recursive helper method for removing a node
    Node<T>* deleteNode(T t); // removes node from tree
    std::string reverseInorder(Node<T>* r); // returns string representation of tree
    void destroy(Node<T>* r); // recursive helper method for destrutor
};

template <typename T> // signifies templated function
Node<T>* BST<T>::recursiveSearch(Node<T>* r, T key) // recursive helper method for search
{
    if (!r || r->getData() == key) // if found, return the node, else return null which is in the node's data
    {
        return r; // returns current node's data
    }
    if (key < r->getData()) // if less than, go left
    {
        return recursiveSearch(r->getLeft(), key); // recursive call
    }
    else // if greater than, go right
    {
        return recursiveSearch(r->getRight(), key); // recursive call
    }
}

template <typename T> // signifies templated function
bool BST<T>::search(T x) // returns whether or not parameter is in the tree
{
    if (recursiveSearch(root, x)) // if returned node is not null
    {
        return true; // returns true
    }
    else // if returned node is null
    {
        return false; // returns false
    }
}

template <typename T> // signifies templated function
Node<T>* BST<T>::insertRecursive(Node<T>* r, Node<T>* n) // recursive helper method for insert
{
    if (!r) // if current node is null
    {
        r = n; // set current node to node to insert
        return r; // return current node
    }
    if (n->getData() < r->getData()) // if insertion node's data is less than current node's data
    {
        r->setLeft(insertRecursive(r->getLeft(), n)); // recursive call for right
    }
    else if (n->getData() > r->getData()) // if insertion node's data is greater than current node's data
    {
        r->setRight(insertRecursive(r->getRight(), n)); // recursive call for right
    }
    else
    {
        r->setData(n->getData() + r->getData()); // recursive call
        return r; // return current node
    }
    return r; // return current node
}



template <typename T> // signifies templated function
void BST<T>::insert(T x)
{
    Node<T>* newnode = new Node<T>(x);
    root = insertRecursive(root, newnode);
}

template <typename T> // signifies templated function
T BST<T>::replacementNode(Node<T>* r) // recursive helper function to find minimum in subtree
{
    if (!r->getLeft())  // if current node's left pointer is null
    {
        return r->getData(); // returns miminum data
    }
    return replacementNode(r->getLeft()); // recursive call
}

template <typename T> // signifies templated function
Node<T>* BST<T>::removeRecursive(Node<T>* r, T key) // recursive helper function for removing a node
{
    if (!r) // if current node is null
    {
        return r; // returns current node
    }
    if (key < r->getData()) // if parameter is less than current node's data
    {
        r.setLeft(removeRecursive(r->getLeft(), key)); // recursive call for left
    }
    else if (key > r->getData()) // if parameter is less than current node's data
    {
        r.setRight(removeRecursive(r->getRight(), key)); // recursive call for right
    }
    else // if node to remove is found
    {
        if (!r->getLeft())  // if current node's left pointer is null
        {
            return r->getRight(); // return right pointer
        }
        else if (!r->getRight()) // if current node's right pointer is null
        {
            return r->getLeft(); // return left pointer
        }
        r->setData(replacementNode(r->getRight())); // sets data using helper function
        r->setRight(removeRecursive(r->getRight(), r->getData())); // recursive call
    }
    return r; // returns current node
}



template <typename T> // signifies templated function
Node<T>* BST<T>::deleteNode(T x) // removes node for tree
{
    root = removeRecursive(root, x); // calls recursive helper function
    return root; // returns removed node
}


template <typename T> // signifies templated function
std::string BST<T>::reverseInorder(Node<T>* r) // returns string representation of tree
{
    std::string ans; // string to hold answer
    if (!r) // if current node is null
    {
        return ans; // return answer
    }
    ans += reverseInorder(r->getRight()); // recursive call for left
    if (r->getData().toString().at(0) == '-') // if negative
    {
        ans += r->getData().toString(); // add onto ans
    }
    else // if positive
    {
        ans += "+" + r->getData().toString(); // add onto ans with plus sign
    }
    ans += reverseInorder(r->getLeft()); // recursive call for right
    return ans; // return answer
}

template <typename T> // signifies templated function
BST<T>::~BST() // destructor
{
    destroy(root); // calls recursive helper function
}

template <typename T>  // signifies templated function
void BST<T>::destroy(Node<T>* r) // recursive helper method for destrutor
{
    if (!r) // if current node is null
    {
        return; // exit function
    }
    destroy(r->getRight()); // recursive call for right
    destroy(r->getLeft()); // recursive call for left
    delete r; // deletes current node
    return; // exits method
}


#endif // ends if statement after defining class
