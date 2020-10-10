
#include <string>

using namespace std;

// intent type
class CNode {
// circularly linked list node 

 int elem;
// linked list intent value
 CNode* next;
// next item in the list
 
 
 friend class CircleList;
// provide CircleList access
};

class CircleList {
// a circularly linked list
public:
 int size = 0;
 CircleList();
// constructor
 ~CircleList();
// destructor
 bool empty() const;
// is list empty?
 const int& front() const;
// intent at cursor
 const int& back() const;
// intent following cursor
 void advance();
// advance cursor
 void add(const int& e);
// add after cursor
 void remove();
// remove node after cursor

string to_str();
private:
 
 CNode* cursor;
// the cursor
};
