#ifndef GUARD
#define GUARD
#include "Student.h"
#include <iostream>

using namespace std;

class Node{
 public:
  Node(Student*);
  ~Node();
  Node* getNext();
  void setNext(Node*);
  Student* getStudent();

 private:
  Node* next;
  Student* student;
};

#endif
