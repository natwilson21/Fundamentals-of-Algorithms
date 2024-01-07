#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include "Mastermind.h"
using namespace std;


Mastermind::Mastermind(int x, int y): secretCode(x, y){
    }
Mastermind::Mastermind():Mastermind(5, 10) {
    Code secretCode(5, 10);
}

// (c)
void Mastermind::printSecretCode(vector<int> codeVector)
// Prints the secret code
{
    for (int i = 0; i < codeVector.size(); i++){
        if (i != 0) {
            cout << ", ";
        }
        cout << codeVector[i];
    }
    cout << endl;
} // end printSecretCode

// (d)
Code Mastermind::humanGuess()
//reads a guess from the keyboard and returns a code object that represents
// the guess
{
    vector<int> guessVector(secretCode.codeVector.size());

    cout << "What is your guess? (Hit enter after each digit)" << endl;
    for (int i = 0; i < secretCode.codeVector.size(); i++)
    // Inputs user guess from keyboard into a vector
    {
        cin >> guessVector[i];
    }
    Code curGuess(guessVector);
    return curGuess;
} // end humanGuess

// (e)
Response Mastermind::getResponse(Code guess)
// Receives the guess code and returns a Response
{
    Response curResponse(secretCode, guess);
    return curResponse;
}

// (f)
bool Mastermind::isSolved(Response theResponse)
// Passed a Response and returns true if the board has been solved
{
    int numCorrect = theResponse.getCorrect();
    int numIncorrect = theResponse.getIncorrect();
    if (numCorrect == secretCode.codeVector.size())
    // Determines if board has been solved
    {
        return true;
    }
    else {
        return false;
    }
} // end isSolved

// (g)
void Mastermind::playGame()
// Initializes a random code, prints it to the screen, and then iteratively
// gets a guess from the user and prints the response until either the
// codemaker or the codebreaker has won.
{
    printSecretCode(secretCode.codeVector);
    Code curGuess = humanGuess();
    Response curResponse = getResponse(curGuess);
    cout << curResponse;
    int numTries = 1;
    while(!(isSolved(curResponse)) && numTries != 11)
    // Game continues to play when board is not solved
    {
        cout << "Your guess is incorrect. Try again." << endl;
        numTries ++;
        curGuess = humanGuess();
        curResponse = getResponse(curGuess);
        cout << curResponse;
    }
    if (numTries < 10)
    // Prints that the codebreaker has cracked the code
    {
        cout << "You cracked the code!" << endl;
    }
    else
    // If the codebreaker can not solve the code in 10 or fewer guesses.
    {
        cout << "You could not crack the code. The codemaker wins." << endl;
    }
} // end playGame