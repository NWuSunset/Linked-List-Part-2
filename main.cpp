#include <iostream>
#include "Student.h"
#include "Node.h"
#include <cstring> 

using namespace std;

void Add(Node* &head, Node* curr);
void Print(Node* node);
void Delete(Node* node);
void deleteNodes(Node* node, int id);
void Average(Node* node, int &num, float &total);
void addNodes(Node* &head, Node* curr, Node* node);

int main() {
  Node* head = nullptr; //create the first (header) node in the list
  bool quit = false;

  int num = 1;
  float total = 0;

  char input[8];

  while (quit == false) {
    cout << "Do you want to ADD, PRINT, DELETE, AVERAGE (Averages student gpas), or QUIT" << endl;
    //    cin.ignore();
    cin.getline(input, 8);

    if (strcasecmp(input, "ADD") == 0) {
      Add(head, head); //pass is head twice for current and head
    } else if (strcasecmp(input, "PRINT") == 0) {
      if (head != nullptr) {
        Print(head);
      } else {
        cout << "There are no students in the list" << endl;
      }
    } else if (strcasecmp(input, "DELETE") == 0) {
      Delete(head);
    } else if (strcasecmp(input, "AVERAGE") == 0) {
      if (head != nullptr) {
	      Average(head, num, total);
      } else {
	cout << "There are no students in the list" << endl;
      }
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
  cout.setf(ios::showpoint); //show zeros in the decimal places
  cout.precision(3); //to 2 decimal places (for the gpa)
  
  //Print out things for the student
  cout << node->getStudent()->getFirstName() << ", "
       << node->getStudent()->getLastName() << ", "
       << node->getStudent()->getId() << ", "
       << node->getStudent()->getGpa() << endl;

  if (node->getNext() != nullptr) {
  Print(node->getNext());
    }
}

void Delete(Node* node) {
  char id;
  if (node == nullptr) {
    cout << "Empty List!" << endl;
    return;
  }
  cout << "Enter the student id you wish to delete: " << endl;
  cin >> id;
  cin.ignore();

  deleteNodes(node, id); 
}

void deleteNodes(Node* curr, int id) {
  //Check if it's the only node in the list...

  //Find that id in the list
  if (curr->getNext()->getStudent()->getId() == input) {
    Node* temp = curr->getNext(); //save the node to delete
    curr->setNext(curr->getNext()->getNext()); //set the next node to the one after the node we are removing
    
    //delete the node from the linked list
    delete temp;

    
  } else if (curr->getNext() != nullptr) { //if a next node exists...
    deleteNodes(curr->getnext()); //Try the next node
  } else {
    cout << "The id doesn't exit in the list" << endl;
  }
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
    if (node->getStudent()->getId() >= curr->getStudent()->getId()) { //If the passed in node would still make the list be in order
      curr->setNext(node); 
      return; //exit because we don't have to sort the list
    }
    curr->setNext(node);
  }

  //If the passed in node is less than the head node. Swap their positions
  if (node->getStudent()->getId() < head->getStudent()->getId()) {
    //Swap the head and node positions in the list
    head->setNext(node->getNext()); //head now has node's next
    node->setNext(head); //and now head is nodes's next. 
    head = node; //change the header pointer to node (making node the new head)
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
  //This will occur for 3 or more nodes in the list
  addNodes(head, curr->getNext(), node);
}

//Prints out the average gpa of all students
void Average(Node* node, int &num, float &total) {
  total += node->getStudent()->getGpa(); //add gpa to the average

  if (node->getNext() != nullptr) {
    num++; //number of things in the list increment
    Average(node->getNext(), num, total);
  } else { //if the end of the list is hit
    float average = 0;
    average = (total/num);
    cout << "GPA average: " << average << endl;
  }
}
