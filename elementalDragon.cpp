#include "monster.h"
#include "airMonster.h"
#include "earthMonster.h"
#include "fireMonster.h"
#include "waterMonster.h"
#include "elementalDragon.h"
#include <string>

elementalDragon::elementalDragon(){
    this->dragonHealth = 400;
    this->dragonAttack = 100;
    this->dragonDefence = 100;
    this->dragonName = "Elegon";
}

int elementalDragon::calculateDmgDone() {
    return dragonAttack-waterMonster::mDefence;
}
int elementalDragon::damageRecieved() {
  int currentmHealth = dragonHealth;
  int damage = waterMonster::calculateDmgDone();
  this->dragonHealth = currentmHealth - damage;
  cout << dragonName <<" has " << dragonHealth << " health left."<< endl;
}
void elementalDragon::attack() {
    cout << this->dragonName << " used " << waterMonster::mAtkType << " and did " << calculateDmgDone() << " amounts of damage!!" << endl;
    

}
