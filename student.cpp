#include <iostream>
using namespace std;
class Student{
  public:
  int age;
  double height;
  int compareTo(Student ss){
    if (age == ss.age && height == ss.height){
      return 0;
    }
    else if (age < ss.age){
      return -1;
    }
    else if (age > ss.age){
      return 1;
    }
    else if (height < ss.height){
      return -1;
    }
    else {
      return 1;
    }
  }
};
