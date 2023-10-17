#ifndef WATERPLAYER_H
#define WATERPLAYER_H
#include "Player.h"

class WaterPlayer: public Player {

    private:
    int waterFlood = 100; // Extra water attack

    public: 
    // default constructor: 
    WaterPlayer(); 

    // Extra water class attack (Not a spell)
    int useWaterFlood(int monsterDefense); 

    int getWaterAtkSpell();

    int getWaterDefSpell();

    // basic attack; 
    virtual int drinkPotion();

};
#endif 