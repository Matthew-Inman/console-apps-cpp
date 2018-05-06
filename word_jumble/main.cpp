//
//  main.cpp
//  word_jumble
//
//  Created by Matthew Inman on 09/01/2018.
//  Copyright © 2018 Matthew Inman. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    const string CLEAR_TERMINAL = "\033[2J\033[1;1H";
    cout << CLEAR_TERMINAL;
    //const int HINT_PENALTY = 30;
    enum fields {WORD, HINT, NUM_FIELDS}; // it is common in enums to name the last element by NUM...
    const int NUM_WORDS = 15;
    const string WORDS [NUM_WORDS][NUM_FIELDS] =
    {
        {"wall", "Do you feel like bangin'your head against something?"},
        {"cinema", "Were's the popcorn?"},
        {"journal", "Wanna read something?"},
        {"review", "Try seeing it again."},
        {"smartphone", "You can't live without it anymore :("},
        {"netflix", "What do you want to watch?"},
        {"friends", "You can count on them."},
        {"cartman", "Respect my authority!"},
        {"blackjack", "Hit me!"},
        {"millionaire", "I bet you'd like to be one."},
        {"monkey", "It climbs in trees."},
        {"paper", "Wanna write something?"},
        {"quest", "In search of something?"},
        {"target", "Aiming for it?"},
        {"playstation", "4 of them exist."},
    };
    bool found = false;
    
    char play = 'y';
    
    srand(static_cast<unsigned int>(time(0)));
    int choice = rand() % NUM_WORDS;
    
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];
    
    string jumble = theWord;
    unsigned long length = jumble.length();
    unsigned long HINT_PENALTY = ((10 / 3) * length);
    unsigned long FOUND = (10 * length);
    
    for (int i = 0; i < length; i++)
    {
        int index1 = rand() % length;
        int index2 = rand() % length;
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }
    
    cout << "\t\t\tWelcome to Word Jumble!" << endl << endl;
    cout << "Unscramble the letters to make a word." << endl;
    cout << "Enter 'hint' for a hint." << endl;
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "Every correct answer gives you 10 points per letter,\n";
    cout << "hints deduct 1/3 of potential points,\n";
    cout << "Three strikes and your out!\n\n";
    
    string guess;
    
    int score = 0;
    int lives = 3;
    
    while ((guess != "quit") && lives > 0 && (play == 'y' || play == 'Y')) // GAME LOOP
    {
        if (found)
        {
            srand(static_cast<unsigned int>(time(0)));
            choice = rand() % NUM_WORDS;
            
            theWord = WORDS[choice][WORD];
            theHint = WORDS[choice][HINT];
            
            jumble = theWord;
            length = jumble.length();
            HINT_PENALTY = ((10 / 3) * length);
            FOUND = (10 * length);
            
            for (int i = 0; i < length; i++)
            {
                int index1 = rand() % length;
                int index2 = rand() % length;
                char temp = jumble[index1];
                jumble[index1] = jumble[index2];
                jumble[index2] = temp;
            }
            found = false;
            cout << "\nThe new jumble is: " << jumble;
        }
        cout << "\nThe jumble is: " << jumble;
        cout << "\n\nYour guess: ";
        cin >> guess;
        cout << CLEAR_TERMINAL;
        
        if (guess == "hint")
        {
            cout << theHint;
            score -= HINT_PENALTY;
        }
        else if (guess != theWord)
        {
            cout << "Sorry, that's not it.";
            if (lives == 3)
                cout << "\nStrike one!\n";
            else if (lives == 2)
                cout << "\nStrrrrriiiike two!\n";
            else if (lives == 1)
                cout << "\nSteeeeerrikeee THREE!! You're out!\n";
            lives --;
        }
        else if (guess == theWord)
        {
            score += FOUND;
            found = true;
            
            cout << "That's it! You guessed it!\n";
            cout << "Your score is: " << score << " points.\n" <<endl;
            
            // PLAY AGAIN ?
            
            cout << "Do you want to continue? (Y/N): ";
            cin >> play;
            
            if (play == 'y' || play == 'Y')
                continue;
            else if (play == 'n' || play == 'N')
                break;
            else
            {
                bool correct = false;
                do
                {
                    cout << "Invalid input.\n";
                    cout << "Do you want to continue? (Y/N): ";
                    cin >> play;
                    if (play == 'y' || play == 'Y' || play == 'n' || play == 'N')
                    {
                        correct = true;
                    }
                } while (!correct);
            }
        }
    }
    
    cout << "\nThanks for playing\n";
    
    return 0;
}
