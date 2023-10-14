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
  int calculateDmgDone();
  int damageRecieved();
  void attack();
};

#endif