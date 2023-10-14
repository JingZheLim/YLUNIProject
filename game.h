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

    if (get_userChoice() == 1) {  // if 1 start the game
      system("clear");            // clears terminal
      menuElement();
      // move into different storylines for the different elements
      if (get_userChoice() == 1) {  // Water
        system("clear");
        cout << "                      GAME START                     " << endl;
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
      } else if (get_userChoice() == 2) {  // Earth
        system("clear");
        cout << "                      GAME START                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "The earth kingdom is sick and tired of everyone fighting "
                "because of the evil Dragon\'s powers and chaos it creates so "
                "you must help your kingdom to defeat it and restore peace for "
                "everyone."
             << endl;
        cout << "However you must also defeat the other elements\' monsters in "
                "order to become powerful enough to take on the dragon."
             << endl;
        cout << "You are a wise earth elder. " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "What is your name wise elder??" << endl;
        cout << "My name is: " << endl;
        // cin << playerName;
      } else if (get_userChoice() == 3) {  // Fire
        system("clear");
        cout << "                      GAME START                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Your kingdom is hungry for power over the other kingdoms and "
                "has set you on an adventure to defeat the almighty dragon so "
                "you can learn other kingdoms\' spells."
             << endl;
        cout << "This will set your kingdom above the others." << endl;
        cout << "You are a fire warrior." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "What is your name warrior?" << endl;
        cout << "My name is: " << endl;
        // cin << playerName;
      } else if (get_userChoice() == 4) {  // Air
        system("clear");
        cout << "                      GAME START                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "You gained inside intel that the fire kingdom is trying to "
                "gain power over other kingdoms by sending someone to defeat "
                "the dragon."
             << endl;
        cout << "In order to prevent the fire kingdom from gaining too much "
                "power and causing chaos themselves, you must defeat the "
                "dragon yourself to protect everyone from the fire kingdom."
             << endl;
        cout << "You are a lone air adventurer." << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "What is your name adventurer?" << endl;
        cout << "My name is: " << endl;
        // cin << playerName;
      }
    }

    else if (get_userChoice() == 2) {  // else if 2 use save file
      system("clear");                 // clears terminal
      cout << "Does nothing for now" << endl;
    }

    else if (get_userChoice() == 3) {  // else if 3 end the game
      system("clear");                 // clears terminal
      cout << "Thanks for Playing!!" << endl;
      return;
    }
  };
};

#endif