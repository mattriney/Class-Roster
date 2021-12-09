#pragma once

#include <string>
#include <iostream>
#include "student.h"

//Code is much more readable without "std:: prefix" everywhere
using namespace std;

/*/D - 2.
Create each of the following functions in the Student class:

a.  an accessor (i.e., getter) for each instance variable from part D1

b.  a mutator (i.e., setter) for each instance variable from part D1

c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.

d.  constructor using all of the input parameters provided in the table

e.  print() to print specific student data
*/
Student::Student() 

{
    //Set to a value which is not null
    this->studentID = ""; 
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = "";

    for (int i = 0; i < 3; i++)
    {
        //this sets the daysInCourse
        this->daysInCourse[i] = 0;
    }
};

//D - 2.
//a.  an accessor (i.e., getter) for each instance variable from part D1

string Student::getID() 
{ 
    return studentID; 
}
string Student::getFName() 
{
    return firstName; 
}
string Student::getLName() 
{
    return lastName; 
}
string Student::getEmailAdd() 
{
    return emailAddress; 
}
string Student::getAge() 
{
    return age; 
}
int Student::getDays(int atArray) 
{
    return daysInCourse[atArray]; 
}
DegreeProgram Student::getDegreeProgram() 
{
    return degreeProgram; 
}

//D - 2
// b.  a mutator (i.e., setter) for each instance variable from part D1

void Student::setID(string studentID) 
{
    this->studentID = studentID; 
}
void Student::setFName(string firstName) 
{
    this->firstName = firstName; 
}
void Student::setLName(string lastName) 
{
    this->lastName = lastName; 
}
void Student::setEmailAdd(string emailAddress)
{
    this->emailAddress = emailAddress; 
}
void Student::setAge(string age) 
{
    this->age = age; 
}

//setDays takes in a parameter for each number of days var and sets them all at once
void Student::setDays(int num0, int num1, int num2) 
{
    this->daysInCourse[0] = num0; this->daysInCourse[1] = num1; this->daysInCourse[2] = num2; 
}

//enter as enum, not int
void Student::setDegreeProgram(DegreeProgram degree) 
{
    this->degreeProgram = degree; 
}

//takes an int value for any var of student class and outputs the variable
void Student::print(int thing) 
{

    //switch statement which prints tthing 0-8 out of the array of values
    switch (thing) 
    {
    case 0:
        cout << studentID;
        break;
    case 1:
        cout << firstName;
        break;
    case 2:
        cout << lastName;
        break;
    case 3:
        cout << emailAddress;
        break;
    case 4:
        cout << age;
        break;
    case 5:
        cout << daysInCourse[0];
        break;
    case 6:
        cout << daysInCourse[1];
        break;
    case 7:
        cout << daysInCourse[2];
        break;
    case 8:
        cout << degreeProgram;
        break;
    default:
        cout << "NUL";
        break;
    }
}