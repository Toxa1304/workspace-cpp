#ifndef DS_MATRIX_H
#define DS_MATRIX_H

#include "Ratio.h"
#include <iostream>
#include <string>

namespace ds_course
{
    template <class T>
    class Matrix
    {
    private:
        int rows; // row count
        int cols; // column count
    public:
        T **a;
        Matrix(int rr, int cc);
        char type[2];
        int getRows();
        int getCols();

        bool operator==(const ds_course::Matrix<T> &rhs);
        void operator+(const ds_course::Matrix<T> &rhs);
        void operator-(const ds_course::Matrix<T> &rhs); 
        void operator*(const ds_course::Matrix<T> &rhs); 
        friend std::istream &operator>>(std::istream &input, ds_course::Matrix<T> &m)
        {
            for (int i = 0; i < m.getRows(); i++)
                for (int j = 0; j < m.getCols(); j++)
                    input >> m.a[i][j];
            return input;
        }
    };
} // namespace ds_course


template <class T>
ds_course::Matrix<T>::Matrix(int rr, int cc) : rows(rr), cols(cc)
{
    a = new T *[rows];
    for (int i = 0; i < rows; i++)
        a[i] = new T[cols];
}

template <class T>
int ds_course::Matrix<T>::getRows() { return rows; }

template <class T>
int ds_course::Matrix<T>::getCols() { return cols; }


template <class T>
bool ds_course::Matrix<T>::operator==(const ds_course::Matrix<T> &rhs)
{
    if (rows != rhs.rows)
    {
        throw std::out_of_range("row counts differ");
    }
    if (cols != rhs.cols)
    {
        throw std::out_of_range("col counts differ");
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (! (a[i][j] == rhs.a[i][j]))
                return false;
    return true;
}
template <class T>
void ds_course::Matrix<T>::operator+(const ds_course::Matrix<T> &rhs)
{
    if (rows != rhs.rows)
    {
        std::cout << "out_of_range";
        throw std::out_of_range("row counts differ");
    }
    if (cols != rhs.cols)
    {
        std::cout << "out_of_range";
        throw std::out_of_range("col counts differ");

    }
    std::cout << "M"<< type[0] << " " << rows << " " << cols << std::endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++){
            a[i][j] = a[i][j] + rhs.a[i][j];
            if(j==cols-1){
                std::cout << a[i][j] << std::endl;
            }
            else{
            std::cout << a[i][j] << " ";
            }
        }    

}
template <class T>
void ds_course::Matrix<T>::operator-(const ds_course::Matrix<T> &rhs)
{
    if (rows != rhs.rows)
    {
        std::cout << "out_of_range";
        throw std::out_of_range("row counts differ");

    }
    if (cols != rhs.cols)
    {
        std::cout << "out_of_range";
        throw std::out_of_range("col counts differ");

    }
    std::cout << "M"<< type[0] << " " << rows << " " << cols << std::endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++){
            a[i][j] = a[i][j] - rhs.a[i][j];
            if(j==cols-1){
                std::cout << a[i][j] << std::endl;
            }
            else{
            std::cout << a[i][j] << " ";
            }
        }    
}
template <class T>
void ds_course::Matrix<T>::operator*(const ds_course::Matrix<T> &rhs)
{
    if (cols != rhs.rows)
    {
        throw std::runtime_error("out_of_range");
        // std::cout << "out_of_range";
        // throw std::out_of_range("Multiplication impossible, invalid matrices");

    }
    Matrix<T> resultingMatrix(rows,rhs.cols);
    int i,j,k;
    for(i=0; i<rows; i++)
      for(j=0; j<rhs.cols; j++)
      for(k=0; k<cols; k++) {
        
         resultingMatrix.a[i][j] = (resultingMatrix.a[i][j] + a[i][k]*rhs.a[k][j]);
      }
    std::cout << "M"<< type[0] << " " << resultingMatrix.rows << " " << resultingMatrix.cols << std::endl;
    for (int i = 0; i < resultingMatrix.rows; i++)
        for (int j = 0; j < resultingMatrix.cols; j++){
            if(j==resultingMatrix.cols-1){
                std::cout << resultingMatrix.a[i][j] << std::endl;
            }
            else{
            std::cout << resultingMatrix.a[i][j] << " ";
            }
        }      
}

#endif /* DS_MATRIX_H */
