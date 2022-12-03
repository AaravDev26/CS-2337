// Aarav Dev
// axd220001

#include <iostream> // common import
#include <fstream> // common import
#include <string> // necessary to use strings becuase it is not a primitive, used for file reading
#include <iomanip> // needed to display numbers with 3 decimal accuracy
#include "Player.h" // includes player class
#include "Node.h" // includes node class
#include "LinkList.h" // includes linklist class
using namespace std; // used to avoid putting std:: in front of every statement which requries the std namespace

void printLeadersBattingAverage(LinkList l); // prototyped method to print the batting average leaders
void printLeadersOnBasePercentage(LinkList l); // prototyped method to print the on-base percentage leaders
void printLeadersHits(LinkList l); // prototyped method to print the hits leaders
void printLeadersWalks(LinkList l); // prototyped method to print the walks leaders
void printLeadersStrikeouts(LinkList l); // prototyped method to print the strikeouts leaders
void printLeadersHitsByPitch(LinkList l); // prototyped method to print the hit by pitch leaders

int main() // main method
{
    LinkList list; // list which will hold nodes holding all player data in a player object
    
    // getting name of file from input and storing it in a string
    string filename;
    cout << "Enter the filename: " << endl;
    cin >> filename;
    
    // opening the file
    ifstream inFile;
    inFile.open(filename);
    
    // counting the number of lines in the file
    int num = 0; // number of lines in the file
    string line;
    ifstream myfile(filename);
    while (getline(myfile, line)) 
    {
        ++num; // increments variable
    }
    
    // reading the contents of the file into an array
    if (inFile.is_open())  
    {
        for (int i = 0; i < num; i++) // iterates through file
        {
            string a; // name of player
            string temp; // letters representing stats of players
            inFile >> a; // stores name into variable
            inFile >> temp; // stores stats into variable
            Player p; // initializes player object
            p.setName(a); // sets name of player to name specified in the file
            p.setStats(temp); // sets stats of player to stats specified in the file
            if (list.contains(a)) // checks to see if player is already in the list; checking for duplicates
            {
                // iterates through the list and sets current node to the node that already points to the duplicate player
                Node* n = list.getHead(); 
                while (n->data.getName() != a) // finding the duplicate
                {
                    n = n->next; // going to next node if current one is not the duplicate
                }
                
                // updates player data for the duplicate
                for (unsigned int i = 0; i < temp.size(); i++) // loop to count stats for a player
                {
                    if (temp.at(i) == 'H') // checks for hits
                    {
                        n->data.setHits(n->data.getHits() + 1); // increments hits variable by 1
                    }
                    if (temp.at(i) == 'O') // checks for outs
                    {
                        n->data.setOuts(n->data.getOuts() + 1); // increments outs variable by 1
                    }
                    if (temp.at(i) == 'K') // checks for strikeouts
                    {
                        n->data.setStrikeouts(n->data.getStrikeouts() + 1); // increments strikeouts variable by 1
                    }
                    if (temp.at(i) == 'W') // checks for walks
                    {
                        n->data.setWalks(n->data.getWalks() + 1); // increments walks variable by 1
                    }
                    if (temp.at(i) == 'P') // checks for hits by pitch
                    {
                        n->data.setHitsByPitch(n->data.getHitsByPitch() + 1); // increments hitsByPitch variable by 1
                    }
                    if (temp.at(i) == 'S') // checks for sacrifices
                    {
                        n->data.setSacrifices(n->data.getSacrifices() + 1); // increments sacrifices variable by 1
                    }
                }
            }
            else // if the player is not a duplicate
            {
                // sets the variables for the player object
                for (unsigned int i = 0; i < temp.size(); i++) // loop to count stats for a player
                {
                    if (temp.at(i) == 'H') // checks for hits
                    {
                        p.setHits(p.getHits() + 1); // increments hits variable by 1
                    }
                    if (temp.at(i) == 'O') // checks for outs
                    {
                        p.setOuts(p.getOuts() + 1); // increments outs variable by 1
                    }
                    if (temp.at(i) == 'K') // checks for strikeouts
                    {
                        p.setStrikeouts(p.getStrikeouts() + 1); // increments strikeouts variable by 1
                    }
                    if (temp.at(i) == 'W') // checks for walks
                    {
                        p.setWalks(p.getWalks() + 1); // increments walks variable by 1
                    }
                    if (temp.at(i) == 'P') // checks for hits by pitch
                    {
                        p.setHitsByPitch(p.getHitsByPitch() + 1); // increments hitsByPitch variable by 1
                    }
                    if (temp.at(i) == 'S') // checks for sacrifices
                    {
                        p.setSacrifices(p.getSacrifices() + 1); // increments sacrifices variable by 1
                    }
                }
                list.insertNode(p); // inserts the node containing the player object into the linked list
            }
        }
        inFile.close(); // Closes the input file
    }
    list.sort(); // sorts list in alphabetical order
    cout << list.toString(list.getHead()) << endl << "LEAGUE LEADERS" << endl; // prints out the stats of all the players and the "LEAGUE LEADERS" header
    printLeadersBattingAverage(list); // prints the batting average leaders
    cout << endl; // goes to the next line
    printLeadersOnBasePercentage(list); // prints the on-base percentage leaders
    cout << endl; // goes to the next line
    printLeadersHits(list); // prints the hits leaders
    cout << endl; // goes to the next line
    printLeadersWalks(list); // prints the walks leaders
    cout << endl; // goes to the next line
    printLeadersStrikeouts(list); // prints the strikeouts leaders
    cout << endl; // goes to the next line
    printLeadersHitsByPitch(list); // prints the hit by pitch leaders
    cout << endl; // goes to the next line
    return 0; // signifies end of main method
}

