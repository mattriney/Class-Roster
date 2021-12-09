#pragma once

#include <string>
#include "student.h"

//Code is much more readable without "std:: prefix" everywhere
using namespace std;

/*
A.  Modify the “studentData Table” to include your personal information as the last item.
*/
const string studentData[5] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Matthew,Riney,mriney3@wgu.edu,34,17,10,20,SOFTWARE"
};

/*
E.  Create a Roster class (roster.cpp) by doing the following:

1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”

2.  Create a student object for each student in the data table and populate classRosterArray.

a.  Parse each set of data identified in the “studentData Table.”

b.  Add each student object to classRosterArray.

3.  Define the following functions:

a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.

b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.

c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.

d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.

e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
*/
class Roster {

public:

    Roster();

    ~Roster();

    Student** classRosterArray;

    void addStudent(int index, string a, string b, string c, string d, string e, int f, int g, int h, DegreeProgram x);

    void removeStudent(string stID);

    void parseArray(int rosterIndex);

    void printAll();

    void printAverageDaysInCourse(string stID);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeprogram);

private:
    void printDegreeString(int dp);
};
