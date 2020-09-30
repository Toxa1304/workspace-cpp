#include "student.cpp"
#include "student.h"

int numberOfStudents {};

Student getMin (vector <Student> obj){
  Student minimumStudent = obj[0];
  
  if(numberOfStudents == 1){ return minimumStudent;}
    for (int i=1; i <=  numberOfStudents - 1; i++) {
      
      if(minimumStudent.compareTo(obj[i]) == -1){minimumStudent = obj[i];}
      
    }
  return minimumStudent;
}

Student getMax (vector <Student> obj){
  Student maximumStudent = obj[0];
  
  if(numberOfStudents == 1){ return maximumStudent;}
    for (int i=1; i <=  numberOfStudents - 1; i++) {
      
      if(maximumStudent.compareTo(obj[i]) == 1){maximumStudent = obj[i];}
      
    }
  return maximumStudent;
}

int main () {

  vector< Student > obj;
  string line;
 
  
    int lineCount;
    lineCount = 0;
    
    while ( getline (cin,line) )
    {
      lineCount+=1;
      //remember number of students
      if (lineCount == 1){
        stringstream intTicket(line);
        intTicket >> numberOfStudents;
      }
      else{
        string input(line); 
        vector<string> result; 
        boost::split(result, input, boost::is_any_of(" ")); 
  
          for (int i = 0; i < result.size(); i++) {
              Student studentTemp;
              if (i==0 | i%2==0){
                stringstream intTicket1(result[i]); 
                intTicket1 >> studentTemp.age;   
              }
              else{
                // stringstream intTicket2(result[i]); 
                // intTicket2 >> studentTemp.height;
                double stHeightTemp = stod(result[i]);
                studentTemp.height = stHeightTemp;
              
                obj.push_back(studentTemp);
                //cout << studentTemp.height << endl;
              }
              //cout << result[i] << endl;
          }
      }

    }

    Student minStud = getMin(obj);
    Student maxStud = getMax(obj);
    cout << minStud.age << " "<< minStud.height << endl;
    cout << maxStud.age << " " << maxStud.height << endl;
  return 0;
}
