/*Nicholas Rich 1/23/18
 *a program that uses a linked list to manage students
*/

#include "Node.h"
#include "Student.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
void addNode(Student* newStudent, Node* current);
Student* addStudent();
void print(Node* next);
void remove(Node* current, int id);
void average(Node* current, float amount, int total);
Node* head = NULL;
int main() {//main function
  bool working = true;//used to run the program
  char* input = new char[16];//used for the user input
  while (working == true) {//while the program is running
    cout << "the options are add, remove, list, average, and quit" << endl;//promt the user for an input
    cin >> input;//read the input
    cin.get();//clear the buffer
    if (strcmp(input, "add") == 0) {//if the input is add
      addNode(addStudent(), head);//call add passing in a new student and the head
    }
    if (strcmp(input, "list") == 0) {//if the input is list
      print(head);//print the list
    }
    if (strcmp(input, "remove") == 0) {//if the input is remove
      int id = 0;//used to get an input for the recursice function
      cout << "input a student id to remove" << endl;//promt the user for input
      cin >> id;//write to id
      remove(head, id);//call remove passing in head and id
    }
    if (strcmp(input, "average") == 0) {//if the input is average
      int amount = 0;//used to hold the amount of students
      int total = 0;//used to hold the total gpa
      average(head, amount, total);//call the average function
    }
    if (strcmp(input, "quit") == 0) {//if the input is quit
      working = false;//end the program
    }
  }
  return 0;
}  
void addNode(Student* newStudent, Node* current) {//add function
  Node* test = new Node(newStudent);//create the new node
  if (current == NULL) {//if this is the first node
    head = new Node(newStudent);//make head equal to the new node
  }
  else {
    if (current->getNext() != NULL) {//if you arent at the end of the list
      if (current->getNext()->getStudent()->getId() > test->getStudent()->getId()) {//if next > the new students id
	current = current->getNext();//go to the next node
	addNode(newStudent,current);//call the add node function again
	return;//end the function
      }
    }
    Node* holding = current->getNext();//used to hold the next node
    current->setNext(test);//set current to the new node
    test->setNext(holding);//set the new node next node
  }
}
void print (Node* next) {//the print function
  if (next == head) {//if the first node is the head
    cout << "list " << endl;//print out list
  }
  if (next != NULL) {//if your arent at the end of the list
    cout << next->getStudent()->getfName() << " ";//print out the first name
    cout << next->getStudent()->getlName() << " id: ";//print out the students last name
    cout << next->getStudent()->getId() << " gpa: ";//print out the students id
    cout << setprecision(3) << next->getStudent()->getGpa() << endl;//print out the students gpa
    print(next->getNext());//call print with the next node
  }
}
Student* addStudent() {//function to create new students
  char* fName = new char[64];//used to hold the first name
  char* lName = new char[64];//used to hold the last name
  int id = 0;//used to hold the students id
  float gpa = 0;//used to hold the students gpa
  cout << "What is the students first name?" << endl;//promt the user for an input
  cin >> fName;//wirte to fName
  cin.get();//clear the bufffer
  cout << "What is the student last name?" << endl;//promt the user for an input
  cin >> lName;//write to lNmae
  cin.get();//clear the buffer
  cout << "What is the student id?" << endl;//promt the user for an input
  cin >> id;//write to id
  cout << "What is the students gpa?" << endl;//promt the user for an input
  cin >> gpa;//write to gpa
  Student* n = new Student(fName, lName, id, gpa);//create the new student
}
void remove(Node* current,int id) {//remove function
  if (current->getStudent()->getId() != id && current != NULL && current != head) {//if current is not the id and not null and not the head
    remove(current->getNext(), id);//call remove again
  }
  if (current->getNext()->getStudent()->getId() == id) {//if nexts id is = to id
    current->setNext(current->getNext()->getNext());//set currents next to skip over
  }
  if (current->getStudent()->getId() == id) {//if currents id is = to id
    head = current->getNext();//head is equal to currents next
    delete(current);//delete current
    }
}
void average(Node* current, float amount, int total) {//average function
  if (current != NULL) {//if current is not equal to null
    amount = current->getStudent()->getGpa() + amount;//amount is equal to the students gpa plus amount
    total = total + 1;//total is equal to total plus 1
    average(current->getNext(), amount, total);//call the average function again
  }
  if (current == NULL) {//if its at the end of the list
    cout << setprecision(3) << amount/total << endl;//print out the average rounded to 2 decimal places
  }
}
