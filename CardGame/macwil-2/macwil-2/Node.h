// Node class header file
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "Card.h"

using namespace std;

class Node
// Represents a node of the linked list
{
    public:
    // Constructor
        Card card;
        Node *next;
        Node(const Card& item, Node *nextNode = NULL) : card(item), next(nextNode) {}
}; // end Node class

#endif 
// End of header file