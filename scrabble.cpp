#include "Tile.h"
#include "LinkedList.h"
#include "Game.h"
#include "Node.h"
#include "Player.h"
#include "Load.h"

#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::cin;

#define NUM_PLAYERS     2

void showCredits();
void showMenu();
void loadGame();
void startNewGame();
bool isUpper(string &input);
void playGame(LinkedList* tileBag, vector<Player*> players, Board* board, Game* game, int numPlayers);
vector<string> splitStringToVec(string input, vector<string> vec);
void printWinner(vector<Player*> players);
inline bool fileExists (const std::string& name);
int returnCharValue(char c);
void saveHighScore(string fileName, vector<std::pair<int,string> > highScores);
void printTopScores();

#define EXIT_SUCCESS    0

int main(void) {
   // LinkedList* list = new LinkedList();
   // delete list;
   showMenu();

   std::cout << "TODO: Implement Scrabble!" << std::endl;

   return EXIT_SUCCESS;
}

void showCredits() {
   cout << "----------------------------------" << endl;
   cout << "Name: Jed Opie" << endl;
   cout << "Student ID: s3868658" << endl;
   cout << "Email: s3868658@student.rmit.edu.au" << endl;
   cout << endl;

   cout << "Name: Mohamed Nur" << endl;
   cout << "Student ID: s3841634" << endl;
   cout << "Email: s3841634@student.rmit.edu.au" << endl;
   cout << endl;

   cout << "Name: Mohammad Abu Taleb Rifat" << endl;
   cout << "Student ID: s3833673" << endl;
   cout << "Email: s3833673@student.rmit.edu.au" << endl;
   cout << endl;

   cout << "Name: Xiu Bin Guo" << endl;
   cout << "Student ID: s3841074" << endl;
   cout << "Email: s3841074@student.rmit.edu.au" << endl;
   cout << "----------------------------------" << endl;
   cout << endl;

   showMenu();
}

void showMenu() {
   cout << "Welcome to Scrabble!" << endl;
   cout << "-------------------" << endl;

   string input;
   bool quit = false;

   cout << "Menu" << endl;
   cout << "----" << endl;
   cout << "1. New Game" << endl;
   cout << "2. Load Game" << endl;
   cout << "3. Credits (Show student information)" << endl;
   cout << "4. Quit"<< endl;
   cout << "\nType \"help\" for further information" << endl;
   cout << endl;

   cout << "> ";
   cin >> input;

   while (input != "1" || input == "2" || input != "3" || input != "4") {
      if (cin.eof()) {
         quit = true;
         exit(EXIT_SUCCESS);
      }
      else if (input == "1") {
         startNewGame();
      }
      else if (input == "2") {
         loadGame();
      }
      else if (input == "3") {
         showCredits();
      }
      else if (input == "4") {
         cout << "Goodbye" << endl;
         exit(EXIT_SUCCESS);
      }
      else if (input == "help") {
         cout << "To start a new game, enter \'1\'." << endl;
         cout << "To load a past game, enter  \'2\'." << endl;
         cout << "To show the credits of our application, enter \'3\'." << endl;
         cout << "To safely quit the application, enter \'4\'." << endl;
      }
      else {
         cout << "Invalid entry. Please try again" << endl;
      }
      cout << "> ";
      cin >> input;
   }
}

