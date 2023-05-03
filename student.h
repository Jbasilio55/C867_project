#include <iostream>
#include "degree.h"

using namespace std;

class Student{
private:    
    //D1 - encapsulation (default modifier is private)
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int *daysInCourse;
    string degreeProgram;
    
public:
    //constructors 1. (default with no perimeters, so you can make an instance of student without providing values)
    Student();

    //D2d constructor 2. (constructor must be provided with all values to instantiate a student)
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int dc1, 
    int dc2, int dc3, DegreeProgram program);

    //destructor - deallocate memory
    ~Student();

    //D2a. accessors
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();

	//D2b - mutators
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int* daysInCourse);

    // Section D2e - print data
    void print();
};