#include "fireMonster.h"

#include "monster.h"
#include <string>
#include <iostream>
using namespace std;

fireMonster::fireMonster() {
    this->mHealth = 100;
    this->mAttack = 65;
    this->mDefence = 35;
    this->mName = "Blazair";
    this->mAtkType = "Fire Tornado";
    this->burnDamage = 5;
}
int fireMonster::calculateDmgDone() {}
int fireMonster::damageRecieved() {}
void fireMonster::attack() {
        cout << this->mName << "used " << this->mAtkType << "and did " << calculateDmgDone() << "amounts of damage!!" << endl;
}