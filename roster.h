#include <iostream>
#include "student.h"

using namespace std;

class Roster {
private:
	int lastIndex;
	int size;
	Student *classRosterArray;

public:
	Roster();
	~Roster();
	//Section E3a-e required functions
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram type);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	Student findStudent(int Index);
};