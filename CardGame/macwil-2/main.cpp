// Main class cpp file

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Card.h"
#include "Node.h"
#include "Deck.h"

using namespace std;

int main()
// Main Function
{
    // Initializes a deck
    Deck deck;
    // Prints all the cards in the deck before shuffle
    cout << "Original Deck:" << endl;
    cout << deck << endl;
    // Prints all the cards in the deck after shuffle
    cout << "Shuffled Deck:" << endl;
    deck.shuffle();
    cout << deck << endl;
    // Play Flip game
    deck.playFlip();
} // end main