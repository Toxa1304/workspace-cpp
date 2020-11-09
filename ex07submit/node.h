#include <iostream>


class Node {

public:
 int elem;
 int numberOfNodes =1;
 Node* theTopNode;
 Node* left;
 Node* right;
 bool topNode = false;
 Node(int value){
     this -> elem = value;
     left = right = NULL;
 }
 
 
};