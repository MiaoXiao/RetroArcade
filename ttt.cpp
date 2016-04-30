#include <vector>
#include <iostream>
#include "ttt.h"

using namespace std;

const bool CLEAR_SCREEN = true;

void ttt::play(){
    const int PLAYER1 = 0;
    const int PLAYER2 = 1;
    
    int loopflag = 0;
    char response = '!';

    this->score1 = 0;
    this->score2 = 0;
    
while (loopflag == 0){

    vector <char> gameBoard(9);
    
    int curPlay = 0;
    
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'

    /// TODO: Initialize board to empty state
    
    initVector(gameBoard);
    
    /// TODO: Display empty board
    
    drawBoard(gameBoard);
    
    /// TODO: Play until game is over
     do{
        /// TODO: Get a play
        
        curPlay = getPlay(gameBoard);

        /// TODO: Set the play on the board
        
        if (whosTurn == PLAYER1){
            gameBoard.at(curPlay) = 'X';
        }
        else {
            gameBoard.at(curPlay) = 'O';
        }

        /// TODO: Switch the turn to the other player
        
        if (whosTurn == PLAYER1)
        {
            whosTurn = PLAYER2;
        }
        else if (whosTurn == PLAYER2) {
            whosTurn = PLAYER1;
        }

        /// TODO: Output the updated board

        drawBoard(gameBoard);
     } while (!gameWon(gameBoard) && !boardFull(gameBoard));

    /// TODO: Determine winner and output appropriate message
    
    if (boardFull(gameBoard)){
        cout << "Board Full" << endl;
    }
    
    if (whosTurn == PLAYER1){
        cout << "Player 2 WINS!"<< endl; // because the turn switch happens before the win conditions are checked
        score2++;
    }
    else {
        cout << "Player 1 WINS!"<< endl;
        score1++;
    }
    
    cout << "\n------ Score Board ------\n"
         << "Player 1 : " << score1 << endl
         << "Player 2 : " << score2 << endl
         << "-------------------------\n\n";
         
    cout << "Play Again? (y/n)\n";
    cin >> response;
    cout << endl;
    
    if (response == 'n'){
        loopflag = 1;
    }
}
    return;
}

 /// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool ttt::boardFull(const vector <char> &gameBoard) {
    // TODO: implement function
    for(unsigned int i = 0; i < gameBoard.size(); ++i){
        if (gameBoard.at(i) != 'X' && gameBoard.at(i) != 'O')
        {
            return false;
        }
    }
    return true;
}

/// @brief Utilizes an escape character sequence to clear the screen
void ttt::clearScreen() {
    cout << endl;

    if (CLEAR_SCREEN)
    {
        cout << "\033c";
    }

    cout << endl;

    return;
}


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void ttt::drawBoard(const vector < char >&gameBoard) {
    clearScreen();
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6)
            cout << "-----|-----|-----" << endl;
    }
    cout << endl;

    return;
}



/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 3 then it will have characters a to c.
///     If the vector is size 5 then it will have characters a to e.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void ttt::initVector(vector <char> &v) {

    // TODO: implement function
    char a = 'a';
    
    for (unsigned int i = 0; i < 9; ++i){
        v.at(i) = a;
        a++;
    }
    
    return;
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int ttt::convertPosition(char boardPosition) {

    // TODO: implement function
    if(boardPosition == 'a') {
        return 0;
    }
    if(boardPosition == 'b') {
        return 1;
    }
    if(boardPosition == 'c') {
        return 2;
    }
    if(boardPosition == 'd') {
        return 3;
    }
    if(boardPosition == 'e') {
        return 4;
    }
    if(boardPosition == 'f') {
        return 5;
    }
    if(boardPosition == 'g') {
        return 6;
    }
    if(boardPosition == 'h') {
        return 7;
    }
    if(boardPosition == 'i') {
        return 8;
    }
    return 0;
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool ttt::validPlacement(const vector <char> &gameBoard, int positionIndex) {

    // TODO: implement function
    
    if (gameBoard.at(positionIndex) != 'X' && gameBoard.at(positionIndex) != 'O')
    {
        return true;
    }
    
    return false;
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int ttt::getPlay(const vector <char> &gameBoard) {

    // TODO: implement function
    char boardPosition = ' ';
    do{
        cout << "Please choose a position: ";
        cin >> boardPosition;
        cout << endl;
    
        if (validPlacement(gameBoard, convertPosition(boardPosition))){
            return convertPosition(boardPosition);
        }
    }while (!(validPlacement(gameBoard,convertPosition(boardPosition))));
        
    return -1;
}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool ttt::gameWon(const vector <char> &gameBoard) {

    // TODO: implement function
    if ((gameBoard.at(0) == gameBoard.at(1)) && (gameBoard.at(1) == gameBoard.at(2))) {// first row
        return true;
    }
    if ((gameBoard.at(0) == gameBoard.at(3)) && (gameBoard.at(3) == gameBoard.at(6))) {// first column
        return true;
    }
    if ((gameBoard.at(0) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(8))) {// diagonal down right
        return true;
    }
    if ((gameBoard.at(1) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(7))) {//middle column
        return true;
    }
    if ((gameBoard.at(2) == gameBoard.at(5)) && (gameBoard.at(5) == gameBoard.at(8))) {// right column
        return true;
    }
    if ((gameBoard.at(2) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(6))) {//diagonal down left
        return true;
    }
    if ((gameBoard.at(3) == gameBoard.at(4)) && (gameBoard.at(4) == gameBoard.at(5))) {//middle row
        return true;
    }
    if ((gameBoard.at(6) == gameBoard.at(7)) && (gameBoard.at(7) == gameBoard.at(8))) {//bottom row
        return true;
    }

    return false;
}