#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include "roster.h"

#define ARRAY_LENGTH 5

using namespace std;

int main()
{
    Roster classRoster(10);
    DegreeProgram degreeProgram;
    
    // Student data information
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jorge,Basilio,jbasi12@wgu.edu,33,20,30,40,SOFTWARE"
    };

    // Loop through each string in studentData
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        stringstream ss(studentData[i]);
        vector<string> resultVector;

        while (ss.good()) {
            string subString;
            getline(ss, subString, ',');
            resultVector.push_back(subString);
        }

        // Determine the degree program of the student
        DegreeProgram degreeProgram = SECURITY;

        if (resultVector[8] == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }
        if (resultVector[8] == "NETWORK") {
            degreeProgram = NETWORK;
        }

        // Check if the student data is valid
        bool invalidData = false;
        for (int j = 4; j <= 7; j++) {
            for (char c : resultVector[j]) {
                if (!isdigit(c)) {
                    invalidData = true;
                    break;
                }
            }
            if (invalidData) {
                cout << "Error: Invalid data for student " << resultVector[0] << ", skipping." << endl;
                break;
            }
        }
        // If the student data is valid, add the student to the roster
        if (!invalidData) {
            classRoster.add(resultVector[0], resultVector[1], resultVector[2], resultVector[3],
                stoi(resultVector[4]), stoi(resultVector[5]), stoi(resultVector[6]), stoi(resultVector[7]), degreeProgram);
        }
    }
    
    
    cout << "\n";
    cout << "Course: Scripting and Programming Applications (C867)" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "Student ID: 011149553" << endl;
    cout << "Name: Jorge Basilio" << endl << endl;

    //output the prompts to the consol. 1-6
    cout << "1. print roster: " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "2. print invalid address: " << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "3. print avg days in course: " << endl;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        string tempString = "A" + to_string(i + 1);
        classRoster.printAverageDaysInCourse(tempString);
    }
    cout << endl;

    cout << "4. print student with degree of software: " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "5. remove student ID A3: " << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "6. Remove student ID A3 again: " << endl;
    classRoster.remove("A3");

    return 0;
}