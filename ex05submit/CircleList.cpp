#include "CircleList.h"
#include <iostream>
CircleList::CircleList()
// constructor
 : cursor(NULL) {}
 
CircleList::~CircleList()
// destructor
 { while (!empty()) remove(); }

 bool CircleList::empty() const
// is list empty?
 { return cursor == NULL; }
 
const int& CircleList::back() const
// element at cursor
 { return cursor->elem; }
 
const int& CircleList::front() const
// element following cursor
 { return cursor->next->elem; }
 
void CircleList::advance()
// advance cursor
 { cursor = cursor->next; }

 void CircleList::add (const int& e) {
// add after cursor
 CNode* v = new CNode;
// create a new node
 v-> elem = e;
 size +=1;
 
 if (cursor == NULL) {
// list is empty?
  v-> next = v; 
// v points to itself
  cursor = v;
// cursor points to v
 }
 
 else {
// list is nonempty?
  v->next = cursor->next;
// link in v after cursor
  cursor->next = v;
 
 }
 
}

void CircleList::remove() {
 size -=1;
// remove node after cursor
 CNode* old = cursor->next;
// the node being removed
 if (old == cursor)
// removing the only node?
  cursor = NULL;
// list is now empty
 else
 
  cursor->next = old->next;
// link out the old node
 delete old;
// delete the old node
}

string CircleList::to_str()
{
    string result;
    for (int i = 0; i < size; i++)
    {
        advance();
        result.append(to_string(back()));
        if (i < size - 1)
        {
            result.append(" ");

        }
    }
    return result;
}

