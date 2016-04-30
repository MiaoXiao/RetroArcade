#ifndef TTT_H
#define TTT_H
#include <iostream>
#include <vector>

using namespace std;

class ttt {
    public:
    
    int score1;
    int score2;
    
    /// @brief Predicate function to determine if the board is full
    /// @param board the current tic-tac-toe board 
    /// @return true iff the board is full (no cell is available)
    bool boardFull(const vector <char> &gameBoard);
    /// @brief Utilizes an escape character sequence to clear the screen
    void clearScreen();
    /// @brief Draws the provided tic-tac-toe board to the screen
    //  @param board is the tic-tac-toe board that should be drawn
    void drawBoard(const vector < char >&gameBoard);
    /// @brief Fills vector with characters starting at lower case a.
    ///
    ///     If the vector is size 3 then it will have characters a to c.
    ///     If the vector is size 5 then it will have characters a to e.
    ///     If the vector is size 26 then it will have characters a to z.
    ///
    /// @param v the vector to initialize
    /// @pre-condition the vector size will never be over 26
    void initVector(vector <char> &v);
    /// @brief Converts a character representing a cell to associated vector index
    /// @param the position to be converted to a vector index
    /// @return the integer index in the vector, should be 0 to (vector size - 1)
    int convertPosition(char boardPosition);
/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
    bool validPlacement(const vector <char> &gameBoard, int positionIndex);
/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
    int getPlay(const vector <char> &gameBoard);
/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
    bool gameWon(const vector <char> &gameBoard);
    
    void play();
};

#endif

