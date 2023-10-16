#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;

class menu {
 protected:
  int userChoice;

 public:
  menu() {  // shows the main menu in the terminal
    cout << " _________________________________________________" << endl;
    cout << "|  Welcome to: \"Elementals\" the Adventure Game!!|" << endl;
    cout << "|                                                 |" << endl;
    cout << "|        Start(1)   Continue(2)   End(3)          |" << endl;
    cout << "|_________________________________________________|" << endl;
    // get user to input a number to continue
    cout << "Enter a number: ";
    cin >> userChoice;
    // if user enters number not 1, 2 or 3 try again
    while (userChoice < 1 || userChoice > 3) {
      cout << "Enter a valid number(1 or 2 or 3): ";
      cin >> userChoice;
    }
    cout << "--------------------------------------------------" << endl;
  };

  void menuElement() {  // menu for selecting the player's element
    cout << " _________________________________________________" << endl;
    cout << "|               Choose your Element!              |" << endl;
    cout << "|     Water(1)   Earth(2)   Fire(3)   Air(4)      |" << endl;
    cout << "|_________________________________________________|" << endl;
    cout << "*You will experience different stories depending on the element "
            "you choose*"
         << endl;
    // get user to input a number to continue
    cout << "Enter a number: ";
    cin >> userChoice;
    // if user enters number not 1, 2, 3 or 4 try again
    while (userChoice < 1 || userChoice > 4) {
      cout << "Enter a valid number(1 or 2 or 3 or 4): ";
      cin >> userChoice;
    }
    cout << "--------------------------------------------------" << endl;
  }

  void menuFight() {  // menu when fighting monsters and dragon
    cout << " _________________________________________________" << endl;
    cout << "|                    Your Turn!                   |" << endl;
    cout << "|   Basic Attack(1)   Spells(2)   Use Potion(3)   |" << endl;
    cout << "|_________________________________________________|" << endl;
    // get user to input a number to continue
    cout << "Enter a number: ";
    cin >> userChoice;
    // if user enters number not 1, 2 or 3 try again
    while (userChoice < 1 || userChoice > 3) {
      cout << "Enter a valid number(1 or 2 or 3): ";
      cin >> userChoice;
    }
    cout << "--------------------------------------------------" << endl;
  }

  void menuFightNP() {  // menu when fighting monsters and dragon (health
                        // potions when you have none)
    cout << " _________________________________________________" << endl;
    cout << "|                    Your Turn!                   |" << endl;
    cout << "|       Basic Attack(1)        Spells(2)          |" << endl;
    cout << "|_________________________________________________|" << endl;

    // get user to input a number to continue
    cout << "Enter a number: ";
    cin >> userChoice;
    // if user enters number not 1 or 2 try again
    while (userChoice < 1 || userChoice > 2) {
      cout << "Enter a valid number(1 or 2): ";
      cin >> userChoice;
    }
    cout << "--------------------------------------------------" << endl;
  }

    // This menu is to show the extra ability gained after defeating the 4th monster
    // Fire: Fire Strike
    // Air: Wind Slash
    // Earth: Ground Shake
    // Water: Water Flood
    void menuFightNPS() {  // menu when fighting monsters and dragon (health
                        // potions when you have none) Special 
    cout << " _________________________________________________" << endl;
    cout << "|                    Your Turn!                   |" << endl;
    cout << "|       Basic Attack(1)       Spells(2)           |" << endl;
    cout << "|                Special Ability (3)              |" << endl;  
    cout << "|_________________________________________________|" << endl;

    // get user to input a number to continue
    cout << "Enter a number: ";
    cin >> userChoice;
    // if user enters number not 1 or 2 try again
    while (userChoice < 1 || userChoice > 3) {
      cout << "Enter a valid number(1, 2, 3): ";
      cin >> userChoice;
    }
    cout << "--------------------------------------------------" << endl;
  }

    // This menu is to show the extra ability gained after defeating the 4th monster
    // Fire: Fire Strike
    // Air: Wind Slash
    // Earth: Ground Shake
    // Water: Water Flood
    void menuFightSpecial() {  // menu when fighting monsters and dragon
    cout << " _________________________________________________" << endl;
    cout << "|                    Your Turn!                   |" << endl;
    cout << "|   Basic Attack(1)   Spells(2)   Use Potion(3)   |" << endl;
    cout << "|                 Special Ability (4)             |" << endl; 
    cout << "|_________________________________________________|" << endl;
    // get user to input a number to continue
    cout << "Enter a number: ";
    cin >> userChoice;
    // if user enters number not 1, 2, 3 or 4 try again
    while (userChoice < 1 || userChoice > 4) {
      cout << "Enter a valid number(1, 2, 3, 4): ";
      cin >> userChoice;
    }
    cout << "--------------------------------------------------" << endl;
  }

  // menu to showcase the array of spells
  void menuSpell(){
    cout << " _________________________________________________" << endl;
    cout << "|      Do you want defense or attack spells?      |" << endl;
    cout << "|                                                 |" << endl; 
    cout << "|      Attack Spell(1)      Defense Spell(2)      |" << endl;
    cout << "|_________________________________________________|" << endl;

    // prompt for user input
    cout << "Enter a number: ";
    cin >> userChoice; 
    // if user enters number not 1 or 2, try again
    while (userChoice < 1 || userChoice > 2) {
      cout << "Enter a valid number(1 or 2): "; 
      cin >> userChoice; 
    }
    cout << "--------------------------------------------------" << endl;
  }

  int get_userChoice() { return userChoice; };
};

#endif
