#include "Highscore.h"
#include <fstream>
#include <iostream>
using namespace std;

void Highscore::prompt(int score) {
    string name;
    
    cout << "Enter your name: ";
    cin >> input;
    cout << endl;
    
    addScore(name, score);
}

void Highscore::display() {
    unsigned size = scores.size();
    
    for (unsigned i = 0; i < size; ++i) {
        cout << names.at(i) << ": " << scores.at(i) << endl;
    }
}

void Highscore::addScore(string name, int score) {
    names.push_back(name);
    scores.push_back(score);
    sort();
}

void Highscore::save() {
    unsigned size = scores.size();
    ofstream fout;
    
    fout.open("Highscore.txt");
    for(unsigned i = 0; i < size; ++i) {
        fout << names.at(i) << " " << scores.at(i) << endl;
    }
    fout.close();
}

void Highscore::load() {
    string name;
    int score;
    ifstream fin;
    
    fin.open("Highscore.txt");
    while (fin >> name) {
        fin >> score;
        addScore(name, score);
    }
    fin.close();
}

void Highscore::clear() {
    names.clear();
    scores.clear();
}

void Highscore::sort() {
    unsigned size = scores.size();
    unsigned index = 999;
    string name = "";
    int score = 0;
    
    for(unsigned i = 0; i < size; ++i) {
        index = i;
        for (unsigned j = i; j < size; ++j) {
            if(scores.at(j) > scores.at(i)) {
                index = j;
            }
        }
        score = scores.at(index);
        scores.at(index) = scores.at(i);
        scores.at(i) = score;
        name = names.at(index);
        names.at(index) = names.at(i);
        names.at(i) = name;
    }
}