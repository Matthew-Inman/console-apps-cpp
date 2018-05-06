//
//  main.cpp
//  Higher_or_lower_vectors
//
//  Created by Matthew Inman on 14/01/2018.
//  Copyright © 2018 Matthew Inman. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

void welcome();
bool isValidChar(char input);

int main() {
    
    const string CLEAR_TERMINAL = "\033[2J\033[1;1H";
    cout << CLEAR_TERMINAL;
    welcome();
    
    vector<string>::const_iterator iter;
    const int NUM_CARDS = 13;
    string tempCards[NUM_CARDS] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    vector<string>cards;
    int remainingCards = NUM_CARDS;
    bool isGameOver = false;
    
    // initialize vector by looping through the array
    for (int i = 0; i < NUM_CARDS; i++) {
        cards.push_back(tempCards[i]);
    }
    
    srand(static_cast<unsigned int>(time(0)));
    
    int pickRandom = rand() % remainingCards;
    cout << "\nThe random card is: " << cards[pickRandom] << endl;
    
    cards.erase(cards.begin() + pickRandom);
    
    remainingCards --;
    int newRandom = 0;
    
    while (remainingCards > 1 && !isGameOver)
    {
        //cout << "Is the next card higher or lower (H) or (L): " << endl;
        cout << "Remaining cards are: \n\n";
        for (int i = 0; i < remainingCards; i++) {
            cout << cards[i] << endl;
        }
        cout << "\nIs the next card higher or lower (H) or (L): " << endl;
        newRandom = rand() % remainingCards;
        
        //cout << "The new card is (cheating for debug): " << cards[newRandom] << endl;
        char choice;
        cin >> choice;
        
        while (cin.fail() || !isValidChar(choice)) {
            if (cin.fail()) {
                cout << "Input must be a valid character" << endl;
            } else {
                cout << "Valid characters are: 'H' for 'higher' 'L' for 'lower' and 'D' to display remaining cards" << endl;
            }
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }
        
        choice = toupper(choice);
        
        //cout << endl << "The current face up card is: " << cards[newRandom] << endl;
        
        if ( ((newRandom >= pickRandom) && (choice == 'H')) || ((newRandom < pickRandom) && (choice == 'L')) ) {
            cout << CLEAR_TERMINAL;
            cout << "Correct!\n";
            cout << endl << "The current face up card is: " << cards[newRandom] << endl;
            cards.erase(cards.begin() + newRandom);
            remainingCards --;
            pickRandom = newRandom;
        } else {
            if (remainingCards == NUM_CARDS - 1) {
                cout << "\nWow! How unlucky!" << endl << endl;
            }
            else if (remainingCards < 6 && remainingCards > 2) {
                cout << "\nClose one! But not good enough!" << endl;
            }
            else if (remainingCards == 2) {
                cout << "\nThat was REALLY close! Unlucky!" << endl;
            }
            cout << "You loose.\n";
            cout << "The card was: " << cards[newRandom] << endl;
            isGameOver = true;
        }
    }
    
    if (!isGameOver)
        cout << "\nWow! Incredible! You win!\n";
    
    return 0;
}

void welcome()
{
    cout << "\t*** Welcome to the HIGHER OR LOWER card guessing game ***\n\n";
    cout << "You win if you guess correctly through the entire suite (13 cards).\n";
    cout << "Good luck!\n";
}

bool isValidChar(char input)
{
    if (toupper(input) == 'H' || toupper(input) == 'L') {
        return true;
    }
    return false;
}











