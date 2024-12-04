#include <iostream>
#include "Student.h"
#include "Node.h"
#include <cstring> 

using namespace std;

void Add(Node* &head);
void Print();
void Delete();
void addNodes(Node* &node)

int main() {
  Node* head = new Node; //create the first (header) node in the list
  
  char input[7]; 
  
  cout << "Do you want to ADD, PRINT, or DELETE?" << endl;
  cin.getline(input, 7);

  if (strcasecmp(input, "ADD") == 0) {
    Add(head);
  } else if (strcasecmp(input, "PRINT") == 0) {
    Print();
  } else if (strcasecmp(input, "DELETE") == 0) {
    Delete();
  }
  
  return 0;
}

void Add(Node* &head) {
  //individual variables for clarity
  char firstName[20];
  char lastName[20];
  int id;
  int gpa;
 
  cout << "First Name: " << endl;
  cin.getline(firstName, 20);
  cout << "Last Name: " << endl;
  cin.getline(lastName, 20);
  cout << "id: " << endl;
  cin >> id;
  cout << "gpa: " << endl;
  cin >> gpa;
  cin.ignore(); 

  Student* student = new Student(firstName, lastName, id, gpa); //Create a new student with the information
    
  //Sort by id number?
  sortNodes(head, student);
}


void Print() {


}

void Delete() {
  
}

//First node to be passed in will be the head node
void addNodes(Node* &node, Student* student) { //Used to sort the nodes
  if (node == nullptr) { //if node is null add the new node to it
    node = new Node(student);
    return;
  } 

  if (node->getNext() == nullptr) { //check if next node is null
    node->setNext(new Node(student));

    
    //If the student that would be getting passed into the node has a id less than the next student in the nodeList
    if (student->getId() < node->getStudent()->getId()) {
      //Swap the node order
      node->setNext(node); //set the next node to this node
      node = new Node(student); //now set this node to the node that would be created
    }
  } 




  /*
  Node* temp = node->getNext(); //save the next node pointer

  //if this id is greater (we will move it up in the list by swapping the two nodes)
  if (node->getStudent()->getId() > node->getNext()->getStudent()->getId() ) {
    node->setNext(node); //set the next node to this node
    node = temp; //set this node to the original nextNode

    //Call the function again to sort the next nodes in the list
    sortNodes(node->getNext());
    } */
}
