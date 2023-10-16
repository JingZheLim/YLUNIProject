#include "AirPlayer.h"

#include <iostream>

#include "Spell.h"

AirPlayer::AirPlayer() {
  health = 250;
  attack = 130;
  defense = 30;
  playerSpells = new Spell*[numSpells];
  currentSpells = 2;
  playerSpells[0] = new Spell("Tornado", 50);      // Attack spell
  playerSpells[1] = new Spell(50, "Wind Shield");  // Defense spell
  healthPotion = 5;
}

int AirPlayer::useWindSlash(int monsterDefense) {
  int damage = 0;
  damage = windSlash - monsterDefense;
  cout << this->getPlayerName() << " used wind slash dealing " << damage
       << " damage!!" << endl;
  cout << "--------------------------------------------------" << endl;
  return damage;
}

// Virtual function, effectives of potion depends on class
int AirPlayer::drinkPotion() {
  this->health += 100;
  if (this->health <= 250) {
    cout << this->getPlayerName() << " healed up by 100 HP using the potion!!"
         << endl;
    cout << "--------------------------------------------------" << endl;
    return this->health;

  } else {
    this->health = 250;
    cout << this->getPlayerName() << " healed up to full using the potion!!"
         << endl;
    cout << "--------------------------------------------------" << endl;
    return this->health;
  }
}