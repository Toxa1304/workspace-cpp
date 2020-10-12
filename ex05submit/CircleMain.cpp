#include <stdio.h>
#include "CircleList.h"
#include <sstream>
#include <iostream>
#include <string.h>
class OutOfBoundsException
{
    private:
        string error_msg;
    public:
        OutOfBoundsException(const string& msg);
        ~OutOfBoundsException();
        string getMessage() const;
};
// thrown when an operation attempts to access data outside the valid range
OutOfBoundsException::OutOfBoundsException(const string& msg) {
    error_msg = msg;
    cerr << "OutOfBoundsException: " << endl;
}
OutOfBoundsException::~OutOfBoundsException() { delete this; }
string OutOfBoundsException::getMessage() const { return error_msg; }

//insert function
void DEL(CircleList &cL, int pos) 
{
    int listSize = cL.size;
    int retreatPos = listSize - pos - 1;
    int toAdvance = 0;
    if (pos < listSize) 
    {
        while (toAdvance != pos)
        {
            cL.advance();
            toAdvance++;
        } 
        cL.remove();
        int toAdvance = 0;
        while (toAdvance != retreatPos)
        {
            cL.advance();
            toAdvance++;
        }
    }
    else
    {
        throw OutOfBoundsException("The element at the provided position does not exist!");
    }
}

void INS(CircleList &cL, int pos, int val) 
{
    int listSize = cL.size;
    int toAdvance = 0;
    int retreatPos = listSize - pos + 1;
    
    if (pos <= listSize) 
    {
        while (toAdvance != pos)
        {
            cL.advance();
            toAdvance++;
        }
        cL.add(val);
        toAdvance = 0;
        while (toAdvance != retreatPos)
        {
            cL.advance();
            toAdvance++;
        }
    }
    else
    {
        throw OutOfBoundsException("The operation cannot be performed!");
    }
}


int main() {
    CircleList circularList;
    int N, initialIntegers, posInList, operationIndex, operationValue;
    string inputLine, operation;

    cin >> N;
    for (posInList = 0; posInList < N; posInList++)
    {
        cin >> initialIntegers;

        circularList.add(initialIntegers);
        circularList.advance();
    }
    while (getline(cin, inputLine))
    {
        istringstream sstr(inputLine); 
        sstr >> operation;
        if (operation == "INS")
        {
            sstr >> operationIndex >> operationValue;
            INS(circularList, operationIndex, operationValue);

        }
        else if (operation == "DEL")
        {
            sstr >> operationIndex;
            DEL(circularList, operationIndex);

        }
    }
    cout << circularList.to_str() << endl;
    return 0;    
}
