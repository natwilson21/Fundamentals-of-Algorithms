#ifndef CODE_H
#define CODE_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
// #include "Response.h"

using namespace std;

// Part A: Implement the class code which stores the code as a vector
class Code {
public: // Access specifier
    // Constructor
    int n;
    int m;
    vector<int> codeVector;
    
    Code(const vector<int> &guess);
    Code(int n, int m);

    // Creates the secretCode vector of n amount of random ints ranging from 0
    // to m-1.
    void Initialize(int n, int m);

    // (d)
    // Calculates and returns the number of correct digits in the correct location
    // from the given parameter Code object guess. Returns the number of correct
    // digits in the right location.
    int checkCorrect(Code &guess);

    // (e)
    // Calculates and returns the number of incorrect digits in the wrong location
    // from the given parameter Code object guess. Returns the number of incorrect
    // digits in the wrong location.
    int checkIncorrect(Code &guess);
}; // end Code

#endif
