#include "airMonster.h"

#include <iostream>
#include <string>

#include "monster.h"
using namespace std;

airMonster::airMonster() {
  this->mHealth = 100;
  this->mAttack = 50;
  this->mDefence = 50;
  this->mName = "Amaya";
  this->mAtkType = "Feather Dance";
  this->atkUp = 5;
}
int airMonster::calculateDmgDone() {

}
int airMonster::damageRecieved() {}
void airMonster::attack() {
        cout << this->mName << "used " << this->mAtkType << "and did " << calculateDmgDone() << "amounts of damage!!" << endl;
}