#ifndef AIRJOURNEY_H
#define AIRJOURNEY_H
#include <cstdlib>   // rand()
#include <iostream>  // input output
#include <string>    // strings

#include "AirPlayer.h"
#include "Spell.h"
#include "airMonster.h"
#include "earthMonster.h"
#include "elementalDragon.h"
#include "fireMonster.h"
#include "game.h"
#include "gameState.h"
#include "menu.h"
#include "monster.h"
#include "waterMonster.h"

using namespace std;

class AirJourney {
 private:
  // Randomizer
  int randNumber;
  string playerName;
  int damageDealt;
  int currentHealth;
  int ogDef;
  int playerStage = 0;
  int playerJourney = 4;
  menu Menu;

  // creating the objects for monsters
  waterMonster WaterMonsters;
  fireMonster FireMonsters;
  earthMonster EarthMonsters;
  airMonster AirMonsters;
  elementalDragon ElementalDragon;

  // create air player object
  // Attributes: playerName, health, attack, defense, healthPotion
  AirPlayer player;

  // initialise game state
  gameState saved;

 public:
  void run(int health, int potion, string name,
           int level) {  // starts the entire game
    player.setPlayerName(playerName);
    currentHealth = player.getHealth();
    ogDef = player.getDefense();
    switch (level) {
      case 0:
        // save checkpoint 0
        playerStage = 0;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);
        system("clear");
        cout << "                      GAME START                     " << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "You gained inside intel that the fire kingdom is trying to "
                "gain power over other kingdoms by sending someone to defeat "
                "the dragon."
             << endl;
        cout << "In order to prevent the fire kingdom from gaining too much "
                "power and causing chaos themselves, you must defeat the "
                "dragon yourself to protect everyone from the fire kingdom."
             << endl;
        cout << "You are a lone air adventurer." << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "What is your name adventurer?" << endl;
        cout << "My name is: ";
        cin >> playerName;  // inputs users name

        // Sets the inputted player name to Air Player's name
        player.setPlayerName(playerName);
        currentHealth = player.getHealth();
        ogDef = player.getDefense();

        cout << "You encounter your first monster!!" << endl;
        cout << "It looks like an fire monster! GET READY!!" << endl;
        // battle Fire Monster
        cout << "--------------------------------------------------" << endl;
        cin.get();
        cout << "Press Enter to Continue..." << endl;
        cin.get();  // pauses and waits for user to press enter to continue
        system("clear");
        int turn;
        randNumber = rand() % 50;
        cout << "                    BATTLE START                   " << endl;
        cout << "--------------------------------------------------" << endl;
        // Determines who starts their turn first
        if (randNumber % 2 == 0) {
          turn = 0;  // Player starts first
        } else {
          turn = 1;  // Monster starts first
        }

        while (player.getHealth() > 0 && FireMonsters.get_fireHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;

              // Calls the fight function from menu
              Menu.menuFight();

              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = FireMonsters.damageRecieved(
                    player.calculateDmgDone(FireMonsters.get_fireDefence()));
                cout << FireMonsters.get_fireName() << " has "
                     << FireMonsters.get_fireHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = FireMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << FireMonsters.get_fireName() << "!!"
                       << endl;
                  cout << FireMonsters.get_fireName() << " has "
                       << FireMonsters.get_fireHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Healthpotion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              Menu.menuFightNP();
              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = FireMonsters.damageRecieved(
                    player.calculateDmgDone(FireMonsters.get_fireDefence()));
                cout << FireMonsters.get_fireName() << " has "
                     << FireMonsters.get_fireHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = FireMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << FireMonsters.get_fireName() << "!!"
                       << endl;
                  cout << FireMonsters.get_fireName() << " has "
                       << FireMonsters.get_fireHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= FireMonsters.attack(player.getDefense());
            player.setHealth(currentHealth);
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died!!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (FireMonsters.get_fireHealth() <= 0) {  // if monster dies
            cout << "Monster Died!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // save checkpoint 1
        playerStage = 1;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);

        cin.get();
        cout << "Game Saved!" << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "You encounter your second monster!!" << endl;
        cout << "It looks like an earth monster! GET READY!!" << endl;
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

        while (player.getHealth() > 0 && EarthMonsters.get_earthHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                          Health Potions: "
                   << player.getHealthPotion() << endl;

              // Calls the fight function from menu
              Menu.menuFight();

              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = EarthMonsters.damageRecieved(
                    player.calculateDmgDone(EarthMonsters.get_earthDefence()));
                cout << EarthMonsters.get_earthName() << " has "
                     << EarthMonsters.get_earthHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = EarthMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << EarthMonsters.get_earthName() << "!!"
                       << endl;
                  cout << EarthMonsters.get_earthName() << " has "
                       << EarthMonsters.get_earthHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Healthpotion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              Menu.menuFightNP();
              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = EarthMonsters.damageRecieved(
                    player.calculateDmgDone(EarthMonsters.get_earthDefence()));
                cout << EarthMonsters.get_earthName() << " has "
                     << EarthMonsters.get_earthHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = EarthMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << EarthMonsters.get_earthName() << "!!"
                       << endl;
                  cout << EarthMonsters.get_earthName() << " has "
                       << EarthMonsters.get_earthHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= EarthMonsters.attack(player.getDefense());
            player.setHealth(currentHealth);
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died!!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (EarthMonsters.get_earthHealth() <= 0) {  // if monster dies
            cout << "Monster Died!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // save checkpoint 2
        playerStage = 2;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);
        cin.get();
        cout << "Game Saved!" << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "You encounter your third monster!!" << endl;
        cout << "It looks like a water monster! GET READY!!" << endl;
        cout << "--------------------------------------------------" << endl;

        // battle Water Monster
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

        while (player.getHealth() > 0 && WaterMonsters.get_waterHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                          Health Potions: "
                   << player.getHealthPotion() << endl;

              // Calls the fight function from menu
              Menu.menuFight();

              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = WaterMonsters.damageRecieved(
                    player.calculateDmgDone(WaterMonsters.get_waterDefence()));
                cout << WaterMonsters.get_waterName() << " has "
                     << WaterMonsters.get_waterHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = WaterMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << WaterMonsters.get_waterName() << "!!"
                       << endl;
                  cout << WaterMonsters.get_waterName() << " has "
                       << WaterMonsters.get_waterHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Healthpotion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              Menu.menuFightNP();
              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = WaterMonsters.damageRecieved(
                    player.calculateDmgDone(WaterMonsters.get_waterDefence()));
                cout << WaterMonsters.get_waterName() << " has "
                     << WaterMonsters.get_waterHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = WaterMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << WaterMonsters.get_waterName() << "!!"
                       << endl;
                  cout << WaterMonsters.get_waterName() << " has "
                       << WaterMonsters.get_waterHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= WaterMonsters.attack(player.getDefense());
            player.setHealth(currentHealth);
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died!!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (WaterMonsters.get_waterHealth() <= 0) {  // if monster dies
            cout << "Monster Died!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // THE 2nd LAST MONSTER (SAME ELEMENT TYPE AS PLAYER)
        // After this battle the player is able to access their additional
        // attack function save checkpoint 3
        playerStage = 3;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);
        cin.get();
        cout << "Game Saved!" << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "You encounter your fourth monster!!" << endl;
        cout << "It looks like a AIR monster?" << endl;
        cout << "I wonder what will happen!" << endl;
        cout << "--------------------------------------------------" << endl;

        // battle Air Monster
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

        while (player.getHealth() > 0 && AirMonsters.get_airHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                          Health Potions: "
                   << player.getHealthPotion() << endl;

              // Calls the fight function from menu
              Menu.menuFight();

              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = AirMonsters.damageRecieved(
                    player.calculateDmgDone(AirMonsters.get_airDefence()));
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = AirMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << AirMonsters.get_airName() << "!!"
                       << endl;
                  cout << AirMonsters.get_airName() << " has "
                       << AirMonsters.get_airHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Healthpotion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              Menu.menuFightNP();
              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = AirMonsters.damageRecieved(
                    player.calculateDmgDone(AirMonsters.get_airDefence()));
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = AirMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << AirMonsters.get_airName() << "!!"
                       << endl;
                  cout << AirMonsters.get_airName() << " has "
                       << AirMonsters.get_airHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= AirMonsters.attack(player.getDefense());
            player.setHealth(currentHealth);
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died!!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (AirMonsters.get_airHealth() <= 0) {  // if monster dies
            cout << "Monster Died!!" << endl;
            cout << "You gained a new special ability!" << endl;
            cout << "WIND SLASH!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // Elemental Dragon
        // save checkpoint 4
        playerStage = 4;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);
        cin.get();
        cout << "Game Saved!" << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "Now you have achieved the final stage!" << endl;
        cout << "You will battle the ELEMENTAL DRAGON!!" << endl;
        cout << "It can transform into previously fought ELEMENTAL MONSTERS!"
             << endl;
        cout << "AND USE THEIR ATTACKS!!" << endl;
        cout << "Goodluck...you will need it" << endl;
        cout << "--------------------------------------------------" << endl;

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
        while (player.getHealth() > 0 &&
               ElementalDragon.get_elementalHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              // Calls special menu with additional ability
              Menu.menuFightSpecial();

              if (Menu.get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(
                    player.calculateDmgDone(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = ElementalDragon.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << ElementalDragon.get_elementalName()
                       << "!!" << endl;
                  cout << ElementalDragon.get_elementalName() << " has "
                       << ElementalDragon.get_elementalHealth() << " health"
                       << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Health potion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              } else if (Menu.get_userChoice() == 4) {
                cout << player.getPlayerName()
                     << " used special ability WIND SLASH!" << endl;

                damageDealt = ElementalDragon.damageRecieved(
                    player.getAttack() +
                    player.useWindSlash(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;
              }

            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;

              // Menu with no potion and special abilitiy
              Menu.menuFightNPS();

              if (Menu.get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(
                    player.calculateDmgDone(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

              } else if (Menu.get_userChoice() == 2) {  // Spells
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = ElementalDragon.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << ElementalDragon.get_elementalName()
                       << "!!" << endl;
                  cout << ElementalDragon.get_elementalName() << " has "
                       << ElementalDragon.get_elementalHealth() << " health"
                       << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // Special ability
              } else if (Menu.get_userChoice() == 3) {
                cout << player.getPlayerName()
                     << " used special ability WIND SLASH!" << endl;

                damageDealt = ElementalDragon.damageRecieved(
                    player.getAttack() +
                    player.useWindSlash(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;
              }
            }
          } else {  // monsters turn

            currentHealth -= ElementalDragon.attack(player.getDefense());
            player.setHealth(currentHealth);
            cout << "Elegon returned to its Dragon Form" << endl;
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (ElementalDragon.get_elementalHealth() <=
                     0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // Free memory allocated for AirPlayer's spells array
        delete[] player.getSpell();
        break;
      case 1:
        // save checkpoint 1
        playerStage = 1;
        // load game state
        currentHealth = health;
        player.setHealth(health);
        player.setHealthPotion(potion);
        player.setPlayerName(name);
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "You encounter your second monster!!" << endl;
        cout << "It looks like an earth monster! GET READY!!" << endl;
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

        while (player.getHealth() > 0 && EarthMonsters.get_earthHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                          Health Potions: "
                   << player.getHealthPotion() << endl;

              // Calls the fight function from menu
              Menu.menuFight();

              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = EarthMonsters.damageRecieved(
                    player.calculateDmgDone(EarthMonsters.get_earthDefence()));
                cout << EarthMonsters.get_earthName() << " has "
                     << EarthMonsters.get_earthHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = EarthMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << EarthMonsters.get_earthName() << "!!"
                       << endl;
                  cout << EarthMonsters.get_earthName() << " has "
                       << EarthMonsters.get_earthHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Healthpotion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              Menu.menuFightNP();
              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = EarthMonsters.damageRecieved(
                    player.calculateDmgDone(EarthMonsters.get_earthDefence()));
                cout << EarthMonsters.get_earthName() << " has "
                     << EarthMonsters.get_earthHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = EarthMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << EarthMonsters.get_earthName() << "!!"
                       << endl;
                  cout << EarthMonsters.get_earthName() << " has "
                       << EarthMonsters.get_earthHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= EarthMonsters.attack(player.getDefense());
            player.setHealth(currentHealth);
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died!!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (EarthMonsters.get_earthHealth() <= 0) {  // if monster dies
            cout << "Monster Died!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // save checkpoint 2
        playerStage = 2;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);
        cin.get();
        cout << "Game Saved!" << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "You encounter your third monster!!" << endl;
        cout << "It looks like a water monster! GET READY!!" << endl;
        cout << "--------------------------------------------------" << endl;

        // battle Water Monster
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

        while (player.getHealth() > 0 && WaterMonsters.get_waterHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                          Health Potions: "
                   << player.getHealthPotion() << endl;

              // Calls the fight function from menu
              Menu.menuFight();

              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = WaterMonsters.damageRecieved(
                    player.calculateDmgDone(WaterMonsters.get_waterDefence()));
                cout << WaterMonsters.get_waterName() << " has "
                     << WaterMonsters.get_waterHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = WaterMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << WaterMonsters.get_waterName() << "!!"
                       << endl;
                  cout << WaterMonsters.get_waterName() << " has "
                       << WaterMonsters.get_waterHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Healthpotion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              Menu.menuFightNP();
              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = WaterMonsters.damageRecieved(
                    player.calculateDmgDone(WaterMonsters.get_waterDefence()));
                cout << WaterMonsters.get_waterName() << " has "
                     << WaterMonsters.get_waterHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = WaterMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << WaterMonsters.get_waterName() << "!!"
                       << endl;
                  cout << WaterMonsters.get_waterName() << " has "
                       << WaterMonsters.get_waterHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= WaterMonsters.attack(player.getDefense());
            player.setHealth(currentHealth);
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died!!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (WaterMonsters.get_waterHealth() <= 0) {  // if monster dies
            cout << "Monster Died!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // THE 2nd LAST MONSTER (SAME ELEMENT TYPE AS PLAYER)
        // After this battle the player is able to access their additional
        // attack function save checkpoint 3
        playerStage = 3;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);
        cin.get();
        cout << "Game Saved!" << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "You encounter your fourth monster!!" << endl;
        cout << "It looks like a AIR monster?" << endl;
        cout << "I wonder what will happen!" << endl;
        cout << "--------------------------------------------------" << endl;

        // battle Air Monster
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

        while (player.getHealth() > 0 && AirMonsters.get_airHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                          Health Potions: "
                   << player.getHealthPotion() << endl;

              // Calls the fight function from menu
              Menu.menuFight();

              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = AirMonsters.damageRecieved(
                    player.calculateDmgDone(AirMonsters.get_airDefence()));
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = AirMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << AirMonsters.get_airName() << "!!"
                       << endl;
                  cout << AirMonsters.get_airName() << " has "
                       << AirMonsters.get_airHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Healthpotion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              Menu.menuFightNP();
              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = AirMonsters.damageRecieved(
                    player.calculateDmgDone(AirMonsters.get_airDefence()));
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = AirMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << AirMonsters.get_airName() << "!!"
                       << endl;
                  cout << AirMonsters.get_airName() << " has "
                       << AirMonsters.get_airHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= AirMonsters.attack(player.getDefense());
            player.setHealth(currentHealth);
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died!!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (AirMonsters.get_airHealth() <= 0) {  // if monster dies
            cout << "Monster Died!!" << endl;
            cout << "You gained a new special ability!" << endl;
            cout << "WIND SLASH!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // Elemental Dragon
        // save checkpoint 4
        playerStage = 4;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);
        cin.get();
        cout << "Game Saved!" << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "Now you have achieved the final stage!" << endl;
        cout << "You will battle the ELEMENTAL DRAGON!!" << endl;
        cout << "It can transform into previously fought ELEMENTAL MONSTERS!"
             << endl;
        cout << "AND USE THEIR ATTACKS!!" << endl;
        cout << "Goodluck...you will need it" << endl;
        cout << "--------------------------------------------------" << endl;

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
        while (player.getHealth() > 0 &&
               ElementalDragon.get_elementalHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              // Calls special menu with additional ability
              Menu.menuFightSpecial();

              if (Menu.get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(
                    player.calculateDmgDone(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = ElementalDragon.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << ElementalDragon.get_elementalName()
                       << "!!" << endl;
                  cout << ElementalDragon.get_elementalName() << " has "
                       << ElementalDragon.get_elementalHealth() << " health"
                       << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Health potion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              } else if (Menu.get_userChoice() == 4) {
                cout << player.getPlayerName()
                     << " used special ability WIND SLASH!" << endl;

                damageDealt = ElementalDragon.damageRecieved(
                    player.getAttack() +
                    player.useWindSlash(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;
              }

            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;

              // Menu with no potion and special abilitiy
              Menu.menuFightNPS();

              if (Menu.get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(
                    player.calculateDmgDone(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

              } else if (Menu.get_userChoice() == 2) {  // Spells
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = ElementalDragon.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << ElementalDragon.get_elementalName()
                       << "!!" << endl;
                  cout << ElementalDragon.get_elementalName() << " has "
                       << ElementalDragon.get_elementalHealth() << " health"
                       << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // Special ability
              } else if (Menu.get_userChoice() == 3) {
                cout << player.getPlayerName()
                     << " used special ability WIND SLASH!" << endl;

                damageDealt = ElementalDragon.damageRecieved(
                    player.getAttack() +
                    player.useWindSlash(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;
              }
            }
          } else {  // monsters turn

            currentHealth -= ElementalDragon.attack(player.getDefense());
            player.setHealth(currentHealth);
            cout << "Elegon returned to its Dragon Form" << endl;
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (ElementalDragon.get_elementalHealth() <=
                     0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // Free memory allocated for AirPlayer's spells array
        delete[] player.getSpell();
        break;
      case 2:  // save checkpoint 2
        playerStage = 2;
        // load game state
        currentHealth = health;
        player.setHealth(health);
        player.setHealthPotion(potion);
        player.setPlayerName(name);
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "You encounter your third monster!!" << endl;
        cout << "It looks like a water monster! GET READY!!" << endl;
        cout << "--------------------------------------------------" << endl;

        // battle Water Monster
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

        while (player.getHealth() > 0 && WaterMonsters.get_waterHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                          Health Potions: "
                   << player.getHealthPotion() << endl;

              // Calls the fight function from menu
              Menu.menuFight();

              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = WaterMonsters.damageRecieved(
                    player.calculateDmgDone(WaterMonsters.get_waterDefence()));
                cout << WaterMonsters.get_waterName() << " has "
                     << WaterMonsters.get_waterHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = WaterMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << WaterMonsters.get_waterName() << "!!"
                       << endl;
                  cout << WaterMonsters.get_waterName() << " has "
                       << WaterMonsters.get_waterHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Healthpotion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              Menu.menuFightNP();
              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = WaterMonsters.damageRecieved(
                    player.calculateDmgDone(WaterMonsters.get_waterDefence()));
                cout << WaterMonsters.get_waterName() << " has "
                     << WaterMonsters.get_waterHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = WaterMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << WaterMonsters.get_waterName() << "!!"
                       << endl;
                  cout << WaterMonsters.get_waterName() << " has "
                       << WaterMonsters.get_waterHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= WaterMonsters.attack(player.getDefense());
            player.setHealth(currentHealth);
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died!!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (WaterMonsters.get_waterHealth() <= 0) {  // if monster dies
            cout << "Monster Died!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // THE 2nd LAST MONSTER (SAME ELEMENT TYPE AS PLAYER)
        // After this battle the player is able to access their additional
        // attack function save checkpoint 3
        playerStage = 3;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);
        cin.get();
        cout << "Game Saved!" << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "You encounter your fourth monster!!" << endl;
        cout << "It looks like a AIR monster?" << endl;
        cout << "I wonder what will happen!" << endl;
        cout << "--------------------------------------------------" << endl;

        // battle Air Monster
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

        while (player.getHealth() > 0 && AirMonsters.get_airHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                          Health Potions: "
                   << player.getHealthPotion() << endl;

              // Calls the fight function from menu
              Menu.menuFight();

              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = AirMonsters.damageRecieved(
                    player.calculateDmgDone(AirMonsters.get_airDefence()));
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = AirMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << AirMonsters.get_airName() << "!!"
                       << endl;
                  cout << AirMonsters.get_airName() << " has "
                       << AirMonsters.get_airHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Healthpotion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              Menu.menuFightNP();
              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = AirMonsters.damageRecieved(
                    player.calculateDmgDone(AirMonsters.get_airDefence()));
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = AirMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << AirMonsters.get_airName() << "!!"
                       << endl;
                  cout << AirMonsters.get_airName() << " has "
                       << AirMonsters.get_airHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= AirMonsters.attack(player.getDefense());
            player.setHealth(currentHealth);
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died!!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (AirMonsters.get_airHealth() <= 0) {  // if monster dies
            cout << "Monster Died!!" << endl;
            cout << "You gained a new special ability!" << endl;
            cout << "WIND SLASH!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // Elemental Dragon
        // save checkpoint 4
        playerStage = 4;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);
        cin.get();
        cout << "Game Saved!" << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "Now you have achieved the final stage!" << endl;
        cout << "You will battle the ELEMENTAL DRAGON!!" << endl;
        cout << "It can transform into previously fought ELEMENTAL MONSTERS!"
             << endl;
        cout << "AND USE THEIR ATTACKS!!" << endl;
        cout << "Goodluck...you will need it" << endl;
        cout << "--------------------------------------------------" << endl;

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
        while (player.getHealth() > 0 &&
               ElementalDragon.get_elementalHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              // Calls special menu with additional ability
              Menu.menuFightSpecial();

              if (Menu.get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(
                    player.calculateDmgDone(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = ElementalDragon.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << ElementalDragon.get_elementalName()
                       << "!!" << endl;
                  cout << ElementalDragon.get_elementalName() << " has "
                       << ElementalDragon.get_elementalHealth() << " health"
                       << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Health potion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              } else if (Menu.get_userChoice() == 4) {
                cout << player.getPlayerName()
                     << " used special ability WIND SLASH!" << endl;

                damageDealt = ElementalDragon.damageRecieved(
                    player.getAttack() +
                    player.useWindSlash(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;
              }

            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;

              // Menu with no potion and special abilitiy
              Menu.menuFightNPS();

              if (Menu.get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(
                    player.calculateDmgDone(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

              } else if (Menu.get_userChoice() == 2) {  // Spells
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = ElementalDragon.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << ElementalDragon.get_elementalName()
                       << "!!" << endl;
                  cout << ElementalDragon.get_elementalName() << " has "
                       << ElementalDragon.get_elementalHealth() << " health"
                       << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // Special ability
              } else if (Menu.get_userChoice() == 3) {
                cout << player.getPlayerName()
                     << " used special ability WIND SLASH!" << endl;

                damageDealt = ElementalDragon.damageRecieved(
                    player.getAttack() +
                    player.useWindSlash(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;
              }
            }
          } else {  // monsters turn

            currentHealth -= ElementalDragon.attack(player.getDefense());
            player.setHealth(currentHealth);
            cout << "Elegon returned to its Dragon Form" << endl;
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (ElementalDragon.get_elementalHealth() <=
                     0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // Free memory allocated for AirPlayer's spells array
        delete[] player.getSpell();
        break;
      case 3:
        // THE 2nd LAST MONSTER (SAME ELEMENT TYPE AS PLAYER)
        // After this battle the player is able to access their additional
        // attack function save checkpoint 3
        playerStage = 3;
        // load game state
        currentHealth = health;
        player.setHealth(health);
        player.setHealthPotion(potion);
        player.setPlayerName(name);
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "You encounter your fourth monster!!" << endl;
        cout << "It looks like a AIR monster?" << endl;
        cout << "I wonder what will happen!" << endl;
        cout << "--------------------------------------------------" << endl;

        // battle Air Monster
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

        while (player.getHealth() > 0 && AirMonsters.get_airHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                          Health Potions: "
                   << player.getHealthPotion() << endl;

              // Calls the fight function from menu
              Menu.menuFight();

              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = AirMonsters.damageRecieved(
                    player.calculateDmgDone(AirMonsters.get_airDefence()));
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = AirMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << AirMonsters.get_airName() << "!!"
                       << endl;
                  cout << AirMonsters.get_airName() << " has "
                       << AirMonsters.get_airHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Healthpotion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              Menu.menuFightNP();
              // Basic Attack
              if (Menu.get_userChoice() == 1) {
                // attacks the enemy with player ATK
                damageDealt = AirMonsters.damageRecieved(
                    player.calculateDmgDone(AirMonsters.get_airDefence()));
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {  //
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = AirMonsters.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << AirMonsters.get_airName() << "!!"
                       << endl;
                  cout << AirMonsters.get_airName() << " has "
                       << AirMonsters.get_airHealth() << " health" << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth -= AirMonsters.attack(player.getDefense());
            player.setHealth(currentHealth);
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died!!!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (AirMonsters.get_airHealth() <= 0) {  // if monster dies
            cout << "Monster Died!!" << endl;
            cout << "You gained a new special ability!" << endl;
            cout << "WIND SLASH!" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // Elemental Dragon
        // save checkpoint 4
        playerStage = 4;
        saved.saveGame(player.getHealth(), player.getHealthPotion(),
                       player.getPlayerName(), playerJourney, playerStage);
        cin.get();
        cout << "Game Saved!" << endl;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "Now you have achieved the final stage!" << endl;
        cout << "You will battle the ELEMENTAL DRAGON!!" << endl;
        cout << "It can transform into previously fought ELEMENTAL MONSTERS!"
             << endl;
        cout << "AND USE THEIR ATTACKS!!" << endl;
        cout << "Goodluck...you will need it" << endl;
        cout << "--------------------------------------------------" << endl;

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
        while (player.getHealth() > 0 &&
               ElementalDragon.get_elementalHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              // Calls special menu with additional ability
              Menu.menuFightSpecial();

              if (Menu.get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(
                    player.calculateDmgDone(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = ElementalDragon.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << ElementalDragon.get_elementalName()
                       << "!!" << endl;
                  cout << ElementalDragon.get_elementalName() << " has "
                       << ElementalDragon.get_elementalHealth() << " health"
                       << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Health potion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              } else if (Menu.get_userChoice() == 4) {
                cout << player.getPlayerName()
                     << " used special ability WIND SLASH!" << endl;

                damageDealt = ElementalDragon.damageRecieved(
                    player.getAttack() +
                    player.useWindSlash(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;
              }

            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;

              // Menu with no potion and special abilitiy
              Menu.menuFightNPS();

              if (Menu.get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(
                    player.calculateDmgDone(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

              } else if (Menu.get_userChoice() == 2) {  // Spells
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = ElementalDragon.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << ElementalDragon.get_elementalName()
                       << "!!" << endl;
                  cout << ElementalDragon.get_elementalName() << " has "
                       << ElementalDragon.get_elementalHealth() << " health"
                       << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // Special ability
              } else if (Menu.get_userChoice() == 3) {
                cout << player.getPlayerName()
                     << " used special ability WIND SLASH!" << endl;

                damageDealt = ElementalDragon.damageRecieved(
                    player.getAttack() +
                    player.useWindSlash(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;
              }
            }
          } else {  // monsters turn

            currentHealth -= ElementalDragon.attack(player.getDefense());
            player.setHealth(currentHealth);
            cout << "Elegon returned to its Dragon Form" << endl;
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (ElementalDragon.get_elementalHealth() <=
                     0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // Free memory allocated for AirPlayer's spells array
        delete[] player.getSpell();
        break;
      case 4:
        // Elemental Dragon
        // save checkpoint 4
        playerStage = 4;
        // load game state
        currentHealth = health;
        player.setHealth(health);
        player.setHealthPotion(potion);
        player.setPlayerName(name);
        ;
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "Now you have achieved the final stage!" << endl;
        cout << "You will battle the ELEMENTAL DRAGON!!" << endl;
        cout << "It can transform into previously fought ELEMENTAL MONSTERS!"
             << endl;
        cout << "AND USE THEIR ATTACKS!!" << endl;
        cout << "Goodluck...you will need it" << endl;
        cout << "--------------------------------------------------" << endl;

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
        while (player.getHealth() > 0 &&
               ElementalDragon.get_elementalHealth() > 0) {
          if (turn % 2 == 0) {  // players turn
            player.setDefense(ogDef);
            if (player.getHealthPotion() >=
                1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;
              // Calls special menu with additional ability
              Menu.menuFightSpecial();

              if (Menu.get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(
                    player.calculateDmgDone(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (Menu.get_userChoice() == 2) {
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = ElementalDragon.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << ElementalDragon.get_elementalName()
                       << "!!" << endl;
                  cout << ElementalDragon.get_elementalName() << " has "
                       << ElementalDragon.get_elementalHealth() << " health"
                       << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // For Health potion
              } else if (Menu.get_userChoice() ==
                         3) {  // Use health potion (heals 100 HP)
                               // use health potion if have
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                currentHealth = player.drinkPotion();
                turn++;  // gets turn back
              } else if (Menu.get_userChoice() == 4) {
                cout << player.getPlayerName()
                     << " used special ability WIND SLASH!" << endl;

                damageDealt = ElementalDragon.damageRecieved(
                    player.getAttack() +
                    player.useWindSlash(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;
              }

            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()

                   << "                           Health Potions: "
                   << player.getHealthPotion() << endl;

              // Menu with no potion and special abilitiy
              Menu.menuFightNPS();

              if (Menu.get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(
                    player.calculateDmgDone(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

              } else if (Menu.get_userChoice() == 2) {  // Spells
                // display spells
                Menu.menuSpell();

                // Attack Spell
                if (Menu.get_userChoice() == 1) {
                  damageDealt = ElementalDragon.damageRecieved(
                      player.getAttack() + player.getAirAtkSpell());
                  cout << player.getPlayerName()
                       << " casted an attack spell and did " << damageDealt
                       << " damage to " << ElementalDragon.get_elementalName()
                       << "!!" << endl;
                  cout << ElementalDragon.get_elementalName() << " has "
                       << ElementalDragon.get_elementalHealth() << " health"
                       << endl;
                  cout << "---------------------------" << endl;
                  // Defense Spell
                } else if (Menu.get_userChoice() == 2) {
                  int tempDef = 0;
                  tempDef = player.getAirDefSpell() + player.getDefense();
                  player.setDefense(tempDef);
                  cout << player.getPlayerName() << " casted a defense spell! "
                       << "and increased defense to " << tempDef << endl;
                  cout << "---------------------------" << endl;
                }

                // Special ability
              } else if (Menu.get_userChoice() == 3) {
                cout << player.getPlayerName()
                     << " used special ability WIND SLASH!" << endl;

                damageDealt = ElementalDragon.damageRecieved(
                    player.getAttack() +
                    player.useWindSlash(ElementalDragon.get_airDefence()));
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;
              }
            }
          } else {  // monsters turn

            currentHealth -= ElementalDragon.attack(player.getDefense());
            player.setHealth(currentHealth);
            cout << "Elegon returned to its Dragon Form" << endl;
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            return;

          } else if (ElementalDragon.get_elementalHealth() <=
                     0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

        // Free memory allocated for AirPlayer's spells array
        delete[] player.getSpell();
        break;
    }
  }
};

#endif