#ifndef AIRMONSTER_H
#define AIRMONSTER_H
#include <string>
using namespace std;
#include <iostream>


class airMonster : public monster {
 protected:
  int atkUp;

 public:
  airMonster();
  int calculateDmgDone();
  int damageRecieved();
  void attack();
};

#endif