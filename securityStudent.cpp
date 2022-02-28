#include "iostream"
#include "securityStudent.h"
using namespace std;
// Subclass security student stuff
SecurityStudent::SecurityStudent() {
	setDegree(SECURITY);
}

SecurityStudent::SecurityStudent(string id, string First_Name, string Last_Name, string eMail, int aGe, int* num_days, Degree degree)
{
	setDegree(SECURITY);
}

Degree SecurityStudent::getDegree()
{
	return SECURITY;
}


void SecurityStudent::setDegree(Degree d)
{
	this->degree = SECURITY;
}



void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}


SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;
}