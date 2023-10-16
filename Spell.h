#ifndef SPELL_H
#define SPELL_H
#include <string>

using namespace std;

// Players can have multiple spells
// Aggregation relationship w/ Player 

class Spell{

private: 
string spellName; 
int spellAttack;
int spellDefense; 

public:
string getSpellName();
int getSpellAttack();
int getSpellDefense(); 

// Constructors 
Spell(string spellName, int spellAttack); 
Spell(string spellName, int spellDefense); 

};
#endif 