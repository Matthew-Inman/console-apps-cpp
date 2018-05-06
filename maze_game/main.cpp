//
//  main.cpp
//  maze_game
//
//  Created by Matthew Inman on 15/01/2018.
//  Copyright © 2018 Matthew Inman. All rights reserved.
//

#include <iostream>
#include <array>
using namespace std;

const int COLUMNS = 8;
const int ROWS = 8;
char maze[COLUMNS][ROWS];
bool won = false;

bool movedLeft = false;
bool movedRight = false;
bool movedDown = false;
bool movedUp = false;


char empty = ' ';
char wall = 'X';

char character = 'P';
int initCharX = 1, initCharY = 1;
int characterX = initCharX, characterY = initCharY;

char block = 'B';
int initBlockX = 2, iniBlockY = 2;
int blockX = initBlockX, blockY = iniBlockY;

char goal = 'O';
int goalX = 6, goalY = 6;

void welcome();
void initMaze();
void update();
bool isValidChar(char input);

//void movePlayer();
//void moveBlock();
//void checkWin();


int main() {
    const string CLEAR_TERMINAL = "\033[2J\033[1;1H";
    cout << CLEAR_TERMINAL;
    cout.width(4);
    welcome();
    initMaze();

    while (!won)
    {
        movedLeft = false;
        movedUp = false;
        movedRight = false;
        movedDown = false;
        
        maze [blockY][blockX] = block;
        maze [characterY][characterX] = character;
        
        update();

        char move = ' ';
        cin >> move;
        
        while (cin.fail() || !isValidChar(move)) {
            if (cin.fail()) {
                cout << "Input must be a valid character" << endl;
            } else {
                cout << "Valid characters are: 'Q' 'Z' 'D' 'S' for movement and 'R' to restart" << endl;
            }
            cin.clear();
            cin.ignore(256, '\n');
            cin >> move;
        }
        
        move = toupper(move);
        
        if (move == 'Q' && (maze[characterY][characterX - 1] != wall))     // move left
        {
            maze[characterY][characterX] = empty;
            characterX --;
            movedLeft = true;
        }
        else if (move == 'Z' && (maze[characterY - 1][characterX] != wall)) // move up
        {
            maze[characterY][characterX] = empty;
            characterY --;
            movedUp = true;
        }
        else if (move == 'D' && (maze[characterY][characterX + 1] != wall)) // move right
        {
            maze[characterY][characterX] = empty;
            characterX ++;
            movedRight = true;
        }
        else if (move == 'S' && (maze[characterY + 1][characterX] != wall)) // move down
        {
            maze[characterY][characterX] = empty;
            characterY ++;
            movedDown = true;
        }
        else if (move == 'R')
        {
            cout << CLEAR_TERMINAL;
            initMaze();
            characterX = initCharX;
            characterY = initCharY;
            blockX = initBlockX;
            blockY = iniBlockY;
            continue;
        }
        
        
        if (movedLeft && characterX == blockX && characterY == blockY) // LEFT
        {
            //cout << "block moved left" << endl;
            if (maze[blockY][blockX - 1] == wall)
            {
                cout << "Invalid move!" << endl;
                characterX ++;
            }
            else if ((blockX - 1) != wall)
            {
                blockX --;
            }
        }
        
        else if (movedUp && characterX == blockX && characterY == blockY) // UP
        {
            //cout << "block moved up" << endl;
            if (maze[blockY - 1][blockX] == wall)
            {
                cout << "Invalid move!" << endl;
                characterY ++; // cancel characters 'up' movement
            }
            else
            {
                blockY --;
            }
        }
        
        else if (movedRight && characterX == blockX && characterY == blockY) // RIGHT
        {
            //cout << "block moved right" << endl;
            if (maze[blockY][blockX + 1] == wall)
            {
                cout << "Invalid move!" << endl;
                characterX --; // cancel characters 'right' movement
            }
            else
            {
                blockX ++;
            }
        }
        
        else if (movedDown && characterX == blockX && characterY == blockY) // DOWN
        {
            //cout << "block moved down" << endl;
            if (maze[blockY + 1][blockX] == wall)
            {
                cout << "Invalid move!" << endl;
                characterY --; // cancel characters 'down' movement
            }
            else
            {
                blockY ++;
            }
        }
        
        // check win
        if (blockX == goalX && blockY == goalY)
        {
            won = true;
            //maze[goalY][goalX] = block;
            update();
            cout << "\nCongratulations! You win!\n";
        }
    }
    
    return 0;
}

void welcome()
{
    cout << "\t*** Welcome to the Maze game ***\n";
    cout << "\nYou must get " << block << " to " << goal << "." << endl;
    cout << "Move " << character << " with 'Q', 'Z', 'D' and 'S' keys.\n";
    cout << "At any time, enter 'R' to restart.\n";
    cout << "Good luck.\n\n";
}

void initMaze()
{
    for (int i = 0; i < COLUMNS; i ++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (i == 0 || i == COLUMNS - 1 || j == 0 || j == ROWS - 1)
            {
                maze[i][j] = wall;
            }
            else
                maze[i][j] = empty;
        }
    }
    maze [3][1] = wall;
    maze [1][6] = wall;
    maze [3][3] = wall;
    maze [1][2] = wall;
    maze [1][5] = wall;
    //maze [2][5] = wall;
    maze [3][5] = wall;
    maze [4][1] = wall;
    maze [5][3] = wall;
    maze [5][4] = wall;
    maze [5][5] = wall;




    maze [goalY][goalX] = goal;
}

void update()
{
    for (int i = 0; i < COLUMNS; i ++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            cout.width(2);
            cout << maze[i][j];
        }
        cout << endl;
    }
}

bool isValidChar(char input)
{
    if (toupper(input) == 'Q' || toupper(input) == 'Z' || toupper(input) == 'D'
        || toupper(input) == 'S' || toupper(input) == 'R') {
        return true;
    }
    return false;
}

void moveBlock()
{
    
}

void checkWin()
{
    
}





