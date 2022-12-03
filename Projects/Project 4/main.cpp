// Aarav Dev
// axd220001

#include <iostream> // common import, used for input and output
#include <fstream> // common import, used for file reading
#include <string> // used for file reading and other necessary uses
#include <iomanip> // needed to display numbers with 3 decimal accuracy
#include <unordered_map> // maps needed to hold data
#include <vector> // used to store names
#include <algorithm> // used for sorting vector
#include <limits.h> // used to set initial maximum to max int
#include "Player.h" // includes player class
using namespace std; // used to avoid putting "std::" in front of every statement which requries the std namespace


void printLeadersBattingAverage(unordered_map <string, Player> m, vector<string> v); // prototyped method to print the batting average leaders
void printLeadersOnBasePercentage(unordered_map <string, Player> m, vector<string> v); // prototyped method to print the on-base percentage leaders
void printLeadersHits(unordered_map <string, Player> m, vector<string> v); // prototyped method to print the hits leaders
void printLeadersWalks(unordered_map <string, Player> m, vector<string> v); // prototyped method to print the walks leaders
void printLeadersStrikeouts(unordered_map <string, Player> m, vector<string> v); // prototyped method to print the strikeouts leaders
void printLeadersHitsByPitch(unordered_map <string, Player> m, vector<string> v); // prototyped method to print the hit by pitch leaders

