// Grid class cpp file

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include "dictionary.h"
#include "Grid.h"

using namespace std;

Grid::Grid(string gridFile)
// Grid class constructor
{
    fstream inputFile;
    inputFile.open(gridFile);
    string line;
    int lineCount = 0;
    while (getline(inputFile, line))
    // Creates matrix rows
    {
        if (lineCount == 0)
        // Skip the first line
        {
            lineCount++;
            continue;
        }
        vector<char> row;
        for (int i = 0; i < int(line.size()); ++i)
        // Fill rows with characters from currWord
        {
            if (line[i] != ' ') {
                row.push_back(line[i]);
            }
        }
        matrix.push_back(row);
    }
    row = matrix.size();
    // col = matrix[0].size();
}

void Grid::displayGrid()
// Prints the grid
{
    for (int i = 0; i < int(matrix.size()); ++i)
    // Traverse through rows
    {
        for (int j = 0; j < int(matrix[i].size()); ++j)
        // Traverse through columns
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
} // end displayGrid