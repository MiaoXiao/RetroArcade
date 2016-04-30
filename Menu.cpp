#include "Menu.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

Menu::Menu(string name) {
    for(int i = 0; i < name.size(); ++i) {  // Converts name to uppercase
        name.at(i) = toupper(name.at(i));
    }
    menuName = name;
}

string Menu::getName() const {
    return menuName;
}

/* Creates an Option object with the parameters name and its corresponding 
   action (0 = go back a menu, 1 = go to next menu, 2 = run game or highscore).
   Then pushes the Option into optionList vector. */
   
void Menu::addOption(string name, int action) {
    Option option(name, action);
    optionList.push_back(option);
    return;
}

// Outputs menu option in the form 1. ... 2. ... 
void Menu::display() const{
    int counter = 1;
    for (unsigned i = 0; i < optionList.size(); i++){
        cout << counter << ". " << optionList.at(i).name << endl;
        counter++;
    }
    return;
}