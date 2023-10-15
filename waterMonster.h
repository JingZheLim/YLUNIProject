#ifndef WATERMONSTER_H
#define WATERMONSTER_H
#include <string>
using namespace std;
#include <iostream>

#include "monster.h"

class waterMonster : public monster {
 protected:
  int healEffect;

 public:
  waterMonster();
  int damageRecieved(int playersAttack);
  int attack(int playersDefence);
  int get_waterHealth();
  int get_waterAttack();
  int get_waterDefence();
  string get_waterName();
};

#endif