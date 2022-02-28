#include "iostream"
#include "softwareStudent.h"
using namespace std;
// Subclass software student stuff
SoftwareStudent::SoftwareStudent() {
	setDegree(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string id, string First_Name, string Last_Name, string eMail, int aGe, int* num_days, Degree degree)
{
	setDegree(SOFTWARE);
}

Degree SoftwareStudent::getDegree()
{
	return SOFTWARE;
}


void SoftwareStudent::setDegree(Degree d)
{
	this->degree = SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
}