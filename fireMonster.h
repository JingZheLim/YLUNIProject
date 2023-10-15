#ifndef FIREMONSTER_H
#define FIREMONSTER_H
#include <string>
using namespace std;
#include <iostream>
#include "monster.h"



class fireMonster  : public monster {
    protected:
    int burnDamage;

    public:
    fireMonster();
  int damageRecieved(int playersAttack);
  int attack(int playersDefence);
  int get_fireHealth();
  int get_fireAttack();
  int get_fireDefence();
  string get_fireName();
};

#endif