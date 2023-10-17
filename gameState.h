#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <string>

class gameState {
    public:
    int playerHealth;
    int playerJourney;
    int potions;
    int playerStage;
    string playerName;

    void saveGame(int playerHealth, int healthPotions, string playerName, int playerJourney, int playerStage) {  // saves game
    gameState state;
    // store state
    state.playerHealth = playerHealth;
    state.potions = healthPotions;
    state.playerJourney = playerJourney;
    state.playerStage = playerStage;
    state.playerName = playerName;

    // write state to a save file
    ofstream output("save.dat");
    output << state.playerHealth << endl;
    output << state.potions << endl;
    output << state.playerJourney << endl;
    output << state.playerStage << endl;
    output << state.playerName << endl;
  }
};

#endif