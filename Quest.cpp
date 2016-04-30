#include "Player.cpp"
using namespace std;

class Quest {
    public:
    void launch();
    int getHighscore() const;
    string getName() const;
    
    private:
    int highscore;
    string name;
    bool FloorOne(Player& Main, Player& Enemy, int Range);
    void Shop(Player& Main);
    Player Intro();
    void GameOver(Player& Main);
};

void Quest::GameOver(Player& Main) { cout << "            GAME OVER\n" << "         _______________\n        /               \\\n       /                 \\\n      /                   \\\n      |   XXXX     XXXX   |\n      |   XXXX     XXXX   |\n      |   XXX       XXX   |\n      |         X         |\n      \\__      XXX      __/\n        |\\     XXX     /|\n        | |           | |\n        | I I I I I I I |\n        |  I I I I I I  |\n        \\_             _/\n          \\_         _/\n            \\_______/\n    XXX                    XXX\n   XXXXX                  XXXXX\n   XXXXXXXXX         XXXXXXXXXX\n          XXXXX   XXXXX\n             XXXXXXX\n          XXXXX   XXXXX\n   XXXXXXXXX         XXXXXXXXXX\n   XXXXX                  XXXXX\n    XXX                    XXX\n\nFinal Stats:\n\n"; Main.display(); cout << endl; }

int Quest::getHighscore() const { return highscore; }

string Quest::getName() const { return name; }

Player Quest::Intro() {
    Player Main;
    string input;
    cout << "\033c" << "Welcome to Question Quest!\n\nEnter your character's name (no spaces!): "; cin >> input;
    Main.Name = input; name = input;
    cout << "\033c"
        << "*****PLEASE READ*****\n\nCharacter Traits:" << endl << endl
        << "HEALTH - When this goes under zero, you lose!" << endl << endl
        << "ATTACK - This is how much damage you can do!" << endl << endl
        << "CONFIDENCE - When you answer 3+ questions correct, you can use a CONFIDENCE ATTACK by entering your EXACT confidence points." << endl << endl
        << "*Be careful, when you miss a question, your confidence will go back down to zero.*" << endl << endl << endl
        << "Classes:\n\n"
        << "A) Warrior: Gains confidence quickly, but has low initial damage." << endl << endl
        << "B) Wizard: Has high health, but mediocre damage and confidence." << endl << endl
        << "C) Rogue: Has very high damage, but very low health." << endl << endl
        << "Which class would you like to be? Enter A/B/C: "; cin >> input;
    while (input < "A" || input > "C") { cout << "\033c" << "Invalid Input. Please type A, B, or C: "; cin >> input; }
    if (input == "A") { Main.setStats(40, 10, 70, 70, 50, 0); Main.Class = "(Warrior)"; }
    else if (input == "B") { Main.setStats(60, 50, 100, 100, 25, 0); Main.Class = "(Wizard)"; }
    else if (input == "C") { Main.setStats(100, 70, 40, 40, 10, 0); Main.Class = "(Rogue)"; }
    return Main;
}

bool Quest::FloorOne(Player& Main, Player& Enemy, int Range) {
    int input; cout << "The " << Enemy.Name << " blocks the way!" << endl << endl;
    while (Main.CurrentHealth > 0 && Enemy.CurrentHealth > 0) {
        Enemy.display(); cout << endl << endl; Main.display(); cout << endl;
        int a = static_cast<int>(rand() % Range); int b = static_cast<int>(rand() % Range); int c = a + b;
        if (Enemy.MaxAttack > Main.CurrentHealth) { cout << "WARNING: IF YOU GET THIS WRONG, YOU MIGHT DIE!" << endl; }
        cout << "What is " << a << " + " << b << " ? "; cin >> input; cout << "\033c";
        if(input == 0) { Enemy.CurrentHealth = 0; }
        else if(input == (Main.Confidence * Main.Combo) && Main.Combo >= 3) { cout << "You used all your confidence!!! You did an extra " << Main.Confidence * Main.Combo << " damage!\n\n"; Enemy.CurrentHealth -= (Main.Confidence * Main.Combo); Main.Combo = 0; }
        else if(input == c) { Enemy.takeDamage(Main); Main.takeBack(Enemy); ++Main.Combo; } else { cout << a << " + " << b << " was " << c << ". Not " << input << "." << endl << endl; Main.takeDamage(Enemy); Main.Combo = 0; }
    }
    if (Main.CurrentHealth > 0) { cout << "\033c" << Enemy.Name << " was defeated!\n\n"; return true; } else { return false; }
}