int main() // main method
{
    unordered_map <string, string> keys; // hash table to hold information from keyfile.txt, codes for plate appearances
    unordered_map <string, Player> players; // hash table to hold players with their name as the key
    
    vector<string> names; // vector to hold players' names
    vector<string> away; // vector to hold away players' names
    vector<string> home; // vector to hold home players' names
    
    // getting name of file from input and storing it in a string
    string filename;
    cout << "Enter the filename: " << endl;
    cin >> filename;
    
    // reading keyfile.txt and updating key hash table
    ifstream inFile;
    inFile.open("keyfile.txt"); // opening file
    if (inFile.is_open())
    {
        string temp;
        getline(inFile, temp);
        // setting codes for outs
        for (int i = 0; i < 21; i++)
        {
            string a;
            inFile >> a;
            keys[a] = "OUTS";
        }
        // skipping lines
        for (int i = 0; i < 6; i++)
        {
            getline(inFile, temp);
        }
        keys["K"] = "STRIKEOUT"; // setting code for strikeouts
        // setting codes for hits
        for (int i = 0; i < 4; i++)
        {
            string b;
            inFile >> b;
            keys[b] = "HITS";
        }
        // skipping lines
        for (int i = 0; i < 6; i++)
        {
            getline(inFile, temp);
        }
        keys["BB"] = "WALK"; // setting code for walks
        // setting codes for sacifices
        for (int i = 0; i < 7; i++)
        {
            string p;
            inFile >> p;
            keys[p] = "SACRIFICE";
        }
        // skipping lines
        for (int i = 0; i < 6; i++)
        {
            getline(inFile, temp);
        }
        keys["HBP"] = "HIT BY PITCH"; // setting code for hits by pitch
        // setting code for errors
        for (int i = 0; i < 9; i++)
        {
            string n;
            inFile >> n;
            keys[n] = "ERRORS";
        }
        inFile.close(); // Closes keyfile.txt
    }
    
    // counting the number of lines in the file
    int num = 0; // number of lines in the file
    string line;
    ifstream count(filename);
    while (getline(count, line)) 
    {
        ++num; // increments variable
    }
    
    ifstream myfile;
    myfile.open(filename); // opening input file
    if (myfile.is_open())
    {
        for (int i = 0; i < num; i++) // iterates through each line of file
        {
            string team; // string to hold team of player (home or away)
            string name; // string to hold name of player
            string code; // string to hold code of plate appearance
            // getting team, name, and code from input and updating variables
            myfile >> team;
            myfile >> name;
            myfile >> code;
            Player p; // initializing player object
            p.setTeam(team); // setting team of player
            p.setName(name); // setting name of player
            if (players.find(name) != players.end()) // if duplicate player
            {
                if (keys[code] == "HITS") // checks for hits
                {
                    Player pl = players[name]; // getting player to change their stats
                    pl.setHits(pl.getHits() + 1); // increments hits variable by 1
                    players[name] = pl; // updating hash table
                }
                if (keys[code] == "OUTS") // checks for outs
                {
                    Player pl = players[name]; // getting player to change their stats
                    pl.setOuts(pl.getOuts() + 1); // increments hits variable by 1
                    players[name] = pl; // updating hash table
                }
                if (keys[code] == "STRIKEOUT") // checks for strikeouts
                {
                    Player pl = players[name]; // getting player to change their stats
                    pl.setStrikeouts(pl.getStrikeouts() + 1); // increments hits variable by 1
                    players[name] = pl; // updating hash table
                }
                if (keys[code] == "WALK") // checks for walks
                {
                    Player pl = players[name]; // getting player to change their stats
                    pl.setWalks(pl.getWalks() + 1); // increments hits variable by 1
                    players[name] = pl; // updating hash table
                }
                if (keys[code] == "HIT BY PITCH") // checks for hits by pitch
                {
                    Player pl = players[name]; // getting player to change their stats
                    pl.setHitsByPitch(pl.getHitsByPitch() + 1); // increments hits variable by 1
                    players[name] = pl; // updating hash table
                }
                if (keys[code] == "SACRIFICE") // checks for sacrifices
                {
                    Player pl = players[name]; // getting player to change their stats
                    pl.setSacrifices(pl.getSacrifices() + 1); // increments hits variable by 1
                    players[name] = pl; // updating hash table
                }
                if (keys[code] == "ERRORS") // checks for errors
                {
                    Player pl = players[name]; // getting player to change their stats
                    pl.setErrors(pl.getErrors() + 1); // increments hits variable by 1
                    players[name] = pl; // updating hash table
                }
            }
            else
            {
                // adding names to vector based on appropriate team if not duplicate
                names.push_back(name); // adding to vector
                if (team == "A") // checking team
                {
                    away.push_back(name); // adding to vector
                }
                else
                {
                    home.push_back(name); // adding to vector
                }
                if (keys[code] == "HITS") // checks for hits
                {
                    p.setHits(p.getHits() + 1); // increments hits variable by 1
                }
                if (keys[code] == "OUTS") // checks for outs
                {
                    p.setOuts(p.getOuts() + 1); // increments outs variable by 1
                }
                if (keys[code] == "STRIKEOUT") // checks for strikeouts
                {
                    p.setStrikeouts(p.getStrikeouts() + 1); // increments strikeouts variable by 1
                }
                if (keys[code] == "WALK") // checks for walks
                {
                    p.setWalks(p.getWalks() + 1); // increments walks variable by 1
                }
                if (keys[code] == "HIT BY PITCH") // checks for hits by pitch
                {
                    p.setHitsByPitch(p.getHitsByPitch() + 1); // increments hitsByPitch variable by 1
                }
                if (keys[code] == "SACRIFICE") // checks for sacrifices
                {
                    p.setSacrifices(p.getSacrifices() + 1); // increments sacrifices variable by 1
                }
                if (keys[code] == "ERRORS") // checks for errors
                {
                    p.setErrors(p.getErrors() + 1); // increments errors variable by 1
                }
                players[name] = p; // updating hash table
            }
        }
        myfile.close(); // closes the input file
    }
    // sorting vectors in alphabetical order
    sort(names.begin(), names.end());
    sort(away.begin(), away.end());
    sort(home.begin(), home.end());
    // printing stats of players, first away then home players
    cout << "AWAY" << endl;
    for (unsigned int i = 0; i < away.size(); i++) // looping through away players
    {
        cout << players[away[i]].toString(); // printing player
    }
    cout << endl << "HOME" << endl;
    for (unsigned int i = 0; i < home.size(); i++) // looping through home players
    {
        cout << players[home[i]].toString(); // printing player
    }
    cout << endl << "LEAGUE LEADERS" << endl;
    printLeadersBattingAverage(players, names); // prints the batting average leaders
    cout << endl; // going to next line
    printLeadersOnBasePercentage(players, names); // prints the on-base percentage leaders
    cout << endl; // going to next line
    printLeadersHits(players, names); // prints the hits leaders
    cout << endl; // going to next line
    printLeadersWalks(players, names); // prints the walks leaders
    cout << endl; // going to next line
    printLeadersStrikeouts(players, names); // prints the strikeouts leaders
    cout << endl; // going to next line
    printLeadersHitsByPitch(players, names); // prints the hit by pitch leaders
    return 0; // signifies end of main method
}

