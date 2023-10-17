#include "Player.h"
#include "Spell.h"
#include "monster.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(){
    playerName = "";
    health = 0;
    attack = 0;
    defense = 0; 
    healthPotion = 0; 
    playerSpells = new Spell*[numSpells]; 
}

// Setters and getters
string Player::getPlayerName(){
    return this->playerName; 
}

void Player::setPlayerName(string name){
    this->playerName = name; 
} 

int Player::getHealth(){
    return this->health; 
}

void Player::setHealth(int health){
    this->health = health; 
}

int Player::getAttack(){
    return this->attack;
}

void Player::setAttack(int attack){
    this->attack = attack; 
}

int Player::getDefense(){
    return this->defense;
}

void Player::setDefense(int defense){
    this->defense = defense; 
}

int Player::getHealthPotion(){
    return this->healthPotion; 
}

void Player::setHealthPotion(int healthPotion){
    this->healthPotion = healthPotion; 
}

// Used to show player all the spells
Spell** Player::getSpell(){
    return this->playerSpells; 
}


void Player::addSpell(Spell** playerSpells){
    if(currentSpells < numSpells){
        this->playerSpells[currentSpells] = *playerSpells; 
        currentSpells++; 
    }
}

// Calculates base attack 
int Player::calculateDmgDone(int monsterDefense){
    int damage = 0; // To store base attack damage
    int damage2 = 0; // To store display damage 
    damage = attack;
    damage2 = attack - monsterDefense; 
    cout << this->playerName << " used basic attack and did " << damage2 << " amounts of damage!!" << endl;
    cout << "--------------------------------------------------" << endl;
    return damage; 
}

int Player::calculateDmgRecieved(int monstersAttack){
    int damageRecieved = 0; 
    damageRecieved = monstersAttack - health; 
    this->health -= damageRecieved; 
    return damageRecieved; 
}

/*
int Player::castSpell(int spellNum, int monsterDefense){
    for(int i = 0; i < currentSpells; i++){
        if(spellNum == i){
            cout << "Player used " << playerSpells[i]->getSpellName() << endl; 
            if (i % 2 == 0){
                int spellDamage = 0;
                spellDamage = playerSpells[i]->getSpellAttack() - monsterDefense; 
                return spellDamage;
                break; 
            }else if (i % 2 != 0){
                health = health + playerSpells[i]->getSpellDefense(); 
                return health;
                break; 
            }

        }
    }
    cout << "--------------------------------------------------" << endl;
}
*/

int Player::drinkPotion(){
    health += 100;
    cout << "Player healed up by 100hp!!" << endl; 
    return health;
    cout << "--------------------------------------------------" << endl;
}








