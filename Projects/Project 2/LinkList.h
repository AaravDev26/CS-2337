// Aarav Dev
// axd22001

#ifndef LINKLIST_H // if linklist is not defined
#define LINKLIST_H // define linklist if not defined
#include <string> // imports string library
#include "Node.h" // includes node class
#include "Player.h" // includes player class

class LinkList
{
private:
    Node* head; // head pointer, first node in the list
    Node* tail; // tail pointer, last node in the list
public:
    Node* getHead() {return head;} // returns head pointer, needed because head is private
    Node* getTail() {return tail;} // returns tail pointer, needed because tail is private
    LinkList() {head = NULL;} // default constructor
    std::string toString(Node* n); // converts linked list into a string
    void insertNode(Player p); // adds a new node specified in the paramater to the end of the linked list
    void sort(); // sorts the linked list in alphabetical order based on the players' names
    int getSize(); // returns the number of nodes in the linked list
    bool contains(std::string name); // checks to see if the parameter is contained in the linked list
};
#endif // ends if statement
