#include <iostream>
#include "student.h"

using namespace std;

// Create an array of degree program strings for printing
string degreeProgramPrint[] = {"SECURITY","NETWORK","SOFTWARE"};

// Default constructor
Student::Student(){
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysInCourse = new int[3];
    this->degreeProgram = SOFTWARE;
}

// Constructor with arguments
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->degreeProgram = degreeProgram;

    this->daysInCourse = new int[3];
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}

Student::~Student(){
    delete[] daysInCourse;
}

string Student::getStudentId(){
    return studentId;
}

string Student::getFirstName(){
    return firstName;
}

string Student::getLastName(){
    return lastName;
}

string Student::getEmailAddress(){
    return emailAddress;
}

int Student::getAge(){
    return age;
}

int* Student::getDaysInCourse(){
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}

void Student::setStudentId(string studentId){
    this->studentId = studentId;
}

void Student::setFirstName(string firstName){
    this->firstName = firstName;
}

void Student::setLastName(string lastName){
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress){
    this->emailAddress = emailAddress;
}

void Student::setAge(int age){
    this->age = age;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram){
    this->degreeProgram = degreeProgram;
}

void Student::setDaysInCourse(int daysInCourse[]){
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
}

void Student::print(){
     // Get the days in course and degree program for the student
    int* pdaysInCourse = getDaysInCourse();
    string dPStr = "SOFTWARE";
    if (getDegreeProgram() == NETWORK) {
        dPStr = "NETWORK";
    }
    else if (getDegreeProgram() == SECURITY) {
        dPStr = "SECURITY";
    }
    
    // Print the student's information
    cout<< getStudentId() << "\t" 
        << getFirstName() << "\t" 
        << getLastName() << "\t" 
        << getEmailAddress() << "\t" 
        << getAge() << "\t" << pdaysInCourse[0] 
        << "\t" << pdaysInCourse[1] << "\t" << pdaysInCourse[2] << "\t" << degreeProgramPrint[degreeProgram] << endl;
}