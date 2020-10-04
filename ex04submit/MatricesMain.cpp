#include <iostream>
#include "Ratio.h"
#include "Matrix.h"
#include <string.h>
using namespace ds_course;
using namespace std;
int main() {
    // rational arithmetic 
    // It is not quite right: fractions not simplified
    
    
    char type[3];
    char type1[3];
    char operation[4];
    int row1, col1, row2, col2;
    
    //read from input
    cin >> type;
    cin >> row1 >> col1;
    if(strcmp(type, "MQ")==0){
        Matrix<Ratio> m1(row1,col1);
        cin >> m1;
        m1.type[0] = 'Q';
        cin >> type1 >> row2 >> col2;
        Matrix<Ratio> m2(row2,col2);
        cin >> m2;
        m2.type[0] = 'Q';
        cin >> operation;
        if(strcmp(operation, "ADD")==0){
            m1 + m2;
        }
        else if(strcmp(operation, "SUB")==0){
            m1 - m2;
        }
        else if(strcmp(operation, "MUL")==0){
            m1 * m2;
        }
        else{
            cout << "out_of_range";
            throw std::out_of_range("Invalid operation");
        }
    }
    if(strcmp(type, "MZ")==0){
        Matrix<int> m1(row1,col1);
        cin >> m1;
        m1.type[0] = 'Z';
        cin >> type1 >> row2 >> col2;
        Matrix<int> m2(row2,col2);
        cin >> m2;
        m2.type[0] = 'Z';
        cin >> operation;
        if(strcmp(operation, "ADD")==0){
            m1 + m2;
        }
        else if(strcmp(operation, "SUB")==0){
            m1 - m2;
        }
        else if(strcmp(operation, "MUL")==0){
            m1 * m2;
        }
        else{
            cout << "out_of_range";
            throw std::out_of_range("Invalid operation");
        }
    }
    if(strcmp(type, "MR")==0){
        Matrix<double> m1(row1,col1);
        cin >> m1;
        m1.type[0] = 'R';
        cin >> type1 >> row2 >> col2;
        Matrix<double> m2(row2,col2);
        cin >> m2;
        m2.type[0] = 'R';
        cin >> operation;
        if(strcmp(operation, "ADD")==0){
            m1 + m2;
        }
        else if(strcmp(operation, "SUB")==0){
            m1 - m2;
        }
        else if(strcmp(operation, "MUL")==0){
            m1 * m2;
        }
        else{
            cout << "out_of_range";
            throw std::out_of_range("Invalid operation");
        }
    }

    


}

