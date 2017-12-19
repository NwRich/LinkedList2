#include "Student.h"

using namespace std;

Student::Student(char* newfName, char* newlName, int newId, float newGpa) {
  fName = newfName;
  lName = newlName;
  id = newId;
  gpa = newGpa;
}
int Student::getId() {
  return id;
}
char* Student::getfName() {
  return fName;
}
char* Student::getlName() {
  return lName;
}
float Student::getGpa() {
  return gpa;
}
Student::~Student() {
  delete fName;
  delete lName;
}
