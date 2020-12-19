#include <iostream>
#include "node.h"
#include <math.h>

Node* topNodeList[1000];
int numberOfTopNodes=0;
int numberOfNodes=0;
Node* topNode;

void print_error(int i){
    std::cout << "error" << i << std::endl;
}
int maxDepth(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  

bool foundParent = false;
bool inserted = false;
int whichTopNodeInserted;

void insert_at(Node* node,int from, int value, char side, int topNodeIndex){
    if(value == from){
        print_error(1);
        numberOfNodes-=1;
        topNode -> numberOfNodes -=1;
        return;
    }
    if(node == NULL){
        return;
    }
    if(node->elem == from){
        if(side == 'L'){
            if(node ->left !=NULL){
                print_error(4);
                numberOfNodes-=1;
                topNode -> numberOfNodes -=1;
                return;
            }
            node->left = new Node(value);
            inserted = true;
            whichTopNodeInserted = topNodeIndex;
            return;
        }
        if(side == 'R'){
            if(node ->right !=NULL){
                print_error(5);
                numberOfNodes-=1;
                topNode -> numberOfNodes -=1;
                return;
            }
            node->right = new Node(value);
            inserted = true;
            whichTopNodeInserted = topNodeIndex;
            return;
        }
    }
    else{
        insert_at(node -> left, from, value, side, topNodeIndex);
        insert_at(node -> right, from, value, side, topNodeIndex);
    }
}
int insertAt = 0;

void fill_array(Node* node, int* list){
    
     if(node == NULL){
        
        return;
        
    }
    fill_array(node -> left, list);
    list[insertAt] = node -> elem;
    insertAt +=1;
    fill_array(node -> right,list);

}
bool firstOne=true;

bool firstOne2 = true;
bool error6 = false;
int main(){

    char c;
    int from;
    int val;
    
    int arraySize;
    using namespace std;
    
    
    while(cin >>c){
        if (c == 'T'){
            cin >> val;
            if(firstOne==true){
                Node* top_Node = new Node(0);
                numberOfNodes = 0;
                top_Node->left = NULL;
                top_Node->right = NULL;
                numberOfNodes +=1;
                //cin >> val;
                top_Node->elem = val;
                top_Node->topNode = true;
                topNodeList[numberOfTopNodes] = top_Node;
                numberOfTopNodes +=1;
                topNode = top_Node;
            }
            if (firstOne!=true){
                for(int i = 0; i< numberOfTopNodes; i++){
                    if(val == topNodeList[i]->elem){
                        print_error(6);
                        error6=true;
                    }
                }
                if(error6==false){   
                    Node* top_Node = new Node(0);
                    topNodeList[numberOfTopNodes]= top_Node;
                    numberOfTopNodes +=1;
                    firstOne2=false;
                    numberOfNodes = 0;
                    top_Node->left = NULL;
                    top_Node->right = NULL;
                    numberOfNodes +=1;
                    
                    top_Node->elem = val;
                    top_Node->topNode = true;
                    topNode = top_Node;
                }
                error6=false;
            }
            firstOne = false;
        }
        if (c == 'L'){
            numberOfNodes +=1;
            cin >> from;
            cin >> val;
            for(int i = 0; i< numberOfTopNodes; i++){
                insert_at(topNodeList[i], from, val, 'L', i);
                if(inserted == true){
                    topNodeList[whichTopNodeInserted]->numberOfNodes +=1;
                    break;
                }
            }
            if(inserted == false){
                print_error(2);
            }
            inserted = false;


        }
        if(c == 'R'){
            numberOfNodes +=1;
            cin >> from;
            cin >> val;
            for(int i = 0; i< numberOfTopNodes; i++){
                insert_at(topNodeList[i], from, val, 'R', i);
                if(inserted == true){
                    topNodeList[whichTopNodeInserted]->numberOfNodes +=1;
                    break;
                }
            }   
            if(inserted == false){
                print_error(2);
            }
            inserted = false;
        }
        if(c == '?'){
            insertAt = 0;    
            cin >> val;
            bool breaker = false;
            for(int i=0; i<numberOfTopNodes; i++){
                if(breaker == true){
                        break;
                }
                int arraySize =topNodeList[i]->numberOfNodes;
                int arrayForOuptut[arraySize];
                insertAt = 0;
                fill_array(topNodeList[i], arrayForOuptut);
                for(int j= 0; j<arraySize; j++){
                    if(val == arrayForOuptut[j]){
                        if(j==0){
                            std::cout <<  "0 " <<arrayForOuptut[j+1]  <<std::endl; 
                        }
                        else if(j==arraySize-1){
                            std::cout << arrayForOuptut[j-1] << " 0" <<std::endl; 
                        }

                        else if (j==0 && j ==arraySize-1){
                            std::cout << "0 0" << std::endl;
                        }
                        else{
                            std::cout << arrayForOuptut[j-1] << " " << arrayForOuptut[j+1] << std::endl;
                        }
                        breaker =true;
                        break;
                    }
                    else if(j==arraySize-1 && i==numberOfTopNodes-1){
                        print_error(0);
                    }
                }
            }

        }
    }
    return 1;
}