void Quest::Shop(Player& Main) {
    int input; Main.MaxAttack += 10; Main.MinAttack += 10; Main.CurrentHealth += 10; Main.MaxHealth += 10; Main.Confidence += 10;
    cout << "\"Hello. I'm the shopkeeper. What would you like?\"\n\n";
    cout << "|---------------------------|" << endl
         << "|                           |" << endl
         << "|      $            $       |" << endl
         << "|     $            $        |" << endl
         << "|      $            $       |" << endl
         << "|       $    /       $      |" << endl
         << "|      $    /       $       |" << endl
         << "|  |       /---          |  |" << endl
         << "|  |                     |  |" << endl
         << "|  |_____________________|  |" << endl
         << "|                           |" << endl
         << "|---------------------------|" << endl << endl << "Your Stats:\n"; Main.display(); cout << "\n1) A Lucky Cookie (Increase maximum attack!)\n\n2) Muscle Milk (Increases mininum + maximum attack!)\n\n3) Sparkling Sparkling Water (Fully heals you!)\n\n" << "4) Truth Cake (Increases you maximum health!)\n\n5) A Leadership Badge (Increases your base confidence!)\n\nEnter 1/2/3/4/5: "; cin >> input;
    while (input < 1 || input > 5) { cout << "Invalid Input. Please type 1, 2, 3, 4, or 5: "; cin >> input; }
    if (input == 1) { Main.MaxAttack += 50; } else if (input == 2) { Main.MaxAttack += 25; Main.MinAttack += 25; } else if (input == 3) { Main.fullHeal(); } else if (input == 4) { Main.MaxHealth += 75; Main.CurrentHealth += 75; } else if (input == 5) { Main.Confidence += 20; } cout << "\033c";
}