void printLeadersBattingAverage(LinkList l) // prints batting average leaders
{
    cout << "BATTING AVERAGE" << endl;
    double lba = -1; // initializes maximum to negative one because zero can be a leader
    string lbaName1; // name of leader
    Node* n = l.getHead(); // node used to traverse list
    while (n != NULL) // checking to see if a node exists
    {
        // finding the maximum batting average
        if (n->data.getBattingAverage() > lba)
        {
            lba = n->data.getBattingAverage();
            lbaName1 = n->data.getName();
        }
        n = n->next; // going to next node
    }
    cout << fixed << setprecision(3) << lba << "\t" << lbaName1; // prints maximum batting average with three decimal accuracy and name of leader
    int count = 0; // used to count number of ties for first place
    n = l.getHead(); // resetting node to head
    while (n != NULL) // checking to see if a node exists
    {
        if (n->data.getBattingAverage() == lba && n->data.getName() != lbaName1) // checking for ties
        {
            cout << ", " << n->data.getName(); // prints tied leader
            count++; // increments count of ties
        }
        n = n->next; // going to next node
    }
    if (count >= 2) // if there are two or more players are tied with the leader
    {
        cout << endl; // goes to next line
        return; // exits method
    }
    n = l.getHead(); // resets node to head
    double lba2 = -1; // initializes second place to negative one because zero can be second place
    string lbaName2; // name of second place   
    if (count == 0 && l.getSize() > 1) // if no ties for leader and more than one player exists
    {
        int count2 = 0; // count number of ties for second place
        cout << endl; // goes to next line
        while (n != NULL) // checking to see if a node exists
        {
            // finding second place
            if (n->data.getBattingAverage() > lba2 && n->data.getBattingAverage() < lba)
            {
                lba2 = n->data.getBattingAverage();
                lbaName2 = n->data.getName();
            }
            n = n->next; // going to next node
        }
        cout << fixed << setprecision(3) << lba2 << "\t" << lbaName2; // prints second place batting average with three decimal accuracy and name
        n = l.getHead(); // resets node to head
        while (n != NULL) // checking to see if a node exists
        {
            if (n->data.getBattingAverage() == lba2 && n->data.getName() != lbaName2) // checking for ties for second place
            {
                cout << ", " << n->data.getName(); // printing tied player
                count2++; // incrementing count of second place ties
            }
            n = n->next; // going to next node
        }
        if (count2 >= 1) // if there is more than one tie for second place
        {
            cout << endl; // goes to next line
            return; // exits method
        }
        else if (count2 == 0 && l.getSize() > 2) // if no ties for second place and more than two players exist
        {
            n = l.getHead(); // resets node to head
            double lba3 = -1; // initializes third place to negative one because zero can be second place
            string lbaName3; // name of third place
            cout << endl; // goes to next line
            while (n != NULL) // checking to see if a node exists
            {
                // finding third place value
                if (n->data.getBattingAverage() > lba3 && n->data.getBattingAverage() < lba && n->data.getBattingAverage() < lba2)
                {
                    lba3 = n->data.getBattingAverage();
                    lbaName3 = n->data.getName();
                }
                n = n->next; // going to next node
            }
            cout << fixed << setprecision(3) << lba3 << "\t" << lbaName3; // prints third place batting average with three decimal accuracy and name 
            n = l.getHead();
            while (n != NULL) // checking to see if a node exists
            {
                if (n->data.getBattingAverage() == lba3 && n->data.getName() != lbaName3) // checking for ties for third place
                {
                    cout << ", " << n->data.getName(); // printing tied players' names
                }
                n = n->next; // going to next node
            }
        }
    }
    else if (count == 1) // if one tie for first place
    {
        cout << endl; // go to next line
        while (n != NULL) // checking to see if a node exists
        {
            // finding second place
            if (n->data.getBattingAverage() > lba2 && n->data.getBattingAverage() < lba)
            {
                lba2 = n->data.getBattingAverage();
                lbaName2 = n->data.getName();
            }
            n = n->next; // going to next node
        }
        cout << fixed << setprecision(3) << lba2 << "\t" << lbaName2; // prints second place batting average with three decimal accuracy and name
        n = l.getHead(); // reset node to head
        while (n != NULL) // checking to see if a node exists
        {
            if (n->data.getBattingAverage() == lba2 && n->data.getName() != lbaName2) // checking for ties for second place
            {
                cout << ", " << n->data.getName(); // printing names of players tied for second place
            }
            n = n->next; // going to next node
        }
    }
    cout << endl; // go to next line
}

