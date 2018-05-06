//
//  main.cpp
//  hangman
//
//  Created by Matthew Inman on 07/01/2018.
//  Copyright © 2018 Matthew Inman. All rights reserved.
//

// cin checks have not been done yet

#include <iostream>
#include <string>
using namespace std;
void ascii1();
void ascii2();
void firstMiss(int lives);
void secondMiss(int lives);
void thirdMiss(int lives);
void fourthMiss(int lives);
void fifthMiss(int lives);
void sixthMiss();

int main() {
    
    const string CLEAR_TERMINAL = "\033[2J\033[1;1H";
    bool isDone = false;
    unsigned int tries = 0;
    unsigned int lives = 6;
    char missed [lives];  // the array is set to the same as lives because you can't miss more than the amount of lives
    unsigned int numTimesMissed = 0;
    
    cout << CLEAR_TERMINAL;
    //ascii1();
    ascii2();
    
    cout << "\n\t*** Welcome to the 2 Player Hangman! ***" << endl << endl;
    
    cout << "In this version, Player 1 inputs the word of his choice and Player 2 must find it." << endl << endl;
    cout << "Tips: Do NOT use spaces nor capital letters" << endl;
    cout << "      Do NOT let player 2 snoop your inputs! :D" << endl << endl;
    
    cout << "Player 1: \nEnter you name: ";
    string name;
    cin >> name;
    
    cout << "Enter your word: ";
    string word;
    cin >> word;
    string empty(word.size(), '_');
    
    cout << "Enter a hint: ";
    string hint;
    cin >> hint;
    
    cout << "\nWhen you are ready for player 2 to play:\n==> press any key, then hit ENTER." << endl;
    
    char keyPress;
    cin >> keyPress;
    cout << CLEAR_TERMINAL;
    
    if (keyPress)
    {
        cout << "Player 2: \n\n";
        cout << "You have " << lives << " lives to find " << name << "'s" << " word." << endl;
        cout << "The word is " << word.length() << " letters long." << endl;
        cout << "These are the blanks in the word you are looking for." << endl;
        cout << "Good Luck!\n";
    }
    cout << empty << endl;
    
    while (!isDone) // game loop
    {
        bool repeatedMiss = false;
        // is it needed to display missed letters? if so do this.
        if (numTimesMissed > 0) {
            if (numTimesMissed == 1)
                cout << endl << "Missed letter is: '" << missed[0] << "'";
            else {
                cout << endl << "Missed letters are: ";
                for (int i = 0; i < numTimesMissed; i++) {
                    cout << "'" << missed[i] << "' ";
                }
            }
        }
        
        cout << "\nEnter a letter: ";

        char guess;
        cin >> guess;
        
        for (int i = 0; i < numTimesMissed; i++) //check if missed char has already been entered
        {
            if (guess == missed[i])
            {
                cout << "You have already entered '" << guess << "'." << endl;
                repeatedMiss = true;
            }
        }

        if (repeatedMiss == true)
            continue;
        
        tries ++;
        
        if (word.find(guess) != string::npos) // if guess is in the string word (example on page 89)
        {
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] == guess)
                {
                    empty[i] = word[i];
                }
            }
        } else if ((word.find(guess) == string::npos)){ // if guess is not in the string word cout ... and go back to top of loop if lives > 0
            lives --;
            missed [numTimesMissed] = guess; // adds the missed char to the array
            numTimesMissed ++;
            
            cout << CLEAR_TERMINAL;
            cout << "The letter " << "'" << guess << "'" << " is not in the word!" << endl;
            
            if (lives > 0) {
                switch (numTimesMissed) {
                    case 1:
                        firstMiss(lives);
                        break;
                    case 2:
                        secondMiss(lives);
                        break;
                    case 3:
                        thirdMiss(lives);
                        break;
                    case 4:
                        fourthMiss(lives);
                        break;
                    case 5:
                        cout << "Here is a HINT " << name << " left for you: " << hint << endl << endl;
                        fifthMiss(lives);
                        break;
                    default:
                        break;
                }
            } else {
                sixthMiss();
                cout << "\nYou loose! Game over! " << name << " wins!" << endl << endl;
                cout << "The word was: " << word << endl;
                break;
            }
        }
        
        if (word == empty) // win condition
        {
            cout << endl << empty << endl;
            cout << "Congratulations!" << endl;
            cout << "You found the word in " << tries << " tries and kicked " << name << "'s" << " butt!" << endl;
            isDone = true;
        }
        
        if (!isDone)
        {
            cout << endl << empty << endl;
        }
    }
    return 0;
}

//check if even a correct value has been entered

void ascii1()
{
    cout <<   "#     #    #    #     #  #####  #     #    #    #     #"<<
    "\n#     #   # #   ##    # #     # ##   ##   # #   ##    #"<<
    "\n#     #  #   #  # #   # #       # # # #  #   #  # #   #"<<
    "\n####### #     # #  #  # #  #### #  #  # #     # #  #  #"<<
    "\n#     # ####### #   # # #     # #     # ####### #   # #"<<
    "\n#     # #     # #    ## #     # #     # #     # #    ##"<<
    "\n#     # #     # #     #  #####  #     # #     # #     #" << endl << endl;
}

void ascii2()
{
    cout << "  _      __    _      __    _       __    _" << endl <<
            " | |_|  / /\\  | |\\ | / /`_ | |\\/|  / /\\  | |\\ |" << endl <<
            " |_| | /_/--\\ |_| \\| \\_\\_/ |_|  | /_/--\\ |_| \\|" << endl;
}

void firstMiss(int lives)
{
    cout << "You have " << lives << " lives remaining." << endl << endl;
    cout << "  +===+              "<< endl <<
            "  |   |              "<< endl <<
            "  O   |              "<< endl <<
            "      |              "<< endl <<
            "      |              "<< endl <<
            "      |              "<< endl <<
            "=======";
}

void secondMiss(int lives)
{
    cout << "You have " << lives << " lives remaining." << endl << endl;
    cout << "  +===+              "<< endl <<
            "  |   |              "<< endl <<
            "  O   |              "<< endl <<
            "  |   |              "<< endl <<
            "      |              "<< endl <<
            "      |              "<< endl <<
            "=======";
}

void thirdMiss(int lives)
{
    cout << "You have " << lives << " lives remaining." << endl << endl;
    cout << "  +===+              "<< endl <<
            "  |   |              "<< endl <<
            "  O   |              "<< endl <<
            " /|   |              "<< endl <<
            "      |              "<< endl <<
            "      |              "<< endl <<
            "=======";
}

void fourthMiss(int lives)
{
    cout << "You have " << lives << " lives remaining." << endl << endl;
    cout << "  +===+              "<< endl <<
            "  |   |              "<< endl <<
            "  O   |              "<< endl <<
            " /|\\  |              "<< endl <<
            "      |              "<< endl <<
            "      |              "<< endl <<
            "=======";
}

void fifthMiss(int lives)
{
    cout << "YOU ONLY HAVE " << lives << " LIFE REMAINING!" << endl;
    cout << "  +===+              "<< endl <<
            "  |   |              "<< endl <<
            "  O   |              "<< endl <<
            " /|\\  |              "<< endl <<
            " /    |              "<< endl <<
            "      |              "<< endl <<
            "=======";
}

void sixthMiss()
{
    cout << "  +===+              "<< endl <<
            "  |   |              "<< endl <<
            "  O   |              "<< endl <<
            " /|\\  |              "<< endl <<
            " / \\  |              "<< endl <<
            "      |              "<< endl <<
            "=======";
}







