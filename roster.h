#include <iostream>
#include "student.h"
#include "degree.h"

// Define the maximum number of students in the roster
const int MAX_STUDENTS = 5; 

using namespace std;
class Roster {
private:
	int lastIndex;
	int size;
	Student** classRosterArray;

public:
	Roster();
	Roster(int size);
	~Roster();
	//Section E3a-e required functions
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram type);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	Student* findStudent(int Index);
};