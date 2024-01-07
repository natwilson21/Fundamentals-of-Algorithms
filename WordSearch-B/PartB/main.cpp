// Main class cpp file 
// Created by Spandana Machavarapu and Natalia Wilson
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include "Grid.h"
#include "dictionary.h"


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
    for (foundWords = wordsFound.begin(); foundWords!=wordsFound.end(); ++foundWords)
    // Only prints out unique words found (no repeats)
    {
        if (foundWords->length() >= 5)
        {
            cout << ' ' << *foundWords << endl;
        }
    } // end for loop
} // end findMatches

void search(int sortingAlgorithm) 
// global function search which prints out all words that can be found in grid.
{
    string dictionaryFile, gridFile;
    dictionaryFile = "dictionary";
    dictionary myDict(dictionaryFile);
    switch (sortingAlgorithm) 
    // Choose sorting algorithm based on the input
    {
        case 1:
            myDict.quickSort(0, myDict.word.size() - 1);
            break;
        case 2:
            myDict.heapSort();
            break;
        default:
            cout << "Invalid sorting algorithm choice." << endl;
            return;
    }
    myDict.printcurrWord();
    //input15, input30, input50-1
    cout << "Enter the name of the grid file: ";
    cin >> gridFile;
    Grid myGrid(gridFile);
    myGrid.displayGrid();
    findMatches(myGrid, myDict);
} // end search


int main()
// Main function
{
    dictionary myDict("dictionary");

    // Auto Chooses input15 File to test Part B
    Grid myGrid("input15");
    myGrid.displayGrid();

    // Perform word search and print result
    findMatches(myGrid, myDict);

    // Perform word search and print result for Part B
    findMatches(myGrid, myDict);
    // Quick Sort
    myDict.quickSort(0, myDict.word.size() - 1);
    // Heap Sort
    myDict.heapSort();
    myDict.printcurrWord();

    // 1 for quicksort and 2 for heapsort
    int searchValue;
    cout << "Enter 1 for quicksort or 2 for heapsort: " << endl;
    cin >> searchValue;
    search(searchValue);
    return 0;
}