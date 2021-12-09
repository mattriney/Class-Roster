#pragma once

#include <sstream>
#include <string>
#include <iostream>

#include "roster.h"
#include "student.h"
#include "degree.h"

//Code is much more readable without "std:: prefix" everywhere
using namespace std;

/*
E.  Create a Roster class (roster.cpp) by doing the following:

1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
*/ 
Roster::Roster() 

{ 
	classRosterArray = new Student * [5]; 
};

/*
F.

5.  Implement the destructor to release the memory that was allocated dynamically in Roster.
*/
Roster::~Roster() 

{
	delete[] classRosterArray; 
};

/*
this prints out the string version of degreeprogram
integer dp is used as a placeholder for enum DegreeProgram
*/
void Roster::printDegreeString(int dp) 

{
	switch (dp) 
	
	{
	case 0:
		cout << "SECURITY";
		break;
	case 1:
		cout << "NETWORK";
		break;
	case 2:
		cout << "SOFTWARE";
		break;
	default:
		cout << "ERROR";
		break;
	}
}

//index is a parameter for which index of classRosterArray to add the student to
//paramaters a - h and x are for variable data to be added to a Student object
void Roster::addStudent(int index, string a, string b, string c, string d, string e, int f, int g, int h, DegreeProgram x) 

{
	//converts the int index into a constant so it can be used for index parameter
	const int indexConst = index;
	//creates a student object to overlay on classRosterArray[x]
	Student* nstudent = new Student();

	//sets vars of student object from parsed data
	nstudent->setID(a);
	nstudent->setFName(b);
	nstudent->setLName(c);
	nstudent->setEmailAdd(d);
	nstudent->setAge(e);
	nstudent->setDays(f, g, h);
	nstudent->setDegreeProgram(x);

	//overlays nstudent on classRosterArray[x]
	classRosterArray[indexConst] = nstudent;
}

//sets all var in Student object to blank
//studentID is also set to NUL so that is is not printed
void Roster::removeStudent(string stID) 

{
	//did the function find the student?
	bool indexFound = false;
	//if the function found the student, what index is the student at?
	int indexNum = 0;

	cout << "Searching for student with ID: " << stID;

	for (int i = 0; i < 5; i++) {
		//check value to see if it matches ID, if so student was found
		if (this->classRosterArray[i]->getID() == stID) 
		{
			indexNum = i;
			indexFound = true;
			cout << ".";
			break;
		}
		//if the value passed in is not equal to one of the ID values, the function did not find the student
		else 
		{
			indexFound = false;
			cout << ".";
			continue;
		}
	}
	cout << endl;

	//if the student is found, clear the data at that index
	if (indexFound) 
	{
		cout << "Removing student from roster.";
		const int indexConst = indexNum;
		//creates a student object
		Student* nstudent = new Student();

		//sets vars of student object

		//sets id to NUL so print function won't print the data if the student is removed
		nstudent->setID("NUL");
		cout << ".";
		nstudent->setFName("");
		cout << ".";
		nstudent->setLName("");
		cout << ".";
		nstudent->setEmailAdd("");
		cout << ".";
		nstudent->setAge("");
		cout << ".";
		nstudent->setDays(0, 0, 0);
		cout << ".";
		nstudent->setDegreeProgram(UNDECIDED);
		cout << ".";

		//overlays new student object on old one so it is cleared
		classRosterArray[indexConst] = nstudent;

		cout << "Complete";
	}

	else 
	{
		//output if the function does not find the student
		cout << "Student ID: " << stID << " not found.";
	}
	cout << endl;
}

void Roster::parseArray(int rosterIndex) 

{

	string studentDataString = studentData[rosterIndex];
	int stringLength = studentDataString.length();

	string studentID = "";
	string firstName = "";
	string lastName = "";
	string email = "";
	string age = "";
	string stringdays0 = "";
	string stringdays1 = "";
	string stringdays2 = "";
	int days0 = 0;
	int days1 = 0;
	int days2 = 0;
	string degreeProgramString = "";	
	DegreeProgram studentDegree;


	int i = 0;

	int commasSkipped = 0;

	//this parses the string one character at a time and adds the characters to each variable
	for (i = 0; i < stringLength; i++) 
	{
		char s = studentDataString.at(i);
		if (s != ',') 
		{
			switch (commasSkipped) 
			{
			case 0:
				studentID.push_back(s);
				break;
			case 1:
				firstName.push_back(s);
				break;
			case 2:
				lastName.push_back(s);
				break;
			case 3:
				email.push_back(s);
				break;
			case 4:
				age.push_back(s);
				break;
			case 5:
				stringdays0.push_back(s);
				break;
			case 6:
				stringdays1.push_back(s);
				break;
			case 7:
				stringdays2.push_back(s);
				break;
			case 8:
				degreeProgramString.push_back(s);
				break;
			default:
				break;
			}
		}

		else 
		{
			//start putting data into the next var
			commasSkipped = commasSkipped + 1;
		}
	}


	stringstream daysConvert0(stringdays0);
	stringstream daysConvert1(stringdays1);
	stringstream daysConvert2(stringdays2);
	daysConvert0 >> days0;
	daysConvert1 >> days1;
	daysConvert2 >> days2;



	if (degreeProgramString == "SECURITY") 
	{
		studentDegree = SECURITY;
	}
	else if (degreeProgramString == "NETWORK") 
	{
		studentDegree = NETWORK;
	}
	else if (degreeProgramString == "SOFTWARE") 
	{
		studentDegree = SOFTWARE;
	}
	else {
		studentDegree = UNDECIDED;
	}

	//adds data to array of objects from the parsed and converted values
	addStudent(rosterIndex, studentID, firstName, lastName, email, age, days0, days1, days2, studentDegree);
}

