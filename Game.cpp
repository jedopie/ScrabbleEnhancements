#include "Game.h"

Game::Game() {
    LinkedList* orderedTileBag = new LinkedList();
    orderedTileBag->initaliseTileBag();
    tileBag = orderedTileBag->shuffleTileBag();
    board = new Board();
}

Game::~Game() {

}

void Game::addPlayers(vector<Player*> players) {
    this->players = players;
}

vector<Player*> Game::getPlayers() {
    return players;
}

LinkedList* Game::getTileBag() {
    return tileBag;
}

// Save game to .save file (Still need board)
void Game::saveGame(string fileName, int numPlayers) {
    ofstream saveFile;
    saveFile.open(fileName + ".save");
    saveFile << numPlayers << "\n";

    for (int i =0; i < numPlayers; i++) { // iterate through players
        string playerName = players[i]->getName(); //Write player details to file
        int playerScore = players[i]->getScore();
        LinkedList* playerHand = players[i]->getPlayerHand();
        
        saveFile << playerName << "\n"; // write name
        saveFile << playerScore << "\n"; // write score
        printLinkedList(saveFile, playerHand); //print hand
        if (i != numPlayers -1) {
            saveFile << "\n";
        }

    }
    
    vector<string> placedTiles = board->getPlacedTiles();
    // then board
    // tileBag already defined
    string currentPlayer;

    // Check for current player
    for (int i= 0; i < numPlayers; i++) {
        if (players[i]->isCurrentTurn() == true) {
            currentPlayer = players[i]->getName();
        }
        else {
            players[0]->isCurrentTurn();
        }
    }
    saveFile << "\n";

    // print board
    printVector(saveFile, placedTiles);
    saveFile << "\n";

    printLinkedList(saveFile, tileBag);
    saveFile << "\n" << currentPlayer;
}

// formatting input list for saveGame file or printing hand for player.
void Game::printLinkedList(ofstream& saveFile, LinkedList* list) {
    for (int i =0; i < list->size(); i++) {
        if (i < list->size() -1 ) {
            saveFile << list->get(i)->getLetter() << "-" << list->get(i)->getValue() << ",";
        }
        else {
            saveFile << list->get(i)->getLetter() << "-" << list->get(i)->getValue();
        }
    }
}

Board* Game::getBoard() {
    return board;
}

void Game::printVector(ofstream& saveFile, vector<string> boardTiles) {
    for (int i =0; i < boardTiles.size(); i++) {
        if (i < boardTiles.size() -1) {
            saveFile << boardTiles[i] << ",";
        }
        else {
            saveFile << boardTiles[i];
        }
    }
}