void printLeadersOnBasePercentage(LinkList l) // prints on-base percentage leaders, same logic as batting average leaders (see comments in that method, process is exactly the same)
{
    cout << "ON-BASE PERCENTAGE" << endl;
    double lba = -1;
    string lbaName1;
    Node* n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getOnBasePercentage() > lba)
        {
            lba = n->data.getOnBasePercentage();
            lbaName1 = n->data.getName();
        }
        n = n->next;
    }
    cout << fixed << setprecision(3) << lba << "\t" << lbaName1;
    int count = 0;
    n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getOnBasePercentage() == lba && n->data.getName() != lbaName1)
        {
            cout << ", " << n->data.getName();
            count++;
        }
        n = n->next;
    }
    if (count >= 2)
    {
        cout << endl;
        return;
    }
    n = l.getHead();
    double lba2 = -1;
    string lbaName2;        
    if (count == 0 && l.getSize() > 1)
    {
        int count2 = 0;
        cout << endl;
        while (n != NULL)
        {
            if (n->data.getOnBasePercentage() > lba2 && n->data.getOnBasePercentage() < lba)
            {
                lba2 = n->data.getOnBasePercentage();
                lbaName2 = n->data.getName();
            }
            n = n->next;
        }
        cout << fixed << setprecision(3) << lba2 << "\t" << lbaName2;
        n = l.getHead();
        while (n != NULL)
        {
            if (n->data.getOnBasePercentage() == lba2 && n->data.getName() != lbaName2)
            {
                cout << ", " << n->data.getName();
                count2++;
            }
            n = n->next;
        }
        if (count2 >= 1)
        {
            cout << endl;
            return;
        }
        else if (count2 == 0 && l.getSize() > 2)
        {
            n = l.getHead();
            double lba3 = -1;
            string lbaName3;
            cout << endl;
            while (n != NULL)
            {
                if (n->data.getOnBasePercentage() > lba3 && n->data.getOnBasePercentage() < lba && n->data.getOnBasePercentage() < lba2)
                {
                    lba3 = n->data.getOnBasePercentage();
                    lbaName3 = n->data.getName();
                }
                n = n->next;
            }
            cout << fixed << setprecision(3) << lba3 << "\t" << lbaName3;
            n = l.getHead();
            while (n != NULL)
            {
                if (n->data.getOnBasePercentage() == lba3 && n->data.getName() != lbaName3)
                {
                    cout << ", " << n->data.getName();
                }
                n = n->next;
            }
        }
    }
    else if (count == 1)
    {
        cout << endl;
        while (n != NULL)
        {
            if (n->data.getOnBasePercentage() > lba2 && n->data.getOnBasePercentage() < lba)
            {
                lba2 = n->data.getOnBasePercentage();
                lbaName2 = n->data.getName();
            }
            n = n->next;
        }
        cout << fixed << setprecision(3) << lba2 << "\t" << lbaName2;
        n = l.getHead();
        while (n != NULL)
        {
            if (n->data.getOnBasePercentage() == lba2 && n->data.getName() != lbaName2)
            {
                cout << ", " << n->data.getName();
            }
            n = n->next;
        }
    }
    cout << endl;
}

