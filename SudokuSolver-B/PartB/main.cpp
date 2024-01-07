// Main class cpp file
// Created by Spandana Machavarapu and Natalia Wilson
#include <iostream>
#include "board.h"
#include <limits.h>
#include "matrix.h"
#include "except.h"
#include <list>
#include <fstream>

using namespace std;

int main()
// Main function to read and solve all Sudoku puzzles
{
    int avgRecursiveCall = 0;
    int boardCount = 0;
    ifstream fin;
    string fileName = "sudoku.txt";
    fin.open(fileName.c_str());
    if (!fin)
    // If file cannot be opened
    {
        cerr << "Cannot open " << fileName << endl;
        exit(1);
    }
    try
    // If file is opened successfully
    {
        board b1(SquareSize);
        while (fin && fin.peek() != 'Z')
        // Reads boards from file
        {
            b1.initialize(fin);
            boardCount++;
            cout << "Board: " << boardCount << endl;
            b1.print();
            if (b1.SolveSudoku())
            // Solves each board recursively
            {
                cout << "The puzzle is solved " << b1.isSolved() << "." << endl;
                b1.print();
                avgRecursiveCall += b1.recursiveCalls;
                cout << "Number of recursive calls needed to solve board: " << b1.recursiveCalls << endl;
            }
            else
            // If board has no valid solutions
            {
                cout << "No solution exists" << endl;
            }
        }
        cout << "Total number of recursive calls for all boards is: " << avgRecursiveCall << endl;
        avgRecursiveCall = avgRecursiveCall/boardCount; 
        cout << "Average number of recursive calls needed to solve all boards is: " << avgRecursiveCall << endl;
    }
    catch (rangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
    return 0;
} // end main

