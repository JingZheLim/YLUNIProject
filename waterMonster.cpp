#include "waterMonster.h"

#include <iostream>
#include <string>

#include "monster.h"
using namespace std;
waterMonster::waterMonster() {  // creates air monsters attributes when called
  this->mHealth = 200;
  this->mAttack = 50;
  this->mDefence = 30;
  this->mName = "Andreas";
  this->mAtkType = "Hydro-Pulse Cannon";
  this->healEffect = 10;
}
int waterMonster::damageRecieved(
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
int waterMonster::attack(
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
  cout << this->mName << " Healed " << healEffect << " of its HP back" << endl;
  cout << "--------------------------------------------------" << endl;
  this->mHealth += this->healEffect;  // extra attribute used here
  return damage;  // returns damage for output and association purposes
}

int waterMonster::get_waterHealth() { return mHealth; }  // gets monsters health
int waterMonster::get_waterAttack() { return mAttack; }  // gets monsters attack
int waterMonster::get_waterDefence() {
  return mDefence;
}  // gets monsters defence
string waterMonster::get_waterName() { return mName; }  // gets monsters name