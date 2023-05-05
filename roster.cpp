#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

// Constructors
Roster::Roster() {
    this->lastIndex = -1;
    this->size = 0;
    this->classRosterArray = nullptr;
}

Roster::Roster(int size) {
    this->lastIndex = -1;
    this->size = size;
    // Create a new array of Student pointers with the specified size
    this->classRosterArray = new Student*[size];
    // Initialize each element of the array to null
    for (int i = 0; i < size; i++) {
        classRosterArray[i] = nullptr;
    }
}

// Destructor
Roster::~Roster() {
    // Loop through the roster array and delete each Student object
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
    }
    // Delete the roster array itself
    delete[] classRosterArray;
}

// Add a student to the roster
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    // Check if the roster is full
    if (lastIndex < MAX_STUDENTS) {
        // If there's room, increment the index and add the new student to the roster
        lastIndex++;
        classRosterArray[lastIndex] = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
        cout << "Student added successfully." << endl;
    }
    else {
        // If the roster is full, output an error message
        cout << "Error: Roster is full, cannot add student." << endl;
    }
}

void Roster::remove(string studentId) {
    bool found = false;
    // Loop through the roster array to find the student with the specified ID
    for (int i = 0; i < lastIndex; i++) {
        // If the student is found, remove them from the roster
        if (classRosterArray[i]->getStudentId() == studentId) {
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex - 1];
            classRosterArray[lastIndex - 1] = nullptr;
            lastIndex--;
            cout << "Student removed successfully." << endl;
            break;
        }
    }
    // If the student is not found, output an error message
    if (!found) {
        cout << "Error: Student with ID " << studentId << " not found." << endl;
    }
}

void Roster::printAll() {
    // Loop through the roster array
    for (int i = 0; i < size; i++) {
        // If the current element is not null, call the print() method for that student
        if (classRosterArray[i]) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;
    // Loop through the roster array to find the student with the specified ID
    for (int i = 0; i < size; i++) {
        // If the student is found, calculate their average days in the course and output it
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
            found = true;
            int* days = classRosterArray[i]->getDaysInCourse();
            double avg = (double)(days[0] + days[1] + days[2]) / 3.0;
            cout << "Student ID: " << studentID << " - Average days in course: " << avg << endl;
            break;
        }
    }
    // If the student is not found, output an error message
    if (!found) {
        cout << "Student with ID " << studentID << " not found." << endl;
    }
}

void Roster::printInvalidEmails() {
    bool invalidEmailFound = false;
    // Loop through the roster array to check for invalid email addresses
    for (int i = 0; i <= lastIndex; i++) {
        // If the current element is not null, check if the email address is invalid
        if (classRosterArray[i] != nullptr) {
            string email = classRosterArray[i]->getEmailAddress();
            if (email.find("@") == string::npos || email.find(".") == string::npos) {
                invalidEmailFound = true;
                cout << email << " is an invalid email address." << endl;
            }
        }
    }
    // If no invalid email addresses are found, output a message indicating that all email addresses are valid
    if (!invalidEmailFound) {
        cout << "All email addresses are valid." << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    bool found = false;
    string degreeString = degreeProgramPrint[degreeProgram];
    // Loop through the roster array to find students with the specified degree program
    for (int i = 0; i <= lastIndex; i++) {
        // If a student with the specified degree program is found, output their information
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            found = true;
            cout << "Printing students by degree program: " << degreeString << endl;
            classRosterArray[i]->print();
        }
    }
    // If no students with the specified degree program are found, output an error message
    if (!found) {
        cout << "No students found with degree program " << degreeString << endl;
    }
}

Student* Roster::findStudent(int index) {
    return classRosterArray[index];
}