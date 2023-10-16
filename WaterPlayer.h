#ifndef WATERPLAYER_H
#define WATERPLAYER_H
#include "Player.h"

class WaterPlayer: public Player {

    private:
    int waterFlood = 20; // Extra water attack

    public: 
    // default constructor: 
    WaterPlayer(); 

    // Extra water class attack (Not a spell)
    int waterFlood(int monsterDefense); 

    // basic attack; 
    virtual void basicAttack();

};
#endif 