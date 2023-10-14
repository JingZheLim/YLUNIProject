#include "waterMonster.h"

#include <iostream>
#include <string>

#include "monster.h"
using namespace std;
waterMonster::waterMonster() {
  this->mHealth = 200;
  this->mAttack = 50;
  this->mDefence = 30;
  this->mName = "Andreas";
  this->mAtkType = "Hydro-Pulse Cannon";
  this->healEffect = 10;
}
int waterMonster::calculateDmgDone() { return mAttack - mDefence; }
int waterMonster::damageRecieved() {
  int currentmHealth = mHealth;
  int damage = calculateDmgDone();
  this->mHealth = currentmHealth - damage;
  cout << mName << " has " << mHealth << " health left." << endl;
}
void waterMonster::attack() {
  cout << this->mName << " used " << this->mAtkType << " and did "
       << calculateDmgDone() << " amounts of damage!!" << endl;
}

int waterMonster::getHealth(){
  return mHealth;
}