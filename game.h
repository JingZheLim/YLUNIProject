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
#include "waterMonster.h"
#include "FireJourney.h"

using namespace std;

// note to Yaline
/* I have implemented the the introduction when the user selects their element,
 * currently only water will run through the entire game. idk if you want the
 * make the battle system into a class or keep it like how it is, currently it
 * is on 850+ lines and if we do it for the other elements this will triple to
 * over 2,550 lines of code. I have manually tested that each battle works but
 * not sure how to document it, makefile is there but doesn't do anything at the
 * moment, you are free to delete or do something about it and test it however
 * you want it. The battle system works for the local values I have created at
 * around line 70 make sure to delete and reimplement with your player class. I
 * have NOT implemented the spells menu and the segways lines between each
 * fight. Currently the elementalDragon does not work properly will try to fix
 * tmrw, its using the monsters attacks but not using its own attributes */

class game : menu {

 public:
  void run() {  // starts the entire game

    if (get_userChoice() == 1) {  // if 1 start the game
      system("clear");            // clears terminal
      menuElement();
      // move into different storylines for the different elements
      if (get_userChoice() == 1) {  // Water (creates the object)


      } else if (get_userChoice() == 2) {  // Earth
        system("clear");
        cout << "                      GAME START                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "The earth kingdom is sick and tired of everyone fighting "
                "because of the evil Dragon\'s powers and chaos it creates so "
                "you must help your kingdom to defeat it and restore peace "
                "for "
                "everyone."
             << endl;
        cout << "However you must also defeat the other elements\' monsters "
                "in "
                "order to become powerful enough to take on the dragon."
             << endl;
        cout << "You are a wise earth elder. " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "What is your name wise elder??" << endl;
        cout << "My name is: " << endl;
        // cin << playerName;

        // blah blah stuff happens
        // battle Air Monster

        // blah blah stuff happens
        // battle Water Monster

        // blah blah stuff happens
        // battle Fire Monster

        // blah blah stuff happens
        // battle Random? Monster

        // blah blah stuff happens
        // battle Elemental Dragon

      } else if (get_userChoice() == 3) {  // Fire
          FireJourney OOP; 
          OOP.run2(); 
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

        // blah blah stuff happens
        // battle Water Monster

        // blah blah stuff happens
        // battle Fire Monster

        // blah blah stuff happens
        // battle Earth Monster

        // blah blah stuff happens
        // battle Random? Monster

        // blah blah stuff happens
        // battle Elemental Dragon
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