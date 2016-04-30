#ifndef HANGMAN_H
#define HANGMAN_H
#include <vector>

using namespace std;

class Hangman {
    public:
        void intro();
        void play();
        string getWord(const vector<string>&);
        bool guessWord(string word);
        
        int score;
        void fill(vector<string>&);
    
};

#endif