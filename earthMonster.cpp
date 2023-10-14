#include "earthMonster.h"

#include <iostream>
#include <string>

#include "monster.h"
using namespace std;

earthMonster::earthMonster() {
  this->mHealth = 150;
  this->mAttack = 35;
  this->mDefence = 65;
  this->mName = "Rowan";
  this->mAtkType = "Meteor Strike";
  this->defUp = 10;
}
int earthMonster::calculateDmgDone() {}
int earthMonster::damageRecieved() {}
void earthMonster::attack() {
      cout << this->mName << "used " << this->mAtkType << "and did " << calculateDmgDone() << "amounts of damage!!" << endl;
}