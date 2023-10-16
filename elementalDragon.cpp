#include "monster.h"
#include "airMonster.h"
#include "earthMonster.h"
#include "fireMonster.h"
#include "waterMonster.h"
#include "elementalDragon.h"
#include <string>

elementalDragon::elementalDragon(){
    this->dragonHealth = 400;
    this->dragonAttack = 100;
    this->dragonDefence = 100;
    this->dragonName = "Elegon";
}

// Calculates the damage done to the dragon 
int elementalDragon::damageRecieved(int playersAttack) {
  int pDamage = 0; 
  pDamage = playersAttack - dragonDefence;
  if (pDamage < 0) {  // if less than 0, make sure damage = 0 so that it doesn't
                      // add the damage health instead
    pDamage = 0;
  }

  this->dragonHealth = dragonHealth - pDamage;
  if (this->dragonHealth < 0) {  // if less than 0 reset hp to 0 for output purposes
    this->dragonHealth = 0;
  }
  return pDamage; // Returns player's damage 
}

int elementalDragon::attack(int playerDefense) {

  // Pick a random monster to reuse attack from
  int randMonster = rand() % 4;
  
  if (randMonster == 0) {
    return airMonster::attack(playerDefense); 
  } else if (randMonster == 1) {
    return earthMonster::attack(playerDefense);
  } else if (randMonster == 2) {
    return fireMonster::attack(playerDefense);
  } else {
    return waterMonster::attack(playerDefense);
  }

}

int elementalDragon::get_elementalHealth() { return dragonHealth; }
int elementalDragon::get_elementalAttack() { return dragonAttack; }
int elementalDragon::get_elementalDefence() { return dragonDefence; }
string elementalDragon::get_elementalName() { return dragonName; }
