#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#define PLAYER1INDEX        0
#define PLAYER2INDEX        1
#define PLAYER3INDEX        2
#define PLAYER4INDEX        3

#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;
using std::ofstream;

#include "Player.h"
#include "Board.h"

class Game {
    public:
    Game();
    ~Game();
    void addPlayers(vector<Player*> players);
    vector<Player*> getPlayers();
    LinkedList* getTileBag();
    void printLinkedList(ofstream& saveFile, LinkedList* list);
    void printVector(ofstream& saveFile,vector<string> boardTiles);
    void saveGame(string fileName, int numPlayers);
    Board* getBoard();

    private:
    vector<Player*> players;
    LinkedList* tileBag;
    Board* board;
};

#endif