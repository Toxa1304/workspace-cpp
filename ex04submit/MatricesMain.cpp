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
    char operation[3];
    int row1, col1, row2, col2;
    
    //read from input
    cin >> type;
    cin >> row1 >> col1;
    Matrix<Ratio> m1(row1,col1);
    
    cin >> m1;
    cin >> type1 >> row2 >> col2;
    Matrix<Ratio> m2(row2,col2);
    cin >> m2;
    cin >> operation;
    cout << "type is: " << type << endl;
    cout << "type1 is: " << type1<< endl;
    if (strcmp(type, "MQ")== 0){
        cout<< "IM HERE"<<endl;
        if(strcmp(operation, "ADD")==0){
            m1 + m2;
            cout << "SUCCESS" << endl;
        }
    }

    cout<< "THE ROW and COLUMN ARE: " << row1 << " " << col1  << " " << type1 << " "<< operation << endl;
    cout << "(m1 == m2) is " << ((m1 == m2)? "true" : "false" ) << endl;
    cout << "m1.a[1][1] = " << m1.a[1][1] << endl;
}

