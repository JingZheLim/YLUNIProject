#ifndef EARTHMONSTER_H
#define EARTHMONSTER_H
#include <string>
using namespace std;
#include <iostream>
#include "monster.h"


class earthMonster : public monster {
    protected:
    int defUp;
    public:
    earthMonster();
    int calculateDmgDone();
    int damageRecieved();
    void attack();  

};

#endif