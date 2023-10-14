#ifndef MENU_H
#define MENU_H
#include <iostream>

class menu {
 protected:
  int userChoice;

 public:
  menu() {  // shows the main menu in the terminal
    cout << " _________________________________________________" << endl;
    cout << "|  Welcome to: \"Elementals\" the Adventure Game!!  |" << endl;
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

    // menu for selecting the player's element
  void menuElement() {
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

  int get_userChoice() { return userChoice; };
};

#endif
