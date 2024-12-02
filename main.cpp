#include <iostream>
#include "Student.h"
#include "Node.h"
#include <cstring> 

using namespace std;

void Add();
void Print();
void Delete();

int main() {
  Student* student = new Student;
  Node* node = new Node(student);
  Node* node2 = new Node(); 

  char input[7]; 
  
  cout << "Do you want to ADD, PRINT, or DELETE?" << endl;
  cin.getline(input, 7);

  if (strcasecmp(input, "ADD") == 0) {
    Add();
  } else if (strcasecmp(input, "PRINT") == 0) {
    Print();
  } else if (strcasecmp(input, "DELETE") == 0) {
    Delete();
  }
  
  return 0;
}

void Add() {
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
  

}


void Print() {


}

void Delete() {
  
}
