#include "WaterPlayer.h"

#include <iostream>

#include "Spell.h"

WaterPlayer::WaterPlayer() {
  health = 500;
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
  cout << this->getPlayerName() << " used water flood dealing 100 damage!!"
       << endl;
  cout << "--------------------------------------------------" << endl;
  return damage;
}

// Virtual function, effectives of potion depends on class
int WaterPlayer::drinkPotion() {
  this->health += 150;
  if (this->health <= 500) {
    cout << this->getPlayerName() << " healed up by 150 HP using the potion!!"
         << endl;
    cout << "--------------------------------------------------" << endl;
    return this->health;

  } else {
    this->health = 500;
    cout << this->getPlayerName() << " healed up to full using the potion!!"
         << endl;
    cout << "--------------------------------------------------" << endl;
    return this->health;
  }
}