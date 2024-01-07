#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include "Code.h"
#include "Response.h"
using namespace std;

// Part 2: implement the class mastermind
class Mastermind{
public:
    // (a)
    Code secretCode;
    
    // (b)
    Mastermind(int x, int y);
    Mastermind();
    // (c)
    // Prints the secret code
    void printSecretCode(vector<int> codeVector);

    // (d)
    //reads a guess from the keyboard and returns a code object that represents
    // the guess
    Code humanGuess();

    // Receives the guess code and returns a Response
    Response getResponse(Code guess);
    
    // (f)
    // Passed a Response and returns true if the board has been solved
    bool isSolved(Response theResponse);
    
    // Initializes a random code, prints it to the screen, and then iteratively
    // gets a guess from the user and prints the response until either the
    // codemaker or the codebreaker has won.
    void playGame();
}; // end Mastermind

#endif