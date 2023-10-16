#include "WaterPlayer.h"
#include "Spell.h"
#include <iostream>

WaterPlayer::WaterPlayer(){
    health = 700; 
    attack = 200; 
    defense = 100; 
    playerSpells = new Spell*[numSpells];
    currentSpells = 2; 
    playerSpells[0] = new Spell("Water Blast", 300); // Attack spell
    playerSpells[1] = new Spell("Water Barrier", 200); // Defense spell
}

int WaterPlayer::useWaterFlood(int monsterDefense){
    int damage = 0;
    damage = waterFlood - monsterDefense; 
    cout << this->getPlayerName() << " used water flood dealing 100 damage!!" << endl;
    cout << "--------------------------------------------------" << endl;
}

// Virtual function, effectives of potion depends on class
int WaterPlayer::drinkPotion(){
    health += 150;
    cout << this->getPlayerName() << " healed up by 150hp using the potion!!" << endl; 
    return health;
    cout << "--------------------------------------------------" << endl;
}


