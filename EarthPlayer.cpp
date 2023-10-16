#include "EarthPlayer.h"

#include <iostream>

#include "Spell.h"

EarthPlayer::EarthPlayer() {
  health = 400;
  attack = 100;
  defense = 35;
  playerSpells = new Spell*[numSpells];
  currentSpells = 2;
  playerSpells[0] = new Spell("Earthquake", 25);      // Attack spell
  playerSpells[1] = new Spell(75, "Grass Mountain");  // Defense spell
  healthPotion = 5;
}

int EarthPlayer::useGroundShake(int monsterDefense) {
  int damage = 0;
  damage = groundShake - monsterDefense;
  cout << this->getPlayerName() << " used ground shake dealing " << damage
       << " damage!!" << endl;
  cout << "--------------------------------------------------" << endl;
  return damage;
}

// Virtual function, effectives of potion depends on class
int EarthPlayer::drinkPotion() {
  this->health += 100;
  if (this->health <= 400) {
    cout << this->getPlayerName() << " healed up by 100 HP using the potion!!"
         << endl;
    cout << "--------------------------------------------------" << endl;
    return this->health;

  } else {
    this->health = 400;
    cout << this->getPlayerName() << " healed up to full using the potion!!"
         << endl;
    cout << "--------------------------------------------------" << endl;
    return this->health;
  }
}