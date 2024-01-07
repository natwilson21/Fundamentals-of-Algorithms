// Main class cpp file for Part A
// Created by Spandana Machavarapu and Natalia Wilson
#include <iostream>
#include <limits.h>
#include "matrix.h"
#include "except.h"
#include <list>
#include <fstream>
#include "board.h"

using namespace std;

int main()
// Main function for Part A
{
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
    // If file opened successfully
    {
        board b1(SquareSize);
        while (fin && fin.peek() != 'Z')
        // Reads each board from file
        {
            b1.initialize(fin);
            boardCount++;
            cout << "\nBoard: " << boardCount << endl;
            b1.print();
            b1.printConflicts();
            cout << "Puzzle solved: " << b1.isSolved() << endl;
        }
    }
    catch (rangeError &ex)
    {
        cout << ex.what() << endl;
        exit(1);
    }
    return 0;
} // End main