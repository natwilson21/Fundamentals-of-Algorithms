#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include "Code.h"
#include "Response.h"
#include "Mastermind.h"
using namespace std;


 void sampleGuesses()
 // Tests the three given sample guess from Part A.
 {
     Code game(5, 10); // Initializes a secret code
     cout << "Secret Code: " << endl;
     for (int i = 0; i < 5; i++) {
         cout << game.codeVector[i] << ", ";
     }
     cout << endl;
     Code sampleGuess1({5, 0, 3, 2, 6});
     cout << "Sample Guess 1: " << endl << "5, 0, 3, 2, 6" << endl;
     cout << "(" << game.checkCorrect(sampleGuess1) << ", " << game.checkIncorrect(sampleGuess1) << ")" << endl;
     Code sampleGuess2({2, 1, 2, 2, 2});
     cout << "Sample Guess 2: " << endl << "2, 1, 2, 2, 2" << endl;
     cout << "(" << game.checkCorrect(sampleGuess2) << ", " << game.checkIncorrect(sampleGuess2) << ")" << endl;
     Code sampleGuess3({1, 3, 3, 4, 5});
     cout << "Sample Guess 3: " << endl << "1, 3, 3, 4, 5" << endl;
     cout << "(" << game.checkCorrect(sampleGuess3) << ", " << game.checkIncorrect(sampleGuess3) << ")" << endl;
 } // end sampleGuesses


// Main Function
int main() {
    int n;
    int m;
    cout << "Part A Sample Guesses" << endl;
    sampleGuesses();
    cout << "\nWelcome to Mastermind!" << endl;
    cout << "How many digits would you like the secret code to be? (value of n)" << endl;
    cin >> m;
    cout << "What is the range of the secret code (range is 0 to m-1)? (value of m)" << endl;
    cin >> n;
    Mastermind game(m, n);
    game.playGame();
    cout << "Thank you for playing!" << endl;
    system("pause");
    return 0;
} // end main