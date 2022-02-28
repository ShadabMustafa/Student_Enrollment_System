#include "iostream"
#include "iomanip"
#include "student.h"
#include "degree.h"
using namespace std;
// Part D. stuff done 
//default student constructor
Student::Student()
{
	this->studentID = "student_id";
	this->firstName = "first_name";
	this->lastName = "last_name";
	this->emailAddress = "email_address";
	this->age = 0;
	this->num_days = new int[num_days_size];
	for (int i = 0; i < num_days_size; i++) this->num_days[i] = 0;
	
}
//student constructor
Student::Student(string id, string First_Name, string Last_Name, string eMail, int aGe, int num_days[], Degree degree)
{
	this->studentID = id;
	this->firstName = First_Name;
	this->lastName = Last_Name; 
	this->emailAddress = eMail;
	this->age = aGe;
	this->num_days = new int[num_days_size];
	for (int i = 0; i < 3; i++) this->num_days[i] = num_days[i];

}

//student accessors
string Student::getStudentID()
{
	return studentID;
}
string Student::getFirstName()
{
	return firstName;
}
string Student::getLastName()
{
	return lastName;
}
string Student::getEmailAddress()
{
	return emailAddress;
}
int    Student::getAge()
{
	return age;
}
int* Student::getNumDays()
{
	return num_days;
}

//student mutators
void   Student::setStudentID    (string id)
{
	this->studentID = id;
}
void   Student::setFirstName    (string First_Name)
{
	this->firstName = First_Name;
}
void   Student::setLastName     (string Last_Name)
{
	this->lastName = Last_Name;
}
void   Student::setEmailAddress (string eMail)
{
	this->emailAddress = eMail;
}
void   Student::setAge          (int aGe)
{
	this->age = aGe;
}
void   Student::setNumDays      (int num_days[])
{
	if (this->num_days != nullptr) {
		delete[] this->num_days;
		this->num_days = nullptr;
	}
	this->num_days = new int[num_days_size];
	for (int i = 0; i < 3; i++) {
		this->num_days[i] = num_days[i];
	}
}
// Prints
void   Student::print()
{
	int* courseday = getNumDays();

	cout <<	"ID: "<< studentID << "\n";
	cout << "\tFirst name is: " << firstName << "\t";
	cout << "\tLast name is: " << lastName << "\t";
	cout << "\tAge is: " << age << "\t";
	cout << "\tDays In Courses: {" << *courseday << " " << *(courseday + 1) << " " << *(courseday + 2) << "}" << "\t";
}

//student destructor
Student::~Student()
{
	if (num_days != nullptr) {
		delete[] num_days;
		num_days = nullptr;
	}
}
