#include "FirePlayer.h"

#include <iostream>

#include "Spell.h"

FirePlayer::FirePlayer() {
  health = 250;
  attack = 100;
  defense = 35;
  playerSpells = new Spell*[numSpells];
  currentSpells = 2;
  playerSpells[0] = new Spell("Fire Balls", 50);    // Attack spell
  playerSpells[1] = new Spell(50, "Fire Fortify");  // Defense spell
  healthPotion = 3;
}

int FirePlayer::useFireStrike(int monsterDefense) {
  int damage = 0;
  damage = fireStrike - monsterDefense;
  cout << this->getPlayerName() << " used fire strike dealing 100 damage!!"
       << endl;
  cout << "--------------------------------------------------" << endl;
  return damage;
}

int FirePlayer::getFireAtkSpell() { return playerSpells[0]->getSpellAttack(); }

int FirePlayer::getFireDefSpell() { return playerSpells[1]->getSpellDefense(); }

// Virtual function, effectives of potion depends on class
int FirePlayer::drinkPotion() {
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