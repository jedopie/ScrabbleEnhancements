#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::ofstream;


int main(void) {
    vector<std::pair<int,string> > highscores;
    string filename = "highScores.txt";
    ifstream file(filename);
    string line;
    string scoreString, name;

    if (file.is_open()) {
        while(file.good()) {
            file >> scoreString;
            file >> name;
            int score = std::stoi(scoreString);
            highscores.push_back(make_pair(score,name));
        }
    }
    for (int i=0; i < highscores.size(); i++) {
        cout << highscores[i].first << " - " << highscores[i].second << endl;
    }
    string name1 = "jo";
    int score = 190;
    highscores.push_back(make_pair(score,name1));
    for (int i=0; i < highscores.size(); i++) {
        cout << highscores[i].first << " - " << highscores[i].second << endl;
    }
    cout << endl;
    sort(highscores.rbegin(), highscores.rend());
    for (int i=0; i < highscores.size(); i++) {
        cout << highscores[i].first << " - " << highscores[i].second << endl;
    }
    ofstream saveFile;
    saveFile.open(filename);
    if (saveFile.is_open()) {
        for (int i =0; i < highscores.size(); i++) {
            saveFile << highscores[i].first << " " << highscores[i].second << "\n";
        }
    }

    return EXIT_SUCCESS;
}