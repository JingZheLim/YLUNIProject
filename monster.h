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
    virtual int calculateDmgDone() = 0;
    virtual int damageRecieved() = 0;
    virtual void attack() = 0;  

};


#endif