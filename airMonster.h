#ifndef AIRMONSTER_H
#define AIRMONSTER_H
#include <string>
using namespace std;
#include <iostream>

#include "monster.h"

class airMonster : public monster {
 protected:
  int atkUp;  // extra attribute which permantly increases air monsters attack

 public:
  airMonster();                           // default constructor
  int damageRecieved(int playersAttack);  // calculate damage recieved and
                                          // directly changes objects attributes
  int attack(int playersDefence);  // calculates damage done and returns that
                                   // damage while outputing message

  // getters
  int get_airHealth();
  int get_airAttack();
  int get_airDefence();
  string get_airName();
};

#endif