void startNewGame() {
   string player1Name;
   string player2Name;
   string player3Name;
   string player4Name;
   vector<Player*> players;
   cout << "2 Player Mode: Enter \'2\'" << endl;
   cout << "3 Player Mode: Enter \'3\'" << endl;
   cout << "4 Player Mode: Enter \'4\'" << endl;
   string numPlayers;
   cout << "> ";
   cin >> numPlayers;
   if (cin.eof()) {
      exit(EXIT_SUCCESS);
   }

   while (numPlayers != "2" && numPlayers !="3" && numPlayers !="4") {
       cout << "Invalid Input. Please Try Again" << endl;
       cin >> numPlayers;
    }
   Game* game = new Game();
    // shuffled tileBag initalised
    LinkedList* tileBag = game->getTileBag();

    cout << "Starting a New Game \n" << endl;
    if (numPlayers =="2" || numPlayers=="3" || numPlayers=="4") {
      cout << "Enter a name for Player 1 (Uppercase characters only)" << endl;
      cout << "> ";
      //  string player1Name;
      cin >> player1Name; // grab player1 name from user input
      if (cin.eof()) {
            exit(EXIT_SUCCESS);
         }
      while (!isUpper(player1Name)) {
         cout << "Sorry, please enter a name with uppercase characters" << endl;

         cin >> player1Name;
         if (cin.eof()) {
            exit(EXIT_SUCCESS);
         }
      }

      cout << "\n" << endl;
      cout << "Enter a name for Player 2 (Uppercase characters only)" << endl;
      cout << "> ";
      //  string player2Name;
      cin >> player2Name;
      if (cin.eof()) {
            exit(EXIT_SUCCESS);
         }

      while (!isUpper(player2Name)) {
         cout << "Sorry, please enter a name with uppercase characters" << endl;

         cin >> player2Name;
         if (cin.eof()) {
            exit(EXIT_SUCCESS);
         }
      }
      Player* player1 = new Player(player1Name);
      Player* player2 = new Player(player2Name);
      players.push_back(player1);
      players.push_back(player2);
    }
    if (numPlayers == "3" || numPlayers =="4") {
      cout << "\n" << endl;
      cout << "Enter a name for Player 3 (Uppercase characters only)" << endl;
      cout << "> ";
      //  string player2Name;
      cin >> player3Name;
      if (cin.eof()) {
            exit(EXIT_SUCCESS);
         }

      while (!isUpper(player3Name)) {
         cout << "Sorry, please enter a name with uppercase characters" << endl;

         cin >> player3Name;
         if (cin.eof()) {
            exit(EXIT_SUCCESS);
         }
      }
      Player* player3 = new Player(player3Name);
      players.push_back(player3);
    }
    if (numPlayers =="4") {
      cout << "\n" << endl;
      cout << "Enter a name for Player 4 (Uppercase characters only)" << endl;
      cout << "> ";
      //  string player2Name;
      cin >> player4Name;
      if (cin.eof()) {
            exit(EXIT_SUCCESS);
         }

      while (!isUpper(player4Name)) {
         cout << "Sorry, please enter a name with uppercase characters" << endl;

         cin >> player4Name;
         if (cin.eof()) {
            exit(EXIT_SUCCESS);
         }
      }
      Player* player4 = new Player(player4Name);
      players.push_back(player4);
    }

   //  }
    cout << endl;
    cout << "Type \"help\" at anytime for information on how to play!" << endl;
    cout << "Let's Play!" << endl;
    cout << endl;

   game->addPlayers(players);

   for (int i=0; i < players.size(); i++) {
      players[i]->initalisePlayerHand(tileBag);
   }

    Board* board = game->getBoard(); // declare & initalise board
    int playerAmount = std::stoi(numPlayers);

   playGame(tileBag, players, board, game, playerAmount); // Run main game loop
}

bool isUpper(string &input) {
    return std::all_of(input.begin(), input.end(), [](unsigned char c){ return std::isupper(c); });

}

vector<string> splitStringToVec(string input, vector<string> vec){
    std::stringstream ss(input);
    while (ss.good()) {
        string substr;
        getline(ss,substr,' ');
        vec.push_back(substr);
    }
    return vec;
}

void printWinner(vector<Player*> players) {
   // Read high score text file
   Player* winner = nullptr;
   string fileName = "highScores.txt";
   ifstream file;
   vector<std::pair<int,string> > highScores; //create vector with score-name pairs
   string name, scoreString;
   file.open(fileName);
   if (file.is_open()) {
      while (file.good()) {
         file >> scoreString; //read score as string
         file >> name; //read name
         int score = std::stoi(scoreString); // convert to int
         highScores.push_back(make_pair(score,name)); // add to highscore vector
      }
   }
   for (int i =0; i < players.size(); i++) {
      highScores.push_back(make_pair(players[i]->getScore(), players[i]->getName())); //push back current scores
   }

   sort(highScores.rbegin(), highScores.rend()); //sort high scores by score
   saveHighScore(fileName, highScores); //save new high scores to file

   cout << "Game over" << endl;
   for (int i =0; i < players.size(); i++) {
      cout << "Score for " << players[i]->getName() << ": " << players[i]->getScore() << endl;
   }
   winner = players[0];

   for (int i =0; i < players.size(); i++) {
      if (players[i]->getScore() > winner->getScore()) {
         winner = players[i];
      }
   }
    cout << "Player " << winner->getName() << " won!" << endl;

   cout << endl;
   printTopScores();

   cout << endl;
   cout << "Goodbye" << endl;
   exit(EXIT_SUCCESS);
}

