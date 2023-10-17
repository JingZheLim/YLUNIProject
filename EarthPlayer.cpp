#include "EarthPlayer.h"

#include <iostream>

#include "Spell.h"

EarthPlayer::EarthPlayer() {
  health = 300;
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

int EarthPlayer::getEarthAtkSpell() {
  return playerSpells[0]->getSpellAttack();
}

int EarthPlayer::getEarthDefSpell() {
  return playerSpells[1]->getSpellDefense();
}

// Virtual function, effectives of potion depends on class
// Total health = 300, potion = 100
// 300 - 100 = 200
int EarthPlayer::drinkPotion() {
  if (this->health < 200) {
    this->health += 100;
    cout << this->getPlayerName() << " healed up by 100 HP using the potion!!"
         << endl;
    cout << "--------------------------------------------------" << endl;

  } else if (this->health >= 200) {
    this->health = 300;
    cout << this->getPlayerName() << " healed up to full using the potion!!"
         << endl;
    cout << "--------------------------------------------------" << endl;
  }
  return this->health;
}