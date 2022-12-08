// Aarav Dev
// axd220001

#ifndef ANT_H // if ant not defined
#define ANT_H // define ant
#include "Creature.h" // includes creature

class Ant : public Creature
{
public:
   virtual int move(int a, int b, int c, int d) const;
   virtual int breed(int a, int b, int c, int d) const;
   Ant() {}
   virtual ~Ant() {};
};
#endif