void Quest::launch() {
    srand(time(0));
    cout << "before intro\n";
    Player Main; Main = Intro();
    cout << "after intro\n";
    Player One("Training Dummy", "(Level 1)\n\n        ---\n        |O|\n        |X|\n        |O|\n        ---\n         |\n         _\n", 10, 1, 100, 100, 0, 0);
    Player Two("Training Dumber", "(Level 2)\n\n     -----\n     |? ?|\n     |   |\n-----| ? |-----\n     |   |\n     |   |\n     -----\n       |\n       |\n       |\n      ___\n", 20, 10, 150, 150, 0, 0);
    Player Three("Training Dumbest", "(Level 3)\n\n     -----\n     |- -|\n     |   |\n-----| - |-----\n     |   |\n     |   |\n     -----\n       |\n       |\n       |\n      ___\n", 50, 20, 200, 200, 0, 0);
    Player Four("Baby Golem", "(Level 4)\n\n    ===\n    ( )\n   _( )_\n    ===\n    | |\n", 100, 50, 250, 250, 0, 0);
    Player Five("Teenage Golem ", "(Level 5)\n\n     =====\n     (o o)\n   |_(   )_|\n     =====\n      | |\n      | |\n", 170, 100, 300, 300, 0, 0);
    Player Six("Father Golem", "(Level 6)\n\n     ===========\n     (  \\   /  )\n    _(  o   o  )_\n   | (    M    ) |\n   | (   ---   ) |\n     (         )\n     ===========\n       |    |\n       |    |\n       |    |\n     III    III\n", 260, 170, 400, 400, 0, 0);
    Player Seven("Ferociously Cute Bear", "(Level 7)\n\n    (\\_/)\n    (O_O)\n   <(   )>\n    ( _ )\n     V V\n", 370, 260, 500, 500, 0, 0);
    Player Eight("King Dummy Jr.", "(Level 8)\n\n        -------\n        |* _ *|\n        |     |\n   -----| (O) |-----\n        | (O) |\n        | (O) |\n        -------\n           |\n           |\n           |\n          ___\n", 500, 370, 650, 650, 0, 0);
    Player Nine("Joker Guardian", "(Level 9)\n\n            ___\n           /\\  \\\n          /  \\/ \\\n     ___  \\   O /  ___\n    /    \\ \\   / /    \\\n   /   __ -    -  __   \\\n  /___/ | <>   <> | \\___\\\n  O  ___|    ^    |___  O\n   /     \\  -^-  /    \\\n  /   /\\  \\_____/ /\\   \\\n  \\_ / /          \\ \\_ /\n  O   /   /\\   /\\  \\  O\n       \\ /  \\ /  \\ /\n        O    O    O\n", 800, 700, 800, 800, 0, 0);
    Player Ten("Dragon King", "(Level 10 BOSS)\n\n              _/|    _   |\\_\n            _/_ |   _|\\\\ | _\\\n          _/_/| /  /   \\|\\ |\\_\\_\n        _/_/  |/  /  _  \\/\\|  \\_\\_\n      _/_/    ||  | | \\o/ ||    \\_\\_\n     /_/  | | |\\  | \\_ V  /| | |  \\_\\\n    //    ||| | \\_/   \\__/ | |||    \\\\\n   // __| ||\\  \\          /  /|| |__ \\\\\n  //_/ \\|||| \\/\\\\        //\\/ ||||/ \\_\\\\\n ///    \\\\\\\\/   /        \\   \\////    \\\\\\\n |/      \\/    |    |    |     \\/      \\|\n               /_|  | |_  \\\n              ///_| |_||\\_ \\\n              |//||/||\\/||\\|\n               / \\/|||/||/\\/\n                 /|/\\| \\/\n                 \\/  |\n", 999, 999, 999, 999, 0, 0);
    cout << "\033c" << "Every 10th level is guarded by a BOSS.\n\nAnswer questions to attack!\n\nGood luck!" << endl << endl;
    if (FloorOne(Main, One, 10)) { cout << "After every battle, you can go to the shopkeeper for power-ups! Choose carefully!\n\n"; Shop(Main); } else { GameOver(Main); highscore = 0; return; }
    if (FloorOne(Main, Two, 20)) { Shop(Main); } else { GameOver(Main); highscore = 1; return; }
    if (FloorOne(Main, Three, 50)) { Shop(Main); } else { GameOver(Main); highscore = 2; return; }
    if (FloorOne(Main, Four, 40)) { Shop(Main); } else { GameOver(Main); highscore = 3; return; }
    if (FloorOne(Main, Five, 100)) { Shop(Main); } else { GameOver(Main); highscore = 4; return; }
    if (FloorOne(Main, Six, 300)) { Shop(Main); } else { GameOver(Main); highscore = 5; return; }
    if (FloorOne(Main, Seven, 400)) { Shop(Main); } else { GameOver(Main); highscore = 6; return; }
    if (FloorOne(Main, Eight, 500)) { Shop(Main); } else { GameOver(Main); highscore = 7; return; }
    if (FloorOne(Main, Nine, 600)) { Shop(Main); } else { GameOver(Main); highscore = 8; return; }
    if (FloorOne(Main, Ten, 999)) { cout << "\033c" << "YOU WIN!\n\nFinal Stats:\n\n"; Main.display(); cout << endl; highscore = 9; return; } else { GameOver(Main); highscore = 10; return; }
    
}

//            ___\n           /\\  \\\n          /  \\/ \\\n     ___  \\   O /  ___\n    /    \\ \\   / /    \\\n   /   __ -    -  __   \\\n  /___/ | <>   <> | \\___\\\n  O  ___|    ^    |___  O\n   /     \\  -^-  /    \\\n  /   /\\  \\_____/ /\\   \\\n  \\_ / /          \\ \\_ /\n  O   /   /\\   /\\  \\  O\n       \\ /  \\ /  \\ /\n        O    O    O\n
//        -------\n        |^ _ ^|\n        |     |\n   -----|XXXXX|-----\n        |XXXXX|\n        |XXXXX|\n        -------\n           |\n           |\n           |\n          ___\n

//         _______________\n        /               \\\n       /                 \\\n      /                   \\\n      |   XXXX     XXXX   |\n      |   XXXX     XXXX   |\n      |   XXX       XXX   |\n      |         X         |\n      \\__      XXX      __/\n        |\\     XXX     /|\n        | |           | |\n        | I I I I I I I |\n        |  I I I I I I  |\n        \\_             _/\n          \\_         _/\n            \\_______/\n    XXX                    XXX\n   XXXXX                  XXXXX\n   XXXXXXXXX         XXXXXXXXXX\n          XXXXX   XXXXX\n             XXXXXXX\n          XXXXX   XXXXX\n   XXXXXXXXX         XXXXXXXXXX\n   XXXXX                  XXXXX\n    XXX                    XXX\n























