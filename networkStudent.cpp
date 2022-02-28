#include "iostream"
#include "networkStudent.h"
using namespace std;
// Subclass network student stuff
NetworkStudent::NetworkStudent() {
	setDegree(NETWORK);
}

NetworkStudent::NetworkStudent(string id, string First_Name, string Last_Name, string eMail, int aGe, int* num_days, Degree degree)
{
	setDegree(NETWORK);
}

Degree NetworkStudent::getDegree()
{
	return NETWORK;
}


void NetworkStudent::setDegree(Degree d)
{
	this->degree = NETWORK;
}



void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent()
{
}