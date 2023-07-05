#pragma once
#include "schedule.h"
#include "course.h"
#include <string>
using namespace std;

class course;

class student
{
private:
	string id;
	string name;
	string DOB;
	string address;
	schedule learningSchedule;
public:
	string getID();
	void set(string i, string n, string d, string a);
	bool registering(course c);
	friend istream& operator>>(istream& in,student& s);
	friend ostream& operator<<(ostream& out, const student& s);
};

