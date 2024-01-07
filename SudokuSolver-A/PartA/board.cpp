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
{
    clear();
}

void board::clear()
{
    for (int i = 0; i < BoardSize; i++)
        for (int j = 0; j < BoardSize; j++)
        {
            value[i][j] = Blank;
            cellConflicts[i][j].assign(BoardSize + 1, true);
            recursiveCalls = 0;
        }
}

void board::initialize(ifstream &fin)
{
    char ch;
    clear();
    for (int i = 0; i < BoardSize; i++)
    {
        for (int j = 0; j < BoardSize; j++)
        {
            fin >> ch;
            if (ch != '.')
            {
                value[i][j] = ch - '0';
                updateConflicts(i, j);
                arr[i][j] = ch - '0';
            }
            else
            {
                arr[i][j] = Blank;
                value[i][j] = Blank;
                updateConflicts(i, j);
            }
        }
    }
}

void board::updateConflicts(int i, int j)
{
    for (int k = 0; k < BoardSize; k++)
    {
        cellConflicts[i][k][value[i][j]] = false;
        cellConflicts[k][j][value[i][j]] = false;
    }

    int squareStartRow = SquareSize * (i / SquareSize);
    int squareStartCol = SquareSize * (j / SquareSize);
    for (int row = squareStartRow; row < squareStartRow + SquareSize; row++)
    {
        for (int col = squareStartCol; col < squareStartCol + SquareSize; col++)
        {
            cellConflicts[row][col][value[i][j]] = false;
        }
    }
}

int squareNumber(int i, int j)
{
    return SquareSize * (i / SquareSize) + (j / SquareSize);
}

ostream &operator<<(ostream &ostr, vector<int> &v)
{
    for (int i = 0; i < int(v.size()); i++)
        ostr << v[i] << " ";
    return ostr;
}

ValueType board::getCell(int i, int j)
{
    return arr[i][j];
}

bool board::isBlank(int i, int j)
{
    return (getCell(i, j) == Blank);
}

void board::print()
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
{
    arr[i][j] = v;
    value[i][j] = v;
    updateConflicts(i, j);
}

void board::clearCell(int i, int j)
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