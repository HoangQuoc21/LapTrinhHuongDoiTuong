#pragma once
#include <string>
#include <iostream>
#include"student.h"
#include <vector>
using namespace std;

class student;

class course
{
private:
	string id;
	string name;
	string openDay;
	string day;
	string session;
	vector<student> courseRoster;
public:
	course();
	string getID();
	string getName();
	string getDay();
	string getSession();
	void resgis(student s);
	void getStudentList();
	void set(string i, string n, string oD, string d, string ses);
	friend ostream& operator<<(ostream& out, const course& c);
};

