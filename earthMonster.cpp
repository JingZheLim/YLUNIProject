#include "earthMonster.h"

#include <iostream>
#include <string>

#include "monster.h"
using namespace std;

earthMonster::earthMonster() {  // creates earth monsters attributes when called
  this->mHealth = 150;
  this->mAttack = 40;
  this->mDefence = 65;
  this->mName = "Rowan";
  this->mAtkType = "Meteor Strike";
  this->defUp = 5;
}
int earthMonster::damageRecieved(
    int playersAttack) {  // directly changes monsters attributes
  int pDamage = playersAttack - mDefence;
  if (pDamage < 0) {  // if less than 0, make sure damage = 0 so that it doesn't
                      // add the damage health instead
    pDamage = 0;
  }

  this->mHealth -= pDamage;
  if (this->mHealth < 0) {  // if less than 0 reset hp to 0 for output purposes
    this->mHealth = 0;
  }
  return pDamage;  // returns damage number for output purposes
}
int earthMonster::attack(
    int playersDefence) {  // calculates the damage and returns while outputing
                           // the damage done
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
  this->mDefence += this->defUp;  // extra attribute used here
  return damage;  // returns damage for output and association purposes
}

int earthMonster::get_earthHealth() { return mHealth; }  // gets monsters health
int earthMonster::get_earthAttack() { return mAttack; }  // gets monsters attack
int earthMonster::get_earthDefence() {
  return mDefence;
}  // gets monsters defence
string earthMonster::get_earthName() { return mName; }  // gets monsters name