#ifndef GAME_H
#define GAME_H
#include <cstdlib>   // rand()
#include <iostream>  // input output
#include <string>    // strings

#include "airMonster.h"
#include "earthMonster.h"
#include "elementalDragon.h"
#include "fireMonster.h"
#include "menu.h"
#include "monster.h"
// Journey header files ( for storyline )
#include "waterMonster.h"
#include "FireJourney.h"
#include "EarthJourney.h"
#include "WaterJourney.h"
#include "AirJourney.h"

using namespace std;

class game : menu {

 public:
  void run() {  // starts the entire game
  menuStart();
    if (get_userChoice() == 1) {  // if 1 start the game
      system("clear");            // clears terminal

      menuElement();
      // Depending on user input, storyline follows either Water, Earth, Fire, Air

      if (get_userChoice() == 1) { // Water 
          WaterJourney OOP;
          OOP.run();  
      
      } else if (get_userChoice() == 2) {  // Earth 
          EarthJourney OOP;
          OOP.run(); 
       
      } else if (get_userChoice() == 3) {  // Fire 
          FireJourney OOP; 
          OOP.run(); 

      } else if (get_userChoice() == 4) { // Air
          AirJourney OOP;
          OOP.run();

      }
    }

    // Else if the player enters 2, the files will be saved 
    else if (get_userChoice() == 2) {  
      system("clear");                 // clears terminal
      cout << "Does nothing for now" << endl;
    }

    // Else if the player enters 3, the game will end (close)
    else if (get_userChoice() == 3) {  
      system("clear");                 // clears terminal
      cout << "Thanks for Playing!!" << endl;
      return;
    }
  }; // End of run() function 
  
};

#endif