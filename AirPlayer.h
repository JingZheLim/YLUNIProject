#ifndef AIRPLAYER_H
#define AIRPLAYER_H
#include "Player.h"

class AirPlayer: public Player {

    private:
    int windSlash = 100; // Extra earth attack

    public: 
    // default constructor: 
    AirPlayer(); 

    // Extra water class attack (Not a spell)
    int useWindSlash(int monsterDefense); 

    virtual int drinkPotion(); 

};
#endif 