void printLeadersBattingAverage(unordered_map <string, Player> m, vector<string> v) // method to print the batting average leaders
{
    cout << "BATTING AVERAGE" << endl;
    int count = 1; // number of players tied with each other for first place
    double max = -1; // initializes maximum to negative one because zero can be a leader
    string leader; // name of leader
    vector<string> ties; // vector to hold all first place players
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding leader
        if (m[v[i]].getBattingAverage() > max)
        {
            max = m[v[i]].getBattingAverage();
            leader = v[i];
        }
    }
    ties.push_back(leader); // adding leader to vector
    cout << fixed << setprecision(3) << max << "\t"; // printing max value
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding ties
        if (m[v[i]].getName() != leader && m[v[i]].getBattingAverage() == max)
        {
            ties.push_back(v[i]);
            count++;
        }
    }
    string leds; // string to hold leader list
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding away players
        if (m[ties[i]].getTeam() == "A")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding home players
        if (m[ties[i]].getTeam() == "H")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    cout << leds.substr(0, leds.length() - 2) << endl; // printing leader list, ommiting trailing comma and space
    if (count >= 3)
    {
        return; // exit function if 3 or more players tied
    }
    else if (count == 1)
    {
        int count2 = 1; // number of players tied with each other for second place
        double max2 = -1; // initializes maximum to negative one because zero can be a leader
        string leader2; // name of leader for second place
        vector<string> ties2; // vector to hold all second place players
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getBattingAverage() > max2 && m[v[i]].getBattingAverage() < max)
            {
                max2 = m[v[i]].getBattingAverage();
                leader2 = v[i];
            }
        }
        ties2.push_back(leader2); // add leader to vector
        cout << fixed << setprecision(3) << max2 << "\t"; // print second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader2 && m[v[i]].getBattingAverage() == max2)
            {
                ties2.push_back(v[i]);
                count2++;
            }
        }
        string leds2; // adding leader to vector
        // printing away players first and then home players
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "A") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "H") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        cout << leds2.substr(0, leds2.length() - 2) << endl; // printing leader list
        if (count2 >= 2)
        {
            return; // exits function if two or more players tied for second
        }
        else
        {
            double max3 = -1; // initializes maximum to negative one because zero can be a leader
            string leader3; // name of leader
            vector<string> ties3; // vector to hold leaders
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding third place
                if (m[v[i]].getBattingAverage() > max3 && m[v[i]].getBattingAverage() < max && m[v[i]].getBattingAverage() < max2)
                {
                    max3 = m[v[i]].getBattingAverage();
                    leader3 = v[i];
                }
            }
            ties3.push_back(leader3); // add leader to vector
            cout << fixed << setprecision(3) << max3 << "\t"; // print third place value
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding ties
                if (m[v[i]].getName() != leader3 && m[v[i]].getBattingAverage() == max3)
                {
                    ties3.push_back(v[i]); // add to vector
                }
            }
            string leds3; // string to hold leader list
            // printing away players first, then home players
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "A") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "H") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
            return; // exits function
        }
    }
    else if (count == 2) // if two players tied for first
    {
        double max3 = -1; // initializes maximum to negative one because zero can be a leader
        string leader3; // name of leader
        vector<string> ties3; // vector to hold leaders
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getBattingAverage() > max3 && m[v[i]].getBattingAverage() < max)
            {
                max3 = m[v[i]].getBattingAverage();
                leader3 = v[i];
            }
        }
        ties3.push_back(leader3); // add leader to vector
        cout << fixed << setprecision(3) << max3 << "\t"; // printing second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader3 && m[v[i]].getBattingAverage() == max3)
            {
                ties3.push_back(v[i]); // add leader to vector
            }
        }
        string leds3;
        // printing away players first, then home players
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "A") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "H") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
    }
}

