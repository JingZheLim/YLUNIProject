#include "FirePlayer.h"
#include "Spell.h"
#include <iostream>

FirePlayer::FirePlayer(){
    health = 500; 
    attack = 400; 
    defense = 200; 
    playerSpells = new Spell*[numSpells];
    currentSpells = 2; 
    playerSpells[0] = new Spell("Fire Balls", 450); // Attack spell
    playerSpells[1] = new Spell("Fire Fortify", 100); // Defense spell
}

int FirePlayer::useFireStrike(int monsterDefense){
    int damage = 0;
    damage = fireStrike - monsterDefense; 
    cout << this->getPlayerName() << " used fire strike dealing 100 damage!!" << endl;
    cout << "--------------------------------------------------" << endl;
}

// Virtual function, effectives of potion depends on class
int FirePlayer::drinkPotion(){
    health += 100;
    cout << this->getPlayerName() << " healed up by 100hp using the potion!!" << endl; 
    return health;
    cout << "--------------------------------------------------" << endl;
}