#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Hangman.h"

using namespace std;

void Hangman::play() {
    string word; vector<string> words; fill(words); srand(time(0)); string KeepGoing = "y"; bool status; score = 0;
    intro();
    while (KeepGoing == "y") {
        word = getWord(words);
        status = guessWord(word); if (status) { ++score; } else { --score; }
        cout << "Current Score: " << score << "\n\nWould you like to keep playing? (NO SPACES!) (y/n) "; cin >> KeepGoing;
        while (KeepGoing != "y" && KeepGoing != "n") { cout << "Invalid input. Please enter \"y\" for yes and \"n\" for no. >:( "; cin >> KeepGoing; }
    }
}

void Hangman::intro() {
    cout << "\033c" << "Welcome to Hangman!\n";
    cout << " ________\n |/      |\n |      (_)\n |      \\|/\n";
    cout << " |       |\n |      / \\" << "\n |\n_|___\n";
    
    return;
}

string Hangman::getWord(const vector<string> &words) { int num = rand() % words.size(); return words.at(num); }

void Hangman::fill(vector<string> &words) {
    words.push_back("azure"); words.push_back("bagpipes"); words.push_back("blitz"); words.push_back("buffalo"); words.push_back("dwarves"); words.push_back("fishhook"); words.push_back("galaxy");
    words.push_back("jiujitsu"); words.push_back("jaywalk"); words.push_back("keyhole"); words.push_back("microwave"); words.push_back("kiwifruit"); words.push_back("megahertz"); words.push_back("luxury");
    words.push_back("numbskull"); words.push_back("oxygen"); words.push_back("vaporize"); words.push_back("unworthy"); words.push_back("xylophone"); words.push_back("youthful"); words.push_back("zombie");
    words.push_back("program"); words.push_back("ensure"); words.push_back("pixel"); words.push_back("quorum"); words.push_back("schizophrenia"); words.push_back("whiskey"); words.push_back("zodiac");
    words.push_back("razzmatazz"); words.push_back("pneumonia"); words.push_back("nightclub"); words.push_back("knapsack"); words.push_back("duplex"); words.push_back("askew"); words.push_back("exodus"); return;
}