void printLeadersOnBasePercentage(unordered_map <string, Player> m, vector<string> v) // method to print the on-base percentage leaders
{
    cout << "ON-BASE PERCENTAGE" << endl;
        int count = 1; // number of players tied with each other for first place
    double max = -1; // initializes maximum to negative one because zero can be a leader
    string leader; // name of leader
    vector<string> ties; // vector to hold all first place players
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding leader
        if (m[v[i]].getOnBasePercentage() > max)
        {
            max = m[v[i]].getOnBasePercentage();
            leader = v[i];
        }
    }
    ties.push_back(leader); // adding leader to vector
    cout << fixed << setprecision(3) << max << "\t"; // printing max value
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding ties
        if (m[v[i]].getName() != leader && m[v[i]].getOnBasePercentage() == max)
        {
            ties.push_back(v[i]);
            count++;
        }
    }
    string leds; // string to hold leader list
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding away players
        if (m[ties[i]].getTeam() == "A")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding home players
        if (m[ties[i]].getTeam() == "H")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    cout << leds.substr(0, leds.length() - 2) << endl; // printing leader list, ommiting trailing comma and space
    if (count >= 3)
    {
        return; // exit function if 3 or more players tied
    }
    else if (count == 1)
    {
        int count2 = 1; // number of players tied with each other for second place
        double max2 = -1; // initializes maximum to negative one because zero can be a leader
        string leader2; // name of leader for second place
        vector<string> ties2; // vector to hold all second place players
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getOnBasePercentage() > max2 && m[v[i]].getOnBasePercentage() < max)
            {
                max2 = m[v[i]].getOnBasePercentage();
                leader2 = v[i];
            }
        }
        ties2.push_back(leader2); // add leader to vector
        cout << fixed << setprecision(3) << max2 << "\t"; // print second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader2 && m[v[i]].getOnBasePercentage() == max2)
            {
                ties2.push_back(v[i]);
                count2++;
            }
        }
        string leds2; // adding leader to vector
        // printing away players first and then home players
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "A") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "H") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        cout << leds2.substr(0, leds2.length() - 2) << endl; // printing leader list
        if (count2 >= 2)
        {
            return; // exits function if two or more players tied for second
        }
        else
        {
            double max3 = -1; // initializes maximum to negative one because zero can be a leader
            string leader3; // name of leader
            vector<string> ties3; // vector to hold leaders
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding third place
                if (m[v[i]].getOnBasePercentage() > max3 && m[v[i]].getOnBasePercentage() < max && m[v[i]].getOnBasePercentage() < max2)
                {
                    max3 = m[v[i]].getOnBasePercentage();
                    leader3 = v[i];
                }
            }
            ties3.push_back(leader3); // add leader to vector
            cout << fixed << setprecision(3) << max3 << "\t"; // print third place value
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding ties
                if (m[v[i]].getName() != leader3 && m[v[i]].getOnBasePercentage() == max3)
                {
                    ties3.push_back(v[i]); // add to vector
                }
            }
            string leds3; // string to hold leader list
            // printing away players first, then home players
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "A") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "H") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
            return; // exits function
        }
    }
    else if (count == 2) // if two players tied for first
    {
        double max3 = -1; // initializes maximum to negative one because zero can be a leader
        string leader3; // name of leader
        vector<string> ties3; // vector to hold leaders
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getOnBasePercentage() > max3 && m[v[i]].getOnBasePercentage() < max)
            {
                max3 = m[v[i]].getOnBasePercentage();
                leader3 = v[i];
            }
        }
        ties3.push_back(leader3); // add leader to vector
        cout << fixed << setprecision(3) << max3 << "\t"; // printing second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader3 && m[v[i]].getOnBasePercentage() == max3)
            {
                ties3.push_back(v[i]); // add leader to vector
            }
        }
        string leds3;
        // printing away players first, then home players
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "A") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "H") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
    }
}

