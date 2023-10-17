#ifndef EARTHPLAYER_H
#define EARTHPLAYER_H
#include "Player.h"

class EarthPlayer: public Player {

    private:
    int groundShake = 100; // Extra earth attack

    public: 
    // default constructor: 
    EarthPlayer(); 

    // Extra earth class attack (Not a spell)
    int useGroundShake(int monsterDefense); 

    int getEarthAtkSpell();

    int getEarthDefSpell(); 

    virtual int drinkPotion(); 

};
#endif 