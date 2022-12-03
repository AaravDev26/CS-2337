// Aarav Dev
// axd220001

#include "Node.h" // includes node class
#include "Player.h" // includes player class, needed because node holds a player object

// default constructor
Node::Node()
{
   next = NULL; // sets next node to null
}

// overloaded constructor
Node::Node(Player p)
{
   this->data = p; // sets data of node to player specified in parameter
   this->next = NULL; // sets next node to null
}