void printLeadersHits(unordered_map <string, Player> m, vector<string> v) // method to print the hits leaders
{
    cout << "HITS" << endl;
    int count = 1; // number of players tied with each other for first place
    int max = -1; // initializes maximum to negative one because zero can be a leader
    string leader; // name of leader
    vector<string> ties; // vector to hold all first place players
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding leader
        if (m[v[i]].getHits() > max)
        {
            max = m[v[i]].getHits();
            leader = v[i];
        }
    }
    ties.push_back(leader); // adding leader to vector
    cout  << max << "\t"; // printing max value
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding ties
        if (m[v[i]].getName() != leader && m[v[i]].getHits() == max)
        {
            ties.push_back(v[i]);
            count++;
        }
    }
    string leds; // string to hold leader list
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding away players
        if (m[ties[i]].getTeam() == "A")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding home players
        if (m[ties[i]].getTeam() == "H")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    cout << leds.substr(0, leds.length() - 2) << endl; // printing leader list, ommiting trailing comma and space
    if (count >= 3)
    {
        return; // exit function if 3 or more players tied
    }
    else if (count == 1)
    {
        int count2 = 1; // number of players tied with each other for second place
        int max2 = -1; // initializes maximum to negative one because zero can be a leader
        string leader2; // name of leader for second place
        vector<string> ties2; // vector to hold all second place players
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getHits() > max2 && m[v[i]].getHits() < max)
            {
                max2 = m[v[i]].getHits();
                leader2 = v[i];
            }
        }
        ties2.push_back(leader2); // add leader to vector
        cout  << max2 << "\t"; // print second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader2 && m[v[i]].getHits() == max2)
            {
                ties2.push_back(v[i]);
                count2++;
            }
        }
        string leds2; // adding leader to vector
        // printing away players first and then home players
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "A") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "H") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        cout << leds2.substr(0, leds2.length() - 2) << endl; // printing leader list
        if (count2 >= 2)
        {
            return; // exits function if two or more players tied for second
        }
        else
        {
            int max3 = -1; // initializes maximum to negative one because zero can be a leader
            string leader3; // name of leader
            vector<string> ties3; // vector to hold leaders
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding third place
                if (m[v[i]].getHits() > max3 && m[v[i]].getHits() < max && m[v[i]].getHits() < max2)
                {
                    max3 = m[v[i]].getHits();
                    leader3 = v[i];
                }
            }
            ties3.push_back(leader3); // add leader to vector
            cout  << max3 << "\t"; // print third place value
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding ties
                if (m[v[i]].getName() != leader3 && m[v[i]].getHits() == max3)
                {
                    ties3.push_back(v[i]); // add to vector
                }
            }
            string leds3; // string to hold leader list
            // printing away players first, then home players
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "A") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "H") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
            return; // exits function
        }
    }
    else if (count == 2) // if two players tied for first
    {
        int max3 = -1; // initializes maximum to negative one because zero can be a leader
        string leader3; // name of leader
        vector<string> ties3; // vector to hold leaders
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getHits() > max3 && m[v[i]].getHits() < max)
            {
                max3 = m[v[i]].getHits();
                leader3 = v[i];
            }
        }
        ties3.push_back(leader3); // add leader to vector
        cout  << max3 << "\t"; // printing second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader3 && m[v[i]].getHits() == max3)
            {
                ties3.push_back(v[i]); // add leader to vector
            }
        }
        string leds3;
        // printing away players first, then home players
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "A") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "H") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
    }
    cout << endl;
}