//this prints all of the student variables in a list using printALL
void Roster::printAll() 
{
	for (int i = 0; i < 5; i++) 
	{
		//makes sure a student exists before printing data
		if (classRosterArray[i]->getID() != "NUL") 
		{
			classRosterArray[i]->print(0);
			cout << "	";
			cout << "First Name: ";
			classRosterArray[i]->print(1);
			cout << "	";
			cout << "Last Name: ";
			classRosterArray[i]->print(2);
			cout << "	";
			cout << "Age: ";
			classRosterArray[i]->print(4);
			cout << "	";
			cout << "Days In Course: {";
			classRosterArray[i]->print(5);
			cout << ",";
			classRosterArray[i]->print(6);
			cout << ",";
			classRosterArray[i]->print(7);
			cout << "}";
			cout << "Degree Program: ";

			//prints out the degree string
			printDegreeString(classRosterArray[i]->getDegreeProgram());
			cout << endl;
		}
	}
	cout << endl;
}

//looks for studentID then prints average dats in course
void Roster::printAverageDaysInCourse(string stID) 
{
	int average;
	int daysA;
	int daysB;
	int daysC;



	//checking to see if student exists
	bool indexFound = false;
	//if existing, what index?
	int indexNum = 0;


	for (int i = 0; i <= 5; i++) 
	{
		if (this->classRosterArray[i]->getID() == stID) 
		{
			indexNum = i;
			indexFound = true;
			break;
		}
		else 
		{
			indexFound = false;
			continue;
		}
	}

	//when student is found, calculate the average days in the course
	if (indexFound) 
	{
		daysA = this->classRosterArray[indexNum]->getDays(0);
		daysB = this->classRosterArray[indexNum]->getDays(1);
		daysC = this->classRosterArray[indexNum]->getDays(2);

		average = ((daysA + daysB + daysC) / 3);

		cout << "Average of days in course for student " << stID << ": " << average;
		cout << endl;

	}

	//if no student found, then print it out
	else 
	{
		cout << "Student " << stID << " was not found.";
		cout << endl;
	}
}

/*
determing whether or not emails are invalid
must have @ symbol and a "." and have no spaces in the string
*/
void Roster::printInvalidEmails() 
{
	cout << "Invalid email addresses: " << endl;

	for (int i = 0; i < 5; i++) 
	{
		string emailStr = classRosterArray[i]->getEmailAdd();
		//does email address contain @ and .
		if ((emailStr.find('@') != string::npos) && emailStr.find('.') != string::npos) 
		{
			//does email address contain spaces
			if (emailStr.find(' ') != string::npos) 
			{
				cout << emailStr;
				cout << endl;
			}
		}
		else 
		{
			cout << emailStr;
			cout << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) 
{

	//this prints students by degree program

	cout << "Printing students by degree program ";
	printDegreeString(degreeprogram);
	cout << ":" << endl;
	for (int i = 0; i < 5; i++) 
	{

		if (classRosterArray[i]->getDegreeProgram() == degreeprogram) 
		{
			if (classRosterArray[i]->getID() != "NUL") 
			{
				classRosterArray[i]->print(0);
				cout << "	";
				cout << "First Name: ";
				classRosterArray[i]->print(1);
				cout << "	";
				cout << "Last Name: ";
				classRosterArray[i]->print(2);
				cout << "	";
				cout << "Age: ";
				classRosterArray[i]->print(4);
				cout << "	";
				cout << "Days In Course: {";
				classRosterArray[i]->print(5);
				cout << ",";
				classRosterArray[i]->print(6);
				cout << ",";
				classRosterArray[i]->print(7);
				cout << "}";
				cout << "Degree Program: ";

				//prints string version of degree program
				printDegreeString(classRosterArray[i]->getDegreeProgram());
				cout << endl;
			}
		}
	}
}