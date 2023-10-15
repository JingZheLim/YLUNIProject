#ifndef EARTHMONSTER_H
#define EARTHMONSTER_H
#include <string>
using namespace std;
#include <iostream>

#include "monster.h"

class earthMonster : public monster {
 protected:
  int defUp;

 public:
  earthMonster();
  int damageRecieved(int playersAttack);
  int attack(int playersDefence);
  int get_earthHealth();
  int get_earthAttack();
  int get_earthDefence();
  string get_earthName();
};

#endif