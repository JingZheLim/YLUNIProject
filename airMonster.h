#ifndef AIRMONSTER_H
#define AIRMONSTER_H
#include <string>
using namespace std;
#include <iostream>

#include "monster.h"

class airMonster : public monster {
 protected:
  int atkUp;

 public:
  airMonster();
  int damageRecieved(int playersAttack);
  int attack(int playersDefence);
  int get_airHealth();
  int get_airAttack();
  int get_airDefence();
  string get_airName();
};

#endif