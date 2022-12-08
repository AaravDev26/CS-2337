// Aarav Dev
// axd220001

#ifndef BEETLE_H
#define BEETLE_H
#include "Creature.h"
#include <vector>

class Beetle : public Creature
{
    //int eat;
    //int life;
public:
   int move(int a, int b, int c, int d) const;
   int breed(int a, int b, int c, int d) const;
   int starve() const;
   Beetle() {}
   virtual ~Beetle() {};
};
#endif
