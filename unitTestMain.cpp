#include "unitTesting.h"

int main() {
  unitTesting tests;
  tests.testMonsterattack();
  tests.testMonsterGetters();
  tests.testMonsterDamageRecieved();
  tests.testPlayerGetters();
  tests.testPlayerSetters();
  tests.testPlayerDamageRecieved();
  tests.testPlayerDamageDone();
  tests.testPlayerDrinkPotion();
  tests.testPlayerSpellGetter();
  tests.testPlayerSpecialAttack();

  return 0;
}