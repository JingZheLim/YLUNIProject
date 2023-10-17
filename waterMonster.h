#ifndef WATERMONSTER_H
#define WATERMONSTER_H
#include <string>
using namespace std;
#include <iostream>

#include "monster.h"

class waterMonster : public monster {
 protected:
  int healEffect;  // extra attribute which heals water monster

 public:
  waterMonster();                         // default constructor
  int damageRecieved(int playersAttack);  // calculate damage recieved and
                                          // directly changes objects attributes
  int attack(int playersDefence);  // calculates damage done and returns that
                                   // damage while outputing message
  // getters
  int get_waterHealth();
  int get_waterAttack();
  int get_waterDefence();
  string get_waterName();
};

#endif