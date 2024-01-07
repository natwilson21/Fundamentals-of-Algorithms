// Deck class header file
#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Card.h"
#include "Node.h"

using namespace std;

class Deck
// Stores the cards in a deck in order using a linked list of nodes
{
    private: // Access specifier
        Node *first = NULL;

    public: // Access specifier
        // Counts the number of cards in a deck
        int cardCount;
        // Constructor and destructor
        Deck();
        ~Deck();
        // Overloaded << operator that prints the cards in the deck
        friend ostream& operator<<(ostream& out, const Deck& theDeck);
        // Shuffles the cards in the deck
        void shuffle();
        // Returns the top card in the deck and removes the card from deck
        Card deal();
        // Given a card to be placed on the bottom of the deck
        void replace(const Card& card);
        // Plays the game called Flip
        void playFlip();
}; // end Deck calss

#endif 
// End of header file