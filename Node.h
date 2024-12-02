#pragma once
#ifndef NODE_H
#define NODE_H


#include "Student.h"


class Node {
 public:
  Node(Student*); //Constructor that takes a Student pointer. Sets 'student' to the passed in pointer
  ~Node(); //Destructor. Deletes 'student'

  Node(); //default constructor 
  Node* getNext(); //get next Node pointer. returns 'next'
  Student* getStudent(); //get student pointer. returns 'student'
  void setNext(Node*); //set the next pointer to the corresponding node pointer. 'next' is set to the passed in pointer

 private:
  Student* student; // 'student'
  Node* next; // 'next'
};

#endif
