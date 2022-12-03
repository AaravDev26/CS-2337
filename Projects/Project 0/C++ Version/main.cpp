// Aarav Dev
// axd220001

#include <iostream> // common import
#include <fstream> // common import
#include <string> // necessary to use strings becuase it is not a primitive
#include <cmath> // needed to perform round function for batting average and on base percentage
#include <array> // necessary to use arrays
#include <iomanip> // needed to display numbers with 3 decimal accuracy
#include <vector> // needed to store league leaders in case of a tie
using namespace std; // used to avoid using "std::" in many instances, shortens code

// prototyped method to obtain batting average given number of hits and at-bats
double getBattingAverage(double, double);

/* prototyped method to obtain on base percentage given number of hits, walks, hits by pitch, and 
plate appearances */
double getOnBasePercentage(double, double, double, double);

// prototyped method to obtain maximum value in an array
double getMax(double[], int);

// prototyped method to print the league leader(s) for a given statistic
void printLeaders(double[], int, string[]);

// prototyped method to obtain minimum value in an array
double getMin(double[], int);

/* prototyped method to print the league leader(s) for a given statistic, designed for strikouts
because the leader for strikeouts is the player with the least strikeouts */
void printLeadersMin(double[], int, string[]) ;

// main method, will perform the main task of displaying the stats and league leaders
int main() {
   int numPlayers = 0; // number of baseball players listed in the file, will be edited later
   // max number of players is 30, so arrays are initialized to size 30
   string names[30]; // array to hold all names of players
   string records[30]; // array to hold all stats of players
   double battingAverages[30]; // array to hold batting averages of each player
   double onBasePercentages[30]; // array to hold on base percetages of each player
   double numHits[30]; // array to hold number of hits for each player
   double numWalks[30]; // array to hold number of walks for each player
   double numStrikeouts[30]; // array to hold number of strikeouts for each player
   double numHitsByPitch[30]; // array to hold number of hits by pitch for each player
   
   // getting name of file from input and storing it in a string
   string filename;
   cout << "Enter the filename: ";
   cin >> filename;
   
   // opening the file
   ifstream inFile;
   inFile.open(filename);
   
   // reading the contents of the file into an array
   if (inFile.is_open())  
   {
       for (int i = 0; i < 60; i++) // iterates through file
       {
            if (i % 2 == 0)
               inFile >> names[i/2]; // storing names into array for names
            else
               inFile >> records[i/2]; // storing player records into array for records
       }
       inFile.close(); // Closes the input file
   }

   // edits the numPlayers variable initialized earlier to store the number of players listed in the file
   for (int i = 0; i < 30; i++)
   {
      if (names[i] != "") // checks to see if player exists
         numPlayers++; // increments numPlayers variable by 1
   }
   
   int index = 0; // variable initialized to keep track of where the loop is in the array
   while (names[index] != "" && index < numPlayers) // loops through each player's stats
   {
      string temp = records[index]; // temporary variable to hold a player's stats in a string
      double hits = 0; // variable to store number of hits for a player
      double outs = 0; // variable to store number of outs for a player
      double strikeouts = 0; // variable to store number of outs for a player
      double walks = 0; // variable to store number of walks for a player
      double hitByPitch = 0; // variable to store number of hits by pitch for a player
      double sacrifices = 0; // variable to store number of sacrifices for a player
      
      for (unsigned int i = 0; i < temp.size(); i++) // loop to count stats for a player
      {
         if (temp.at(i) == 'H') // checks for hits
         {
            hits += 1.0; // increments hits variable by 1
         }
         if (temp.at(i) == 'O') // checks for outs
         {
            outs += 1.0; // increments outs variable by 1
         }
         if (temp.at(i) == 'K') // checks for strikeouts
         {
            strikeouts += 1.0; // increments strikeouts variable by 1
         }
         if (temp.at(i) == 'W') // checks for walks
         {
            walks += 1.0; // increments walks variable by 1
         }
         if (temp.at(i) == 'P') // checks for hits by pitch
         {
            hitByPitch += 1.0; // increments hitByPitch variable by 1
         }
         if (temp.at(i) == 'S') // checks for sacrifices
         {
            sacrifices += 1.0; // increments sacrifices variable by 1
         }
      }
      double battingAverage = 0.0; // variable to store batting average for a player
      double onBasePercentage = 0.0; // variable to store on base percentage for a player
      double atBats = hits + outs + strikeouts; // variable to store number of at bats for a player
      double plateAps = hits + outs + strikeouts + walks + hitByPitch + sacrifices; /* variable to 
      store number of plate appearances for a player */
      
      // sets batting average to zero if player has no at bats to avoid dividing by zero error
      if (atBats == 0.0)
         battingAverage = 0.0; 
      // calculates batting average using getBattingAverage method if a player has at bats
      else
         battingAverage = getBattingAverage(hits, atBats);
         
      // sets on base percentage to 0 if a player has no plate appearances to avoid dividing by 0 error
      if (plateAps == 0.0)
         onBasePercentage = 0.0;
      // calculates on base percentage using getOnBasePercentage method
      else
         onBasePercentage = getOnBasePercentage(hits, walks, hitByPitch, plateAps);
      
      battingAverages[index] = battingAverage; // stores batting averages in the corresponding array
      onBasePercentages[index] = onBasePercentage; // stores on base percentages in an array
      numHits[index] = hits; // stores number of hits in the corresponding array
      numWalks[index] = walks; // stores number of walks in the corresponding array
      numStrikeouts[index] = strikeouts; // stores number of strikouts in the corresponding array
      numHitsByPitch[index] = hitByPitch; // // stores number of hits by pitch in the corresponding array
      cout << names[index] << endl; // prints names
      cout << "BA: " << fixed << setprecision(3) << (round(battingAverage*1000))/1000 << endl; // displays batting averages
      cout << "OB%: " << fixed << setprecision(3) << (round(onBasePercentage*1000))/1000 << endl; // displays on base percentages
      cout << "H: " << (int) hits << endl; // displays number of hits
      cout << "BB: " << (int) walks << endl; // displays number of walks
      cout << "K: " << (int) strikeouts << endl; // displays number of strikeouts
      cout << "HBP: " << (int) hitByPitch << endl; // displays number of hits by pitch
      
      // goes to the next line after each displayment of each player and the player's stats
      if (index < numPlayers)
      {
         cout << "" << endl;
      }
      index++; // increments the index variable to move on to the next player
   }
   
   cout << "LEAGUE LEADERS" << endl; // prints "LEAGUE LEADERS" and goes to the next line
   
   // displays the leader(s) for batting average and what their batting average was
   cout <<  "BA: ";
   printLeaders(battingAverages, numPlayers, names);
   cout << " " << getMax(battingAverages, numPlayers) << endl;
   
   // displays the leader(s) for on base percentage and what their on base percentage was
   cout <<  "OB%: ";
   printLeaders(onBasePercentages, numPlayers, names);
   cout << " " << getMax(onBasePercentages, numPlayers) << endl;
   
   // displays the leader(s) for hits and how many hits they had
   cout <<  "H: ";
   printLeaders(numHits, numPlayers, names);
   cout << " " << (int) getMax(numHits, numPlayers) << endl;
   
   // displays the leader(s) for walks and how many walks they had
   cout <<  "BB: ";
   printLeaders(numWalks, numPlayers, names);
   cout << " " << (int) getMax(numWalks, numPlayers) << endl;
   
   // displays the leader(s) for strikouts and how many strikeouts they had
   cout <<  "K: ";
   printLeadersMin(numStrikeouts, numPlayers, names);
   cout << " " << (int) getMin(numStrikeouts, numPlayers) << endl;
   
   // displays the leader(s) for hits by pitch and how many hits by pitch they had
   cout <<  "HBP: ";
   printLeaders(numHitsByPitch, numPlayers, names);
   cout << " " << (int) getMax(numHitsByPitch, numPlayers) << endl;
}

