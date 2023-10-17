#include "fireMonster.h"

#include <iostream>
#include <string>

#include "monster.h"
using namespace std;

fireMonster::fireMonster() {  // creates fire monsters attributes when called
  this->mHealth = 100;
  this->mAttack = 65;
  this->mDefence = 35;
  this->mName = "Blazair";
  this->mAtkType = "Fire Tornado";
  this->burnDamage = 5;
}
int fireMonster::damageRecieved(
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
int fireMonster::attack(
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
  cout << this->mName << " Burnt you for extra " << this->burnDamage
       << " damage" << endl;
  cout << "--------------------------------------------------" << endl;
  return damage + burnDamage;  // extra attribute used here & returns damage
                               // for output and association purposes
}

int fireMonster::get_fireHealth() { return mHealth; }  // gets monsters health
int fireMonster::get_fireAttack() { return mAttack; }  // gets monsters attack
int fireMonster::get_fireDefence() {
  return mDefence;
}  // gets monsters defence
string fireMonster::get_fireName() { return mName; }  // gets monsters name