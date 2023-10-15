#ifndef ELEMENTALDRAGON_H
#define ELEMENTALDRAGON_H
#include "airMonster.h"
#include "earthMonster.h"
#include "fireMonster.h"
#include "monster.h"
#include "waterMonster.h"

class elementalDragon : public waterMonster,
                        public fireMonster,
                        public earthMonster,
                        public airMonster {
 private:
  int dragonHealth;
  int dragonAttack;
  int dragonDefence;
  string dragonName;

 public:
  elementalDragon();
  int damageRecieved(int playersAttack);
  int attack(int playersDefence);
  int get_elementalHealth();
  int get_elementalAttack();
  int get_elementalDefence();
  string get_elementalName();
};

#endif