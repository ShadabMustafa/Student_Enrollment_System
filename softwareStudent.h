#pragma once
#ifndef SOFTWARE_H
#define SOFTWARE_H
#include "iostream"
#include "string"
#include "degree.h"
#include "student.h"
using namespace std;
// Subclass software student stuff
class SoftwareStudent : public Student {
public:
	SoftwareStudent();
	SoftwareStudent(string id, string First_Name, string Last_Name, string eMail, int aGe, int* num_days, Degree degree);
	Degree getDegree() override;
	void setDegree(Degree d);
	void print();
	~SoftwareStudent();
};
#endif