#include "Node.h"

Node::Node() = default; 

Node::Node(Student* student) {
  this->student = student;
}

Node* Node::getNext() {
  return next; 
}

Student* Node::getStudent() {
  return student; //returns the student pointer
}

void Node::setNext(Node* next) {
  this->next = next; //set the 'next' node in the node class to the passed in node
}

Node::~Node() {
  delete next;
  delete student; //are we supposed to remove the student?
}
