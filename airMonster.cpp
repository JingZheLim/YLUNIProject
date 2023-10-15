#include "airMonster.h"

#include <iostream>
#include <string>

#include "monster.h"
using namespace std;

airMonster::airMonster() {
  this->mHealth = 100;
  this->mAttack = 50;
  this->mDefence = 50;
  this->mName = "Amaya";
  this->mAtkType = "Feather Dance";
  this->atkUp = 5;
}

int airMonster::damageRecieved(int playersAttack) {
  int pDamage = playersAttack - mDefence;
  if (pDamage < 0) {  // if less than 0, make sure damage = 0 so that it doesn't
                      // add the damage to health instead
    pDamage = 0;
  }
  this->mHealth -= pDamage;
  if (this->mHealth < 0) {  // if less than 0 reset hp to 0 for output purposes
    this->mHealth = 0;
  }
  return pDamage;
}

int airMonster::attack(int playersDefence) {
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
  this->mAttack += this->atkUp;
  return damage;
}

int airMonster::get_airHealth() { return mHealth; }
int airMonster::get_airAttack() { return mAttack; }
int airMonster::get_airDefence() { return mDefence; }
string airMonster::get_airName() { return mName; }