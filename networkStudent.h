#pragma	once
#ifndef NETWORK_H
#define NETWORK_H
#include "iostream"
#include "string"
#include "degree.h"
#include "student.h"
using namespace std;
// Subclass network student stuff

class NetworkStudent : public Student {
public:
	NetworkStudent();
	NetworkStudent(string id, string First_Name, string Last_Name, string eMail, int aGe, int* num_days, Degree degree);
	Degree getDegree() override;
	void setDegree(Degree d);
	void print();
	~NetworkStudent();
};
#endif