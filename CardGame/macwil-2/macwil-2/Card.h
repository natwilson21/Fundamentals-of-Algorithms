// Card class header file
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class Card
// Stores a single card
{
    private: // Access specifier
        // A value can be Ace, 2-10, King, Queen, or Jack
        string value;
        // A suite can be Club, Diamond, Heart, or Spade
        string suite;

    public: // Access specifier
        // Constructor
        Card(string theValue, string theSuite);
        // Copy constructor
        Card(const Card& other);
        // setValue function that sets a card's value
        void setValue(string newValue);
        // setSuite function that sets a card's suite
        void setSuite(string newSuite);
        // getValue function that returns a card's value
        string getValue();
        // getSuite function that returns a card's suite
        string getSuite();
        // Overloaded << operator to print a card's value and suite
        friend ostream& operator<<(ostream& out, const Card& one);
        // Overloaded assignment operator
        Card& operator=(const Card& other);
}; // end Card class

#endif
// End of header file