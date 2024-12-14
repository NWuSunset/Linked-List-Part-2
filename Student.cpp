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

int Student::getId() const {
    return id;
}

float Student::getGpa() const {
    return gpa;
}

char* Student::getFirstName() {
    char* toReturn = firstName;
    return toReturn;
}

char* Student::getLastName() {
    char* toReturn = lastName;
    return toReturn;
}

Student::~Student() = default;
