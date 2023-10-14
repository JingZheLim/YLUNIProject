#include "waterMonster.h"
#include <string>
#include <iostream>
#include "elementalDragon.h"

int main(){
    waterMonster wMonster;
    elementalDragon dragon;

    wMonster.attack();
    dragon.damageRecieved();
    dragon.attack();
    wMonster.damageRecieved();
    
}