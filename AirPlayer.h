#ifndef AIRPLAYER_H
#define AIRPLAYER_H
#include "Player.h"

class AirPlayer: public Player {

    private:
    int windSlash = 150; // Extra earth attack

    public: 
    // default constructor: 
    AirPlayer(); 

    // Extra water class attack (Not a spell)
    int useWindSlash(int monsterDefense); 

    int getAirAtkSpell();

    int getAirDefSpell(); 

    virtual int drinkPotion(); 

};
#endif 