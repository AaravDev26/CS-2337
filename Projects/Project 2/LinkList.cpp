// Aarav Dev
// axd220001

#include <string> // imports string library
#include "LinkList.h" // includes LinkList class
#include "Node.h" // includes node class
#include "Player.h" // includes player class
#include <cmath> // needed to perform round function for batting average and on base percentage

// recursive method which converts LinkedList to string formatted to match the required output
std::string LinkList::toString(Node* n)
{
    if (n->next != NULL) // recursive case
    {
        std::string a = n->data.getName() + "\t"; // name of player and a tab
        std::string b = std::to_string(n->data.getAtBats()) + "\t"; // number of at-bats and a tab
        std::string c = std::to_string(n->data.getHits()) + "\t"; // number of hits and a a tab
        std::string d = std::to_string(n->data.getWalks()) + "\t"; // number of walks and a tab
        std::string e = std::to_string(n->data.getStrikeouts()) + "\t"; // number of strikeouts and a tab
        std::string f = std::to_string(n->data.getHitsByPitch()) + "\t"; // number of hits by pitch and a tab
        std::string g = std::to_string(n->data.getSacrifices()) + "\t"; // number of sacrifices and a tab
        std::string h;
        if (n->data.getHits() + n->data.getOuts() + n->data.getStrikeouts() == 0) // if denominator(at-bats) is zero, avoids dividing by zero
        {
            h = "0.000\t"; // batting average is zero if there are zero at-bats
        }
        else // if denominator(at-bats) is not zero
        {
            h = std::to_string((round(n->data.getBattingAverage()*1000))/1000).substr(0, 5) + "\t"; // batting average and a tab
        }
        std::string i;
        if (n->data.getHits() + n->data.getOuts() + n->data.getStrikeouts() == 0)  // if denominator(plate appearances) is zero, avoids dividing by zero
        {
            i = "0.000"; // on-base percentage is zero if there are zero plate appearances
        }
        else // if denominator(plate appearances) is not zero
        {
            i = std::to_string((round(n->data.getOnBasePercentage()*1000))/1000).substr(0,5); // on-base percentage
        }
        return a + b + c + d + e + f + g + h + i + "\n" + toString(n->next); // recursion implemented here, forms string of player and calls itself to add the next player to the string
    }
    else // base case
    {
        std::string a = n->data.getName() + "\t"; // name of player and a tab
        std::string b = std::to_string(n->data.getAtBats()) + "\t"; // number of at-bats and a tab
        std::string c = std::to_string(n->data.getHits()) + "\t"; // number of hits and a a tab
        std::string d = std::to_string(n->data.getWalks()) + "\t"; // number of walks and a tab
        std::string e = std::to_string(n->data.getStrikeouts()) + "\t"; // number of strikeouts and a tab
        std::string f = std::to_string(n->data.getHitsByPitch()) + "\t"; // number of hits by pitch and a tab
        std::string g = std::to_string(n->data.getSacrifices()) + "\t"; // number of sacrifices and a tab
        std::string h;
        if (n->data.getHits() + n->data.getOuts() + n->data.getStrikeouts() == 0)  // if denominator(at-bats) is zero, avoids dividing by zero
        {
            h = "0.000\t"; // batting average is zero if there are zero at-bats
        }
        else // if denominator(at-bats) is not zero
        {
            h = std::to_string((round(n->data.getBattingAverage()*1000))/1000).substr(0, 5) + "\t"; // batting average and a tab
        }
        std::string i;
        if (n->data.getHits() + n->data.getOuts() + n->data.getStrikeouts() == 0) 
        {
            i = "0.000"; // on-base percentage is zero if there are zero plate appearances
        }
        else // if denominator(plate appearances) is not zero
        {
            i = std::to_string((round(n->data.getOnBasePercentage()*1000))/1000).substr(0,5); // on-base percentage
        }
        return a + b + c + d + e + f + g + h + i + "\n"; // last player in the list as next is pointing to null, finalizes string of player and returns it
    }
}


void LinkList::insertNode(Player p) // adds node to end of list
{
   Node *tmp = new Node; // initializes the node
   tmp->data = p; // sets data of node to player specified in parameter
   tmp->next = NULL; // sets next pointer to null
   
   if(this->head == NULL) // if list is empty
   {
      this->head = tmp; // set head to previously initilized node
      this->tail = tmp; // set tail to the same node since only one node
   }
   else // if list is not empty
   {
      this->tail->next = tmp; // set last node to specified player
      this->tail = tail->next; // sets tail
   }
}

void LinkList::sort() // sorts link list in alphabetical order of player names
{
    Node* cur1 = head; // node used to traverse list
    Node* cur2 = head; // another node used to traverse list
    for (int i = 0; i < getSize(); i++) // looping through list
    {
        for (int j = 0; j < getSize() - 1; j++) // looping through list
        {
            if (cur1->data.getName() < cur2->data.getName()) // checking to see what order nodes should be in
            {
                // swapping data in nodes
                Player temp = cur1->data;
                cur1->data = cur2->data; 
                cur2->data = temp;
            }
            cur2 = cur2->next; // going to next node
        }
        cur2 = head; // resetting node to head
        cur1 = head->next; // going to next node
        for (int k = 0; k < i; k++) // loop through list
        {
            cur1 = cur1->next; // go to next node
        }
    }
}

int LinkList::getSize() // finds number of nodes in the list
{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL) // checking if a player exists in the node
    {
        count++; // increments count variable
        current = current->next; // goes to next node
    }
    return count; // returns size of list
}

bool LinkList::contains(std::string name) // checks to see if the linked list contains the specified player using its name
{
    Node* n = head; // node used to traverse the list
    while (n != NULL) // checking if a player exists in the node
    {
        if (n->data.getName() == name) // if name matches with existing name
        {
            return true; // returns true immediately if match is found
        }
        n = n->next; // going to next node
    }
    return false; // returns false if no match found
}



