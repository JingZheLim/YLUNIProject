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

// all journeys
#include "AirJourney.h"
#include "EarthJourney.h"
#include "FireJourney.h"
#include "WaterJourney.h"

class unitTesting {
 private:
  // create monster objects
  airMonster AirMonsters;
  earthMonster EarthMonsters;
  fireMonster FireMonsters;
  waterMonster WaterMonsters;
  elementalDragon ElementalDragons;

  //
  bool allMonsterGetterTestPass = true;
  bool allMonsterDamageRecieveTestPass = true;
  bool allMonsterAttackPass = true;

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
      cout << "All Monster Getter Tests Passed!" << endl;
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
      cout << "All Monster Damage Recieved Tests Passed!" << endl;
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
      cout << "All Monster Attack Tests Passed!" << endl;
    }
  }

  /* Player (with random number in (int monsterDefense))
         Check setters and getters
         Check calculateDmgDone
         Check calculateDmgRecieved
         Check drinkPotion
         Check Spells
         Check Special Ability Damage
          */
};

#endif