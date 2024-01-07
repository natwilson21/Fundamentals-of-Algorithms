// Card class cpp file

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Card.h"

using namespace std;

Card::Card(string theValue, string theSuite)
// Constructor that sets the value and suite of the card
{
    value = theValue;
    suite = theSuite;
}

Card::Card(const Card& other) 
// Copy constructor that copies the value and suite of a card
{
    value = other.value;
    suite = other.suite;
}

void Card::setValue(string newValue)
// Sets a card's value
{
    value = newValue;
} // end setValue

void Card::setSuite(string newSuite)
// Sets a card's suite
{
    suite = newSuite;
} // end setSuite

string Card::getValue()
// Returns a card's value
{
    return value;
} // end getValue

string Card::getSuite()
// Returns a card's suite
{
    return suite;
} // end getSuite

//Overloaded << operator to print a card's value and suite
ostream& operator<<(ostream& out, const Card& theCard)
{
    // All possible card values
    string valueList[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    out << theCard.value << " of " << theCard.suite << endl;
    return out;
}

// Overloaded assignment operator that copies a card's value and suite
Card& Card::operator=(const Card& other) {
    if (this != &other) 
    // Copies the card value and suite if it is different
    {
        value = other.value;
        suite = other.suite;
    }
    return *this;
}