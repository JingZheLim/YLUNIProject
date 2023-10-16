#ifndef FIREJOURNEY_H
#define FIREJOURNEY_H
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
#include "FirePlayer.h"
#include "Spell.h"

using namespace std;

class FireJourney : menu {
 private:
 // Randomizer 
  int randNumber;
  string playerName; 
  int damageDealt; 
  int currentHealth;

  // creating the objects for monsters
  waterMonster WaterMonsters;
  fireMonster FireMonsters;
  earthMonster EarthMonsters;
  airMonster AirMonsters;
  elementalDragon ElementalDragon;

  // create fire player object
  // Attributes: playerName, health, attack, defense, healthPotion
  FirePlayer player; 

 public:
  void run2() {  // starts the entire game

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
        cout << "Your kingdom is hungry for power over the other kingdoms and "
                "has set you on an adventure to defeat the almighty dragon"
             << endl;
        cout << "The almighty dragon will give power to your kingdom through"
                "its multitude of elemental spells!"
             << endl;
        cout << "You must defeat the dragon give your kingdom the power it"
                "craves!"
             << endl;
        cout << "You are a mighty fire warrior" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "What is your name mighty warrior?" << endl;
        cout << "My name is: ";
        cin >> playerName;  // inputs users name

        // Sets the inputted player name to Fire Player's name 
        player.setPlayerName(playerName); 

        cout << "You encounter your first monster!!" << endl;
        cout << "It looks like an air monster! GET READY!!" << endl; 

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
        // Determines who starts their turn first
        if (randNumber % 2 == 0) {
          turn = 0;  // Player starts first
        } else {
          turn = 1;  // Monster starts first
        }

        while (player.getHealth() > 0 && AirMonsters.get_airHealth() > 0) {
          if (turn % 2 == 0) {       // players turn
            if (player.getHealthPotion() >= 1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()
                                              
                   << "        Health Potions: " << player.getHealthPotion() << endl;

             // Calls the fight function from menu
              menuFight();

            // Basic Attack
              if (get_userChoice() == 1) { 
                // attacks the enemy with player ATK
                damageDealt = AirMonsters.damageRecieved(player.calculateDmgDone(50));
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

            // Spells
              } else if (get_userChoice() == 2) {  // 
                // display spells 
                menuSpell();
                    
                    // Attack Spell 
                    if (get_userChoice() == 1){
                        damageDealt = AirMonsters.damageRecieved(player.getAttack() + player.getFireAtkSpell());
                        cout << player.getPlayerName() << " casted an attack spell and did "
                             << damageDealt << " damage to "
                             << AirMonsters.get_airName() << "!!" << endl;
                        cout << AirMonsters.get_airName() << " has "
                             << AirMonsters.get_airHealth() << " health" << endl;
                        cout << "---------------------------" << endl;
                    // Defense Spell
                    }else if (get_userChoice() == 2){
                        cout << player.getPlayerName() << " casted a defense spell! " << endl;
                        int tempHealth = 0;
                        tempHealth = player.getFireDefSpell() + player.getHealth(); 
                        player.setHealth(tempHealth); 
                        cout << "---------------------------" << endl;
                        }

            // For Healthpotion
              } else if (get_userChoice() ==
                         3) {  // Use health potion (heals 50 HP)
                               // use health potion if have
                cout << playerName << " used a health potion" << endl;
                cout << "--------------------------------------------------"
                     << endl;
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                player.drinkPotion(); 
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth() 
                                               
                   << "        Health Potions: " << player.getHealthPotion() << endl;
              menuFightNP();
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy player ATK
                damageDealt = AirMonsters.damageRecieved(player.calculateDmgDone(50));
                cout << AirMonsters.get_airName() << " has "
                     << AirMonsters.get_airHealth() << " health" << endl;
                cout << "---------------------------" << endl;

              } else if (get_userChoice() == 2) {  // Spells
                // display spells 
                menuSpell();
                    
                    // Attack Spell 
                    if (get_userChoice() == 1){
                        damageDealt = AirMonsters.damageRecieved(player.getAttack() + player.getFireAtkSpell());
                        cout << player.getPlayerName() << " casted an attack spell and did "
                             << damageDealt << " damage to "
                             << AirMonsters.get_airName() << "!!" << endl;
                        cout << AirMonsters.get_airName() << " has "
                             << AirMonsters.get_airHealth() << " health" << endl;
                        cout << "---------------------------" << endl;
                    // Defense Spell
                    }else if (get_userChoice() == 2){
                        cout << player.getPlayerName() << " casted a defense spell! " << endl;
                        int tempHealth = 0;
                        tempHealth = player.getFireDefSpell() + player.getHealth(); 
                        player.setHealth(tempHealth); 
                        cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth = player.calculateDmgRecieved(AirMonsters.attack(player.getDefense()));
            player.setHealth(currentHealth); 
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
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
        cout << "You encounter your seoncd monster!!" << endl;
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

        while (currentHealth > 0 && EarthMonsters.get_earthHealth() > 0) {
          if (turn % 2 == 0) {       // players turn
            if (player.getHealthPotion() >= 1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()  
                                               
                   << "        Health Potions: " << player.getHealthPotion() << endl;

            // Calls the fight function from menu
              menuFight();

              // Basic Attack 
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = EarthMonsters.damageRecieved(player.calculateDmgDone(65));
                cout << playerName << "\'s basic attack did " << damageDealt
                     << " damage to " << EarthMonsters.get_earthName() << "!!"
                     << endl;
                cout << EarthMonsters.get_earthName() << " has "
                     << EarthMonsters.get_earthHealth() << " health" << endl;
                cout << "---------------------------" << endl;

            // Spells
              } else if (get_userChoice() == 2) {  // 
                // display spells 
                menuSpell();
                    
                // Attack Spell 
                    if (get_userChoice() == 1){
                        damageDealt = EarthMonsters.damageRecieved(player.getAttack() + player.getFireAtkSpell());
                        cout << player.getPlayerName() << " casted an attack spell and did "
                             << damageDealt << " damage to "
                             << EarthMonsters.get_earthName() << "!!" << endl;
                        cout << EarthMonsters.get_earthName() << " has "
                             << EarthMonsters.get_earthHealth() << " health" << endl;
                        cout << "---------------------------" << endl;
                    // Defense Spell
                    }else if (get_userChoice() == 2){
                        cout << player.getPlayerName() << " casted a defense spell! " << endl;
                        int tempHealth = 0;
                        tempHealth = player.getFireDefSpell() + player.getHealth(); 
                        player.setHealth(tempHealth); 
                        cout << "---------------------------" << endl;
                    }

            // For Health potion 
              } else if (get_userChoice() == 3){
                cout << playerName << " used a health potion" << endl;
                cout << "--------------------------------------------------"
                     << endl;
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                player.drinkPotion(); 
                turn++;  // gets turn back

            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth() 
                                               
                   << "        Health Potions: " << player.getHealthPotion() << endl;
              menuFightNP();
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy player ATK
                damageDealt = EarthMonsters.damageRecieved(player.calculateDmgDone(65));
                cout << EarthMonsters.get_earthName() << " has "
                     << EarthMonsters.get_earthHealth() << " health" << endl;
                cout << "---------------------------" << endl;

              } else if (get_userChoice() == 2) {  // Spells
                // display spells 
                menuSpell();
                    
                    // Attack Spell 
                    if (get_userChoice() == 1){
                        damageDealt = EarthMonsters.damageRecieved(player.getAttack() + player.getFireAtkSpell());
                        cout << player.getPlayerName() << " casted an attack spell and did "
                             << damageDealt << " damage to "
                             << EarthMonsters.get_earthName() << "!!" << endl;
                        cout << EarthMonsters.get_earthName() << " has "
                             << EarthMonsters.get_earthHealth() << " health" << endl;
                        cout << "---------------------------" << endl;
                    // Defense Spell
                    }else if (get_userChoice() == 2){
                        cout << player.getPlayerName() << " casted a defense spell! " << endl;
                        int tempHealth = 0;
                        tempHealth = player.getFireDefSpell() + player.getHealth(); 
                        player.setHealth(tempHealth); 
                        cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth = player.calculateDmgRecieved(EarthMonsters.attack(player.getDefense()));
            player.setHealth(currentHealth); 
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
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
          if (turn % 2 == 0) {       // players turn
            if (player.getHealthPotion() >= 1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()
                                              
                   << "        Health Potions: " << player.getHealthPotion() << endl;

             // Calls the fight function from menu
              menuFight();

            // Basic Attack
              if (get_userChoice() == 1) { 
                // attacks the enemy with player ATK
                damageDealt =  WaterMonsters.damageRecieved(player.calculateDmgDone(30));
                cout <<  WaterMonsters.get_waterName() << " has "
                     <<  WaterMonsters.get_waterHealth() << " health" << endl;
                cout << "---------------------------" << endl;

            // Spells
              } else if (get_userChoice() == 2) {  // 
                // display spells 
                menuSpell();
                    
                    // Attack Spell 
                    if (get_userChoice() == 1){
                        damageDealt =  WaterMonsters.damageRecieved(player.getAttack() + player.getFireAtkSpell());
                        cout << player.getPlayerName() << " casted an attack spell and did "
                             << damageDealt << " damage to "
                             << WaterMonsters.get_waterName() << "!!" << endl;
                        cout << WaterMonsters.get_waterName() << " has "
                             << WaterMonsters.get_waterHealth() << " health" << endl;
                        cout << "---------------------------" << endl;
                    // Defense Spell
                    }else if (get_userChoice() == 2){
                        cout << player.getPlayerName() << " casted a defense spell! " << endl;
                        int tempHealth = 0;
                        tempHealth = player.getFireDefSpell() + player.getHealth(); 
                        player.setHealth(tempHealth); 
                        cout << "---------------------------" << endl;
                    }

            // For Healthpotion
              } else if (get_userChoice() ==
                         3) {  // Use health potion (heals 50 HP)
                               // use health potion if have
                cout << playerName << " used a health potion" << endl;
                cout << "--------------------------------------------------"
                     << endl;
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                player.drinkPotion(); 
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth() 
                                               
                   << "        Health Potions: " << player.getHealthPotion() << endl;
              menuFightNP();
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy player ATK
                damageDealt =  WaterMonsters.damageRecieved(player.calculateDmgDone(30));
                cout <<  WaterMonsters.get_waterName() << " has "
                     <<  WaterMonsters.get_waterHealth() << " health" << endl;
                cout << "---------------------------" << endl;

              } else if (get_userChoice() == 2) {  // Spells
                // display spells 
                menuSpell();
                    
                    // Attack Spell 
                    if (get_userChoice() == 1){
                        damageDealt =  WaterMonsters.damageRecieved(player.getAttack() + player.getFireAtkSpell());
                        cout << player.getPlayerName() << " casted an attack spell and did "
                             << damageDealt << " damage to "
                             << WaterMonsters.get_waterName() << "!!" << endl;
                        cout << WaterMonsters.get_waterName() << " has "
                             << WaterMonsters.get_waterHealth() << " health" << endl;
                        cout << "---------------------------" << endl;
                    // Defense Spell
                    }else if (get_userChoice() == 2){
                        cout << player.getPlayerName() << " casted a defense spell! " << endl;
                        int tempHealth = 0;
                        tempHealth = player.getFireDefSpell() + player.getHealth(); 
                        player.setHealth(tempHealth); 
                        cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth = player.calculateDmgRecieved(WaterMonsters.attack(player.getDefense()));
            player.setHealth(currentHealth); 
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;

          } else if ( WaterMonsters.get_waterHealth() <= 0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

// THE 2nd LAST MONSTER (SAME ELEMENT TYPE AS PLAYER)
// After this battle the player is able to access their additional attack function
        cin.get();
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "You encounter your fourth monster!!" << endl;
        cout << "It looks like a FIRE monster?" << endl; 
        cout << "I wonder what will happen!" << endl; 
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

        while (player.getHealth() > 0 && FireMonsters.get_fireHealth() > 0) {
          if (turn % 2 == 0) {       // players turn
            if (player.getHealthPotion() >= 1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth()
                                              
                   << "        Health Potions: " << player.getHealthPotion() << endl;

             // Calls the fight function from menu
              menuFight();

            // Basic Attack
              if (get_userChoice() == 1) { 
                // attacks the enemy with player ATK
                damageDealt =  FireMonsters.damageRecieved(player.calculateDmgDone(200));
                cout <<  FireMonsters.get_fireName() << " has "
                     <<  FireMonsters.get_fireHealth() << " health" << endl;
                cout << "---------------------------" << endl;

            // Spells
              } else if (get_userChoice() == 2) {  // 
                // display spells 
                menuSpell();
                    
                    // Attack Spell 
                    if (get_userChoice() == 1){
                        damageDealt =  FireMonsters.damageRecieved(player.getAttack() + player.getFireAtkSpell());
                        cout << player.getPlayerName() << " casted an attack spell and did "
                             << damageDealt << " damage to "
                             << FireMonsters.get_fireName() << "!!" << endl;
                        cout << FireMonsters.get_fireName() << " has "
                             << FireMonsters.get_fireHealth() << " health" << endl;
                        cout << "---------------------------" << endl;
                    // Defense Spell
                    }else if (get_userChoice() == 2){
                        cout << player.getPlayerName() << " casted a defense spell! " << endl;
                        int tempHealth = 0;
                        tempHealth = player.getFireDefSpell() + player.getHealth(); 
                        player.setHealth(tempHealth); 
                        cout << "---------------------------" << endl;
                    }

            // For Healthpotion
              } else if (get_userChoice() ==
                         3) {  // Use health potion (heals 50 HP)
                               // use health potion if have
                cout << playerName << " used a health potion" << endl;
                cout << "--------------------------------------------------"
                     << endl;
                // Decreases health potion by 1
                player.setHealthPotion(player.getHealthPotion() - 1);
                player.drinkPotion(); 
                turn++;  // gets turn back
              }
            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth() 
                                               
                   << "        Health Potions: " << player.getHealthPotion() << endl;
              menuFightNP();
              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy player ATK
                damageDealt =  FireMonsters.damageRecieved(player.calculateDmgDone(200));
                cout <<  FireMonsters.get_fireName() << " has "
                     <<  FireMonsters.get_fireHealth() << " health" << endl;
                cout << "---------------------------" << endl;

              } else if (get_userChoice() == 2) {  // Spells
                // display spells 
                menuSpell();
                    
                    // Attack Spell 
                    if (get_userChoice() == 1){
                        damageDealt =  FireMonsters.damageRecieved(player.getAttack() + player.getFireAtkSpell());
                        cout << player.getPlayerName() << " casted an attack spell and did "
                             << damageDealt << " damage to "
                             << FireMonsters.get_fireName() << "!!" << endl;
                        cout << FireMonsters.get_fireName() << " has "
                             << FireMonsters.get_fireHealth() << " health" << endl;
                        cout << "---------------------------" << endl;
                    // Defense Spell
                    }else if (get_userChoice() == 2){
                        cout << player.getPlayerName() << " casted a defense spell! " << endl;
                        int tempHealth = 0;
                        tempHealth = player.getFireDefSpell() + player.getHealth(); 
                        player.setHealth(tempHealth); 
                        cout << "---------------------------" << endl;
                }
              }
            }
          } else {  // monsters turn
            currentHealth = player.calculateDmgRecieved(FireMonsters.attack(player.getDefense()));
            player.setHealth(currentHealth); 
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;

          } else if ( FireMonsters.get_fireHealth() <= 0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "You gained a new special ability!" << endl; 
            cout << "FIRESTRIKE!" << endl; 
            cout << "--------------------------------------------------"
                 << endl;
          }
        }

    // Elemental Dragon 
        cin.get();
        cout << "Press Enter to Continue..." << endl;
        cin.get();
        system("clear");
        cout << "Now you have achieved the final stage!" << endl;
        cout << "You will battle the ELEMENTAL DRAGON!!" << endl;
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
        while (currentHealth > 0 && ElementalDragon.get_elementalHealth() > 0) {
          if (turn % 2 == 0) {       // players turn
            if (player.getHealthPotion() >= 1) {  // if have potion display normal menu

              cout << "HP: " << player.getHealth() 
                                            
                   << "        Health Potions: " << player.getHealthPotion() << endl;
            // Calls special menu with additional ability 
              menuFightSpecial();

              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(player.calculateDmgDone(100));
                cout << playerName << "\'s basic attack did " << damageDealt << endl; 
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

                // Spells
              } else if (get_userChoice() == 2) {  
                // display spells 
                menuSpell();
                
                    // Attack Spell 
                    if (get_userChoice() == 1){
                        damageDealt = ElementalDragon.damageRecieved(player.getAttack() + player.getFireAtkSpell());
                        cout << player.getPlayerName() << " casted an attack spell and did "
                             << damageDealt << " damage to "
                             << ElementalDragon.get_elementalName() << "!!" << endl;
                        cout << ElementalDragon.get_elementalName() << " has "
                             << ElementalDragon.get_elementalHealth() << " health" << endl;
                        cout << "---------------------------" << endl;
                    // Defense Spell
                    }else if (get_userChoice() == 2){
                        cout << player.getPlayerName() << " casted a defense spell! " << endl;
                        int tempHealth = 0;
                        tempHealth = player.getFireDefSpell() + player.getHealth(); 
                        player.setHealth(tempHealth); 
                        cout << "---------------------------" << endl;
                    }
            
            // For Health potion 
              } else if (get_userChoice() ==
                         3) {         
                    cout << player.getPlayerName() << " used a health potion" << endl;
                    cout << "--------------------------------------------------"
                         << endl;
                    // Decreases health potion by 1
                    player.setHealthPotion(player.getHealthPotion() - 1);
                    player.drinkPotion(); 
                    turn++;  // gets turn back
              } else if (get_userChoice() == 4){
                    cout << player.getPlayerName() << " used special ability FIRE STRIKE!" << endl;

                    damageDealt = ElementalDragon.damageRecieved(player.getAttack() + player.useFireStrike(100));
                    cout << ElementalDragon.get_elementalName() << " has "
                    << ElementalDragon.get_elementalHealth() << " health" << endl;
                    cout << "---------------------------" << endl;             
              }

            } else {  // if doesn't display menuNP

              cout << "HP: " << player.getHealth()  
                                               
                   << "        Health Potions: " << player.getHealthPotion() << endl;

            // Menu with no potion and special abilitiy 
              menuFightNPS();

              if (get_userChoice() == 1) {  // Basic Attack
                // attacks the enemy with player ATK
                damageDealt = ElementalDragon.damageRecieved(player.calculateDmgDone(100));
                cout << playerName << "\'s basic attack did " << damageDealt << endl; 
                cout << ElementalDragon.get_elementalName() << " has "
                     << ElementalDragon.get_elementalHealth() << " health"
                     << endl;
                cout << "---------------------------" << endl;

              } else if (get_userChoice() == 2) {  // Spells
                // display spells 
                menuSpell();
                
                    // Attack Spell 
                    if (get_userChoice() == 1){
                        damageDealt = ElementalDragon.damageRecieved(player.getAttack() + player.getFireAtkSpell());
                        cout << player.getPlayerName() << " casted an attack spell and did "
                             << damageDealt << " damage to "
                             << ElementalDragon.get_elementalName() << "!!" << endl;
                        cout << ElementalDragon.get_elementalName() << " has "
                             << ElementalDragon.get_elementalHealth() << " health" << endl;
                        cout << "---------------------------" << endl;
                    // Defense Spell
                    }else if (get_userChoice() == 2){
                        cout << player.getPlayerName() << " casted a defense spell! " << endl;
                        int tempHealth = 0;
                        tempHealth = player.getFireDefSpell() + player.getHealth(); 
                        player.setHealth(tempHealth); 
                        cout << "---------------------------" << endl;
                    }

                // Special ability
              }else if (get_userChoice() == 3){
                    cout << player.getPlayerName() << " used special ability FIRE STRIKE!" << endl;

                    damageDealt = ElementalDragon.damageRecieved(player.getAttack() + player.useFireStrike(100));
                    cout << ElementalDragon.get_elementalName() << " has "
                    << ElementalDragon.get_elementalHealth() << " health" << endl;
                    cout << "---------------------------" << endl;                      

              }
            }
          } else {  // monsters turn
            currentHealth = player.calculateDmgRecieved(ElementalDragon.attack(player.getDefense()));
            player.setHealth(currentHealth); 
          }
          turn++;

          if (player.getHealth() <= 0) {  // if player dies
            cout << "You died" << endl;
            cout << "--------------------------------------------------"
                 << endl;

          } else if (ElementalDragon.get_elementalHealth() <=
                     0) {  // if monster dies
            cout << "Monster Died" << endl;
            cout << "--------------------------------------------------"
                 << endl;
          }
        }
    }
    }
  };
  cout << "Thank you for playing elementals!" << endl; 
};
}; 
#endif