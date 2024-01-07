// Main class cpp file for Part A
// Created by Spandana Machavarapu and Natalia Wilson
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

void findMatches(Grid myGrid, dictionary dictWord) 
// Prints out all currWord that can be found in the grid
{
    vector<string> wordsFound;
    for (int i = 0; i < int(dictWord.word.size()); i++) 
    // For each word in the dictionary
    {
        string currWord = dictWord.word[i]; 
        for (int r = 0; r < int(myGrid.row); ++r)
        // Search rows
        {
            for (int c = 0; c < int(myGrid.matrix[r].size()); ++c)
            // Search columns
            {
                if (myGrid.matrix[r][c] == currWord[0]) 
                // If current element matches the first letter of the word
                // Check if word can be found in any direction starting from this element
                {
                    if (int(myGrid.row) >= r + int(currWord.length()))
                    // Check downwards
                    {
                        string temp = "";
                        for (int k = 0; k < int(currWord.length()); k++) 
                        {
                            temp += myGrid.matrix[r + k][c];
                        }
                        if (temp == currWord) 
                        {
                            wordsFound.push_back(currWord);
                        }
                    }

                    if (-1 <= r - int(currWord.length())) 
                    // Check upwards
                    {
                        string temp = "";
                        for (int k = 0; k < int(currWord.length()); k++) 
                        {
                            temp += myGrid.matrix[r - k][c];
                        }
                        if (temp == currWord) 
                        {
                            wordsFound.push_back(currWord);
                        }
                    }

                    if (c + int(currWord.length()) <= int(myGrid.col)) 
                    // Check elements to the right
                    {
                        string temp = "";
                        for (int k = 0; k < int(currWord.length()); k++) 
                        {
                            temp += myGrid.matrix[r][c+k];
                        }
                        if (temp == currWord) 
                        {
                            wordsFound.push_back(currWord);
                        }
                    }

                    if (c - int(currWord.length()) >= -1) 
                    // Check elements to the left
                    { 
                        string temp = "";
                        for (int k = 0; k < int(currWord.length()); k++) 
                        {
                            temp += myGrid.matrix[r][c-k];
                        }
                        if (temp == currWord) 
                        {
                            wordsFound.push_back(currWord);
                        }
                    }

                    if (r + int(currWord.length()) <= int(myGrid.row) && c + int(currWord.length()) <= int(myGrid.col)) 
                    // Check negative diagonal (down and right)
                    {
                        string temp = "";
                        for (int k = 0; k < int(currWord.length()); k++) 
                        {
                            temp += myGrid.matrix[r+k][c+k];
                        }
                        if (temp == currWord) 
                        {
                            wordsFound.push_back(currWord);
                        }
                    }

                    if (r - int(currWord.length()) >= -1 && c + int(currWord.length()) <= int(myGrid.col)) 
                    // Check positive diagonal (up and right)
                    {
                        string temp = "";
                        for (int k = 0; k < int(currWord.length()); k++) 
                        {
                            temp += myGrid.matrix[r-k][c+k];
                        }
                        if (temp == currWord) 
                        {
                            wordsFound.push_back(currWord);
                        }
                    }

                    if (r + int(currWord.length()) <= int(myGrid.row) && c - int(currWord.length()) >= -1) 
                    // Check positive diagonal (downwards leftwards)
                    {
                        string temp = "";
                        for (int k = 0; k < int(currWord.length()); k++) 
                        {
                            temp += myGrid.matrix[r+k][c-k];
                        }
                        if (temp == currWord) 
                        {
                            wordsFound.push_back(currWord);
                        }
                    }

                    if (r - int(currWord.length()) >= -1 && c - int(currWord.length()) >= -1) 
                    // Check negative diagonal (up and left)
                    {
                        string temp = "";
                        for (int k = 0; k < int(currWord.length()); k++) 
                        {
                            temp += myGrid.matrix[r-k][c-k];
                        }
                        if (temp == currWord) 
                        {
                            wordsFound.push_back(currWord);
                        }
                    } 
                } // end if
            } // end for loop (col)
        } // end for loop (row)
    } // end for loop (matrix)

    auto foundWords = unique(wordsFound.begin(), wordsFound.end());
    wordsFound.resize(distance(wordsFound.begin(), foundWords));
    for(foundWords = wordsFound.begin(); foundWords!=wordsFound.end(); ++foundWords) 
    // Only prints out unique words found (no repeats)
    {
        cout << ' ' << *foundWords << endl;
    } // end for loop
} // end findMatches


int main()
// Main function
{
    dictionary myDict("dictionary");
    string findWord;
    cout << "Enter a word to look up: " << endl;
    cin >> findWord;
    myDict.binarySearch(findWord);

    // Auto Chooses input15 File to test Part A
    Grid myGrid("input15");
    myGrid.displayGrid();

    // Perform word search and print result
    findMatches(myGrid, myDict);
    return 0;
}