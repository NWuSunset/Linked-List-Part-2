#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {
 public:
  Student(char firstName[], char lastName[], int id, float gpa);
  Student();

  int getId();
  float getGpa();
  
private:
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
};

#endif
