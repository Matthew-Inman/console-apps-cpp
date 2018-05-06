#include <iostream>
#include "Board.hpp"
using namespace std;

void startMenu();

int main() {
    const string CLEAR_TERMINAL = "\033[2J\033[1;1H";
    cout << CLEAR_TERMINAL;
    
    startMenu();
    Board board; //create instance (object)
    board.initBoard();

    while (board.isGameOver() == false)
    {
        board.printBoard();
        board.userInput();
        board.isGameOver();
    }
    return 0;
}

void startMenu()
{
    cout << "*** Welcome to TIC TAC TOE ***" << endl << endl;
    cout << "This is what the grid looks like:" << endl << endl;
    cout << "      Col 1: Col 2: Col 3:" << endl;
    cout << "Row 1:  .     .     ." << endl;
    cout << "Row 2:  .     .     ." << endl;
    cout << "Row 3:  .     .     ." << endl << endl;
}

//add player scores after each win ==> change game loop so it doesnt break but
// ==> ask wether players want to keep playing or not
// add "tie game" event ==> if all chars have been set to something ==> nobody wins
//get players to input their names via the class
// make code look nicer







