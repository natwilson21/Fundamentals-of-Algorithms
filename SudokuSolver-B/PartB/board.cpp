// board class cpp file

#include <iostream>
#include <limits.h>
#include "matrix.h"
#include "except.h"
#include <list>
#include <fstream>
#include "board.h"

using namespace std;

board::board(int sqSize) : value(BoardSize, BoardSize), cellConflicts(BoardSize, BoardSize)
// board class constructor
{
    clear();
}

void board::clear()
// Resets counters for num of recursive calls and cell conflicts
{
    for (int row = 0; row < BoardSize; row++)
        for (int col = 0; col < BoardSize; col++)
        // Traverses through each row and column
        {
            value[row][col] = Blank;
            cellConflicts[row][col].assign(BoardSize + 1, true);
            recursiveCalls = 0;
        }
}

void board::initialize(ifstream &fin)
// Reads each board from file and updates conflict vectors
{
    char ch;
    clear();
    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        // Traverses through each row and column
        {
            fin >> ch;
            if (ch != '.')
            // Converts numbers from char to int for each board
            {
                value[i][j] = ch - '0';
                updateConflicts(i, j);
                arr[i][j] = ch - '0';
            }
            else
            // Changes '.' to 0 to represent a blank space on the board
            {
                arr[i][j] = Blank;
                value[i][j] = Blank;
                updateConflicts(i, j);
            }
        }
    }
}

void board::updateConflicts(int i, int j)
// Updates conflict vectors as board changes for each recursive call
{
    for (int k = 0; k < BoardSize; k++)
    // Updates vectors based on row values or column values
    {
        cellConflicts[i][k][value[i][j]] = false;
        cellConflicts[k][j][value[i][j]] = false;
    }

    int squareStartRow = SquareSize * (i / SquareSize);
    int squareStartCol = SquareSize * (j / SquareSize);
    for (int row = squareStartRow; row < squareStartRow + SquareSize; row++)
    {
        for (int col = squareStartCol; col < squareStartCol + SquareSize; col++)
        // Updates vectors based on values in 3x3 square
        {
            cellConflicts[row][col][value[i][j]] = false;
        }
    }
}

ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class.
{
    for (int i = 0; i < int(v.size()); i++)
        ostr << v[i] << " ";
    return ostr;
}

ValueType board::getCell(int i, int j)
// Returns the value stored in a cell.
{
    return arr[i][j];
}

bool board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{
    return (getCell(i, j) == Blank);
}

void board::print()
// Prints the current board.
{
    for (int i = 0; i < BoardSize; i++)
    {
        if (i > 0 && i % SquareSize == 0)
        {
            cout << " -";
            for (int j = 0; j < BoardSize; j++)
                cout << "---";
                cout << "-";
                cout << endl;
        }
        for (int j = 0; j < BoardSize; j++)
        {
            if (j > 0 && j % SquareSize == 0)
                cout << "|";
            if (!isBlank(i, j))
                cout << " " << getCell(i, j) << " ";
            else
                cout << " " << " " << " ";
        }
        cout << "|";
        cout << endl;
    }
    cout << " -";
    for (int j = 0; j < BoardSize; j++)
        cout << "---";
    cout << "-" << endl;
}

void board::printConflicts()
// Prints the cell conflicts vector for the current board
{
    cout << "Conflicts:" << endl;
    for (int i = 0; i < BoardSize; i++)
        for (int j = 0; j < BoardSize; j++)
        {
            updateConflicts(i, j);
            cout << "{";
            for (int k = 0; k < BoardSize; k++)
                cout << cellConflicts[i][j][k] << ",";
            cout << "}" << endl;
        }
}

void board::setValue(int i, int j, ValueType v)
// Sets a new value at a specified cell and updates conflict vectors
{
    arr[i][j] = v;
    value[i][j] = v;
    updateConflicts(i, j);
}

void board::clearCell(int i, int j)
// Clears the value at a specified cell and updates conflict vectors
{
    if (i >= 0 && i < BoardSize && j >= 0 && j < BoardSize)
    {
        arr[i][j] = 0;
        for (int k = 0; k <= BoardSize; k++)
        {
            cellConflicts[i][j][k] = true;
        }
        updateConflicts(i, j);
    }
}

bool board::isSolved()
// Determines if the board is solved. Outputs true(1) if solvable and false(0) otherwise.
{
    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        {
            if (isBlank(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

bool board::SolveSudoku()
// Solves the Sudoku puzzle
{
    int row, col;
    if (!FindEmptyVal(row, col)) // Determines if all cells contain a value
        return true;
    for (int num = MinValue; num <= MaxValue; num++) 
    // Inputs a number from 1 to 9 in a cell
    {
        if (isSafe(row, col, num))
        // Inputs number if valid and updates conflict vectors
        {
            arr[row][col] = num;
            setValue(row, col, num);
            updateConflicts(row, col);
            if (SolveSudoku())
            // If board has been solved
                return true;
            arr[row][col] = 0;
            setValue(row, col, 0);
            updateConflicts(row, col);
        }
    }
    // If board has not been fully solved
    // printConflicts();
    recursiveCalls++;
    return false;
}

bool board::FindEmptyVal(int &row, int &col)
// Finds empty cells in a board and returns true if found, false otherwise
{
    for (row = 0; row < BoardSize; row++)
        for (col = 0; col < BoardSize; col++)
            if (arr[row][col] == 0)
                return true;
    return false;
}

bool board::UsedInRow(int row, int num)
// Determines if number is already in the row and returns true, otherwise returns false
{
    for (int col = 0; col < BoardSize; col++)
        if (arr[row][col] == num)
            return true;
    return false;
}

bool board::UsedInCol(int col, int num)
// Determines if number is already in the column and returns true, otherwise returns false
{
    for (int row = 0; row < BoardSize; row++)
        if (arr[row][col] == num)
            return true;
    return false;
}

bool board::UsedInBox(int boxStartRow, int boxStartCol, int num)
// Determines if number is already in the 3x3 box and returns true, otherwise returns false
{
    for (int row = 0; row < SquareSize; row++)
        for (int col = 0; col < SquareSize; col++)
            if (arr[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

bool board::isSafe(int row, int col, int num)
// If number is not in row and column and in 3x3 box, the number is valid
{
    return !UsedInRow(row, num) && !UsedInCol(col, num) && !UsedInBox(row - row % SquareSize, col - col % SquareSize, num);
}