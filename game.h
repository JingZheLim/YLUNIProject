#ifndef GAME_H
#define GAME_H
#include <cstdlib>  // rand()
#include <fstream>
#include <iostream>  // input output
#include <string>    // strings

#include "AirPlayer.h"
#include "EarthPlayer.h"
#include "FirePlayer.h"
#include "WaterPlayer.h"
#include "airMonster.h"
#include "earthMonster.h"
#include "elementalDragon.h"
#include "fireMonster.h"
#include "menu.h"
#include "monster.h"
#include "waterMonster.h"
// Journey header files ( for storyline )
#include "AirJourney.h"
#include "EarthJourney.h"
#include "FireJourney.h"
#include "WaterJourney.h"
#include "gameState.h"

using namespace std;

class game : menu {
 private:
  WaterJourney wOOP;
  EarthJourney eOOP;
  FireJourney fOOP;
  AirJourney aOOP;

 public:
  game() {}
  void loadGame() {  // loads game
    gameState state;
  }

  void run() {  // starts the entire game
    menuStart();
    if (get_userChoice() == 1) {  // if 1 start the game
      system("clear");            // clears terminal

      menuElement();
      // Depending on user input, storyline follows either Water, Earth, Fire,
      // Air

      if (get_userChoice() == 1) {  // Water
        wOOP.run(300, 5, "", 0);

      } else if (get_userChoice() == 2) {  // Earth
        eOOP.run(300,5,"",0);

      } else if (get_userChoice() == 3) {  // Fire
        fOOP.run(250, 5, "", 0);

      } else if (get_userChoice() == 4) {  // Air
        aOOP.run(250,5,"",0);
      }
    }

    // Else if the player enters 2, the files will be saved
    else if (get_userChoice() == 2) {
      int tempHealth;
      int tempPotion;
      int journey;
      int stage;
      string tempName;
      system("clear");  // clears terminal
      ifstream input("save.dat");
      input >> tempHealth;
      input >> tempPotion;
      input >> journey;
      input >> stage;
      input >> tempName;

      if (journey == 1) {  // run water journey
        wOOP.run(tempHealth, tempPotion, tempName, stage);
      } else if (journey == 2) {  // run earth journey
        eOOP.run(tempHealth, tempPotion, tempName, stage);
      } else if (journey == 3) {  // run fire journey
        fOOP.run(tempHealth, tempPotion, tempName, stage);
      } else if (journey == 4) {  // run air journey
        aOOP.run(tempHealth, tempPotion, tempName, stage);
      }
    }

    // Else if the player enters 3, the game will end (close)
    else if (get_userChoice() == 3) {
      system("clear");  // clears terminal
      cout << "Thanks for Playing!!" << endl;
      return;
    }
  };  // End of run() function
};

#endif