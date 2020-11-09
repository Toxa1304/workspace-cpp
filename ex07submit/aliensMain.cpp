#include <iostream>
#include "node.h"
#include <math.h>

Node* topNodeList[50];
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

// void treeIterator(Node* node, int current_level, int maxDepth){
//     if (node==NULL){
//         return;
//     }
//     if(current_level < maxDepth){
//         if (node->left == NULL){
//             node->left = new Node(0);
//         }
//         if(node->right == NULL){
//             node->right = new Node(0);
//         }
//     }
//     treeIterator(node->left, current_level+1, maxDepth);
//     treeIterator(node->right, current_level+1, maxDepth);
// }
// void fill_tree(Node* headNode){
//     if (headNode == NULL)  
//         return; 
//     treeIterator(headNode, 1, maxDepth(headNode));

    
    
    
// }
bool foundParent = false;
void insert_at(Node* node,int from, int value, char side){
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
            }
            node->left = new Node(value);
            return;
        }
        if(side == 'R'){
            if(node ->right !=NULL){
                print_error(5);
                numberOfNodes-=1;
                topNode -> numberOfNodes -=1;
            }
            node->right = new Node(value);
            return;
        }
    }
    else{
        insert_at(node -> left, from, value, side);
        insert_at(node -> right, from, value, side);

    }


}
int insertAt = 0;
void fill_array(Node* node, int* list){
    
     if(node == NULL){
        
        return;
        
    }
    
    fill_array(node -> left, list);
    //std::cout << node->elem << ' ' ;
    list[insertAt] = node -> elem;
    insertAt +=1;
    fill_array(node -> right,list);

}
bool firstOne=true;

bool firstOne2 = true;
int main(){

    char c;
    int from;
    int val;
    
    int arraySize;
    using namespace std;
    
    
    while(cin >>c){
        if (c == 'T'){
             if(firstOne==true){
                Node* top_Node = new Node(0);
                numberOfNodes = 0;
                top_Node->left = NULL;
                top_Node->right = NULL;
                numberOfNodes +=1;
                cin >> val;
                top_Node->elem = val;
                top_Node->topNode = true;
                topNodeList[numberOfTopNodes] = top_Node;
                numberOfTopNodes +=1;
                topNode = top_Node;
            }
            if (firstOne!=true){
                Node* top_Node = new Node(0);
                topNodeList[numberOfTopNodes]= top_Node;
                topNodeList[numberOfTopNodes-1]->numberOfNodes = numberOfNodes;
                numberOfTopNodes +=1;
                firstOne2=false;
                numberOfNodes = 0;
                top_Node->left = NULL;
                top_Node->right = NULL;
                numberOfNodes +=1;
                cin >> val;
                top_Node->elem = val;
                top_Node->topNode = true;
                topNode = top_Node;
                //std::cout << &top_Node << std::endl;
                
                //std::cout << "num of top nodes: " << numberOfTopNodes << std::endl;
            }
            


           
            
            
            

            firstOne = false;

            
        }
        if (c == 'L'){
            numberOfNodes +=1;
            topNode -> numberOfNodes +=1;
            cin >> from;
            cin >> val;
            insert_at(topNode, from, val, 'L');

        }
        if(c == 'R'){
            numberOfNodes +=1;
            topNode -> numberOfNodes +=1;
            cin >> from;
            cin >> val;
            insert_at(topNode, from, val, 'R');
        }
        if(c == '?'){
          
            insertAt = 0;    

            if(1){
                //topNodeList[numberOfTopNodes-1] = &topNode;
                //numberOfTopNodes+=1;
                topNodeList[numberOfTopNodes-1]->numberOfNodes = numberOfNodes;
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
                    //cout << "number of topNodes= " << arraySize << endl;
                    // for(int z=0; z<arraySize; z++){
                    //     cout<<arrayForOuptut[z]<< " ";
                    // }
                    for(int j= 0; j<arraySize; j++){
                        //cout<< "array number: "<<i << arrayForOuptut[j]<< " ";
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
        if (c=='F'){

            //print_tree(&topNode);
            //update_tree(&topNode);
           // print_tree(&topNode);

           //std::cout << "Node from list: " << topNodeList[1]->left->elem << std::endl;
           //fill_tree(&topNode);
           //print_tree(&topNode);
        }
    }

    return 1;

}
