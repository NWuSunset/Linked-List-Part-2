#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student {
public:
    Student(char firstName[], char lastName[], int id, float gpa);
    Student();
    ~Student();

    int getId() const;
    float getGpa() const;
    char* getFirstName();
    char* getLastName();

private:
    char firstName[20]{}; //Fields are initialized (with defaults {} ) just in case
    char lastName[20]{};
    int id{};
    float gpa{};
};

#endif
