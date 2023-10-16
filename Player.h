#ifndef PLAYER_H
#define PLAYER_H
#include <string>

#include "Spell.h"

using namespace std;

class Player {
 protected:
  string playerName;  // user inputted
  int health;         // base health (according to player type)
  int attack;         // base attack (set according to player type)
  int defense;        // base defense (set according to player type)

  int healthPotion;  // player can have multiple potions, heals 30 hp 

  int currentSpells; // Keep count of current spells
  int numSpells = 8; // To keep count of number of spells 
  Spell** playerSpells;  // For array of spells  

 public:

  // default constructor 
  Player(); 

  // getters and setters
  string getPlayerName();
  void setPlayerName(string name); 

  int getHealth();
  void setHealth(int health);

  int getAttack();
  void setAttack(int attack);

  int getDefense();
  void setDefense(int defense);

  int getHealthPotion();
  void setHealthPotion(int healthPotion);

  // Used to show player all the spells
  Spell** getSpell();  // Returns array of pointers to spells

  // To add new spells into the spells array
  void addSpell(Spell** playerSpells);

  int calculateDmgDone(int monsterDefense);  // Returns damage that is done by player
  int calculateDmgRecieved(int monstersAttack); // Returns damage that is done to player 

  int castSpell(int spellNum, int monsterDefense);    // Casts the spell

  virtual int drinkPotion();  // Uses potion, effectiveness depends on class

};
#endif