void printLeadersWalks(unordered_map <string, Player> m, vector<string> v) // method to print the walks leaders
{
    cout << "WALKS" << endl;
    int count = 1; // number of players tied with each other for first place
    int max = -1; // initializes maximum to negative one because zero can be a leader
    string leader; // name of leader
    vector<string> ties; // vector to hold all first place players
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding leader
        if (m[v[i]].getWalks() > max)
        {
            max = m[v[i]].getWalks();
            leader = v[i];
        }
    }
    ties.push_back(leader); // adding leader to vector
    cout  << max << "\t"; // printing max value
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding ties
        if (m[v[i]].getName() != leader && m[v[i]].getWalks() == max)
        {
            ties.push_back(v[i]);
            count++;
        }
    }
    string leds; // string to hold leader list
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding away players
        if (m[ties[i]].getTeam() == "A")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding home players
        if (m[ties[i]].getTeam() == "H")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    cout << leds.substr(0, leds.length() - 2) << endl; // printing leader list, ommiting trailing comma and space
    if (count >= 3)
    {
        return; // exit function if 3 or more players tied
    }
    else if (count == 1)
    {
        int count2 = 1; // number of players tied with each other for second place
        int max2 = -1; // initializes maximum to negative one because zero can be a leader
        string leader2; // name of leader for second place
        vector<string> ties2; // vector to hold all second place players
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getWalks() > max2 && m[v[i]].getWalks() < max)
            {
                max2 = m[v[i]].getWalks();
                leader2 = v[i];
            }
        }
        ties2.push_back(leader2); // add leader to vector
        cout  << max2 << "\t"; // print second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader2 && m[v[i]].getWalks() == max2)
            {
                ties2.push_back(v[i]);
                count2++;
            }
        }
        string leds2; // adding leader to vector
        // printing away players first and then home players
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "A") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "H") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        cout << leds2.substr(0, leds2.length() - 2) << endl; // printing leader list
        if (count2 >= 2)
        {
            return; // exits function if two or more players tied for second
        }
        else
        {
            int max3 = -1; // initializes maximum to negative one because zero can be a leader
            string leader3; // name of leader
            vector<string> ties3; // vector to hold leaders
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding third place
                if (m[v[i]].getWalks() > max3 && m[v[i]].getWalks() < max && m[v[i]].getWalks() < max2)
                {
                    max3 = m[v[i]].getWalks();
                    leader3 = v[i];
                }
            }
            ties3.push_back(leader3); // add leader to vector
            cout  << max3 << "\t"; // print third place value
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding ties
                if (m[v[i]].getName() != leader3 && m[v[i]].getWalks() == max3)
                {
                    ties3.push_back(v[i]); // add to vector
                }
            }
            string leds3; // string to hold leader list
            // printing away players first, then home players
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "A") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "H") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
            return; // exits function
        }
    }
    else if (count == 2) // if two players tied for first
    {
        int max3 = -1; // initializes maximum to negative one because zero can be a leader
        string leader3; // name of leader
        vector<string> ties3; // vector to hold leaders
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getWalks() > max3 && m[v[i]].getWalks() < max)
            {
                max3 = m[v[i]].getWalks();
                leader3 = v[i];
            }
        }
        ties3.push_back(leader3); // add leader to vector
        cout  << max3 << "\t"; // printing second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader3 && m[v[i]].getWalks() == max3)
            {
                ties3.push_back(v[i]); // add leader to vector
            }
        }
        string leds3;
        // printing away players first, then home players
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "A") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "H") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
    }
}

