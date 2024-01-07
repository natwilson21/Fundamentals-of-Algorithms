#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include "Response.h"
using namespace std;

Response::Response(Code codeVector, Code guess) {
    correct = codeVector.checkCorrect(guess);
    incorrect = codeVector.checkIncorrect(guess);
}
// (b)
void Response::setCorrect(int numberCorrect)
// Sets the value of correct within a response object.
{
    correct = numberCorrect;
}
int Response::getCorrect()
// Gets the individual stored value of numberCorrect within a response object.
{
    return correct;
}
void Response::setIncorrect(int numberIncorrect)
// Sets the value of incorrect within a response object.
{
    incorrect = numberIncorrect;
}
int Response::getIncorrect()
// Gets the individual stored value of numberIncorrect within a response object.
{
    return incorrect;
}
// (c)
bool operator==(Response one, Response two)
// overloaded operator == that compares Response objects and returns true if
// both objects are equal.
{
    if ((one.correct == two.correct) && (one.incorrect == two.incorrect))
    // compares the values of variables correct and incorrect for both
    // Response objects.
    {
        return true; // If both Response objects are equal.
    }
    else
    {
        return false; // If both Response objects are unequal.
    }
} // end operator==

ostream &operator<<(ostream &out, const Response &one)
// overloaded operator << that compares Response objects and returns the
// response object.
{
    out << "(" << one.correct << "," << one.incorrect << ")" << endl;
    return out;
}