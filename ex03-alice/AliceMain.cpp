#include "Node.h"

//using namespace ds_course;
using namespace std;

vector<ds_course::Node> finalNodeList;
void recursiveFind(int child, vector <ds_course::Node> vectorOfNodes) {
    for (int i = 0; i < vectorOfNodes.size(); i++) {
        for (int j = 0; j < vectorOfNodes[i].children.size(); j++) {
            if (vectorOfNodes[i].val == child && vectorOfNodes[i].isInList == false) {
                vectorOfNodes[i].isInList = true;
                finalNodeList.push_back(vectorOfNodes[i]);
                for (int k = 0; k < vectorOfNodes[i].children.size(); k++) {
                    recursiveFind(vectorOfNodes[i].children[k], vectorOfNodes);
                }
            }
        }
    }
    
}
int checkIfHeadNode(int val, vector <ds_course::Node> vectorOfNodes){
  
  //1-true 0-false
  int foundNTimes = 0;
  for (int i=0; i < vectorOfNodes.size(); i++){
    
    
    for(int b=0; b < vectorOfNodes[i].children.size(); b++){
      
      if (val == vectorOfNodes[i].children[b]){
        return 0;
      }
    }
  }
  return 1;
}

int main(){

  //open input file

 // ifstream inFile;
  //inFile.open("example.txt");

  ifstream inFile;
  inFile.open("in.txt");
  
  string line;
  std::map < int, ds_course::Node > nodeMap;

  
  vector<ds_course::Node> vectorOfNodes;
  //vector<ds_course::Node> finalNodeList;
  
  while(getline(cin, line)){
    //get input each line
    istringstream treeline(line);
    int currentnode;
    int checker = 0;
    ds_course::Node bufferNode(0);
    while(treeline >> currentnode){
      //loop through line
      if (checker == 0){
        bufferNode.changeValue(currentnode);
        checker = 1;
      }
      else{

          bufferNode.addChild(currentnode);
        
        
      }

      //cout << currentnode <<endl;
    }
    //cout << "Line has ended" << endl;
    if(bufferNode.val!=0){
      vectorOfNodes.push_back(bufferNode);
    }
    //cout<<bufferNode.val<<endl;
    checker = 0;
  }
  //inFile.close();
  //cout << vectorOfNodes[0].children[0]<< endl;
  //ofstream outputFile;
 // outputFile.open("output.txt");


for (int i = 0; i < vectorOfNodes.size(); i++) {
        vectorOfNodes[i].reflect();
        if (checkIfHeadNode(vectorOfNodes[i].val, vectorOfNodes) == 1) {
            finalNodeList.push_back(vectorOfNodes[i]);
            //cout << "im here" << endl;
        }
    }

    for (int i = 0; i < finalNodeList[0].children.size(); i++) {
        recursiveFind(finalNodeList[0].children[i], vectorOfNodes);
        
    }
    

    for (int i = 0; i < finalNodeList.size(); i++) {
        finalNodeList[i].printPreorder();
    }
  cout << "0";


}



