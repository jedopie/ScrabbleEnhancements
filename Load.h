#ifndef ASSIGN2_LOAD_H
#define ASSIGN2_LOAD_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "LinkedList.h"
#include "Player.h"

using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;

class Load {
    public:
    Load(string fileName);
    void loadGame(string fileName);
    vector<string> splitStringToVec(string text, vector<string> bag);
    vector<string> getTileBag();
    vector<string> getPlayer1Hand();
    vector<string> getPlayer2Hand();
    vector<string> getPlayer3Hand();
    vector<string> getPlayer4Hand();
    vector<string> getTilePositions();
    string getPlayer1Name();
    string getPlayer2Name();
    string getPlayer3Name();
    string getPlayer4Name();
    int getPlayer1Score();
    int getPlayer2Score();
    int getPlayer3Score();
    int getPlayer4Score();
    string getCurrentPlayer();
    int getNumPlayers();

    private:
    string fileName;

    string player1Name;
    int player1Score;
    vector<string> player1Hand;

    string player2Name;
    int player2Score;
    vector<string> player2Hand;

    string player3Name;
    int player3Score;
    vector<string> player3Hand;

    string player4Name;
    int player4Score;
    vector<string> player4Hand;

    vector<string> tileBag;

    vector<string> tilePositions;

    string currentTurn;

    vector<Player*> players;

    int numPlayers;


};

#endif