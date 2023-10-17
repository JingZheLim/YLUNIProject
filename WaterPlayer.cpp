#include "WaterPlayer.h"

#include <iostream>

#include "Spell.h"

WaterPlayer::WaterPlayer() {
  health = 300;
  attack = 125;
  defense = 20;
  playerSpells = new Spell*[numSpells];
  currentSpells = 2;
  playerSpells[0] = new Spell("Water Blast", 75);    // Attack spell
  playerSpells[1] = new Spell(25, "Water Barrier");  // Defense spell
  healthPotion = 5;
}

int WaterPlayer::useWaterFlood(int monsterDefense) {
  int damage = 0;
  damage = waterFlood - monsterDefense;
  cout << this->getPlayerName() << " used water flood dealing " << damage
       << " damage!!" << endl;
  cout << "--------------------------------------------------" << endl;
  return damage;
}

int WaterPlayer::getWaterAtkSpell() {
  return playerSpells[0]->getSpellAttack();
}

int WaterPlayer::getWaterDefSpell() {
  return playerSpells[1]->getSpellDefense();
}

// Virtual function, effectives of potion depends on class
// 300 - 150 = 150
int WaterPlayer::drinkPotion() {
  if (this->health < 150) {
    this->health += 150;
    cout << this->getPlayerName() << " healed up by 150 HP using the potion!!"
         << endl;
    cout << "--------------------------------------------------" << endl;

  } else if (this->health >= 150) {
    this->health = 300;
    cout << this->getPlayerName() << " healed up to full using the potion!!"
         << endl;
    cout << "--------------------------------------------------" << endl;
  }
  return this->health;
}