// prints leaders for hits, same logic as batting average leaders with exception of using ints instead of doubles because hits are integer values (see comments in that method for logic)
void printLeadersHits(LinkList l) 
{
    cout << "HITS" << endl;
    int lba = -1;
    string lbaName1;
    Node* n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getHits() > lba)
        {
            lba = n->data.getHits();
            lbaName1 = n->data.getName();
        }
        n = n->next;
    }
    cout << lba << "\t" << lbaName1;
    int count = 0;
    n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getHits() == lba && n->data.getName() != lbaName1)
        {
            cout << ", " << n->data.getName();
            count++;
        }
        n = n->next;
    }
    if (count >= 2)
    {
        cout << endl;
        return;
    }
    n = l.getHead();
    int lba2 = -1;
    string lbaName2;        
    if (count == 0 && l.getSize() > 1)
    {
        int count2 = 0;
        cout << endl;
        while (n != NULL)
        {
            if (n->data.getHits() > lba2 && n->data.getHits() < lba)
            {
                lba2 = n->data.getHits();
                lbaName2 = n->data.getName();
            }
            n = n->next;
        }
        cout << lba2 << "\t" << lbaName2;
        n = l.getHead();
        while (n != NULL)
        {
            if (n->data.getHits() == lba2 && n->data.getName() != lbaName2)
            {
                cout << ", " << n->data.getName();
                count2++;
            }
            n = n->next;
        }
        if (count2 >= 1)
        {
            cout << endl;
            return;
        }
        else if (count2 == 0 && l.getSize() > 2)
        {
            n = l.getHead();
            int lba3 = -1;
            string lbaName3;
            cout << endl;
            while (n != NULL)
            {
                if (n->data.getHits() > lba3 && n->data.getHits() < lba && n->data.getHits() < lba2)
                {
                    lba3 = n->data.getHits();
                    lbaName3 = n->data.getName();
                }
                n = n->next;
            }
            cout << lba3 << "\t" << lbaName3;
            n = l.getHead();
            while (n != NULL)
            {
                if (n->data.getHits() == lba3 && n->data.getName() != lbaName3)
                {
                    cout << ", " << n->data.getName();
                }
                n = n->next;
            }
        }
    }
    else if (count == 1)
    {
        cout << endl;
        while (n != NULL)
        {
            if (n->data.getHits() > lba2 && n->data.getHits() < lba)
            {
                lba2 = n->data.getHits();
                lbaName2 = n->data.getName();
            }
            n = n->next;
        }
        cout << lba2 << "\t" << lbaName2;
        n = l.getHead();
        while (n != NULL)
        {
            if (n->data.getHits() == lba2 && n->data.getName() != lbaName2)
            {
                cout << ", " << n->data.getName();
            }
            n = n->next;
        }
    }
    cout << endl;
}

