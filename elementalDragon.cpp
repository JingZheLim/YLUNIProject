#include "elementalDragon.h"

#include <string>

#include "airMonster.h"
#include "earthMonster.h"
#include "fireMonster.h"
#include "monster.h"
#include "waterMonster.h"

elementalDragon::elementalDragon() {
  this->dragonHealth = 400;
  this->dragonAttack = 25;
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
  if (this->dragonHealth <
      0) {  // if less than 0 reset hp to 0 for output purposes
    this->dragonHealth = 0;
  }
  return pDamage;  // Returns player's damage
}

int elementalDragon::attack(int playerDefense) {
  // Pick a random monster to reuse attack from
  int randMonster = rand() % 4;
  int dragonAtk = this->dragonAttack;
  int atkboost = 0;

  if (randMonster == 0) {
    cout << this->dragonName
         << " is swift as the wind and transformed into Amaya!" << endl;
    cout << "---------------------------" << endl;
    atkboost += 5;
    return airMonster::attack(playerDefense - atkboost - dragonAtk + 5);

  } else if (randMonster == 1) {
    cout << this->dragonName << " shatters the ground to turn into Rowan!"
         << endl;
    cout << "---------------------------" << endl;
    this->dragonDefence += 5;
    return earthMonster::attack(playerDefense - atkboost - dragonAtk);

  } else if (randMonster == 2) {
    cout << this->dragonName << " erupts into Blazair!" << endl;
    cout << "---------------------------" << endl;
    return fireMonster::attack(playerDefense - atkboost - dragonAtk);
  } else {
    cout << this->dragonName
         << " \'s skin is smooth as water and liquified into Andreas!" << endl;
    cout << "---------------------------" << endl;
    this->dragonHealth += 10;
    return waterMonster::attack(playerDefense - atkboost - dragonAtk);
  }
}

int elementalDragon::get_elementalHealth() { return dragonHealth; }
int elementalDragon::get_elementalAttack() { return dragonAttack; }
int elementalDragon::get_elementalDefence() { return dragonDefence; }
string elementalDragon::get_elementalName() { return dragonName; }
