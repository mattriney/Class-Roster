#include <iostream>
#include <string>

#include "roster.h"

//Code is much more readable without "std:: prefix" everywhere
using namespace std;

int main() 

{

    //F - 1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.

    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Language: C++" << endl;
    cout << "By: Matthew Riney" << endl;
    cout << "Student ID: 001383787";
    cout << endl;
    cout << "\n----------------------------------------------";
    cout << endl << endl;

    //F - 2.  Create an instance of the Roster class called classRoster.
    Roster* classRoster = new Roster();

    //F - 3.  Add each student to classRoster.
    for (int i = 0; i <= 5; i++) 
    {
        classRoster->parseArray(i); 
    }

    //F - 4.  Convert the following pseudo code to complete the rest of the  main() function:
    cout << "List of all students: ";
    cout << endl;
    classRoster->printAll();
    classRoster->printInvalidEmails();

    cout << "Average days in course for each student:" << endl;

    for (int i = 0; i < 5; i++) 
    {
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getID());
    }

    //this prints out students in each degree program
    cout << endl;
    classRoster->printByDegreeProgram(SECURITY);

    cout << endl;
    classRoster->printByDegreeProgram(NETWORK);

    cout << endl;
    classRoster->printByDegreeProgram(SOFTWARE);

    //this removes student A3 from the roster

    cout << endl;
    classRoster->removeStudent("A3");


    //this prints all students
    cout << endl;
    cout << "Printing all students:\n";
    classRoster->printAll();
    classRoster->removeStudent("A3");

    return 0;
}