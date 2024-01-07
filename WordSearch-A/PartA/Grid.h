// Grid class header file
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include "dictionary.h"

using namespace std;

class Grid
// Reads the letters in the grid from a file and stores them in a matrix
{
public: // Access specifier
    Grid(string gridFile); // Constructor
    void displayGrid();
    vector<vector<char>> matrix;
    friend void findMatches(Grid myGrid, dictionary currWord);
private: // Access specifier
    int row;
    int col;
};
#endif
// End of header file