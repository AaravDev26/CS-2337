// Aarav Dev
// axd22001

#ifndef NODE_H // if node class is not defined
#define NODE_H // defines node class if not already defined
#include "Player.h" // includes player class because nodes need to store a player object

class Node
{
public:
   Player data; // player object which the node will hold
   Node* next; // pointer to the next node
   Node(); // default constructor
   Node(Player p); // overloaded constructor
};
#endif // ends if statement
