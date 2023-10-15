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

using namespace std;

class game : menu {
 private:
  int currentHealth;
  int randNumber;
  string playerName;

  // creating the objects for monsters
  // waterMonster WaterMonsters;
  fireMonster FireMonsters;
  earthMonster EarthMonsters;
  airMonster AirMonsters;

 public:
  void run() {  // starts the entire game

    // when run the menu will first be displayed
    // types number in terminal

    if (get_userChoice() == 1) {  // if 1 start the game
      system("clear");            // clears terminal
      menuElement();
      // move into different storylines for the different elements
      if (get_userChoice() == 1) {  // Water (creates the object)
        system("clear");
        cout << "                      GAME START                     " << endl;
        cout << "--------------------------------------------------" << endl;
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
        cout << "--------------------------------------------------" << endl;
        cout << "What is your name brave mage?" << endl;
        cout << "My name is: ";
        cin >> playerName;  // inputs users name

        int tempPotions = 5;  // get rid of these after
        int pDefence = 30;
        int pAttack = 100;
        currentHealth = 100;
        int mana = 100;
        int spellDmg = 25;
        int damageDealt;
        cout << "---------------------------" << endl;
        cout << "blah blah stuff happens" << endl;

        // battle Air Monster
        cout << "--------------------------------------------------" << endl;
        cin.get();
        cout << "Press Enter to Continue..." << endl;
        cin.get();  // pauses and waits for user to press enter to continue
        system("clear");
        int turn;
        randNumber = rand() % 50;
        cout << "                    BATTLE START                   " << endl;
        cout << "--------------------------------------------------" << endl;
        if (randNumber % 2 == 0) {
          turn = 0;  // Player starts first
        } else {
          turn = 1;  // Monster starts first
        }

        while (currentHealth > 0 && AirMonsters.get_airHealth() > 0) {
          if (turn % 2 == 0) {       // players turn
            if (tempPotions >= 1) {  // if have potion display normal menu

              cout << "HP: " << currentHealth  // REPLACE 100 WITH USERS HP AND
                                               // MANA AND HEALTHPOTS
                   << "         Mana: " << mana
                   << "        Health Potions: " << tempPotions << endl;
              menuFight();
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = AirMonsters.damageRecieved(pAttack);
                cout << playerName << "\'s basic attack did " << damageDealt
                     << " damage to " << AirMonsters.get_airName() << "!!"
                     << endl;
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                if (mana < 100) {  // gain mana
                  mana += 15;
                  if (mana > 100) {  // doesn't go above max mana
                    mana = 100;
                  }
                }

              } else if (get_userChoice() == 2) {  // Spells
                // display spells (uses mana)
                // make sure player has enough mana for the spell
                if (mana >= 20 /*requied mana*/) {  // cast spell
                  damageDealt = AirMonsters.damageRecieved(pAttack + spellDmg);
                  cout << playerName << " casted a spell and did "
                       << damageDealt << " damage to "
                       << AirMonsters.get_airName() << "!!" << endl;
                  cout << AirMonsters.get_airName() << " has "
                       << AirMonsters.get_airHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  mana -= 20;
                } else {  // if not enough
                  cout << "You do not have enough mana to cast this spell!"
                       << endl;
                  cout << "--------------------------------------------------"
                       << endl;
                  turn++;  // gets turn back
                }

              } else if (get_userChoice() ==
                         3) {  // Use health potion (heals 50 HP)
                               // use health potion if have
                cout << playerName << " used a health potion" << endl;
                cout << "--------------------------------------------------"
                     << endl;
                tempPotions--;
                currentHealth += 50;
                if (currentHealth > 100) {
                  currentHealth = 100;
                }
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << currentHealth  // REPLACE 100 WITH USERS HP AND
                                               // MANA AND HEALTHPOTS
                   << "         Mana: " << mana
                   << "        Health Potions: " << tempPotions << endl;
              menuFightNP();
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy player ATK
                damageDealt = AirMonsters.damageRecieved(pAttack);
                cout << playerName << "\'s basic attack did " << damageDealt
                     << " damage to " << AirMonsters.get_airName() << "!!"
                     << endl;
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

              } else if (get_userChoice() == 2) {  // Spells
                // display spells (uses mana)
                // make sure player has enough mana for the spell
                if (mana > 20 /*requied mana*/) {  // cast spell
                  damageDealt = AirMonsters.damageRecieved(pAttack + spellDmg);
                  cout << playerName << " casted a spell and did "
                       << damageDealt << " damage to "
                       << AirMonsters.get_airName() << "!!" << endl;
                  cout << AirMonsters.get_airName() << " has "
                       << AirMonsters.get_airHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  mana -= 20;
                } else {  // if not enough
                  cout << "You do not have enough mana to cast this spell!"
                       << endl;
                  cout << "--------------------------------------------------"
                       << endl;
                  turn++;  // gets turn back
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= AirMonsters.attack(pDefence);
          }
          turn++;

          if (currentHealth <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;

          } else if (AirMonsters.get_airHealth() <= 0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        cin.get();
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "blah blah stuff happens" << endl;
        cout << "--------------------------------------------------" << endl;

        // battle Earth Monster
        cout << "Press Enter to Continue..." << endl;
        cin.get();  // pauses and waits for user to press enter to continue
        system("clear");
        randNumber = rand() % 50;
        cout << "                    BATTLE START                   " << endl;
        cout << "--------------------------------------------------" << endl;
        if (randNumber % 2 == 0) {
          turn = 0;  // Player starts first
        } else {
          turn = 1;  // Monster starts first
        }

        while (currentHealth > 0 && EarthMonsters.get_earthHealth() > 0) {
          if (turn % 2 == 0) {       // players turn
            if (tempPotions >= 1) {  // if have potion display normal menu

              cout << "HP: " << currentHealth  // REPLACE 100 WITH USERS HP AND
                                               // MANA AND HEALTHPOTS
                   << "         Mana: " << mana
                   << "        Health Potions: " << tempPotions << endl;
              menuFight();
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = EarthMonsters.damageRecieved(pAttack);
                cout << playerName << "\'s basic attack did " << damageDealt
                     << " damage to " << EarthMonsters.get_earthName() << "!!"
                     << endl;
                cout << EarthMonsters.get_earthName() << " has "
                     << EarthMonsters.get_earthHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                if (mana < 100) {  // gain mana
                  mana += 15;
                  if (mana > 100) {  // doesn't go above max mana
                    mana = 100;
                  }
                }

              } else if (get_userChoice() == 2) {  // Spells
                // display spells (uses mana)
                // make sure player has enough mana for the spell
                if (mana >= 20 /*requied mana*/) {  // cast spell
                  damageDealt =
                      EarthMonsters.damageRecieved(pAttack + spellDmg);
                  cout << playerName << " casted a spell and did "
                       << damageDealt << " damage to "
                       << EarthMonsters.get_earthName() << "!!" << endl;
                  cout << EarthMonsters.get_earthName() << " has "
                       << EarthMonsters.get_earthHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  mana -= 20;
                } else {  // if not enough
                  cout << "You do not have enough mana to cast this spell!"
                       << endl;
                  cout << "--------------------------------------------------"
                       << endl;
                  turn++;  // gets turn back
                }

              } else if (get_userChoice() ==
                         3) {  // Use health potion (heals 50 HP)
                               // use health potion if have
                cout << playerName << " used a health potion" << endl;
                cout << "--------------------------------------------------"
                     << endl;
                tempPotions--;
                currentHealth += 50;
                if (currentHealth > 100) {
                  currentHealth = 100;
                }
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << currentHealth  // REPLACE 100 WITH USERS HP AND
                                               // MANA AND HEALTHPOTS
                   << "         Mana: " << mana
                   << "        Health Potions: " << tempPotions << endl;
              menuFightNP();
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy player ATK
                damageDealt = EarthMonsters.damageRecieved(pAttack);
                cout << playerName << "\'s basic attack did " << damageDealt
                     << " damage to " << EarthMonsters.get_earthName() << "!!"
                     << endl;
                cout << EarthMonsters.get_earthName() << " has "
                     << EarthMonsters.get_earthHealth() << " health" << endl;
                cout << "---------------------------" << endl;

              } else if (get_userChoice() == 2) {  // Spells
                // display spells (uses mana)
                // make sure player has enough mana for the spell
                if (mana > 20 /*requied mana*/) {  // cast spell
                  damageDealt =
                      EarthMonsters.damageRecieved(pAttack + spellDmg);
                  cout << playerName << " casted a spell and did "
                       << damageDealt << " damage to "
                       << EarthMonsters.get_earthName() << "!!" << endl;
                  cout << EarthMonsters.get_earthName() << " has "
                       << EarthMonsters.get_earthHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  mana -= 20;
                } else {  // if not enough
                  cout << "You do not have enough mana to cast this spell!"
                       << endl;
                  cout << "--------------------------------------------------"
                       << endl;
                  turn++;  // gets turn back
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= EarthMonsters.attack(pDefence);
          }
          turn++;

          if (currentHealth <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;

          } else if (EarthMonsters.get_earthHealth() <= 0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        cin.get();
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "blah blah stuff happens" << endl;
        cout << "--------------------------------------------------" << endl;

        // battle Fire Monster
        cout << "Press Enter to Continue..." << endl;
        cin.get();  // pauses and waits for user to press enter to continue
        system("clear");
        randNumber = rand() % 50;
        cout << "                    BATTLE START                   " << endl;
        cout << "--------------------------------------------------" << endl;
        if (randNumber % 2 == 0) {
          turn = 0;  // Player starts first
        } else {
          turn = 1;  // Monster starts first
        }
        while (currentHealth > 0 && FireMonsters.get_fireHealth() > 0) {
          if (turn % 2 == 0) {       // players turn
            if (tempPotions >= 1) {  // if have potion display normal menu

              cout << "HP: " << currentHealth  // REPLACE 100 WITH USERS HP AND
                                               // MANA AND HEALTHPOTS
                   << "         Mana: " << mana
                   << "        Health Potions: " << tempPotions << endl;
              menuFight();
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = FireMonsters.damageRecieved(pAttack);
                cout << playerName << "\'s basic attack did " << damageDealt
                     << " damage to " << FireMonsters.get_fireName() << "!!"
                     << endl;
                cout << FireMonsters.get_fireName() << " has "
                     << FireMonsters.get_fireHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                if (mana < 100) {  // gain mana
                  mana += 15;
                  if (mana > 100) {  // doesn't go above max mana
                    mana = 100;
                  }
                }

              } else if (get_userChoice() == 2) {  // Spells
                // display spells (uses mana)
                // make sure player has enough mana for the spell
                if (mana >= 20 /*requied mana*/) {  // cast spell
                  damageDealt = FireMonsters.damageRecieved(pAttack + spellDmg);
                  cout << playerName << " casted a spell and did "
                       << damageDealt << " damage to "
                       << FireMonsters.get_fireName() << "!!" << endl;
                  cout << FireMonsters.get_fireName() << " has "
                       << FireMonsters.get_fireHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  mana -= 20;
                } else {  // if not enough
                  cout << "You do not have enough mana to cast this spell!"
                       << endl;
                  cout << "--------------------------------------------------"
                       << endl;
                  turn++;  // gets turn back
                }

              } else if (get_userChoice() ==
                         3) {  // Use health potion (heals 50 HP)
                               // use health potion if have
                cout << playerName << " used a health potion" << endl;
                cout << "--------------------------------------------------"
                     << endl;
                tempPotions--;
                currentHealth += 50;
                if (currentHealth > 100) {
                  currentHealth = 100;
                }
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << currentHealth  // REPLACE 100 WITH USERS HP AND
                                               // MANA AND HEALTHPOTS
                   << "         Mana: " << mana
                   << "        Health Potions: " << tempPotions << endl;
              menuFightNP();
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy player ATK
                damageDealt = FireMonsters.damageRecieved(pAttack);
                cout << playerName << "\'s basic attack did " << damageDealt
                     << " damage to " << FireMonsters.get_fireName() << "!!"
                     << endl;
                cout << FireMonsters.get_fireName() << " has "
                     << FireMonsters.get_fireHealth() << " health" << endl;
                cout << "---------------------------" << endl;

              } else if (get_userChoice() == 2) {  // Spells
                // display spells (uses mana)
                // make sure player has enough mana for the spell
                if (mana > 20 /*requied mana*/) {  // cast spell
                  damageDealt = FireMonsters.damageRecieved(pAttack + spellDmg);
                  cout << playerName << " casted a spell and did "
                       << damageDealt << " damage to "
                       << FireMonsters.get_fireName() << "!!" << endl;
                  cout << FireMonsters.get_fireName() << " has "
                       << FireMonsters.get_fireHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  mana -= 20;
                } else {  // if not enough
                  cout << "You do not have enough mana to cast this spell!"
                       << endl;
                  cout << "--------------------------------------------------"
                       << endl;
                  turn++;  // gets turn back
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= FireMonsters.attack(pDefence);
          }
          turn++;

          if (currentHealth <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;

          } else if (FireMonsters.get_fireHealth() <= 0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // blah blah stuff happens
        // battle Random? Monster

        // blah blah stuff happens
        // battle Elemental Dragon
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

        // blah blah stuff happens
        // battle Air Monster

        // blah blah stuff happens
        // battle Earth Monster

        // blah blah stuff happens
        // battle Water Monster

        // blah blah stuff happens
        // battle Random? Monster

        // blah blah stuff happens
        // battle Elemental Dragon
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