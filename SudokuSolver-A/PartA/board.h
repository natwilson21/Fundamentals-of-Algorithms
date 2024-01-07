// board class header file
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <limits.h>
#include "matrix.h"
#include "except.h"
#include <list>
#include <fstream>
using namespace std;

typedef int ValueType;
const int Blank = 0;
const int SquareSize = 3;
const int BoardSize = SquareSize * SquareSize;
const int ColSize = SquareSize * SquareSize;
const int MinValue = 1;
const int MaxValue = 9;

class board
// Reads and solves each board from file and outputs conflict vectors
{
public:
    board(int);
    int recursiveCalls = 0;
    void clear();
    void initialize(ifstream &fin);
    void print();
    bool isBlank(int, int);
    ValueType getCell(int, int);
    matrix<vector<bool>> cellConflicts;
    void updateConflicts(int i, int j);
    void printConflicts();
    void setValue(int i, int j, ValueType v);
    void clearCell(int i, int j);
    bool isSolved();
private:
    matrix<ValueType> value;
    int arr[BoardSize][BoardSize];
};

#endif
// End of header file