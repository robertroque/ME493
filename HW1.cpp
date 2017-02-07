//
//  main.cpp
//  ME493_Homework1
//
//  Created by Robert Roque on 2/4/17.
//  Copyright © 2017 Robert Roque. All rights reserved.
//

#include <iostream>
#include <random>
#include <assert.h>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;
int n=1; // Defines the Variable n (to be changed later)

class card { // Defines the object with two characteristics
public:
    int value;
    int suit;
};

void TestA (vector <card>* DECK) {
    int l=1; // Accounts for first recording for assert check
    for (int q=0; q<52; q++) { // Test every card in the deck
        for (int w=0; w<52; w++) { // Checks the card (above) against the other cards
            if (q==w) {
                assert (q==w);
            }
            else {
                if ((DECK->at(q).value == DECK->at (w).value) && (DECK->at(q).suit == DECK->at(w).suit)) {
                    // If the checking card is the same in suit and value, the test fails
                    cout << "Test A Failed" << endl;
                    l++;
                }
            } // If the test doesn't fail, it passes
        }
    }
    cout << "Test A Complete" << endl;
    assert(l=n); // Error returns when not true (Fail)
    if(l==n) {
        cout << "Test A Pass" << endl;
    }
}

void TestB (vector <card>* DECK) {
    int q=0; // Record the first card in operation
    int l=0; // Accounts for this recording
    for (int w=0; w<52*n; w++) { // Checks the card (above) against the other cards
        
        if ((DECK->at(q).value == DECK->at (w).value) && (DECK->at(q).suit == DECK->at(w).suit)) {
            l++; // If the checking card is the same in suit and value, record another occurance
        }
    }
    cout << l << " Number of occurances" << endl; // Display in the window the number of occurances
    cout << "Test B Complete" << endl;
    assert(l==n); // Error returns when not true (Fail)
    if(l==n) {
        cout << "Test B Pass" << endl;
    }
}

int main() {
    cout << "Please enter the ammount of decks:\n>"; // User input ammount of decks
    cin >> n;
    vector <card> deck; // Create a vector to store the cards later
    vector <card>* DECK=&deck; // Create a pointer to rearrange the vector later
    for (int i=0; i<n; i++) { // Create n decks of cards // Respected ammount of particular cards
        for (int j=0; j<4; j++) { // Suit
            for (int k=1; k<14; k++) { // A(1), J(11), Q(12), K(13)
                card Robert; // Create a temporary card
                Robert.value=k; // Assign it a value
                Robert.suit=j; // Assign it a suit
                deck.push_back(Robert); // Record it into the vector
            }
        }
    }
    for (int o=0; o<5200; o++) { // Randomize 5200 (arbitrary) number of cards
        card Daniel; // Create a temporary card
        int a = rand()% 52*n; // Randomly select a card
        int b = rand()% 52*n;
        Daniel = DECK->at(a); // Assign the temp card as a storage space
        DECK->at(a) = DECK->at(b); // Input the b card to replace card a
        DECK->at(b) = Daniel; // Input the temp card to replace card b
    }
    if (n==1) {
        TestA(DECK); // Conduct test A if condition is met (1 deck)
    }
    else {
        TestB(DECK); // Else conduct test B
    }
    
    ofstream cout("HW1.txt"); // Output a text file
    cout << "Position" << "\t" << "Suit" << "\t" << "Value" << endl;
    for (int p=0; p < deck.size(); p++) {
        cout << p+1 << "\t" << deck.at(p).suit << "\t" << deck.at(p).value << endl;
    }
    return 0;
}
