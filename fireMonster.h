#ifndef FIREMONSTER_H
#define FIREMONSTER_H
#include <string>
using namespace std;
#include <iostream>
#include "monster.h"



class fireMonster  : public monster {
    protected:
    int burnDamage;

    public:
    fireMonster();
    int calculateDmgDone();
    int damageRecieved();
    void attack();  

};

#endif