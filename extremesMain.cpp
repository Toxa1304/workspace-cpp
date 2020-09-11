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
  cout << std::setprecision(10);
  //Student obj[3];
  vector< Student > obj;
  string line;
  ifstream myfile ("example.txt");


  if (myfile.is_open()){
    int lineCount;
    lineCount = 0;
    
    while ( getline (myfile,line) )
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
  }
  else cout << "Unable to open file";
  myfile.close();
    //cout << &obj[0].age << endl;
    cout << numberOfStudents << endl;
    for (int i =0; i <=  numberOfStudents - 1; i++) {
      //cout << obj[i].height <<endl;
    }
    Student minStud = getMin(obj);
    Student maxStud = getMax(obj);
    cout << minStud.height << endl;
    cout << maxStud.height << endl;
    
     ofstream MyFile("output.txt");

  // Write to the file
  MyFile << minStud.age;
  MyFile << " " << std::fixed << std::setprecision(5) << minStud.height << endl;
  MyFile << maxStud.age;
  MyFile << " " << std::fixed << std::setprecision(5) << maxStud.height << endl;
  // Close the file
  MyFile.close();
  return 0;
}