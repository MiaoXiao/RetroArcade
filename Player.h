#ifndef PLAYER
#define PLAYER
#include <cstdlib>
#include <string>
using namespace std;

class Player {
    public:
    Player();
    Player(string, string, int, int, int, int, int, int);
    void setStats(int, int, int, int, int, int);
    void takeBack(Player);
    void takeDamage(Player);
    void takeConfidence(Player);
    void fullHeal();
    void display();
    
    string Name;
    string Class;
    int MaxAttack;
    int MinAttack;
    int CurrentHealth;
    int MaxHealth;
    int Confidence;
    int Combo;
};

#endif