#include "airMonster.h"

#include <iostream>
#include <string>

#include "monster.h"
using namespace std;

airMonster::airMonster() {  // creates air monsters attributes when called
  this->mHealth = 100;
  this->mAttack = 50;
  this->mDefence = 50;
  this->mName = "Amaya";
  this->mAtkType = "Feather Dance";
  this->atkUp = 5;
}

int airMonster::damageRecieved(
    int playersAttack) {  // directly changes monsters attributes
  int pDamage = playersAttack - mDefence;
  if (pDamage < 0) {  // if less than 0, make sure damage = 0 so that it doesn't
                      // add the damage to health instead
    pDamage = 0;
  }
  this->mHealth -= pDamage;
  if (this->mHealth < 0) {  // if less than 0 reset hp to 0 for output purposes
    this->mHealth = 0;
  }
  return pDamage;  // returns damage number for output purposes
}

int airMonster::attack(
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
  cout << this->mName << "\'s Attack rose by " << atkUp << endl;
  cout << "--------------------------------------------------" << endl;
  this->mAttack += this->atkUp;  // extra attribute used here
  return damage;  // returns damage for output and association purposes
}

int airMonster::get_airHealth() { return mHealth; }    // gets monsters health
int airMonster::get_airAttack() { return mAttack; }    // gets monsters attack
int airMonster::get_airDefence() { return mDefence; }  // gets monsters defence
string airMonster::get_airName() { return mName; }     // gets monsters name