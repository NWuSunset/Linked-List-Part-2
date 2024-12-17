#include "Node.h"
#include "Student.h"

//constuctor
Node::Node(Student* student) : student(student), node(nullptr) {}

//destructor
Node::~Node() {
  delete student;
}

//retursn pointer to next node
Node* Node::getNext() {
  return node;
}

//get pointer to student obj
Student* Node::getStudent() {
  return student;
}

//set pointer to next node
void Node::setNext(Node* nextnode) {
  node = nextnode;
}
