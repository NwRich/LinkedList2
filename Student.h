#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
class Student {
 public:
  Student(char*, char*,int, float);
  int getId();
  char* getfName();
  char* getlName();
  float getGpa();
  ~Student();
 private:
  int id;
  char* fName;
  char* lName;
  float gpa;
};
#endif
