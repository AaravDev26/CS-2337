// Aarav Dev
// axd220001

#ifndef CREATURE_H // if creature not defined
#define CREATURE_H // define creature

class Creature // defines creature class
{
    int eat; // time since eaten for beetle
    int life; // lifespan of beetle
public:
   virtual int move(int a, int b, int c, int d) const = 0; // pure virtual move method
   virtual int breed(int a, int b, int c, int d) const = 0; // pure virtual breed method
   Creature() {} // constructor
   virtual ~Creature() {}; // virtual destructor
    int getEat() {return eat;} // getter method for time since eaten for beetle
   void setEat(int newEat) {eat = newEat;} // setter method fro time since eaten for beetle
   int getLife() {return life;} // getter method for lifespan of beetle
   void setLife(int newLife) {life = newLife;} // setter method for lifespan of beetle
};
#endif // ends if statement
