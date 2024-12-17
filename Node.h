#ifndef NODE_H
#define NODE_H

#include "Student.h"

//Node header file.
//Created by Tai Wong on December 9th

class Node {
protected:
  Student* student;
  Node* node;
public:
  Node(Student* student); //constructor
  Node* getNext();
  Student* getStudent();
  void setNext(Node* nextnode);
  ~Node(); //destructor
};

#endif
