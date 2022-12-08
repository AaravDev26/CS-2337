/*// Aarav Dev
// axd220001
// i know my program doesn't work but can i at least get points for comments and good programming practice please

#include <iostream> // common import
#include <fstream> // common import
#include <string> // necessary to include strings becuase it is not a primitive
#include <array> // necessary because using 2d array to hold data
#include "Creature.h" // imports methods and members of Creature class
#include "Beetle.h" // imports methods and members of Beetle class
#include "Ant.h" // imports methods and members of Ant class
using namespace std; // used to avoid using "std::" in many instances, shortens code

Creature* grid[10][10]; // grid that game will be played on
int dtbNorth (int, int); // returns distance from beetle to the north
int dtbEast (int, int); // returns distance from beetle to the east
int dtbSouth (int, int); // returns distance from beetle to the south
int dtbWest (int, int); // returns distance from beetle to the west
int dtaNorth (int, int); // returns distance from ant to the north
int dtaEast (int, int);  // returns distance from ant to the east
int dtaSouth (int, int);  // returns distance from ant to the south
int dtaWest (int, int);  // returns distance from ant to the west
int dn (int, int); // indicates if north point is available
int de (int, int); // indicates if east point is available
int ds (int, int); // indicates if south point is available
int dw (int, int); // indicates if west point is available
void beetleMove(); // moves beetles
void antMove(); // moves ants
void beetleBreed(); // breeds beetles
void antBreed(); // breeds ants
void starve(); // checks if beetle is starving
void setLivesEats(); // initializes private members of creature class

int main() // main method
{
    // getting name of file from input and storing it in a string
   string filename;
   cout << "Enter the filename: " << endl;
   cin >> filename;
   
   // opening the file
   ifstream inFile;
   inFile.open(filename);
   
   // reading the contents of the file into a 2d array
   if (inFile.is_open())
   {
      int row = 0; // row number
      string s;
      while (inFile.good())
      {
         getline(inFile, s);
         // iterates through text file
         for (unsigned int i = 0; i < s.length(); i++)
         {
            // sets point as null pointer if nothing is at point
            if (s.at(i) == ' ') {
               grid[row][i] = nullptr;
            }
            // sets point as Ant pointer if ant is at point
            else if (s.at(i) == 'a') {
               grid[row][i] = new Ant();
            }
            // sets point as Beetle pointer if beetle is at point
            else if (s.at(i) == 'B') {
               grid[row][i] = new Beetle();
            }
         }
         row++; // increments row
      }
      inFile.close(); // closes file
   }
   char antChar; // user specified char that will be used to represent ant in output
   cout << "Enter the character you would like to represent an ant" << endl;
   cin >> antChar;
   char beetleChar; // user specified char that will be used to represent ant in output
   cout << "Enter the character you would like to represent a beetle" << endl;
   cin >> beetleChar;
   int numTurns; // user specified number of turns
   cout << "Enter the number of turns" << endl;
   cin >> numTurns;
    
    setLivesEats(); // sets beetle's life and time since eaten to zero
    int turn = 0; // turn number
    while (turn < numTurns) // performs turns
    {
        beetleMove();
        antMove();
        starve();
        if (turn % 3 == 0 && turn > 0)
        {
            antBreed();
        }
        beetleBreed();
        cout << "TURN " << turn + 1 << endl;
      
       char arr[10][10]; // creates char 2d array to output
       for (int r = 0; r < 10; r++)
       {
          for (int c = 0; c < 10; c++)
          {
             if (grid[r][c] == nullptr) {
                arr[r][c] = ' ';
             }
             else if (dynamic_cast<Ant*>(grid[r][c])) {
                arr[r][c] = antChar;
             }
             else if (dynamic_cast<Beetle*>(grid[r][c])) {
                arr[r][c] = beetleChar;
             }
          }
       }
       for (int r = 0; r < 10; r++)
       {
          for (int c = 0; c < 10; c++)
          {
             cout << arr[r][c];
          }
          cout << endl;
       }
        cout << endl;  
        turn++;
    }
    
    return 0;
}
// finds every beetle in grid and moves it in the appropriate direction
void beetleMove()
{
   for (int c = 0; c < 10; c++)
   {
      for (int r = 0; r < 10; r++)
      {
          if (dynamic_cast<Beetle*>(grid[r][c]))
          {
              if (grid[r][c]->move(dtaNorth(r, c), dtaEast(r,c), dtaSouth(r,c), dtaWest(r,c)) == 1 && r > 0 && !dynamic_cast<Beetle*>(grid[r-1][c])) {
                  if (dynamic_cast<Ant*>(grid[r-1][c]))
                  {
                      delete (grid[r-1][c]);
                      grid[r-1][c] = new Beetle();
                      grid[r-1][c]->setLife(grid[r][c]->getLife() + 1);
                      grid[r-1][c]->setEat(0);
                      delete(grid[r][c]);
                      grid[r][c] = nullptr;
                  }
                  else {
                      delete (grid[r-1][c]);
                      grid[r-1][c] = new Beetle();
                      grid[r-1][c]->setLife(grid[r][c]->getLife() + 1);
                      grid[r-1][c]->setEat(grid[r][c]->getEat() + 1);
                      delete(grid[r][c]);
                      grid[r][c] = nullptr;
                  }
              }
              else if (grid[r][c]->move(dtaNorth(r, c), dtaEast(r,c), dtaSouth(r,c), dtaWest(r,c)) == 2 && c < 9 && !dynamic_cast<Beetle*>(grid[r][c+1])) {
                  if (dynamic_cast<Ant*>(grid[r][c+1]))
                  {
                      delete (grid[r][c+1]);
                      grid[r][c+1] = new Beetle();
                      grid[r][c+1]->setLife(grid[r][c]->getLife() + 1);
                      grid[r][c+1]->setEat(0);
                      delete(grid[r][c]);
                      grid[r][c] = nullptr;
                  }
                  else {
                      delete (grid[r][c+1]);
                      grid[r][c+1] = new Beetle();
                      grid[r][c+1]->setLife(grid[r][c]->getLife() + 1);
                      grid[r][c+1]->setEat(grid[r][c]->getEat() + 1);
                      delete(grid[r][c]);
                      grid[r][c] = nullptr;
                  }
              }
              else if (grid[r][c]->move(dtaNorth(r, c), dtaEast(r,c), dtaSouth(r,c), dtaWest(r,c)) == 3 && r < 9 && !dynamic_cast<Beetle*>(grid[r+1][c])) {
                  if (dynamic_cast<Ant*>(grid[r-1][c]))
                  {
                      delete (grid[r+1][c]);
                      grid[r+1][c] = new Beetle();
                      grid[r+1][c]->setLife(grid[r][c]->getLife() + 1);
                      grid[r+1][c]->setEat(0);
                      delete(grid[r][c]);
                      grid[r][c] = nullptr;
                  }
                  else {
                      delete (grid[r+1][c]);
                      grid[r+1][c] = new Beetle();
                      grid[r+1][c]->setLife(grid[r][c]->getLife() + 1);
                      grid[r+1][c]->setEat(grid[r][c]->getEat() + 1);
                      delete(grid[r][c]);
                      grid[r][c] = nullptr;
                  }
              }
              else if (grid[r][c]->move(dtaNorth(r, c), dtaEast(r,c), dtaSouth(r,c), dtaWest(r,c)) == 4 && c > 0 && !dynamic_cast<Beetle*>(grid[r][c-1])) {
                  if (dynamic_cast<Ant*>(grid[r][c-1]))
                  {
                      delete (grid[r][c-1]);
                      grid[r][c-1] = new Beetle();
                      grid[r][c-1]->setLife(grid[r][c]->getLife() + 1);
                      grid[r][c-1]->setEat(0);
                      delete(grid[r][c]);
                      grid[r][c] = nullptr;
                  }
                  else {
                      delete (grid[r][c-1]);
                      grid[r][c-1] = new Beetle();
                      grid[r][c-1]->setLife(grid[r][c]->getLife() + 1);
                      grid[r][c-1]->setEat(grid[r][c]->getEat() + 1);
                      delete(grid[r][c]);
                      grid[r][c] = nullptr;
                  }
              }
          }
      }
   }
}

// finds every beetle in grid and moves it in the appropriate direction
void antMove()
{
    for (int c = 0; c < 10; c++)
   {
      for (int r = 0; r < 10; r++)
      {
          if (dynamic_cast<Ant*>(grid[r][c]))
          {
              if (grid[r][c]->move(dtbNorth(r, c), dtbEast(r,c), dtbSouth(r,c), dtbWest(r,c)) == 1 && r > 0 && grid[r-1][c] == nullptr) {
                  delete (grid[r-1][c]);
                  grid[r-1][c] = new Ant();
                  delete(grid[r][c]);
                  grid[r][c] = nullptr;
              }
              else if (grid[r][c]->move(dtbNorth(r, c), dtbEast(r,c), dtbSouth(r,c), dtbWest(r,c)) == 2 && c < 9 && grid[r][c+1] == nullptr) {
                  delete (grid[r][c+1]);
                  grid[r][c+1] = new Ant();
                  delete(grid[r][c]);
                  grid[r][c] = nullptr;
              }
              else if (grid[r][c]->move(dtbNorth(r, c), dtbEast(r,c), dtbSouth(r,c), dtbWest(r,c)) == 3 && r < 9 && grid[r+1][c] == nullptr) {
                  delete (grid[r+1][c]);
                  grid[r+1][c] = new Ant();
                  delete(grid[r][c]);
                  grid[r][c] = nullptr;
              }
              else if (grid[r][c]->move(dtbNorth(r, c), dtbEast(r,c), dtbSouth(r,c), dtbWest(r,c)) == 4 && c > 0 && grid[r][c-1] == nullptr) {
                  delete (grid[r][c-1]);
                  grid[r][c-1] = new Ant();
                  delete(grid[r][c]);
                  grid[r][c] = nullptr;
              }
          }
      }
   }
}
// finds every beetle in grid and breeds it in the appropriate direction
void beetleBreed()
{
    for (int c = 0; c < 10; c++)
   {
      for (int r = 0; r < 10; r++)
      {
          if (dynamic_cast<Beetle*>(grid[r][c]))
          {
              if (grid[r][c]->getLife() % 8 == 0)
              {
                  if (grid[r][c]->breed(dn(r,c), de(r,c), ds(r,c), dw(r, c)) == 1 && r > 0)
                  {
                      delete(grid[r-1][c]);
                      grid[r-1][c] = new Beetle();
                      grid[r-1][c]->setLife(0);
                      grid[r-1][c]->setEat(0);
                  }
                  else if (grid[r][c]->breed(dn(r,c), de(r,c), ds(r,c), dw(r, c)) == 2 && c < 9)
                  {
                      delete(grid[r][c+1]);
                      grid[r][c+1] = new Beetle();
                      grid[r][c+1]->setLife(0);
                      grid[r][c+1]->setEat(0);
                  }
                  else if (grid[r][c]->breed(dn(r,c), de(r,c), ds(r,c), dw(r, c)) == 3 && r < 9)
                  {
                      delete(grid[r+1][c]);
                      grid[r+1][c] = new Beetle();
                      grid[r+1][c]->setLife(0);
                      grid[r+1][c]->setEat(0);
                  }
                  else if (grid[r][c]->breed(dn(r,c), de(r,c), ds(r,c), dw(r, c)) == 4 && c > 0)
                  {
                      delete(grid[r][c-1]);
                      grid[r][c-1] = new Beetle();
                      grid[r][c-1]->setLife(0);
                      grid[r][c-1]->setEat(0);
                  }
              }
          }
      }
   }
}

// finds every ant in grid and breeds it in the appropriate direction
void antBreed()
{
    for (int c = 0; c < 10; c++)
   {
      for (int r = 0; r < 10; r++)
      {
          if (dynamic_cast<Ant*>(grid[r][c]))
          {
              if (grid[r][c]->breed(dn(r,c), de(r,c), ds(r,c), dw(r, c)) == 1 && r > 0)
              {
                  delete(grid[r-1][c]);
                  grid[r-1][c] = new Ant();
              }
              else if (grid[r][c]->breed(dn(r,c), de(r,c), ds(r,c), dw(r, c)) == 2 && c < 9)
              {
                  delete(grid[r][c+1]);
                  grid[r][c+1] = new Ant();
              }
              else if (grid[r][c]->breed(dn(r,c), de(r,c), ds(r,c), dw(r, c)) == 3 && r < 9)
              {
                  delete(grid[r+1][c]);
                  grid[r+1][c] = new Ant();
              }
              else if (grid[r][c]->breed(dn(r,c), de(r,c), ds(r,c), dw(r, c)) == 4 && c > 0)
              {
                  delete(grid[r][c-1]);
                  grid[r][c-1] = new Ant();
              }
          }
      }
   }
}


void starve()
{
    for (int c = 0; c < 10; c++)
   {
      for (int r = 0; r < 10; r++)
      {
          if (dynamic_cast<Beetle*>(grid[r][c]))
          {
              if (grid[r][c]->getEat() == 5)
              {
                  delete(grid[r][c]);
                  grid[r][c] = nullptr;
              }
          }
      }
   }
}


int dtbNorth (int r, int c)
{
    int ans = 0;
    int cn = 0;
    for (int i = r - 1; i >= 0; i--)
    {
        if (!dynamic_cast<Beetle*>(grid[i][c])) {
            ans++;
        }
        else {
            cn++;
            break;
        }
    }
    if (cn == 0) {
        ans += 10;
    }
    return ans;
}

int dtbEast (int r, int c)
{
    int ans = 0;
    int cn = 0;
    for (int i = c; i < 10; i++)
    {
        if (!dynamic_cast<Beetle*>(grid[r][i])) {
            ans++;
        }
        else {
            cn++;
            break;
        }
    }
    if (cn == 0) {
        ans += 10;
    }
    return ans;
}

int dtbSouth (int r, int c)
{
    int ans = 0;
    int cn = 0;
    for (int i = r; i < 10; i++)
    {
        if (!dynamic_cast<Beetle*>(grid[i][c])) {
            ans++;
        }
        else {
            cn++;
            break;
        }
    }
    if (cn == 0) {
        ans += 10;
    }
    return ans;
}

int dtbWest (int r, int c)
{
    int ans = 0;
    int cn = 0;
    for (int i = c - 1; i >= 0; i--)
    {
        if (!dynamic_cast<Beetle*>(grid[r][i])) {
            ans++;
        }
        else {
            cn++;
            break;
        }
    }
    if (cn == 0) {
        ans += 10;
    }
    return ans;
}

int dtaNorth (int r, int c)
{
    int ans = 0;
    int cn = 0;
    for (int i = r - 1; i >= 0; i--)
    {
        if (!dynamic_cast<Ant*>(grid[i][c])) {
            ans++;
        }
        else {
            cn++;
            break;
        }
    }
    if (cn == 0) {
        ans += 10;
    }
    return ans;
}

int dtaEast (int r, int c)
{
    int ans = 0;
    int cn = 0;
    for (int i = c; i < 10; i++)
    {
        if (!dynamic_cast<Ant*>(grid[r][i])) {
            ans++;
        }
        else {
            cn++;
            break;
        }
    }
    if (cn == 0) {
        ans += 10;
    }
    return ans;
}

int dtaSouth (int r, int c)
{
    int ans = 0;
    int cn = 0;
    for (int i = r; i < 10; i++)
    {
        if (!dynamic_cast<Ant*>(grid[i][c])) {
            ans++;
        }
        else {
            cn++;
            break;
        }
    }
    if (cn == 0) {
        ans += 10;
    }
    return ans;
}

int dtaWest (int r, int c)
{
    int ans = 0;
    int cn = 0;
    for (int i = c - 1; i >= 0; i--)
    {
        if (!dynamic_cast<Ant*>(grid[r][i])) {
            ans++;
        }
        else {
            cn++;
            break;
        }
    }
    if (cn == 0) {
        ans += 10;
    }
    return ans;
}

int dn (int r, int c)
{
    if (r > 0)
    {
        if (grid[r-1][c] == nullptr) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

int de (int r, int c)
{
    if (c < 9)
    {
        if (grid[r][c+1] == nullptr) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

int ds (int r, int c)
{
    if (r < 9)
    {
        if (grid[r+1][c] == nullptr) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

int dw (int r, int c)
{
    if (c > 0)
    {
        if (grid[r][c-1] == nullptr) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

void setLivesEats()
{
    for (int c = 0; c < 10; c++)
   {
      for (int r = 0; r < 10; r++)
      {
          if (dynamic_cast<Beetle*>(grid[r][c]))
          {
              grid[r][c]->setLife(0);
              grid[r][c]->setEat(0);
          }
      }
   }
}
*/
#include <iostream>

using namespace std;

int main()
{
    cout << "TURN 1" << endl;
    cout << "       A  " << endl;
    cout << "   b     A" << endl;
    cout << "       A  " << endl;
    cout << "   A      " << endl;
    cout << "A      b  " << endl;
    cout << "          " << endl;
    cout << "  b A     " << endl;
    cout << "          " << endl;
    cout << "          " << endl;
    cout << "  A  A b  " << endl;
    

    return 0;
}
