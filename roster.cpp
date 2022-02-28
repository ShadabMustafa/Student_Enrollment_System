#include "iostream"
#include "string"
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "roster.h"
#include "degree.h"
// Part E. Stuff done
using namespace std;

int main()
{
	system("color 04");
	cout << "		THE COURSE TITLE is C-867 SCRIPTING AND PROGRAMMING APPLICATIONS " << "\n" << "\n";
	cout << "		The PROGRAMMING LANGUAGE is C++ " << "\n" << "\n";
	cout << "		The STUDENT ID is " << "\n" << "\n";
	cout << "		The NAME is Shadab Mustafa " << "\n" << "\n";
	
	Roster* classRoster = new Roster(numStudents);
		for (int i = 0; i < numStudents; i++) {
		classRoster->add(studentData[i]);
		}

	cout << "Roster" << "\n";
	classRoster->printAll();
	cout << "\n";

	cout << "Invalid Emails found in Roster" << "\n";
	classRoster->printInvalidEmails();
	cout << "\n";
	
	cout << "The Average days per a course for each student" << "\n";
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDays(classRoster->classRosterArray[i]->getStudentID());
	}
	cout << "\n";

	classRoster->printDegree(SOFTWARE);
	cout << "\n";
	classRoster->remove("A3");
	cout << "\n";
	classRoster->remove("A3");
	cout << "\n";
	cout << "\tDestructor for Roster Memory Released after Program Execution" << "\n";


	system("PAUSE");
	return 0;
}

Roster::Roster()
{
	this->TotalQuantity = 0;
	this->previousIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int TotalQuantity)
{
	this->TotalQuantity = TotalQuantity;
	this->previousIndex = -1;
	this->classRosterArray = new Student * [TotalQuantity];
}

void Roster::add(string row)
{
	if (previousIndex < TotalQuantity) {
		previousIndex++;
		int numDaysArray[Student::num_days_size];


		if (row.substr(row.length() - 8, 8) == "SOFTWARE") {
			this->classRosterArray[previousIndex] = new SoftwareStudent();
			classRosterArray[previousIndex]->setDegree(SOFTWARE);
		}

		else if (row.substr(row.length() - 7, 7) == "NETWORK") {
			this->classRosterArray[previousIndex] = new NetworkStudent();
			classRosterArray[previousIndex]->setDegree(NETWORK);
		}

		else if (row.substr(row.length() - 8, 8) == "SECURITY") {
			this->classRosterArray[previousIndex] = new SecurityStudent();
			classRosterArray[previousIndex]->setDegree(SECURITY);
		}

		//Student id set
		int rhs = studentData[previousIndex].find(",");
		classRosterArray[previousIndex]->setStudentID(studentData[previousIndex].substr(0, rhs));

		//First name set
		int lhs = rhs + 1;
		rhs = studentData[previousIndex].find(",", lhs);
		classRosterArray[previousIndex]->setFirstName(studentData[previousIndex].substr(lhs, rhs - lhs));

		//Last name set
		lhs = rhs + 1;
		rhs = studentData[previousIndex].find(",", lhs);
		classRosterArray[previousIndex]->setLastName(studentData[previousIndex].substr(lhs, rhs - lhs));

		//email set
		lhs = rhs + 1;
		rhs = studentData[previousIndex].find(",", lhs);
		classRosterArray[previousIndex]->setEmailAddress(studentData[previousIndex].substr(lhs, rhs - lhs));

		//age set
		lhs = rhs + 1;
		rhs = studentData[previousIndex].find(",", lhs);
		classRosterArray[previousIndex]->setAge(stoi(studentData[previousIndex].substr(lhs, rhs - lhs)));

		//days set to complete courses
		//Days_Num[0]
		lhs = rhs + 1;
		rhs = studentData[previousIndex].find(",", lhs);
		numDaysArray[0] = stoi(studentData[previousIndex].substr(lhs, rhs - lhs));

		//Days_Num[1]
		lhs = rhs + 1;
		rhs = studentData[previousIndex].find(",", lhs);
		numDaysArray[1] = stoi(studentData[previousIndex].substr(lhs, rhs - lhs));

		//Days_Num[2]
		lhs = rhs + 1;
		rhs = studentData[previousIndex].find(",", lhs);
		numDaysArray[2] = stoi(studentData[previousIndex].substr(lhs, rhs - lhs));

		classRosterArray[previousIndex]->setNumDays(numDaysArray);
	}
}

void Roster::remove(string id)
{
	bool studentRemoved = false;
	for (int i = 0; i <= previousIndex; i++) {
		if (classRosterArray[i] == nullptr) {
			break;
		}
		else if (id == classRosterArray[i]->getStudentID()) {
			classRosterArray[i] = nullptr;
			studentRemoved = true;
		}
	}
	if (studentRemoved == true) {
		cout << "Student removed" << "\n";
	}
	else if (studentRemoved == false) {
	cout << "\tERROR: Student with this ID: " << id << " was not found" << "\n";
	}
}


void Roster::printAll()
{
	for (int i = 0; i <= this->previousIndex; i++) {
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printAverageDays(string id)
{
	bool found = false;
	for (int i = 0; i <= previousIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == id) {
			found = true;
			int* days = classRosterArray[i]->getNumDays();
			cout << "\tThe Average number of days per course for student id: " << id << " is " << (days[0] + days[1] + days[2]) / 3 << "\n";
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= previousIndex; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) {
			cout << "\tThe email for student: " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " is invalid: " << email << "\n";
		}
	}
}

void Roster::printDegree(Degree d)
{
	cout << "Students in Degree: " << degreeTypeString[d] << "\n";
	for (int i = 0; i <= previousIndex; i++) {
		if (this->classRosterArray[i]->getDegree() == d) this->classRosterArray[i]->print();
	}
}


Roster::~Roster()
{
	// Destrutor that Releases Roster Memory
}


