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
    playerSpells[1] = new Spell(200, "Water Barrier"); // Defense spell
}

int WaterPlayer::useWaterFlood(int monsterDefense){
    int damage = 0;
    damage = waterFlood - monsterDefense; 
    cout << this->getPlayerName() << " used water flood dealing 100 damage!!" << endl;
    cout << "--------------------------------------------------" << endl;
    return damage;
}

// Virtual function, effectives of potion depends on class
int WaterPlayer::drinkPotion(){
    if(this->health <= 550){
        this->health += 150;
        cout << this->getPlayerName() << " healed up by 150hp using the potion!!" << endl; 
        return health;
        cout << "--------------------------------------------------" << endl;
    }else{
        this->health = 700;
        return health; 

    }
}


