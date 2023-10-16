#ifndef FIREPLAYER_H
#define FIREPLAYER_H
#include "Player.h"

class FirePlayer : public Player {
 private:
  int fireStrike = 100;  // Extra fire attack

 public:
  // default constructor:
  FirePlayer();

  // Extra fire class attack (Not a spell)
  int useFireStrike(int monsterDefense);

  int getFireAtkSpell();

  int getFireDefSpell();

  virtual int drinkPotion();
};
#endif