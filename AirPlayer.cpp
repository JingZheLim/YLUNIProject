#include "AirPlayer.h"
#include "Spell.h"
#include <iostream>

AirPlayer::AirPlayer(){
    health = 500; 
    attack = 300; 
    defense = 200; 
    playerSpells = new Spell*[numSpells];
    currentSpells = 2; 
    playerSpells[0] = new Spell("Tornado", 300); // Attack spell
    playerSpells[1] = new Spell("Wind Shield", 200); // Defense spell
}

int AirPlayer::useWindSlash(int monsterDefense){
    int damage = 0;
    damage = windSlash - monsterDefense; 
    cout << this->getPlayerName() << " used wind slash dealing 100 damage!!" << endl;
    cout << "--------------------------------------------------" << endl;
}

// Virtual function, effectives of potion depends on class
int AirPlayer::drinkPotion(){
    health += 150;
    cout << this->getPlayerName() << " healed up by 150hp using the potion!!" << endl; 
    return health;
    cout << "--------------------------------------------------" << endl;
}