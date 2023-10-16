#include "Spell.h"
#include <string>

using namespace std;

Spell::Spell(string spellName, int spellAttack){
    this->spellName = spellName;
    this->spellAttack = spellAttack;
}

Spell::Spell(int spellDefense, string spellName){
    this->spellName = spellName;
    this->spellDefense = spellDefense;
}

string Spell::getSpellName(){
    return spellName;
}

int Spell::getSpellAttack(){
    return spellAttack; 
}

int Spell::getSpellDefense(){
    return spellDefense; 
}