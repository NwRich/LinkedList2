#include "Node.h"
#include "Student.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
void addNode(Student* newStudent);
Student* addStudent();
void print(Node* next);
void remove(Node* current, int id);
void average(Node* current, float amount, int total);
Node* head = NULL;
int main() {
  bool working = true;
  char* input = new char[16];
  while (working == true) {
    cout << "the options are add, remove, list, average, and quit" << endl;
    cin >> input;
    cin.get();
    if (strcmp(input, "add") == 0) {
      addNode(addStudent());
    }
    if (strcmp(input, "list") == 0) {
      print(head);
    }
    if (strcmp(input, "remove") == 0) {
      int id = 0;
      cout << "input a student id to remove" << endl;
      cin >> id;
      remove(head, id);
    }
    if (strcmp(input, "average") == 0) {
      int amount = 0;
      int total = 0;
      average(head, amount, total);
    }
    if (strcmp(input, "quit") == 0) {
      working = false;
    }
  }
}  
void addNode(Student* newStudent) {
  Node* current = head;
  if (current == NULL) {
    head = new Node(newStudent);
  }
  else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    Node* test = new Node(newStudent);
    current->setNext(test);
  }
}
void print (Node* next) {
  if (next == head) {
    cout << "list ";
  }
  if (next != NULL) {
    cout << next->getStudent()->getfName() << " ";
    cout << next->getStudent()->getlName() << " id: ";
    cout << next->getStudent()->getId() << " gpa: ";
    cout << next->getStudent()->getGpa() << endl;
    print(next->getNext());
  }
}
Student* addStudent() {
  char* fName = new char[64];
  char* lName = new char[64];
  int id = 0;
  float gpa = 0;
  cout << "What is the students first name?" << endl;
  cin >> fName;
  cin.get();
  cout << "What is the student last name?" << endl;
  cin >> lName;
  cin.get();
  cout << "What is the student id?" << endl;
  cin >> id;
  cout << "What is the students gpa?" << endl;
  cin >> gpa;
  Student* n = new Student(fName, lName, id, gpa);
}
void remove(Node* current,int id) {
  if (current->getStudent()->getId() != id && current != NULL && current != head) {
    remove(current->getNext(), id);
  }
  if (current->getNext()->getStudent()->getId() == id) {
    current->setNext(current->getNext()->getNext());
  }
  if (current->getStudent()->getId() == id) {
    head = current->getNext();
    delete(current);
    }
}
void average(Node* current, float amount, int total) {
  if (current != NULL) {
    amount = current->getStudent()->getGpa() + amount;
    total = total + 1;
    average(current->getNext(), amount, total);
  }
  if (current == NULL) {
    cout << setprecision(3) << amount/total << endl;
  }
}
# LinkedList2
