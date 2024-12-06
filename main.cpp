#include <iostream>
#include "Student.h"
#include "Node.h"
#include <cstring> 

using namespace std;

void Add(Node* &head, Node* curr);
void Print(Node* node);
void Delete();
void addNodes(Node* &head, Node* curr, Node* node);

int main() {
  Node* head = nullptr; //create the first (header) node in the list
  bool quit = false;

  char input[7]; 

  while (quit == false) {
    cout << "Do you want to ADD, PRINT, DELETE, or QUIT" << endl;
    //    cin.ignore();
    cin.getline(input, 7);

    if (strcasecmp(input, "ADD") == 0) {
      Add(head, head); //pass is head twice for current and head
    } else if (strcasecmp(input, "PRINT") == 0) {
      if (head != nullptr) {
        Print(head);
      } else {
        cout << "There are no students in the list" << endl;
      }
    } else if (strcasecmp(input, "DELETE") == 0) {
      Delete();
    } else if (strcasecmp(input, "QUIT") == 0) {
      quit = true;
    }
  }
  
  return 0;
}

void Add(Node* &head, Node* curr) {
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
  Node* node = new Node(student); //create a new node based on the student

  addNodes(head, curr, node); //Make sure the nodes will be sorted into the list correctly
}

//Go though all the nodes in the list using recursion
void Print(Node* node) {
  //test printing first:
  cout << node->getStudent()->getId() << endl;


  if (node->getNext() != nullptr) {
  Print(node->getNext());
    }
}

void Delete() {
  
}

//Sorts the list from lowest to highest student id.
void addNodes(Node* &head, Node* curr, Node* node) { //Used to sort the nodes
  //If there isn't a head node (no items in list) then add the first item and exit the function
  if (head == nullptr) {
    head = node;
    return;
  }

  //If there isn't a next item in the list then add the passed in node to the list and exit the function. (also checking in case this is the second item added to the list)
  if (curr->getNext() == nullptr) {
    cout << "Hey1" << endl;
    curr->setNext(node);
  }

  //If the passed in node is less than the head node. Swap their positions
  if (node->getStudent()->getId() < head->getStudent()->getId()) {
    cout << "Hey" << endl;
    Node* temp = head;
    head = node;
    head->setNext(temp); //!for some reasons when this happens an infinite recursion of nexts occurs
    return;
  }



  //If the next node is greater than the node passed in we want to swap their places in the list
 if (curr->getNext()->getStudent()->getId() > node->getStudent()->getId()) {
    node->setNext(curr->getNext()); //Then set the greater node (next node) after the passed in node
    curr->setNext(node); //Then the node after current will be set to the passed in node
    cout << "Checking if next node is greater than node passed in" << endl;
    Print(head);
    return; //we can then stop the recursion 
 }
  //Go through function again if there is still more list to go through (to fully sort it)
  addNodes(head, curr->getNext(), node);
}