// prints leaders for walks, same logic as printing leaders for hits (see comments in that method for understanding logic)
void printLeadersWalks(LinkList l)
{
    cout << "WALKS" << endl;
    int lba = -1;
    string lbaName1;
    Node* n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getWalks() > lba)
        {
            lba = n->data.getWalks();
            lbaName1 = n->data.getName();
        }
        n = n->next;
    }
    cout << lba << "\t" << lbaName1;
    int count = 0;
    n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getWalks() == lba && n->data.getName() != lbaName1)
        {
            cout << ", " << n->data.getName();
            count++;
        }
        n = n->next;
    }
    if (count >= 2)
    {
        cout << endl;
        return;
    }
    n = l.getHead();
    int lba2 = -1;
    string lbaName2;        
    if (count == 0 && l.getSize() > 1)
    {
        int count2 = 0;
        cout << endl;
        while (n != NULL)
        {
            if (n->data.getWalks() > lba2 && n->data.getWalks() < lba)
            {
                lba2 = n->data.getWalks();
                lbaName2 = n->data.getName();
            }
            n = n->next;
        }
        cout << lba2 << "\t" << lbaName2;
        n = l.getHead();
        while (n != NULL)
        {
            if (n->data.getWalks() == lba2 && n->data.getName() != lbaName2)
            {
                cout << ", " << n->data.getName();
                count2++;
            }
            n = n->next;
        }
        if (count2 >= 1)
        {
            cout << endl;
            return;
        }
        else if (count2 == 0 && l.getSize() > 2)
        {
            n = l.getHead();
            int lba3 = -1;
            string lbaName3;
            cout << endl;
            while (n != NULL)
            {
                if (n->data.getWalks() > lba3 && n->data.getWalks() < lba && n->data.getWalks() < lba2)
                {
                    lba3 = n->data.getWalks();
                    lbaName3 = n->data.getName();
                }
                n = n->next;
            }
            cout << lba3 << "\t" << lbaName3;
            n = l.getHead();
            while (n != NULL)
            {
                if (n->data.getWalks() == lba3 && n->data.getName() != lbaName3)
                {
                    cout << ", " << n->data.getName();
                }
                n = n->next;
            }
        }
    }
    else if (count == 1)
    {
        cout << endl;
        while (n != NULL)
        {
            if (n->data.getWalks() > lba2 && n->data.getWalks() < lba)
            {
                lba2 = n->data.getWalks();
                lbaName2 = n->data.getName();
            }
            n = n->next;
        }
        cout << lba2 << "\t" << lbaName2;
        n = l.getHead();
        while (n != NULL)
        {
            if (n->data.getWalks() == lba2 && n->data.getName() != lbaName2)
            {
                cout << ", " << n->data.getName();
            }
            n = n->next;
        }
    }
    cout << endl;
}

// prints leaders for walks, same logic as printing leaders for hits except that leaders for strikeouts are players with the least amount of strikeouts (see comments in that method for understanding logic)
void printLeadersStrikeouts(LinkList l)
{
    cout << "STRIKEOUTS" << endl;
    int a = 0;
    Node* n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getStrikeouts() > a)
        {
            a = n->data.getStrikeouts();
        }
        n = n->next;
    }   
    int lba = a + 1;
    string lbaName1;
    n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getStrikeouts() < lba)
        {
            lba = n->data.getStrikeouts();
            lbaName1 = n->data.getName();
        }
        n = n->next;
    }
    cout << lba << "\t" << lbaName1;
    int count = 0;
    n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getStrikeouts() == lba && n->data.getName() != lbaName1)
        {
            cout << ", " << n->data.getName();
            count++;
        }
        n = n->next;
    }
    if (count >= 2)
    {
        cout << endl;
        return;
    }
    n = l.getHead();
    int lba2 = a + 1;
    string lbaName2;        
    if (count == 0 && l.getSize() > 1)
    {
        int count2 = 0;
        cout << endl;
        while (n != NULL)
        {
            if (n->data.getStrikeouts() < lba2 && n->data.getStrikeouts() > lba)
            {
                lba2 = n->data.getStrikeouts();
                lbaName2 = n->data.getName();
            }
            n = n->next;
        }
        cout << lba2 << "\t" << lbaName2;
        n = l.getHead();
        while (n != NULL)
        {
            if (n->data.getStrikeouts() == lba2 && n->data.getName() != lbaName2)
            {
                cout << ", " << n->data.getName();
                count2++;
            }
            n = n->next;
        }
        if (count2 >= 1)
        {
            cout << endl;
            return;
        }
        else if (count2 == 0 && l.getSize() > 2)
        {
            n = l.getHead();
            int lba3 = a + 1;
            string lbaName3;
            cout << endl;
            while (n != NULL)
            {
                if (n->data.getStrikeouts() < lba3 && n->data.getStrikeouts() > lba && n->data.getStrikeouts() > lba2)
                {
                    lba3 = n->data.getStrikeouts();
                    lbaName3 = n->data.getName();
                }
                n = n->next;
            }
            cout << lba3 << "\t" << lbaName3;
            n = l.getHead();
            while (n != NULL)
            {
                if (n->data.getStrikeouts() == lba3 && n->data.getName() != lbaName3)
                {
                    cout << ", " << n->data.getName();
                }
                n = n->next;
            }
        }
    }
    else if (count == 1)
    {
        cout << endl;
        while (n != NULL)
        {
            if (n->data.getStrikeouts() < lba2 && n->data.getStrikeouts() > lba)
            {
                lba2 = n->data.getStrikeouts();
                lbaName2 = n->data.getName();
            }
            n = n->next;
        }
        cout << lba2 << "\t" << lbaName2;
        n = l.getHead();
        while (n != NULL)
        {
            if (n->data.getStrikeouts() == lba2 && n->data.getName() != lbaName2)
            {
                cout << ", " << n->data.getName();
            }
            n = n->next;
        }
    }
    cout << endl;
}

