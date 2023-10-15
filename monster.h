#ifndef MONSTER_H
#define MONSTER_H
#include <string>
using namespace std;

class monster{

    protected:
    int mHealth = 0;
    int mAttack = 0;
    int mDefence = 0;
    string mName = " ";
    string mAtkType = " ";

    public:
    virtual int damageRecieved(int playersAttack) = 0;
    virtual int attack(int playersDefence) = 0;  

};


#endif