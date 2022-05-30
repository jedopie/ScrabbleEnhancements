#include "Load.h"

// Load game, then store variable into Player objects
// eg. player->setScore(load->getPlayer1Score())

Load::Load(string fileName) {
    this->fileName = fileName;

}
// Loads lines into their respective containers
// Player hand and tileBag first stored as vectors, to where they can be made into tile objects.
void Load::loadGame(string fileName) {
    string text;
    ifstream file;

    file.open(fileName);

    if(file.is_open()) {
        getline(file,text);
        numPlayers = std::stoi(text);
        getline(file,text);
        player1Name = text;
        getline(file,text);
        player1Score = std::stoi(text);
        getline(file, text);
        player1Hand = splitStringToVec(text, player1Hand); 

        getline(file,text);
        player2Name = text;
        getline(file, text);
        player2Score = std::stoi(text);
        getline(file,text);
        player2Hand = splitStringToVec(text,player2Hand);

        if (numPlayers ==3 || numPlayers == 4) {
            getline(file,text);
            player3Name = text;
            getline(file, text);
            player3Score = std::stoi(text);
            getline(file,text);
            player3Hand = splitStringToVec(text,player3Hand);
        }

        if (numPlayers == 4) {
            getline(file,text);
            player4Name = text;
            getline(file, text);
            player4Score = std::stoi(text);
            getline(file,text);
            player4Hand = splitStringToVec(text,player4Hand);
        }

        getline(file,text);
        tilePositions = splitStringToVec(text,tileBag);
        getline(file,text);
        tileBag = splitStringToVec(text,tileBag);

        getline(file,text);
        currentTurn = text;
    }
}

//Splits TileBag/Player Hand strings to <letter>-<value> and adds to string vector
vector<string> Load::splitStringToVec(string text, vector<string> bag) {
    std::stringstream ss(text);
    while (ss.good()) {
        string substr;
        getline(ss,substr,',');
        bag.push_back(substr);
    }
    return bag;
}

vector<string> Load::getTileBag() {
    return tileBag;
}

string Load::getPlayer1Name() {
    return player1Name;
}

int Load::getPlayer1Score() {
    return player1Score;
}

vector<string> Load::getPlayer1Hand() {
    return player1Hand;
}

string Load::getPlayer2Name() {
    return player2Name;
}

int Load::getPlayer2Score() {
    return player2Score;
}

vector<string> Load::getPlayer2Hand() {
    return player2Hand;
}

vector<string> Load::getTilePositions() {
    return tilePositions;
}

string Load::getCurrentPlayer() {
    return currentTurn;
}

// void Load::setPlayers(vector<Player*> players) {
//     this->players = players;
// }

// vector<Player*> Load::getPlayers() {
//     return this->players;
// }

int Load::getNumPlayers() {
    return numPlayers;
}

string Load::getPlayer3Name() {
    return player3Name;
}

int Load::getPlayer3Score() {
    return player3Score;
}
string Load::getPlayer4Name() {
    return player4Name;
}

int Load::getPlayer4Score() {
    return player4Score;
}

vector<string> Load::getPlayer3Hand() {
    return player3Hand;
}

vector<string> Load::getPlayer4Hand() {
    return player4Hand;
}