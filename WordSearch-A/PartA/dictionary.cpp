// dictionary class cpp file

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include "dictionary.h"

using namespace std;

dictionary::dictionary(string wordFile)
// dictionary class constructor
{
    dictionaryFile = wordFile;
    readcurrWord();
    selSort();
} // end dictionary

void dictionary::readcurrWord()
// Read currWord from the dictionary.txt file
{
    fstream dictFile;
    dictFile.open(dictionaryFile); // open file
    if (dictFile.is_open())
        // check if file opened properly
    {
        string str;
        while (getline(dictFile, str))
            // read currWord from file as a string vector
        {
            word.push_back(str);
        }
        dictFile.close(); // close file
    }
} // end readcurrWord

void dictionary::printcurrWord()
// Prints the word vector
{
    cout << "\nVector word elements are: " << endl;
    for (int i = 0; i < int(word.size()); i++)
    // Traverse through every element in the vector
    {
        cout << word[i] << endl;
    }
} // end printcurrWord

void dictionary::selSort()
// Sorts the currWord using selection sort with time complexity of O(n^2)
{
    int n = word.size(); 
    int i;
    int j;
    int min_index;
    for (i = 0; i < n - 1; i++)
    // Traverse vector to constantly move boundary between sorted and unsorted currWord
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (word[j] < word[min_index])
            // Find the minimum element
            {
                min_index = j;
            }
        }
        if (min_index != i)
        // Swap the minimum element with the first element
        {
            swap(word[min_index], word[i]);
        }
    }
} // end selSort

int dictionary::binarySearch(string findWord)
// Binary search function for word look up
{
    int i = 0;
    int n = (word.size()) - 1;
    while (i <= n)
    // Divide the search space in half
    {
        int eleIndex = i + (n - i) / 2;
        if (word[eleIndex] == findWord)
        // check if findWord is at middle position
        {
            cout << "Word found at index: " << eleIndex << endl;
            return eleIndex;
        }
        if (word[eleIndex] < findWord)
        // If findWord is greater than middle element, ignore left half
        {
            i = eleIndex + 1;
        }
        else
        // If findWord is smaller than middle element, ignore right half
        {
            n = eleIndex - 1;
        }
    }
    // If element was not found in vector
    cout << "Word was not found." << endl;
    return -1;
} // end binarySearch