void loadGame() {
   vector<Player*> players;
   string fileName;
   cout << endl;
   cout << "Enter the file name from which load a game" << endl;
   cout << "> ";
   cin >> fileName; // ask for saveFile from user
   if (cin.eof()) {
      exit(EXIT_SUCCESS);
   }
   while (!fileExists(fileName)) { //If file cannot be found, ask user to enter another attempt
      cout << "Sorry, this save file couldn't be found. Please try again" << endl;
      cout << "> ";
      cin >> fileName;
      if (cin.eof()) {
         exit(EXIT_SUCCESS);
      }
   }
   Load* load = new Load(fileName);
   load->loadGame(fileName);
   int numPlayers = load->getNumPlayers();
   // Create player objects
   Player* player1 = new Player(load->getPlayer1Name());
   player1->setScore(load->getPlayer1Score()); // set score

   // Set player hand linked list
   for (int i =0; i < load->getPlayer1Hand().size(); i++) {
      int j = load->getPlayer1Hand()[i][2] -'0';
      Tile* tile = new Tile(load->getPlayer1Hand()[i][0], j);
      player1->getPlayerHand()->addBack(tile);
   }
   players.push_back(player1); //add players to vector for gameLoop
   // create Player2 object
   Player* player2 = new Player(load->getPlayer2Name());
   player2->setScore(load->getPlayer2Score());

   // set player2's hand
   for (int i =0; i < load->getPlayer2Hand().size(); i++) {
      int j = load->getPlayer2Hand()[i][2] - '0'; // get value of letter
      Tile* tile = new Tile(load->getPlayer2Hand()[i][0], j); // make tile with first char of vector for tile letter
      player2->getPlayerHand()->addBack(tile); //add tile to player hand
   }
   players.push_back(player2);

   if (numPlayers ==3 || numPlayers==4) { //if 3 or 4 player mode
      Player* player3 = new Player(load->getPlayer3Name()); //create player object
      player3->setScore(load->getPlayer3Score()); // score
      for (int i =0; i < load->getPlayer3Hand().size(); i++) {
         int j = load->getPlayer3Hand()[i][2] - '0';
         Tile* tile = new Tile(load->getPlayer3Hand()[i][0], j);
         player3->getPlayerHand()->addBack(tile);
      }
      players.push_back(player3);
   }
   if (numPlayers==4) {
      Player* player4 = new Player(load->getPlayer4Name());
      player4->setScore(load->getPlayer4Score());
      for (int i =0; i < load->getPlayer4Hand().size(); i++) {
         int j = load->getPlayer4Hand()[i][2] - '0';
         Tile* tile = new Tile(load->getPlayer4Hand()[i][0], j);
         player4->getPlayerHand()->addBack(tile);
      }
      players.push_back(player4);
   }
   vector<Player*> finalPlayers; // finalPlayers sequencing for starting player
   // if player is current, add to final players
   for (int i =0; i < players.size(); i++) {
      if (load->getCurrentPlayer() == players[i]->getName()) {
         finalPlayers.push_back(players[i]);
      }
   }
   //  if player is not in finalPlayers, add to finalPlayers
   for (int i =0; i < players.size(); i++) {
      if (!(std::find(std::begin(finalPlayers), std::end(finalPlayers), players[i]) != std::end(finalPlayers))) {
         finalPlayers.push_back(players[i]);
      }
   }

   Game* game = new Game();
   LinkedList* tileBag = game->getTileBag(); // get linked list
   tileBag->clearLinkedList(); // Clear shuffled linked list
   Board* board = game->getBoard(); // initalise empty board

   for (int i =0; i < load->getTileBag().size(); i++) {
      int j = load->getTileBag()[i][2] - '0';
      Tile* tile = new Tile(load->getTileBag()[i][0], j); //Create tiles from save file
      tileBag->addBack(tile); // Add tile to empty tileBag
   }
   // insert saved tiles into empty board
   for (int i =0; i < load->getTilePositions().size(); i++) {
      string position;
      position = load->getTilePositions()[i].substr(2,4); // position substring
      char c = load->getTilePositions()[i][0]; // char (tile Letter)
      Tile* tile = new Tile(c, returnCharValue(c)); //Create new tile
      board->insertTile(position, tile); // Insert tile at given position
   }

   cout << endl;
   cout << "Scrabble Game Successfully Loaded!" << endl;

   for (int i =0; i < players.size(); i++) {
      if (players[i]->getPlayerHand()->size() < 7) {
         players[i]->addTilesToHand(tileBag);
      }
   }
   game->addPlayers(finalPlayers); //register players for saving mechanic

   playGame(tileBag, finalPlayers, board, game, numPlayers);

}

