#include "Node.h"

using namespace std;
using namespace ds_course;

Node::Node(int vv){
  this->val = vv;
  vector<int> children;
  bool isInList = false;
}

void Node::changeValue(int value){
  this->val = value;
}
void Node::addChild(int value){
  children.push_back(value);
 // cout << children[0] << endl;
  //cout << "value is "<< children[1].val << endl;
   
}
void Node::reflect(){
  std::reverse(children.begin(), children.end());
}
void Node::printPreorder()
{
    cout << val << " ";
    for (auto &element : children)
        cout << element << ' ';
    cout << endl;
}

/*
struct Node {
  private:
  int val;
  vector<Node *> chilren;
  public:
  Node(int vv);
  void addChild(Node nn);
  void reflect();
  int getVal();
  vector<int> getChildren();


};
*/