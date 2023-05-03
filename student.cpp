#include <iostream>
#include "student.h"

using namespace std;

Student::Student(){
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    this->daysInCourse = new int[3];
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int dc1, int dc2, int dc3, DegreeProgram program){
    this->setStudentId(studentId);
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setEmailAddress(emailAddress);
    this->setAge(age);

    this->daysInCourse = new int[3];
    daysInCourse[0] = dc1;
    daysInCourse[1] = dc2;
    daysInCourse[2] = dc3;
}

Student::~Student(){}

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
void Student::setDaysInCourse(int* dc){
    daysInCourse[0] = dc[0];
	daysInCourse[1] = dc[1];
	daysInCourse[2] = dc[2];
}

void Student::print(){
    int* pdaysInCourse = getDaysInCourse();
	string dPStr = "Software";
	if (getDegreeProgram() == DegreeProgram::NETWORK) dPStr = "Network";
	if (getDegreeProgram() == DegreeProgram::SECURITY) dPStr = "Security";
	cout << "Student ID: " << getStudentId()
		<< "First Name: " << getFirstName()
		<< "\t Last Name: " << getLastName()
		<< "\t Student Age: " << getAge();
	cout << "\t Days In Course: {" << pdaysInCourse[0] << ", " << pdaysInCourse[1] << ", " << pdaysInCourse[2] << "}";
	cout << "\t Degree Program: " << dPStr << "." << endl;
}