void playGame(LinkedList* tileBag, vector<Player*> players, Board* board, Game* game, int numPlayers) {
   string input;
    char c;
    // int i = 0;
    while (tileBag->size() > 0) {
       cout << endl;
      for (int i = 0; i < numPlayers; i++) {
            if (tileBag->size() < 1) {
                     printWinner(players);
                  }
            players[i]->setCurrentTurn();
            cout << players[i]->getName() << ", it's your turn" << endl; // prints name of current player
            for (int i = 0; i < numPlayers; i++) {
               cout << "Score for " << players[i]->getName() << ": " << players[i]->getScore() << endl; //print name and scores
            }
            board->printBoard(); // print the board
            cout << endl;
            cout << "Your hand is" << endl;
            players[i]->getPlayerHand()->printLinkedList(); //print player's hand
            do {
               cout << "> ";
               std::getline(cin >> std::ws, input);
               if (cin.eof()) {
                  exit(EXIT_SUCCESS);
               }

               vector<string> inputs; 
               inputs = splitStringToVec(input, inputs);

               if (input == "quit") { //if player inputs "quit", exit game safely
               cout << "Goodbye" << endl;
               exit(EXIT_SUCCESS);
               }
               // if player inputs "place" and following input is valid, place tile on board at given location
               if (inputs[0] == "place" && board->inputValid(inputs[3]) && !board->locationFilled(inputs[3])) {
                  c = inputs[1][0];
                  if (players[i]->getPlayerHand()->isLetterinHand(c)) {
                     int j = players[i]->getPlayerHand()->searchForLetter(c);
                     Tile* tile = new Tile(*players[i]->getPlayerHand()->get(j));
                     board->insertTile(inputs[3], tile); // add to board
                     players[i]->getPlayerHand()->remove(j); // remove tile from hand
                     int addScore =0;
                     addScore += tile->value; //increment score by value of placed tile
                     players[i]->addToScore(addScore); // add to player's score
                     if (players[i]->getPlayerHand()->size() == 0) { //if player has zero tiles after turn, print bingo
                        cout << endl; 
                        cout << "BINGO!" << endl;
                        }
                     players[i]->resetPassTally(); // reset pass tally if make move
                  }
                  else {
                     cout << inputs[1] << " is not in your hand. Try again" << endl;
                     input ="";
                     // cout << board->locationFilled(inputs[3]);
                  }
               }
               else if (board->locationFilled(inputs[3]) == true) { //if location already filled
                     cout << "Sorry, a tile has already been placed there. Please try again." << endl;
                     }
               
               else if (input == "pass") {
                  players[i]->incrementPassTally(); //keeps tally of how many passes in a row
                  if (players[i]->getPassTally() == 2) {
                     cout << "That was " << players[i]->getName() << "'s second pass in a row!" << endl;
                     cout << endl;
                     cout << "Game Over" << endl;
                     cout << "Goodbye" << endl;
                     exit(EXIT_SUCCESS);
                  }
                  else {
                     input = "done";
                     cout << endl;
                  }
               }

               else if (inputs[0] == "replace") {
                  if (inputs[1] >= "A" && inputs[1] <= "Z") { // check if input is correct
                     if (players[i]->getPlayerHand()->isLetterinHand(inputs[1][0])) { // check if letter is in hand
                        int index = players[i]->getPlayerHand()->searchForLetter(inputs[1][0]);
                        Tile* tile = new Tile(*players[0]->getPlayerHand()->get(index)); //create reference to tile to be replaced
                        players[i]->getPlayerHand()->remove(index); // remove tile
                        players[i]->addTilesToHand(tileBag); //grab tile from tileBag
                        tileBag->addBack(tile); // add replaced tile to back of tileBag
                        players[i]->resetPassTally(); // reset pass tally
                        input = "done"; // end turn
                     }
                     else {
                        cout << "Sorry, " << inputs[1] << " is not in your hand. Try again." << endl;
                        input = "";
                     }
                  }
                  else {
                     cout << "Invalid entry. Please Try again." << endl;
                     input = "";
                  }
                  cout << endl;
               }

               else if (inputs[0] == "save") { 
                  cout << inputs[1];
                  game->saveGame(inputs[1],numPlayers); // save game with fileName given by user
                  cout << endl;
                  cout << "Game successfully saved" << endl;
               }

               else if (input == "done") {
                  cout << endl;
               }

               // HELP MENU - MILESTONE 3
               else if (input == "help") {
                  cout << "1. Placing a Tile:" << endl;
                  cout << "   To place a letter on the board, choose a tile from your hand and a coordinate to place it." << endl;
                  cout << "   To implement this, type \"place <letter> at <coordinate>\" - Make sure it is within the bounds of the board!" << endl;
                  cout << "   An example for your hand: " << "place " << players[i]->getPlayerHand()->get(0)->getLetter() << " at A0\n" << endl;

                  cout << "2. Replace a Tile in Your Hand" << endl;
                  cout << "   Replacing a letter in your hand will replace your chosen letter with another from the tile bag." << endl;
                  cout << "   To do this, type \"replace <letter>\" - Make sure the chosen letter is in your hand!" << endl;
                  cout << "   An example for your hand: replace " << players[i]->getPlayerHand()->get(0)->getLetter() << endl;
                  cout << endl;

                  cout << "3. Pass Turn" << endl;
                  cout << "   You may pass your turn if you don't want to take your turn. Be careful though, two passes in a row will end the game!" << endl;
                  cout << "   To do this, type \"pass\"" << endl;
                  cout << "   Doing so will automatically end your turn\n" << endl;

                  cout << "4. Quit Game" << endl;
                  cout << "   To safely quit the game, simply type \"quit\"" << endl;

                  cout << "5. Save Game" << endl;
                  cout << "   In order to save your game for a later time, type \"save <filename>\"" << endl;

                  cout << "Once you have entered your move(s), enter \"done\" to end your turn" << endl;
               }
               else {
                  cout << "Invalid Entry. Try again." << endl;
               }
         } while (input != "done");
         players[i]->addTilesToHand(tileBag); // once turn is complete, add tile to fill hand (will only add if needed)
         players[i]->endCurrentTurn();
      }
      }

      printWinner(players); // once tileBag is empty, print winners


}
// Checks if file can be found
inline bool fileExists (const std::string& name) {
   ifstream f(name.c_str());
   return f.good(); 
}