// prints leaders for walks, same logic as printing leaders for hits (see comments in that method for understanding logic)
void printLeadersHitsByPitch(LinkList l)
{
    cout << "HIT BY PITCH" << endl;
    int lba = -1;
    string lbaName1;
    Node* n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getHitsByPitch() > lba)
        {
            lba = n->data.getHitsByPitch();
            lbaName1 = n->data.getName();
        }
        n = n->next;
    }
    cout << lba << "\t" << lbaName1;
    int count = 0;
    n = l.getHead();
    while (n != NULL)
    {
        if (n->data.getHitsByPitch() == lba && n->data.getName() != lbaName1)
        {
            cout << ", " << n->data.getName();
            count++;
        }
        n = n->next;
    }
    if (count >= 2)
    {
        cout << endl;
        return;
    }
    n = l.getHead();
    int lba2 = -1;
    string lbaName2;        
    if (count == 0 && l.getSize() > 1)
    {
        int count2 = 0;
        cout << endl;
        while (n != NULL)
        {
            if (n->data.getHitsByPitch() > lba2 && n->data.getHitsByPitch() < lba)
            {
                lba2 = n->data.getHitsByPitch();
                lbaName2 = n->data.getName();
            }
            n = n->next;
        }
        cout << lba2 << "\t" << lbaName2;
        n = l.getHead();
        while (n != NULL)
        {
            if (n->data.getHitsByPitch() == lba2 && n->data.getName() != lbaName2)
            {
                cout << ", " << n->data.getName();
                count2++;
            }
            n = n->next;
        }
        if (count2 >= 1)
        {
            cout << endl;
            return;
        }
        else if (count2 == 0 && l.getSize() > 2)
        {
            n = l.getHead();
            int lba3 = -1;
            string lbaName3;
            cout << endl;
            while (n != NULL)
            {
                if (n->data.getHitsByPitch() > lba3 && n->data.getHitsByPitch() < lba && n->data.getHitsByPitch() < lba2)
                {
                    lba3 = n->data.getHitsByPitch();
                    lbaName3 = n->data.getName();
                }
                n = n->next;
            }
            cout << lba3 << "\t" << lbaName3;
            n = l.getHead();
            while (n != NULL)
            {
                if (n->data.getHitsByPitch() == lba3 && n->data.getName() != lbaName3)
                {
                    cout << ", " << n->data.getName();
                }
                n = n->next;
            }
        }
    }
    else if (count == 1)
    {
        cout << endl;
        while (n != NULL)
        {
            if (n->data.getHitsByPitch() > lba2 && n->data.getHitsByPitch() < lba)
            {
                lba2 = n->data.getHitsByPitch();
                lbaName2 = n->data.getName();
            }
            n = n->next;
        }
        cout << lba2 << "\t" << lbaName2;
        n = l.getHead();
        while (n != NULL)
        {
            if (n->data.getHitsByPitch() == lba2 && n->data.getName() != lbaName2)
            {
                cout << ", " << n->data.getName();
            }
            n = n->next;
        }
    }
    cout << endl;
}
