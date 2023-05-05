#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

extern string degreeProgramPrint[];
class Student{
private:    
    //D1 - encapsulation
    string studentId, firstName, lastName, emailAddress;
    int age;
    int *daysInCourse;
    DegreeProgram degreeProgram;

public:
    //constructors 1. (default with no perimeters, so you can make an instance of student without providing values)
    Student();

    //D2d constructor 2. (constructor must be provided with all values to instantiate a student)
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
    int daysInCourse3, DegreeProgram degreeProgram);
;

    //destructor - deallocate memory
    ~Student();

    //D2a. accessors
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    DegreeProgram getDegreeProgram();
    int* getDaysInCourse();

	//D2b - mutators
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDegreeProgram(DegreeProgram degreeProgram);
    void setDaysInCourse(int* daysInCourse);

    // Section D2e - print data
    void print();
};