// Used to fill tiles for loading board
int returnCharValue(char c) {
   int retValue = 0;
   if (c == 'A' || c== 'E' || c== 'I' || c=='O' || c== 'U'|| c== 'L'|| c== 'N'|| c== 'S'|| c== 'T'|| c== 'R') {
      retValue = 1;
   }
   else if (c== 'D'|| c== 'G') {
      retValue = 2;
   }
   else if (c== 'B'|| c== 'C' || c== 'M'|| c== 'P') {
      retValue = 3;
   }
   else if (c== 'F'|| c== 'H'|| c== 'V'|| c== 'W'|| c== 'Y') {
      retValue = 4;
   }
   else if (c== 'K') {
      retValue = 5;
   }
   else if (c == 'J' || c== 'X') {
      retValue = 8;
   }
   else {
      retValue = 10;
   }
   return retValue;
}

void saveHighScore(string fileName, vector<std::pair<int,string> > highScores) { //save high scores to file
    ofstream saveFile;
    saveFile.open(fileName);
    if (saveFile.is_open()) {
        for (int i =0; i < highScores.size(); i++) { //iterate through score,name pairs
           if (i < highScores.size() -1) { // print new line if not last index
               saveFile << highScores[i].first << " " << highScores[i].second << "\n";
           }
           else {
              saveFile << highScores[i].first << " " << highScores[i].second;
           }
        }
    }
}

void printTopScores() {
   string fileName = "highScores.txt";
   ifstream file(fileName);
   cout << "---------------HIGH SCORES---------------" << endl;
   cout << "RANK:          SCORE:            NAME:          " << endl;
   if (file.is_open()) {
      for (int i =0; i < 5; i++) { // read first instances from file
         string score,name;
         file >> score;
         file >> name;
         cout << " " << i+1 << "              " << score << "               " << name << endl; // print rank,score,name
      }
   }
}
