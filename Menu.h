#ifndef MENU_H
#define MENU_H

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct Option {
    string name;
    int action;
    // 0 = go back a menu
    // 1 = go to next menu
    // 2 = run game or highscore
    Option(string name, int action): name(name), action(action) {}
};

class Menu {
  private:
    vector<Option> optionList;
    string menuName;
    
  public:
    Menu(string name);
    string getName() const;
    void addOption(string name, int action);
    void display() const;
  
};

#endif