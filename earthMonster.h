#ifndef EARTHMONSTER_H
#define EARTHMONSTER_H
#include <string>
using namespace std;
#include <iostream>

#include "monster.h"

class earthMonster : public monster {
 protected:
  int defUp;  // extra attribute which permantly increases earth monsters
              // defence

 public:
  earthMonster();                         // default constructor
  int damageRecieved(int playersAttack);  // calculate damage recieved and
                                          // directly changes objects attributes
  int attack(int playersDefence);  // calculates damage done and returns that
                                   // damage while outputing message

  // getters
  int get_earthHealth();
  int get_earthAttack();
  int get_earthDefence();
  string get_earthName();
};

#endif