bool Hangman::guessWord(string word) {
    int numWrong = 0;
    int numCorrect = 0;
    
    vector<char> usedLetters;
    vector<string> guessedLetters(word.size());
    for (unsigned i = 0; i < guessedLetters.size(); ++i) {
        guessedLetters.at(i) = "_ ";
    }
    string guess = "";
    char guessCopy = ' ';
    
    while (numWrong < 9 && numCorrect != word.size()) {
        switch (numWrong) {
            case 0:
                cout << "\033c"; 
                cout << " ________\n |/      |\n |      \n |      \n";
                cout << " |       \n |      " << "\n |\n_|___\n\n";
                
                for (unsigned i = 0; i < guessedLetters.size(); ++i) {
                    cout << guessedLetters.at(i);
                }
                
                cout << "\nUsed Letters: ";
                for (unsigned i = 0; i < usedLetters.size(); ++i) {
                    cout << usedLetters.at(i) << " ";
                }
                
                cout << "\nGuess a letter or word: \n";
                cin  >> guess;
                
                if (guess == word || numCorrect == word.size()) {
                    cout << "\nYou won!\n";
                    return true;
                } else if (word.find(guess) != string::npos) {
                    guessCopy = guess.at(0);
                    usedLetters.push_back(guessCopy);
                    for (unsigned i = 0; i < word.size(); ++i) {
                        if (guessCopy == word.at(i)) {
                            guessedLetters.at(i) = guess;
                        }
                    }
                    ++numCorrect;
                } else {
                    if (guess.size() == 1) {
                        usedLetters.push_back(guess.at(0));
                    }
                    cout << "Wrong guess!\n";
                    ++numWrong;
                }
                
                break;
            case 1:
                cout << "\033c"; 
                cout << " ________\n |/      |\n |      (\n |      \n";
                cout << " |       \n |      " << "\n |\n_|___\n\n";
                
                for (unsigned i = 0; i < guessedLetters.size(); ++i) {
                    cout << guessedLetters.at(i);
                }
                
                cout << "\nUsed Letters: ";
                for (unsigned i = 0; i < usedLetters.size(); ++i) {
                    cout << usedLetters.at(i) << " ";
                }
                
                cout << "\nGuess a letter or word: \n";
                cin  >> guess;
                
                if (guess == word || numCorrect == word.size()) {
                    cout << "\nYou won!\n";
                    return true;
                } else if (word.find(guess) != string::npos) {
                    guessCopy = guess.at(0);
                    usedLetters.push_back(guessCopy);
                    for (unsigned i = 0; i < word.size(); ++i) {
                        if (guessCopy == word.at(i)) {
                            guessedLetters.at(i) = guess;
                        }
                    }
                    ++numCorrect;
                } else {
                    if (guess.size() == 1) {
                        usedLetters.push_back(guess.at(0));
                    }
                    cout << "Wrong guess!\n";
                    ++numWrong;
                }
                
                break;
            case 2:
                cout << "\033c"; 
                cout << " ________\n |/      |\n |      (_\n |      \n";
                cout << " |       \n |      " << "\n |\n_|___\n\n";
                
                for (unsigned i = 0; i < guessedLetters.size(); ++i) {
                    cout << guessedLetters.at(i);
                }
                
                cout << "\nUsed Letters: ";
                for (unsigned i = 0; i < usedLetters.size(); ++i) {
                    cout << usedLetters.at(i) << " ";
                }
                
                cout << "\nGuess a letter or word: \n";
                cin  >> guess;
                
                if (guess == word || numCorrect == word.size()) {
                    cout << "\nYou won!\n";
                    return true;
                } else if (word.find(guess) != string::npos) {
                    guessCopy = guess.at(0);
                    usedLetters.push_back(guessCopy);
                    for (unsigned i = 0; i < word.size(); ++i) {
                        if (guessCopy == word.at(i)) {
                            guessedLetters.at(i) = guess;
                        }
                    }
                    ++numCorrect;
                } else {
                    if (guess.size() == 1) {
                        usedLetters.push_back(guess.at(0));
                    }
                    cout << "Wrong guess!\n";
                    ++numWrong;
                }
                
                break;
            case 3:
                cout << "\033c"; 
                cout << " ________\n |/      |\n |      (_)\n |      \n";
                cout << " |       \n |      " << "\n |\n_|___\n\n";
                
                for (unsigned i = 0; i < guessedLetters.size(); ++i) {
                    cout << guessedLetters.at(i);
                }
                
                cout << "\nUsed Letters: ";
                for (unsigned i = 0; i < usedLetters.size(); ++i) {
                    cout << usedLetters.at(i) << " ";
                }
                
                cout << "\nGuess a letter or word: \n";
                cin  >> guess;
                
                if (guess == word || numCorrect == word.size()) {
                    cout << "\nYou won!\n";
                    return true;
                } else if (word.find(guess) != string::npos) {
                    guessCopy = guess.at(0);
                    usedLetters.push_back(guessCopy);
                    for (unsigned i = 0; i < word.size(); ++i) {
                        if (guessCopy == word.at(i)) {
                            guessedLetters.at(i) = guess;
                        }
                    }
                    ++numCorrect;
                } else {
                    if (guess.size() == 1) {
                        usedLetters.push_back(guess.at(0));
                    }
                    cout << "Wrong guess!\n";
                    ++numWrong;
                }
                
                break;
            case 4:
                cout << "\033c"; 
                cout << " ________\n |/      |\n |      (_)\n |      \\\n";
                cout << " |       \n |      " << "\n |\n_|___\n\n";
                
                for (unsigned i = 0; i < guessedLetters.size(); ++i) {
                    cout << guessedLetters.at(i);
                }
                
                cout << "\nUsed Letters: ";
                for (unsigned i = 0; i < usedLetters.size(); ++i) {
                    cout << usedLetters.at(i) << " ";
                }
                
                cout << "\nGuess a letter or word: \n";
                cin  >> guess;
                
                if (guess == word || numCorrect == word.size()) {
                    cout << "\nYou won!\n";
                    return true;
                } else if (word.find(guess) != string::npos) {
                    guessCopy = guess.at(0);
                    usedLetters.push_back(guessCopy);
                    for (unsigned i = 0; i < word.size(); ++i) {
                        if (guessCopy == word.at(i)) {
                            guessedLetters.at(i) = guess;
                        }
                    }
                    ++numCorrect;
                } else {
                    if (guess.size() == 1) {
                        usedLetters.push_back(guess.at(0));
                    }
                    cout << "Wrong guess!\n";
                    ++numWrong;
                }
                
                break;
            case 5:
                cout << "\033c"; 
                cout << " ________\n |/      |\n |      (_)\n |      \\|\n";
                cout << " |       \n |      " << "\n |\n_|___\n\n";
                
                for (unsigned i = 0; i < guessedLetters.size(); ++i) {
                    cout << guessedLetters.at(i);
                }
                
                cout << "\nUsed Letters: ";
                for (unsigned i = 0; i < usedLetters.size(); ++i) {
                    cout << usedLetters.at(i) << " ";
                }
                
                cout << "\nGuess a letter or word: \n";
                cin  >> guess;
                
                if (guess == word || numCorrect == word.size()) {
                    cout << "\nYou won!\n";
                    return true;
                } else if (word.find(guess) != string::npos) {
                    guessCopy = guess.at(0);
                    usedLetters.push_back(guessCopy);
                    for (unsigned i = 0; i < word.size(); ++i) {
                        if (guessCopy == word.at(i)) {
                            guessedLetters.at(i) = guess;
                        }
                    }
                    ++numCorrect;
                } else {
                    if (guess.size() == 1) {
                        usedLetters.push_back(guess.at(0));
                    }
                    cout << "Wrong guess!\n";
                    ++numWrong;
                }
            
                break;
            case 6:
                cout << "\033c"; 
                cout << " ________\n |/      |\n |      (_)\n |      \\|/\n";
                cout << " |       \n |      " << "\n |\n_|___\n\n";
                
                for (unsigned i = 0; i < guessedLetters.size(); ++i) {
                    cout << guessedLetters.at(i);
                }
                
                cout << "\nUsed Letters: ";
                for (unsigned i = 0; i < usedLetters.size(); ++i) {
                    cout << usedLetters.at(i) << " ";
                }
                
                cout << "\nGuess a letter or word: \n";
                cin  >> guess;
                
                if (guess == word || numCorrect == word.size()) {
                    cout << "\nYou won!\n";
                    return true;
                } else if (word.find(guess) != string::npos) {
                    guessCopy = guess.at(0);
                    usedLetters.push_back(guessCopy);
                    for (unsigned i = 0; i < word.size(); ++i) {
                        if (guessCopy == word.at(i)) {
                            guessedLetters.at(i) = guess;
                        }
                    }
                    ++numCorrect;
                } else {
                    if (guess.size() == 1) {
                        usedLetters.push_back(guess.at(0));
                    }
                    cout << "Wrong guess!\n";
                    ++numWrong;
                }
                
                break;
            case 7:
                cout << "\033c"; 
                cout << " ________\n |/      |\n |      (_)\n |      \\|/\n";
                cout << " |       |\n |      " << "\n |\n_|___\n\n";
                
                for (unsigned i = 0; i < guessedLetters.size(); ++i) {
                    cout << guessedLetters.at(i);
                }
                
                cout << "\nUsed Letters: ";
                for (unsigned i = 0; i < usedLetters.size(); ++i) {
                    cout << usedLetters.at(i) << " ";
                }
                
                cout << "\nGuess a letter or word: \n";
                cin  >> guess;
                
                if (guess == word || numCorrect == word.size()) {
                    cout << "\nYou won!\n";
                    return true;
                } else if (word.find(guess) != string::npos) {
                    guessCopy = guess.at(0);
                    usedLetters.push_back(guessCopy);
                    for (unsigned i = 0; i < word.size(); ++i) {
                        if (guessCopy == word.at(i)) {
                            guessedLetters.at(i) = guess;
                        }
                    }
                    ++numCorrect;
                } else {
                    if (guess.size() == 1) {
                        usedLetters.push_back(guess.at(0));
                    }
                    cout << "Wrong guess!\n";
                    ++numWrong;
                }
                
                break;
            case 8:
                cout << "\033c";
                cout << " ________\n |/      |\n |      (_)\n |      \\|/\n";
                cout << " |       |\n |      /" << "\n |\n_|___\n\n";
                
                for (unsigned i = 0; i < guessedLetters.size(); ++i) {
                    cout << guessedLetters.at(i);
                }
                
                cout << "\nUsed Letters: ";
                for (unsigned i = 0; i < usedLetters.size(); ++i) {
                    cout << usedLetters.at(i) << " ";
                }
                
                cout << "\nGuess a letter or word: \n";
                cin  >> guess;
                
                if (guess == word || numCorrect == word.size()) {
                    cout << "\nYou won!\n";
                    return true;
                } else if (word.find(guess) != string::npos) {
                    guessCopy = guess.at(0);
                    usedLetters.push_back(guessCopy);
                    for (unsigned i = 0; i < word.size(); ++i) {
                        if (guessCopy == word.at(i)) {
                            guessedLetters.at(i) = guess;
                        }
                    }
                    ++numCorrect;
                } else {
                    if (guess.size() == 1) {
                        usedLetters.push_back(guess.at(0));
                    }
                    cout << "Wrong guess!\n";
                    ++numWrong;
                }
                
                break;
            case 9:
                cout << "\033c";
                cout << " ________\n |/      |\n |      (_)\n |      \\|/\n";
                cout << " |       |\n |      / \\" << "\n |\n_|___\n\n";
                
                for (unsigned i = 0; i < guessedLetters.size(); ++i) {
                    cout << guessedLetters.at(i);
                }
                
                cout << "\nUsed Letters: ";
                for (unsigned i = 0; i < usedLetters.size(); ++i) {
                    cout << usedLetters.at(i) << " ";
                }
                
                cout << "\nGuess a letter or word: \n";
                cin  >> guess;
                
                if (guess == word || numCorrect == word.size()) {
                    cout << "\nYou won!\n";
                    return true;
                } else if (word.find(guess) != string::npos) {
                    guessCopy = guess.at(0);
                    usedLetters.push_back(guessCopy);
                    for (unsigned i = 0; i < word.size(); ++i) {
                        if (guessCopy == word.at(i)) {
                            guessedLetters.at(i) = guess;
                        }
                    }
                    ++numCorrect;
                } else {
                    if (guess.size() == 1) {
                        usedLetters.push_back(guess.at(0));
                    }
                    cout << "Wrong guess!\n";
                    ++numWrong;
                }
                
                break;
        }
    }
    cout << "\033c";
    cout << " ________\n |/      |\n |      (_)\n |      \\|/\n";
    cout << " |       |\n |      / \\" << "\n |\n_|___\n\n";
    return false;
}