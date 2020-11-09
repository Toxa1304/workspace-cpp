#include <iostream>


class Node {

public:
 int elem;
 int numberOfNodes;
 Node* theTopNode;
 Node* left;
 Node* right;
 bool topNode = false;
 Node(int value){
     this -> elem = value;
     left = right = NULL;
 }
 
 
};