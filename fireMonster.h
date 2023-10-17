#ifndef FIREMONSTER_H
#define FIREMONSTER_H
#include <string>
using namespace std;
#include <iostream>

#include "monster.h"

class fireMonster : public monster {
 protected:
  int burnDamage;  // extra attribute which does extra damage to player

 public:
  fireMonster();                          // default constructor
  int damageRecieved(int playersAttack);  // calculate damage recieved and
                                          // directly changes objects attributes
  int attack(int playersDefence);  // calculates damage done and returns that
                                   // damage while outputing message

  // getters
  int get_fireHealth();
  int get_fireAttack();
  int get_fireDefence();
  string get_fireName();
};

#endif