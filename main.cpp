#include "Quest.cpp"
#include "Highscore.cpp"
#include "ttt.cpp"
#include <limits>

int main() {
    char LetsPlay = 'y';
    string Option; Highscore QuestionQuest, TicTacToe, Snake;
    while (LetsPlay == 'y') {
        cout << "\033c" << "\nWelcome to RETRO FADS ARCADE!\n\n\nWhat would you like to do?\n\n1) Play Question Quest\n2) View QuestionQuest Highscores\n\n3) Play Tic-Tac-Toe\n4) View Tic-Tac-Toe Highscores\n\n5) Play Snake\n6) View Snake Highscores\n\n7) Quit\n";
        cin >> Option; while (Option != "1" && Option != "2" && Option != "3" && Option != "4" && Option != "5" && Option != "6" && Option != "7") { cout << "\nInvalid input. Please enter 1/2/3/4/5/6/7: "; cin >> Option; cout << endl; }

        if (Option == "1") { Quest ONE; ONE.launch(); QuestionQuest.prompt(ONE.getHighscore()); }
        else if (Option == "2") { cout << "\033c"; QuestionQuest.display(); }
        else if (Option == "3") { ttt TWO; TWO.play(); cout << "First Player:\n"; TicTacToe.prompt(TWO.score1); cout << "Second Player:\n"; TicTacToe.prompt(TWO.score2); }
        else if (Option == "4") { cout << "\033c"; TicTacToe.display(); }
        else if (Option == "5") { }
        else if (Option == "6") { cout << "\033c"; Snake.display(); }
        else if (Option == "7") { return 0; }

        cout << "\033c" << "Would you like to do something else? (y/n) ";
        cin >> LetsPlay;
        while (LetsPlay != 'y' && LetsPlay != 'n') { cout << "Invalid input. Please enter y/n: "; cin >> LetsPlay; cout << endl; }
        cout << "\033c";
    }
    return 0;
}