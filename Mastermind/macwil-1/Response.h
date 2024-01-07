#ifndef RESPONSE_H
#define RESPONSE_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include "Code.h"
// #include "Mastermind.h"

using namespace std;

// Part B
// Part 1: Implementing the class response
class Response {
public:
    // (a)
    Response(Code codeVector, Code guess);
    void setCorrect(int numberCorrect);
    // Gets the individual stored value of numberCorrect within a response object.
    int getCorrect();
    void setIncorrect(int numberIncorrect);
    int getIncorrect();
    // (c)
    friend bool operator==(Response one, Response two);

    friend ostream& operator<<(ostream& out, const Response& one);

private:
    // Constructors
    int correct, incorrect; // Number of correct and incorrect digits guessed
}; // end Response

#endif