#ifndef UNITTESTING_H
#define UNITTESTING_H
// create a new main file (testMain.cpp)
// create a unitTest.h files and create tests like if(this happens) = something
// (test each class' function) then cout << failed
// to use make file type make in terminal

/* g++ main.cpp menu.h game.h airMonster.cpp earthMonster.cpp fireMonster.cpp
   waterMonster.cpp elementalDragon.cpp  monster.h  AirPlayer.cpp
   EarthPlayer.cpp FirePlayer.cpp WaterPlayer.cpp Spell.cpp Player.cpp
   unitTest.h FireJourney.h WaterJourney.h EarthJourney.h AirJourney.h -o main
 */

// all monster classes
#include "airMonster.h"
#include "earthMonster.h"
#include "elementalDragon.h"
#include "fireMonster.h"
#include "monster.h"
#include "waterMonster.h"

// all player classes
#include <iostream>

#include "AirPlayer.h"
#include "EarthPlayer.h"
#include "FirePlayer.h"
#include "Player.h"
#include "WaterPlayer.h"
#include "menu.h"

class unitTesting {
 private:
  // create monster objects
  airMonster AirMonsters;
  earthMonster EarthMonsters;
  fireMonster FireMonsters;
  waterMonster WaterMonsters;
  elementalDragon ElementalDragons;

  // create player objects
  Player _Player;
  AirPlayer Air_Player;
  EarthPlayer Earth_Player;
  FirePlayer Fire_Player;
  WaterPlayer Water_Player;

  // To store whether test failed or passed
  bool allMonsterGetterTestPass = true;
  bool allMonsterDamageRecieveTestPass = true;
  bool allMonsterAttackPass = true;
  bool allPlayerGetterTestPass = true;
  bool allPlayerSetterTestPass = true; 
  bool allPlayerDamageRecieveTestPass = true; 
  bool allPlayerAttackPass = true; 
  bool allPlayerDrinkPotionPass = true;
  bool allSpellGetterTestPass = true; 
  bool allPlayerSpecialAttackPass = true; 

