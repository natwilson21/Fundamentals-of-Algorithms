#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include "Code.h"
using namespace std;

Code::Code(const vector<int> &guess)
// Sets guess equal to Code object called codeVector
{
    codeVector = guess;
}

// (b) the code class declaration
Code::Code(int n, int m) {
    codeVector.resize(n);
    Initialize(n, m);
}

// (c)
void Code::Initialize(int n, int m)
// Creates the secretCode vector of n amount of random ints ranging from 0
// to m-1.
{
    srand(time(0)); // Use current time as seed for random number generator
    for (int i = 0; i < n; i++)
    // Iterates through the codeVector to assign random integer values
    // for each element.
    {
        codeVector[i] = rand() % m;
    }
} // end Initialize

int Code::checkCorrect(Code &guess)
// Calculates and returns the number of correct digits in the correct location
// from the given parameter Code object guess. Returns the number of correct
// digits in the right location.
{
    int correct = 0;
    for (int i = 0; i < guess.codeVector.size(); i++)
    // Iterates through the secretCode vector and guess code vector to
    // determine if both elements are equal.
    {
        if (guess.codeVector[i] == codeVector[i]) {
            correct++;
        }
    }
    return correct;
} // end checkCorrect

int Code::checkIncorrect(Code &guess)
// Calculates and returns the number of incorrect digits in the wrong location
// from the given parameter Code object guess. Returns the number of incorrect
// digits in the wrong location.
{
    int incorrect = 0;
    vector<int> tempCodeVector {codeVector};
    for (int i = 0; i < guess.codeVector.size(); i++)
    // Iterates through the guess vector
    {
        for (int i = 0; i < guess.codeVector.size(); i++)
        // Iterates through code vector to determine if both elements are
        // equal and changes values to -2 and -1.
        {
            if (guess.codeVector[i] == tempCodeVector[i]) {
                guess.codeVector[i] = -2;
                tempCodeVector[i] = -1;
            }
        }

        for (int j = 0; j < guess.codeVector.size(); j++)
        // Iterates through the code vectors to determine correct digits in
        // the incorrect location
        {
            if ((guess.codeVector[i] == tempCodeVector[j]) && (tempCodeVector[j] >= 0)) {
                tempCodeVector[j] = -1; //avoid counting duplicates
                incorrect++;
                break;
                }
            }

        }
    return incorrect;
} // end checkIncorrect