void printLeadersStrikeouts(unordered_map <string, Player> m, vector<string> v) // method to print the strikeouts leaders
{
    cout << "STRIKEOUTS" << endl;
    int count = 1; // number of players tied with each other for first place
    int max = INT_MAX; // initializes minimum to max int
    string leader; // name of leader
    vector<string> ties; // vector to hold all first place players
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding leader
        if (m[v[i]].getStrikeouts() < max)
        {
            max = m[v[i]].getStrikeouts();
            leader = v[i];
        }
    }
    ties.push_back(leader); // adding leader to vector
    cout  << max << "\t"; // printing max value
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding ties
        if (m[v[i]].getName() != leader && m[v[i]].getStrikeouts() == max)
        {
            ties.push_back(v[i]);
            count++;
        }
    }
    string leds; // string to hold leader list
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding away players
        if (m[ties[i]].getTeam() == "A")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding home players
        if (m[ties[i]].getTeam() == "H")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    cout << leds.substr(0, leds.length() - 2) << endl; // printing leader list, ommiting trailing comma and space
    if (count >= 3)
    {
        return; // exit function if 3 or more players tied
    }
    else if (count == 1)
    {
        int count2 = 1; // number of players tied with each other for second place
        int max2 = INT_MAX; // initializes minimum to max int
        string leader2; // name of leader for second place
        vector<string> ties2; // vector to hold all second place players
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getStrikeouts() < max2 && m[v[i]].getStrikeouts() > max)
            {
                max2 = m[v[i]].getStrikeouts();
                leader2 = v[i];
            }
        }
        ties2.push_back(leader2); // add leader to vector
        cout  << max2 << "\t"; // print second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader2 && m[v[i]].getStrikeouts() == max2)
            {
                ties2.push_back(v[i]);
                count2++;
            }
        }
        string leds2; // adding leader to vector
        // printing away players first and then home players
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "A") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "H") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        cout << leds2.substr(0, leds2.length() - 2) << endl; // printing leader list
        if (count2 >= 2)
        {
            return; // exits function if two or more players tied for second
        }
        else
        {
            int max3 = INT_MAX; // initializes minimum to max int
            string leader3; // name of leader
            vector<string> ties3; // vector to hold leaders
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding third place
                if (m[v[i]].getStrikeouts() < max3 && m[v[i]].getStrikeouts() > max && m[v[i]].getStrikeouts() > max2)
                {
                    max3 = m[v[i]].getStrikeouts();
                    leader3 = v[i];
                }
            }
            ties3.push_back(leader3); // add leader to vector
            cout  << max3 << "\t"; // print third place value
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding ties
                if (m[v[i]].getName() != leader3 && m[v[i]].getStrikeouts() == max3)
                {
                    ties3.push_back(v[i]); // add to vector
                }
            }
            string leds3; // string to hold leader list
            // printing away players first, then home players
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "A") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "H") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
            return; // exits function
        }
    }
    else if (count == 2) // if two players tied for first
    {
        int max3 = INT_MAX; // initializes minimum to max int
        string leader3; // name of leader
        vector<string> ties3; // vector to hold leaders
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getStrikeouts() < max3 && m[v[i]].getStrikeouts() > max)
            {
                max3 = m[v[i]].getStrikeouts();
                leader3 = v[i];
            }
        }
        ties3.push_back(leader3); // add leader to vector
        cout  << max3 << "\t"; // printing second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader3 && m[v[i]].getStrikeouts() == max3)
            {
                ties3.push_back(v[i]); // add leader to vector
            }
        }
        string leds3;
        // printing away players first, then home players
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "A") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "H") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
    }
}