 public:
  // Monsters (with random number in (int playersDefence))
  void testMonsterGetters() {  // Check getters
                               // health

    if (AirMonsters.get_airHealth() != 100) {  // if not equal to set attribute
      cout << "Air Monster Health Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (EarthMonsters.get_earthHealth() !=
        150) {  // if not equal to set attribute
      cout << "Earth Monster Health Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (FireMonsters.get_fireHealth() !=
        100) {  // if not equal to set attribute
      cout << "Fire Monster Health Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (WaterMonsters.get_waterHealth() !=
        200 + 10 + 10 + 10) {  // consider 3x 10+ health from monsters attack &
                               // if not equal to set attribute
      cout << "Water Monster Health Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (ElementalDragons.get_elementalHealth() !=
        400) {  // if not equal to set attribute
      cout << "Elemental Dragon Health Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }

    // attack
    if (AirMonsters.get_airAttack() !=
        50 + 15) {  // if not equal to set attribute
      // + 15 due to the 3x +5 permanent atk increase from the monster attack
      // tests
      cout << "Air Monster Attack Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (EarthMonsters.get_earthAttack() !=
        40) {  // if not equal to set attribute
      cout << "Earth Monster Attack Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (FireMonsters.get_fireAttack() != 65) {  // if not equal to set attribute
      cout << "Fire Monster Attack Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (WaterMonsters.get_waterAttack() !=
        50) {  // if not equal to set attribute
      cout << "Water Monster Attack Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (ElementalDragons.get_elementalAttack() !=
        25) {  // if not equal to set attribute
      cout << "Elemental Dragon Attack Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }

    // defence
    if (AirMonsters.get_airDefence() != 50) {  // if not equal to set attribute
      cout << "Air Monster Defence Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (EarthMonsters.get_earthDefence() !=
        65 + 5 + 5 + 5) {  // consider 3x +5 from monster attack if not equal to
                           // set attribute
      cout << "Earth Monster Defence Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (FireMonsters.get_fireDefence() !=
        35) {  // if not equal to set attribute
      cout << "Fire Monster Defence Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (WaterMonsters.get_waterDefence() !=
        30) {  // if not equal to set attribute
      cout << "Water Monster Defence Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (ElementalDragons.get_elementalDefence() !=
        100) {  // if not equal to set attribute
      cout << "Elemental Dragon Defence Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }

    // name
    if (AirMonsters.get_airName() !=
        "Amaya") {  // if not equal to set attribute
      cout << "Air Monster Name Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (EarthMonsters.get_earthName() !=
        "Rowan") {  // if not equal to set attribute
      cout << "Earth Monster Name Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (FireMonsters.get_fireName() !=
        "Blazair") {  // if not equal to set attribute
      cout << "Fire Monster Name Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (WaterMonsters.get_waterName() !=
        "Andreas") {  // if not equal to set attribute
      cout << "Water Monster Name Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }
    if (ElementalDragons.get_elementalName() !=
        "Elegon") {  // if not equal to set attribute
      cout << "Elemental Dragon Name Getter Failed! " << endl;
      allMonsterGetterTestPass = false;
    }

    if (allMonsterGetterTestPass == true) {  // if all getter tests passes
      cout << "(All Monster Getter Tests Passed!)" << endl;
    }
  }

  void testMonsterDamageRecieved() {  // Check damage recieved
    // air monster
    if (AirMonsters.damageRecieved(1000) != 950) {  // big number
      cout << "Air Monsters Damage Recieved Big Number Test Failed!" << endl;
      if (AirMonsters.get_airHealth() != 0) {  // monsters health should be 0
        cout << "Air Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }
    if (AirMonsters.damageRecieved(0) != 0) {  // edge case 0
      cout << "Air Monsters Damage Recieved Edge Case Test Failed!" << endl;
      if (AirMonsters.get_airHealth() !=
          200) {  // should do 0 damage to monster
        cout << "Air Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }
    if (AirMonsters.damageRecieved(-50) != 0) {  // negative number
      cout << "Air Monsters Damage Recieved Negative Number Test Failed!"
           << endl;
      if (AirMonsters.get_airHealth() !=
          200) {  // should do 0 damage to monster
        cout << "Air Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }

    // earth monster
    if (EarthMonsters.damageRecieved(1000) !=
        920) {  // big number (-15 from monster attack 3x before)
      cout << "Earth Monsters Damage Recieved Big Number Test Failed!" << endl;
      if (EarthMonsters.get_earthHealth() !=
          0) {  // monsters health should be 0
        cout << "Earth Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }
    if (EarthMonsters.damageRecieved(0) != 0) {  // edge case 0
      cout << "Earth Monsters Damage Recieved Edge Case Test Failed!" << endl;
      if (EarthMonsters.get_earthHealth() !=
          200) {  // should do 0 damage to monster
        cout << "Earth Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }
    if (EarthMonsters.damageRecieved(-50) != 0) {  // negative number
      cout << "Earth Monsters Damage Recieved Negative Number Test Failed!"
           << endl;
      if (EarthMonsters.get_earthHealth() !=
          200) {  // should do 0 damage to monster
        cout << "Earth Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }

    // fire monster
    if (FireMonsters.damageRecieved(1000) != 965) {  // big number
      cout << "Fire Monsters Damage Recieved Big Number Test Failed!" << endl;
      if (FireMonsters.get_fireHealth() != 0) {  // monsters health should be 0
        cout << "Fire Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }
    if (FireMonsters.damageRecieved(0) != 0) {  // edge case 0
      cout << "Fire Monsters Damage Recieved Edge Case Test Failed!" << endl;
      if (FireMonsters.get_fireHealth() !=
          200) {  // should do 0 damage to monster
        cout << "Fire Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }
    if (FireMonsters.damageRecieved(-50) != 0) {  // negative number
      cout << "Fire Monsters Damage Recieved Negative Number Test Failed!"
           << endl;
      if (FireMonsters.get_fireHealth() !=
          200) {  // should do 0 damage to monster
        cout << "Fire Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }

    // water monster
    if (WaterMonsters.damageRecieved(1000) != 970) {  // big number
      cout << "Water Monsters Damage Recieved Big Number Test Failed!" << endl;
      if (WaterMonsters.get_waterHealth() !=
          0) {  // monsters health should be 0
        cout << "Water Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }
    if (WaterMonsters.damageRecieved(0) != 0) {  // edge case 0
      cout << "Water Monsters Damage Recieved Edge Case Test Failed!" << endl;
      if (WaterMonsters.get_waterHealth() !=
          200) {  // should do 0 damage to monster
        cout << "Water Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }
    if (WaterMonsters.damageRecieved(-50) != 0) {  // negative number
      cout << "Water Monsters Damage Recieved Negative Number Test Failed!"
           << endl;
      if (WaterMonsters.get_waterHealth() !=
          200) {  // should do 0 damage to monster
        cout << "Water Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }

    // elemental dragon
    if (ElementalDragons.damageRecieved(1000) != 900) {  // big number
      cout << "Elemental Dragon Damage Recieved Big Number Test Failed!"
           << endl;
      if (ElementalDragons.get_elementalHealth() !=
          0) {  // monsters health should be 0
        cout << "Elemental Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }
    if (ElementalDragons.damageRecieved(0) != 0) {  // edge case 0
      cout << "Elemental Dragon Damage Recieved Edge Case Test Failed!" << endl;
      if (ElementalDragons.get_elementalHealth() !=
          200) {  // should do 0 damage to monster
        cout << "Elemental Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }
    if (ElementalDragons.damageRecieved(-50) != 0) {  // negative number
      cout << "Elemental Dragon Damage Recieved Negative Number Test Failed!"
           << endl;
      if (ElementalDragons.get_elementalHealth() !=
          200) {  // should do 0 damage to monster
        cout << "Elemental Monsters Damage Health Change Test Failed!" << endl;
      }
      allMonsterDamageRecieveTestPass = false;
    }

    if (allMonsterDamageRecieveTestPass ==
        true) {  // if all getter tests passes
      cout << "(All Monster Damage Recieved Tests Passed!)" << endl;
    }
  }

  void testMonsterattack() {  // Check attack

    // Air Monster have to consider permanent attack increase per attack
    if (AirMonsters.attack(1000) != 0) {  // big number
      cout << "Air Monsters Attack Big Number Test Failed!" << endl;
      if (AirMonsters.get_airAttack() == 50 + 5) {
        cout << "Air Monsters Attack Increase Big Number Test Failed!" << endl;
      }
      allMonsterAttackPass = false;
    }
    if (AirMonsters.attack(0) != 55) {  // edge case 0
      cout << "Air Monsters Attack Edge Case Test Failed!" << endl;
      if (AirMonsters.get_airAttack() ==
          50 + 5 + 5) {  // check if atk increased
        cout << "Air Monsters Attack Increase Big Number Test Failed!" << endl;
      }
      allMonsterAttackPass = false;
    }
    if (AirMonsters.attack(-50) != 110) {  // negative number
      cout << "Air Monsters Attack Negative Test Failed!" << endl;
      if (AirMonsters.get_airAttack() ==
          50 + 5 + 5) {  // check if atk increased
        cout << "Air Monsters Attack Increase Big Number Test Failed!" << endl;
      }
      allMonsterAttackPass = false;
    }

    // earth monster
    if (EarthMonsters.attack(1000) != 0) {  // big number
      cout << "Earth Monsters Attack Big Number Test Failed!" << endl;
      if (EarthMonsters.get_earthDefence() ==
          65 + 5) {  // check if def increased
        cout << "Earth Monsters Defence Increase Big Number Test Failed!"
             << endl;
      }
      allMonsterAttackPass = false;
    }
    if (EarthMonsters.attack(0) != 40) {  // edge case 0
      cout << "Earth Monsters Attack Edge Case Test Failed!" << endl;
      if (EarthMonsters.get_earthDefence() ==
          65 + 5 + 5) {  // check if def increased
        cout << "Earth Monsters Defence Increase Big Number Test Failed!"
             << endl;
      }
      allMonsterAttackPass = false;
    }
    if (EarthMonsters.attack(-50) != 90) {  // negative number
      cout << "Earth Monsters Attack Negative Test Failed!" << endl;
      if (EarthMonsters.get_earthDefence() ==
          65 + 5 + 5 + 5) {  // check if def increased
        cout << "Earth Monsters Defence Increase Big Number Test Failed!"
             << endl;
      }
      allMonsterAttackPass = false;
    }

    // fire monster
    // consider extra 5 damage that ignores def
    if (FireMonsters.attack(1000) != 5) {  // big number
      cout << "Fire Monsters Attack Big Number Test Failed!" << endl;
      allMonsterAttackPass = false;
    }
    if (FireMonsters.attack(0) != 70) {  // edge case 0
      cout << "Fire Monsters Attack Edge Case Test Failed!" << endl;
      allMonsterAttackPass = false;
    }
    if (FireMonsters.attack(-50) != 120) {  // negative number
      cout << "Fire Monsters Attack Negative Test Failed!" << endl;
      allMonsterAttackPass = false;
    }

    // water monster
    // consider increase health by 5 per attack
    if (WaterMonsters.attack(1000) != 0) {  // big number
      cout << "Water Monsters Attack Big Number Test Failed!" << endl;
      if (WaterMonsters.get_waterHealth() ==
          200 + 5) {  // check if HP increased
        cout << "Water Monsters HP Increase Big Number Test Failed!" << endl;
      }
      allMonsterAttackPass = false;
    }
    if (WaterMonsters.attack(0) != 50) {  // edge case 0
      cout << "Water Monsters Attack Edge Case Test Failed!" << endl;
      if (WaterMonsters.get_waterHealth() ==
          200 + 5 + 5) {  // check if HP increased
        cout << "Water Monsters HP Increase Big Number Test Failed!" << endl;
      }
      allMonsterAttackPass = false;
    }
    if (WaterMonsters.attack(-50) != 100) {  // negative number
      cout << "Water Monsters Attack Negative Test Failed!" << endl;
      if (WaterMonsters.get_waterHealth() ==
          200 + 5 + 5 + 5) {  // check if HP increased
        cout << "Water Monsters HP Increase Big Number Test Failed!" << endl;
      }
      allMonsterAttackPass = false;
    }

    // elemental dragon uses all of these so no testing needed
    system("clear");  // because it outputs text other than the damage number
    // clear terminal for better user experience (comment system("clear") if All
    // Monster Attack Tests Passed! is not showing and go through everthing
    // sorry)
    if (allMonsterAttackPass == true) {  // if all damage recieved tests passes
      cout << "(All Monster Attack Tests Passed!)" << endl;
    }
  }
  
  void testPlayerGetters(){

    // Air Players
    if (Air_Player.getHealth() != 250){
      cout << "Air Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Air_Player.getAttack() != 130){
      cout << "Air Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Air_Player.getDefense() != 30){
      cout << "Air Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Air_Player.getHealthPotion() != 5){
      cout << "Air Player Getter Failed!" << endl;
      allPlayerGetterTestPass = false;
    }

    // Earth Players
    if (Earth_Player.getHealth() != 300){
      cout << "Earth Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Earth_Player.getAttack() != 100){
      cout << "Earth Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Earth_Player.getDefense() != 35){
      cout << "Earth Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Earth_Player.getHealthPotion() != 5){
      cout << "Earth Player Getter Failed!" << endl;
      allPlayerGetterTestPass = false;
    }

    // Fire Players
    if (Fire_Player.getHealth() != 250){
      cout << "Fire Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Fire_Player.getAttack() != 150){
      cout << "Fire Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Fire_Player.getDefense() != 15){
      cout << "Fire Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Fire_Player.getHealthPotion() != 5){
      cout << "Fire Player Getter Failed!" << endl;
      allPlayerGetterTestPass = false;
    }

    // Water Players
    if (Water_Player.getHealth() != 300){
      cout << "Water Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Water_Player.getAttack() != 125){
      cout << "Water Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Water_Player.getDefense() != 20){
      cout << "Water Player Getter Failed!" << endl; 
      allPlayerGetterTestPass = false;
    }

    if (Water_Player.getHealthPotion() != 5){
      cout << "Water Player Getter Failed!" << endl;
      allPlayerGetterTestPass = false;
    }

    if (allPlayerGetterTestPass == true){
      cout << "(All Player Getters Passed!)" << endl; 
    }
  }

  void testPlayerSetters(){
    int testNum = 233;
    string playerName = "Jumpy Joe"; 
    _Player.setPlayerName("Jumpy Joe"); 
    _Player.setHealth(testNum);
    _Player.setAttack(testNum);
    _Player.setDefense(testNum);
    _Player.setHealthPotion(testNum);

    if (_Player.getPlayerName() != playerName){
      allPlayerSetterTestPass = false;
    }

    if (_Player.getHealth() != testNum){
      allPlayerSetterTestPass = false;
    }

    if (_Player.getAttack() != testNum){
      allPlayerSetterTestPass = false;
    }

    if (_Player.getDefense() != testNum){
      allPlayerSetterTestPass = false;
    }
    if (_Player.getHealthPotion() != testNum){
      allPlayerSetterTestPass = false;
    }
    if (allPlayerSetterTestPass == true){
      cout << "(All Player Setters Passed!)" << endl; 
    }
  }

  void testPlayerDamageRecieved(){
    int monsterAtk1 = 10000; // Big number 
    int monsterAtk2 = 0; // Edge case 
    int monsterAtk3 = -10; // Negative number 
    _Player.setHealth(200); // Set player's health

    if (_Player.calculateDmgRecieved(monsterAtk1) != 9800){
      allPlayerDamageRecieveTestPass = false; 
    }
    _Player.setHealth(200); // re-set player's health

    if (_Player.calculateDmgRecieved(monsterAtk2) != -200){
      allPlayerDamageRecieveTestPass = false; 
    }
    _Player.setHealth(200); // re-set player's health

    if (_Player.calculateDmgRecieved(monsterAtk3) != -210){
      allPlayerDamageRecieveTestPass = false; 
    }
    _Player.setHealth(200); // re-set player's health

    if (allPlayerDamageRecieveTestPass == true){
      cout << "(All Player Damage Recieved Test Passed!)" << endl; 
    }
  }

  void testPlayerDamageDone(){
    int monsterDef1 = 100000; // Big number 
    int monsterDef2 = 0; // Edge case 
    int monsterDef3 = -10; // Negative number
    _Player.setAttack(990); // Set player's attack

    if (_Player.calculateDmgDone(monsterDef1) != 990){
      allPlayerDamageRecieveTestPass = false; 
    }
    if (_Player.calculateDmgDone(monsterDef2) != 990){
      allPlayerDamageRecieveTestPass = false; 
    }
    if (_Player.calculateDmgDone(monsterDef3) != 990){
      allPlayerDamageRecieveTestPass = false; 
    }

    if (allPlayerAttackPass == true){
      cout << "(All Player Damage Done Test Passed!)" << endl; 
    }
  }

  void testPlayerDrinkPotion(){
    // Air Player
    if (Air_Player.drinkPotion() != 250){
      allPlayerDrinkPotionPass = false; 
    }
    // Earth Player
    if (Earth_Player.drinkPotion() != 300){
      allPlayerDrinkPotionPass = false; 
    }
    // Fire Player
    if (Fire_Player.drinkPotion() != 250){
      allPlayerDrinkPotionPass = false; 
    }
    // Water Player
    if (Water_Player.drinkPotion() != 300){
      allPlayerDrinkPotionPass = false; 
    }

    if ( allPlayerDrinkPotionPass == true){
      cout << "(All Player Drink Potion Test Passed!)" << endl; 
    }
  }

  // Air -> Earth -> Fire -> Water ( Atk and Def)
  void testPlayerSpellGetter(){
    // Atk Spells
    // Air Player
    if(Air_Player.getAirAtkSpell() != 50){
      allSpellGetterTestPass = false; 
    }
    // Earth Player
    if(Earth_Player.getEarthAtkSpell() != 25){
      allSpellGetterTestPass = false; 
    }
    // Fire Player
    if(Fire_Player.getFireAtkSpell() != 50){
      allSpellGetterTestPass = false; 
    }
    // Water Player
    if(Water_Player.getWaterAtkSpell() != 75){
      allSpellGetterTestPass = false; 
    }
    // Def Spells
    // Air Player
    if(Air_Player.getAirDefSpell() != 50){
      allSpellGetterTestPass = false; 
    }
    // Earth Player
    if(Earth_Player.getEarthDefSpell() != 75){
      allSpellGetterTestPass = false; 
    }
    // Fire Player
    if(Fire_Player.getFireDefSpell() != 50){
      allSpellGetterTestPass = false; 
    }
    // Water Player
    if(Water_Player.getWaterDefSpell() != 25){
      allSpellGetterTestPass = false; 
    }
    if (allSpellGetterTestPass == true){
      cout << "(All Player Spell Getters Test Passed!)" << endl; 
    }
  }

// bool allPlayerSpecialAttackPass = true;
// Air, Earth, Fire, Water
  void testPlayerSpecialAttack(){
    int monsterDef1 = 10000; // Big Number
    int monsterDef2 = 0; // Edge Case
    int monsterDef3 = -6; // Negative Number 

    // Air Player
    if (Air_Player.useWindSlash(monsterDef1) != -9850){
      allPlayerSpecialAttackPass = false; 
    }
    if (Air_Player.useWindSlash(monsterDef2) != 150){
      allPlayerSpecialAttackPass = false; 
    }
    if (Air_Player.useWindSlash(monsterDef3) != 156){
      allPlayerSpecialAttackPass = false; 
    }
    // Earth Player
    if (Earth_Player.useGroundShake(monsterDef1) != -9900){
      allPlayerSpecialAttackPass = false; 
    }
    if (Earth_Player.useGroundShake(monsterDef2) != 100){
      allPlayerSpecialAttackPass = false; 
    }
    if (Earth_Player.useGroundShake(monsterDef3) != 106){
      allPlayerSpecialAttackPass = false; 
    }
    // Fire Player
    if (Fire_Player.useFireStrike(monsterDef1) != -9850){
      allPlayerSpecialAttackPass = false; 
    }
    if (Fire_Player.useFireStrike(monsterDef2) != 150){
      allPlayerSpecialAttackPass = false; 
    }
    if (Fire_Player.useFireStrike(monsterDef3) != 156){
      allPlayerSpecialAttackPass = false; 
    }    
    // Water Player
    if (Water_Player.useWaterFlood(monsterDef1) != -9900){
      allPlayerSpecialAttackPass = false; 
    }
    if (Water_Player.useWaterFlood(monsterDef2) != 100){
      allPlayerSpecialAttackPass = false; 
    }
    if (Water_Player.useWaterFlood(monsterDef3) != 106){
      allPlayerSpecialAttackPass = false; 
    }  

    if (allPlayerSpecialAttackPass == true){
      cout << "(All Player Special Attack Test Passed!)" << endl; 
    } 
  }

};

#endif