#ifndef HIGHSCORE
#define HIGHSCORE

#include <string>
#include <vector>
using namespace std;

class Highscore {
    public:
    vector<string> names;   //list of player names
    vector<int> scores;     //list of player scores parallel to the names
    
    void prompt(int);           //passes in a score and prompts for a name
    void display();             //displays all current scores in order
    void save();                //saves all scores to "Highscore.txt"
    void load();                //loads all scores in "Highscore.txt" to the score database
    void clear();               //clears all names and scores
    
    private:
    void addScore(string, int); //adds and sorts scores and names
    void sort();                //sorts the scores from highest to lowest and keeps vectors parallel
    
};

#endif