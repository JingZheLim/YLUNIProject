#include "Player.h"
#include "Spell.h"
#include "monster.h"
#include <iostream>
#include <string>

using namespace std

Player::Player(){
    playerName = "";
    health = 0;
    attack = 0;
    defense = 0; 
    healthPotion = 0; 
    currentSpells = 0;
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
    int damage = 0;
    damage = attack - monsterDefense; 
    cout << this->playerName << " used basic attack and did " << damage << " amounts of damage!!" << endl;
    cout << "--------------------------------------------------" << endl;
    return damage; 
}

int Player::calculateDmgRecieved(int monstersAttack){
    int damageRecieved = 0; 
    damageRecieved = monstersAttack - health; 
    this->health -= damageRecieved; 
    return damageRecieved; 
}


int Player::castSpell(int spellNum, int monsterDefense){
    for(int i = 0; i < currentSpells; i++){
        if(spellNum == i){
            cout << "Player used " << playerSpells[i]->getSpellName() << endl; 
            if (i % 2 == 0){
                int spellDamage = 0;
                spellDamage = playerSpells[i]->getSpellAttack() - monsterDefense; 
                return spellDamage; 
            }else if (i % 2 != 0){
                health = health + playerSpells[i]->getSpellDefense(); 
                return health; 
            }

        }
    }
    cout << "--------------------------------------------------" << endl;
}

int Player::drinkPotion(){
    health += 30;
    cout << "Player healed up by 30hp!!" << endl; 
    return health;
    cout << "--------------------------------------------------" << endl;
}

// Virtual function
void Player::basicAttack(){
    cout << " " << endl; 
}