// method to obtain batting average given number of hits and at-bats
double getBattingAverage(double hits, double atBats)
{
   return hits/atBats; // calculates batting average and returns it
}

// method to obtain on base percentage given number of hits, walks, hits by pitch, and plate appearances
double getOnBasePercentage(double hits, double walks, double hitByPitch, double plateAps)
{
   return (hits + walks + hitByPitch)/plateAps; // calculates on base percentage and returns it
}

// method to obtain maximum value in an array
double getMax(double arr[], int size)
{
   double max = arr[0]; // sets maximum to first value in array, can be changed later in method
   for (int i = 0; i < size; i++) // iterates through array
   {
      if (arr[i] > max) // finds maximum
         max = arr[i];
   }
   return max; // returns answer
}

// method to print the league leader(s) for a given statistic
void printLeaders(double arr[], int size, string names[])
{
   vector<string> ans; // initializes string vector
   for (int i = 0; i < size; i++) // iterates through given array
   {
      if (arr[i] == getMax(arr, size)) // checks to see where the max value(s) of the array is located
         ans.push_back(names[i]); // adds string to the vector
   }
   for (unsigned int i = 0; i < ans.size(); i++) // iterates through vector
   {
      if (i != 0)
         cout << ", "; // separates contents of vector with commas
      cout << ans[i]; // prints contents of vector
   }
}

// method to obtain minimum value in an array
double getMin(double arr[], int size)
{
   double min = arr[0]; // sets minimum to first value in array, can be changed later in method
   for (int i = 0; i < size; i++) // iterates through array
   {
      if (arr[i] < min) // finds minimum
         min = arr[i];
   }
   return min; // returns answer
}

/* method to print the league leader(s) for a given statistic, designed for strikouts
because the leader for strikeouts is the player with the least strikeouts */
void printLeadersMin(double arr[], int size, string names[])
{
   vector<string> ans; // initializes string vector
   for (int i = 0; i < size; i++) // iterates through given array
   {
      if (arr[i] == getMin(arr, size)) // checks to see where the min value(s) of the array is located
         ans.push_back(names[i]);  // adds string to the vector
   }
   for (unsigned int i = 0; i < ans.size(); i++) // iterates through vector
   {
      if (i != 0)
         cout << ", "; // separates contents of vector with commas
      cout << ans[i]; // prints contents of vector
   }
}
// end of program
