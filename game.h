#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>

#include "airMonster.h"
#include "earthMonster.h"
#include "elementalDragon.h"
#include "fireMonster.h"
#include "menu.h"
#include "monster.h"
#include "waterMonster.h"

using namespace std;

class game : menu {
 public:
  void run() {  // starts the entire game

    // when run the menu will first be displayed
    // types number in terminal
    // if 1 start the game
    if (get_userChoice() == 1) {
      menuElement();
      // move into different storylines for the different elements
      if (get_userChoice() == 1) {
        // Water
        system("clear");  // clears terminal
        cout << "                       GAME START                    " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "The water kingdom is going through a drought because of the "
                "increasing temperatures."
             << endl;
        cout << "The cause of the temperatures is because of the evil Dragon "
                "that terrorizes their kingdom by breathing fire onto their "
                "homes and structures and causing chaos."
             << endl;
        cout << "You must defeat the dragon to get rid of the drought that is "
                "plaguing your kingdom."
             << endl;
        cout << "You are a brave water mage." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "What is your name brave mage?" << endl;
        cout << "My name is: " << endl;
        // cin << playerName;
      } else if (get_userChoice() == 2) {
        // Earth
      } else if (get_userChoice() == 3) {
        // Fire
      } else if (get_userChoice() == 4) {
        // Air
      }
    }
    // else if 2 use save file
    else if (get_userChoice() == 2) {
      cout << "Does nothing for now" << endl;
    }
    // else if 3 end the game
    else if (get_userChoice() == 3) {
      cout << "Thanks for Playing!!" << endl;
      return;
    }
  };
};

#endif