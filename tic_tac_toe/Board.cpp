#include <iostream>
#include "Board.hpp"
using namespace std;


Board::Board()   //Constructor
{
    
}

void Board::initBoard()
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = '.';
        }
    }
}

void Board::printBoard()
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void Board::userInput()
{
    static bool player1Turn = true;
    int rowInput, colInput = 0;
    if (player1Turn){
        cout << endl << "Player 1 turn (X)" << endl;
    } else {
        cout << endl << "Player 2 turn (O)" << endl;
    }
    
    //while (rowInput < LOWER_CASE_MIN && rowInput)
    cout << "Enter row number: ";
    cin >> rowInput;
    while (cin.fail() || rowInput < 1 || rowInput > 3) {
        if (cin.fail()) {
            cout << "You must input a number." << endl << endl;
        } else {
            cout << "Input must be in range of 1 to 3" << endl << endl;
        }
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter row number: ";
        cin >> rowInput;
    }
    
    cout << "Enter column number: ";
    cin >> colInput;
    while (cin.fail() || colInput < 1 || colInput > 3) {
        if (cin.fail()) {
            cout << "You must input a number." << endl << endl;
        } else {
            cout << "Input must be in range of 1 to 3" << endl << endl;
        }
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter column number: ";
        cin >> colInput;
    }
    
    // check if the input is valid (neither 'X' or 'O' has been entered
    if ((board[rowInput - 1][colInput - 1] == 'X') || (board[rowInput - 1][colInput - 1] == 'O')) {
        cout << endl << "Invalid input, row " << rowInput << " and column " << colInput << " has already been played." << endl;
        return;
    }
    
    if (player1Turn){
        board[rowInput - 1][colInput - 1] = 'X';
        player1Turn = false;
    } else {
        board[rowInput - 1][colInput - 1] = 'O';
        player1Turn = true;
    }
}

bool Board::isGameOver()
{
    if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || //Colomn checks
        (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || //Colomn checks
        (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') || //Colomn checks
        (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || //Diagonal checks
        (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))   //Diagonal checks
    {
        printBoard();
        cout << endl << "Player 1 won!" << endl;
        return true;//gameOver = true;
    } else if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') || //Colomn checks
               (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') || //Colomn checks
               (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') || //Colomn checks
               (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || //Diagonal checks
               (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))   //Diagonal checks
    {
        printBoard();
        cout << endl << "Player 2 won!" << endl;
        return true;//gameOver = true;
    }
    return false;
}














