#pragma once
#ifndef SECURITY_H
#define SECURITY_H
#include "iostream"
#include "string"
#include "degree.h"
#include "student.h"
using namespace std;
// subclass Security student stuff
class SecurityStudent : public Student {
public:
	SecurityStudent();
	SecurityStudent(string id, string First_Name, string Last_Name, string eMail, int aGe, int* num_days, Degree degree);
	Degree getDegree() override;
	void setDegree(Degree d);
	void print();
	~SecurityStudent();
};
#endif