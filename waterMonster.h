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
  int calculateDmgDone();
  int damageRecieved();
  void attack();
  int getHealth();
};

#endif