#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

template <typename T>
class matrix 
{
public:
    matrix(int rows, int cols);
    matrix(const matrix<T>& rhs);
    matrix<T>& operator=(const matrix<T>& rhs);
    std::vector<T>& operator[](int row);
    const std::vector<T>& operator[](int row) const;
    int rows() const;
    int cols() const;

private:
    int numRows;
    int numCols;
    std::vector<std::vector<T>> mat;
};

template <typename T>
matrix<T>::matrix(int rows, int cols) : numRows(rows), numCols(cols), mat(rows, std::vector<T>(cols)) {}

template <typename T>
matrix<T>::matrix(const matrix<T>& rhs) : numRows(rhs.numRows), numCols(rhs.numCols), mat(rhs.mat) {}

template <typename T>
matrix<T>& matrix<T>::operator=(const matrix<T>& rhs) 
{
    if (this != &rhs) 
    {
        numRows = rhs.numRows;
        numCols = rhs.numCols;
        mat = rhs.mat;
    }
    return *this;
}

template <typename T>
std::vector<T>& matrix<T>::operator[](int row) 
{
    return mat[row];
}

template <typename T>
const std::vector<T>& matrix<T>::operator[](int row) const 
{
    return mat[row];
}

template <typename T>
int matrix<T>::rows() const 
{
    return numRows;
}

template <typename T>
int matrix<T>::cols() const 
{
    return numCols;
}

#endif  // MATRIX_H
