#include "EarthPlayer.h"
#include "Spell.h"
#include <iostream>

EarthPlayer::EarthPlayer(){
    health = 600; 
    attack = 200; 
    defense = 100; 
    playerSpells = new Spell*[numSpells];
    currentSpells = 2; 
    playerSpells[0] = new Spell("Earthquake", 400); // Attack spell
    playerSpells[1] = new Spell(300, "Grass Mountain"); // Defense spell
    healthPotion = 3;
}

int EarthPlayer::useGroundShake(int monsterDefense){
    int damage = 0;
    damage = groundShake - monsterDefense; 
    cout << this->getPlayerName() << " used ground shake dealing 100 damage!!" << endl;
    cout << "--------------------------------------------------" << endl;
    return damage;
}

// Virtual function, effectives of potion depends on class
int EarthPlayer::drinkPotion(){
    if(this->health <= 500){
        health += 100;
        cout << this->getPlayerName() << " healed up by 100hp using the potion!!" << endl; 
        return health;
        cout << "--------------------------------------------------" << endl;
    }else{
        this->health = 600; 
        return health; 
    }
}