void printLeadersHitsByPitch(unordered_map <string, Player> m, vector<string> v) // method to print the hit by pitch leaders
{
    cout << "HIT BY PITCH" << endl;
    int count = 1; // number of players tied with each other for first place
    int max = -1; // initializes maximum to negative one because zero can be a leader
    string leader; // name of leader
    vector<string> ties; // vector to hold all first place players
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding leader
        if (m[v[i]].getHitsByPitch() > max)
        {
            max = m[v[i]].getHitsByPitch();
            leader = v[i];
        }
    }
    ties.push_back(leader); // adding leader to vector
    cout  << max << "\t"; // printing max value
    for (unsigned int i= 0; i < v.size(); i++) // looping through players
    {
        // finding ties
        if (m[v[i]].getName() != leader && m[v[i]].getHitsByPitch() == max)
        {
            ties.push_back(v[i]);
            count++;
        }
    }
    string leds; // string to hold leader list
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding away players
        if (m[ties[i]].getTeam() == "A")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    for (unsigned int i= 0; i < ties.size(); i++) // looping through leaders
    {
        // finding home players
        if (m[ties[i]].getTeam() == "H")
        {
            leds += ties[i] + ", "; // adding to leader list
        }
    }
    cout << leds.substr(0, leds.length() - 2) << endl; // printing leader list, ommiting trailing comma and space
    if (count >= 3)
    {
        return; // exit function if 3 or more players tied
    }
    else if (count == 1)
    {
        int count2 = 1; // number of players tied with each other for second place
        int max2 = -1; // initializes maximum to negative one because zero can be a leader
        string leader2; // name of leader for second place
        vector<string> ties2; // vector to hold all second place players
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getHitsByPitch() > max2 && m[v[i]].getHitsByPitch() < max)
            {
                max2 = m[v[i]].getHitsByPitch();
                leader2 = v[i];
            }
        }
        ties2.push_back(leader2); // add leader to vector
        cout  << max2 << "\t"; // print second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader2 && m[v[i]].getHitsByPitch() == max2)
            {
                ties2.push_back(v[i]);
                count2++;
            }
        }
        string leds2; // adding leader to vector
        // printing away players first and then home players
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "A") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        for (unsigned int i= 0; i < ties2.size(); i++) // looping through leaders
        {
            if (m[ties2[i]].getTeam() == "H") // checking team
            {
                leds2 += ties2[i] + ", "; // add to leader list
            }
        }
        cout << leds2.substr(0, leds2.length() - 2) << endl; // printing leader list
        if (count2 >= 2)
        {
            return; // exits function if two or more players tied for second
        }
        else
        {
            int max3 = -1; // initializes maximum to negative one because zero can be a leader
            string leader3; // name of leader
            vector<string> ties3; // vector to hold leaders
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding third place
                if (m[v[i]].getHitsByPitch() > max3 && m[v[i]].getHitsByPitch() < max && m[v[i]].getHitsByPitch() < max2)
                {
                    max3 = m[v[i]].getHitsByPitch();
                    leader3 = v[i];
                }
            }
            ties3.push_back(leader3); // add leader to vector
            cout  << max3 << "\t"; // print third place value
            for (unsigned int i= 0; i < v.size(); i++) // looping through players
            {
                // finding ties
                if (m[v[i]].getName() != leader3 && m[v[i]].getHitsByPitch() == max3)
                {
                    ties3.push_back(v[i]); // add to vector
                }
            }
            string leds3; // string to hold leader list
            // printing away players first, then home players
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "A") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            for (unsigned int i= 0; i < ties3.size(); i++) // looping through leaders
            {
                if (m[ties3[i]].getTeam() == "H") // checking team
                {
                    leds3 += ties3[i] + ", "; // adding to leader list
                }
            }
            cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
            return; // exits function
        }
    }
    else if (count == 2) // if two players tied for first
    {
        int max3 = -1; // initializes maximum to negative one because zero can be a leader
        string leader3; // name of leader
        vector<string> ties3; // vector to hold leaders
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding second place
            if (m[v[i]].getHitsByPitch() > max3 && m[v[i]].getHitsByPitch() < max)
            {
                max3 = m[v[i]].getHitsByPitch();
                leader3 = v[i];
            }
        }
        ties3.push_back(leader3); // add leader to vector
        cout  << max3 << "\t"; // printing second place value
        for (unsigned int i= 0; i < v.size(); i++) // looping through players
        {
            // finding ties
            if (m[v[i]].getName() != leader3 && m[v[i]].getHitsByPitch() == max3)
            {
                ties3.push_back(v[i]); // add leader to vector
            }
        }
        string leds3;
        // printing away players first, then home players
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "A") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        for (unsigned int i= 0; i < ties3.size(); i++)
        {
            if (m[ties3[i]].getTeam() == "H") // checking team
            {
                leds3 += ties3[i] + ", "; // adding to leader list
            }
        }
        cout << leds3.substr(0, leds3.length() - 2) << endl; // prints leader list
    }
}
