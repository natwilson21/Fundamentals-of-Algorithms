// Deck class cpp file

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Card.h"
#include "Node.h"
#include "Deck.h"

using namespace std;

Deck::Deck()
// Deck constructor that creates a deck with all the cards in order
{
    // Default number of cards in a deck
    cardCount = 52;
    // All possible card values and suite types
    string suiteList[] = {"Club", "Diamond", "Heart", "Spade"};
    string valueList[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    Node* tail = NULL;
    
    // Assigns a cards value and suite type
    for (int i = 0; i < 4; i++)
    // Assigns all four suite types
    {
        for (int j = 0; j < 13; j++)
        // Assigns all 13 possible values
        {
            Card currCard(valueList[j], suiteList[i]);
            // Creates a new node for every card
            Node* newNode = new Node(currCard);
            newNode->next = NULL;
            if (first == NULL) 
            // If the head node is NULL
            {
                first = newNode;
                tail = newNode;
            } 
            else 
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
} // end Deck

Deck::~Deck() 
// Destructor that deallocates the list of cards
{
    Node* current = first;
    while (current) 
    // While cards are still in the deck to be removed
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    first = NULL;
} // end ~Deck

// Overloaded << operator that prints the cards in the deck
ostream& operator<<(ostream& out, const Deck& theDeck)
{
    Node* current = theDeck.first;
    for (int i = 0; i < theDeck.cardCount; i++)
    // Prints every card in a deck 
    {
        out << current->card;
        current = current->next;
    }

    return out;
}

void Deck::shuffle()
// Shuffles the cards in the deck that puts cards in a random order
{
    vector<Card> cardVector;
    Node* current = first;
    while (current) 
    // Inserts cards back into the deck
    {
        cardVector.push_back(current->card);
        current = current->next;
    }

    int n = cardVector.size();
    // Randomizes what two cards are swapping positions
    srand(time(0));
    for (int i = n - 1; i > 0; i--) 
    {
        int j = rand() % (i + 1);
        swap(cardVector[i], cardVector[j]);
    }

    current = first;
    for (int i = 0; i < n; i++) 
    {
        current->card = cardVector[i];
        current = current->next;
    }
} // end shuffle

Card Deck::deal() 
// Returns the top card in the deck and removes it from the deck
{
    if (first != NULL) 
    // Gets the first card and deletes it from the deck
    {
        Card top = first->card;
        Node* temp = first;
        first = first->next;
        delete temp;
        cardCount--;
        return top;
    }
    else
    // Returns "Empty" if there is no top card
    {
        return Card("Empty", "Empty");
    }
} // end deal

void Deck::replace(const Card& card) 
// Given a card to be placed at the bottom of the deck
{
    // Creates a new node for the given card
    Node* newCard = new Node(card);
    newCard->next = NULL;

    if (first == NULL) 
    // If there is no top card
    {
        first = newCard;
    } 
    else
    // Places card at the bottom of the deck 
    {
        Node* current = first;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newCard;
    }
    cardCount++;
} // end replace

void Deck::playFlip() 
// Plays the game by reading instructions for the user and prints the results of the game
{
    // Initial values 
    int score = 0;
    int cardsDrawn = 0;
    cout << "Game started. The deck is shuffled three times." << endl;
    // The deck is shuffled three times
    shuffle();
    shuffle();
    shuffle();
    while (cardsDrawn < 24) 
    // The users deck contains 24 cards
    {
        Node* current = first;
        for (int i = 0; i < cardsDrawn; i++) 
        // Assign the user's 24 cards from the deck
        {
            current = current->next;
        }
        
        // Outputs number of cards drawn to the user
        cout << "Number of cards drawn: " << cardsDrawn << endl;
        cout << endl;
        
        // Determines if the user wants to flip a card or quit the game
        char flip;
        cout << "Do you want to flip the next card? (y/n): ";
        cin >> flip;
        if (flip == 'y') 
        // If user wants to flip the next card
        {
            // Oututs the value and suite of the card flipped
            Card cardDrawn = deal();
            cout << "Card drawn: " << cardDrawn;

            if (cardDrawn.getValue() == "Ace")
            // If card is an Ace, user recieves 10 points
            {
                score += 10;
            }
            else if (cardDrawn.getValue() == "King" || cardDrawn.getValue() == "Queen" || cardDrawn.getValue() == "Jack")
            // If card is a King, Queen, or Jack, user recieves 5 points
            {
                score += 5;
            }
            else if (cardDrawn.getValue() == "7")
            // If card is a 7, user loses half of their points
            {
                score /= 2;
            }
            else if (cardDrawn.getValue() == "2" || cardDrawn.getValue() == "3" || cardDrawn.getValue() == "4" || cardDrawn.getValue() == "5" || cardDrawn.getValue() == "6")
            // If card is a 2, 3, 4, 5, or 6, user loses all of their points
            {
                score = 0;
            }
            if (cardDrawn.getSuite() == "Heart")
            // If card is an Heart, user recieves 1 additional point
            {
                score += 1;
            }

            cardsDrawn++;
            cout << "Current score: " << score << endl;
        } // end if wants to play
        else if (flip == 'n') 
        // if user does not want to play
        {
            break;
        } // end else if 
        else 
        // If user input is invalid
        {
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl;
        } // end else
    } // end while
    
    cout << "Game ended. Final score: " << score << endl;
} // end playFlip