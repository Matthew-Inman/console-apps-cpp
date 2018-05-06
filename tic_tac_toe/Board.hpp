#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>

#define LOWER_CASE_MIN 97
#define LOWER_CASE_MAX 122
#define UPPER_CASE_MIN 65
#define UPPER_CASE_MAX 90

class Board
{
public:
    Board();
    void initBoard();
    void printBoard();
    void userInput();
    bool isGameOver();
private:
    char board [3][3];
};



#endif /* Board_hpp */
