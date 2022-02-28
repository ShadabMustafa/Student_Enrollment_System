#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "iostream"
#include "string"
#include "degree.h"
using namespace std;
class Student
{

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int    age;
	int*   num_days; //  daysremaining in course array
	Degree degree;
	
public:
	const static int num_days_size = 3;
	//the student constructors
	Student();
	Student(string id, string First_Name, string Last_Name, string eMail, int aGe, int num_days[], Degree degree);

	//the student accessors
	
	string          getStudentID();
	string          getFirstName();
	string          getLastName();
	string          getEmailAddress();
	int             getAge();
	int*            getNumDays();
	virtual Degree  getDegree() = 0;

	//the student mutators
	void         setStudentID    (string id);
	void         setFirstName    (string First_Name);
	void         setLastName     (string Last_Name);
	void         setEmailAddress (string eMail);
	void         setAge          (int aGe);
	void         setNumDays      (int num_days[]);
	virtual void setDegree       (Degree d) = 0;
	virtual void print() = 0;
	
	//the student destructor
	~Student();
};
#endif
