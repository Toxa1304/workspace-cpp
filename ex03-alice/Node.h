#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <fstream>
#include <algorithm> 
using namespace std;
namespace ds_course {
struct Node {
  public:
  int val;
  vector<int> children;
  bool isInList;
  void addChild(int value);
  Node(int value);
  void changeValue(int value);
  void reflect();
  void printPreorder();
};
}