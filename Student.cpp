#include <iostream>
#include "Student.h"
#include <cstring>

Student::Student() = default;

Student::Student(char firstName[], char lastName[], int id, float gpa) {
  cout << "Student Constructor" << endl;
  strcpy(this->firstName, firstName);
  strcpy(this->lastName, lastName);
  this->id = id;
  this->gpa = gpa;
}

int Student::getId() {
  return id;
}

float Student::getGpa() {
  return gpa;
}

char* Student::getFirstName() {
  char* toReturn;
  toReturn = firstName;
  return toReturn;
}

char* Student::getLastName() {
  char* toReturn;
  toReturn = lastName;
  return toReturn;
}

Student::~Student() {
  //Can only call delete on a pointer allocated with new[]?
}
