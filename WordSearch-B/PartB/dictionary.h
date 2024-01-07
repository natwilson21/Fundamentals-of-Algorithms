// dictionary class header file
#ifndef DICTIONARY_H
#define DICTIONARY_H 

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class dictionary
// dictionary class that reads the currWord from the dictionary file and stores them in a vector
{
private: // Access specifier
    string dictionaryFile;
public: // Access specifier
    dictionary(string wordFile); // Constructor
    vector<string> word;
    void readcurrWord();
    void printcurrWord();
    void selSort();
    void heapSort();
    void quickSort(int low, int high);
    int binarySearch(string findWord);
};

template <class T>
class heap {
private:
    int parent(int i);
    int left(int i);
    int right(int i);

public:
    vector<T> items;

    void initializeMaxHeap();
    void maxHeapify(int i, int heapSize);
    void buildMaxHeap();
    void heapsort();
};
#endif
// End of header file