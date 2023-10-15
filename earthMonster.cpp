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
  this->defUp = 5;
}
int earthMonster::damageRecieved(int playersAttack) {
  int pDamage = playersAttack - mDefence;
  if (pDamage < 0) {  // if less than 0, make sure damage = 0 so that it doesn't
                      // add the damage health instead
    pDamage = 0;
  }

  this->mHealth -= pDamage;
  if (this->mHealth < 0) {  // if less than 0 reset hp to 0 for output purposes
    this->mHealth = 0;
  }
  return pDamage;
}
int earthMonster::attack(int playersDefence) {
  int currentAttack = mAttack;
  int damage = currentAttack - playersDefence;
  if (damage < 0) {  // if less than 0, make sure damage = 0 so that it doesn't
                     // add the damage to health instead
    damage = 0;
  }
  cout << this->mName << " used " << this->mAtkType << " and did " << damage
       << " amounts of damage!!" << endl;
  cout << this->mName << "\'s Defence strengthed by " << defUp << endl;
  cout << "--------------------------------------------------" << endl;
  this->mDefence += this->defUp;
  return damage;
}

int earthMonster::get_earthHealth() { return mHealth; }
int earthMonster::get_earthAttack() { return mAttack; }
int earthMonster::get_earthDefence() { return mDefence; }
string earthMonster::get_earthName() { return mName; }