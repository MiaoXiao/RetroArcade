#include <iostream>
#include <map>
using namespace std;

class Highscore {
    private:
    vector<string> names;
    vector<int> scores;
    public:
    void display();
    void addScore();
    void save();
    void load();
    void clear();
}
