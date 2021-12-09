#pragma once

#include "degree.h"

//Code is much more readable without "std" everywhere
using namespace std;

class Student {



private:
    /*
    D.  For the Student class, do the following:

1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:

•  student ID

•  first name

•   last name

•  email address

•  age

•  array of number of days to complete each course

•  degree program
    */

    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    string age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    //student constructor
    Student();

    /*
     D2 - A.
     a.  an accessor (i.e., getter) for each instance variable from part D1
     */
    string getID();
    string getFName();
    string getLName();
    string getEmailAdd();
    string getAge();
    int getDays(int atArray);
    DegreeProgram getDegreeProgram();

    /*
     D2 - B.
     b.  a mutator (i.e., setter) for each instance variable from part D1
     */
    void setID(string studentID);
    void setFName(string firstName);
    void setLName(string lastName);
    void setEmailAdd(string emailAddress);
    void setAge(string age);
    void setDays(int num0, int num1, int num2);
    void setDegreeProgram(DegreeProgram degree);

    //others
    void print(int thing);

};