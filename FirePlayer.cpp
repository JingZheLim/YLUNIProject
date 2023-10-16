#include "FirePlayer.h"

#include <iostream>

#include "Spell.h"

FirePlayer::FirePlayer() {
  health = 500;
  attack = 400;
  defense = 200;
  playerSpells = new Spell*[numSpells];
  currentSpells = 2;
  playerSpells[0] = new Spell("Fire Balls", 450);    // Attack spell
  playerSpells[1] = new Spell(100, "Fire Fortify");  // Defense spell
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
  if (this->health <= 400) {
    this->health += 100;
    cout << this->getPlayerName() << " healed up by 100hp using the potion!!"
         << endl;
    return health;
    cout << "--------------------------------------------------" << endl;
  } else {
    this->health = 500;
    return health;
  }
}