#pragma once
#include "student.h"
#include "course.h"

using namespace std;

class registrar
{
public:
	void readCourseList(vector<course> &cour, string fileName);
	void readStudentList(vector<student>& stu, string fileName);
	void writeStudentList(vector<student>& stu, string fileName);
	void registering(vector<student>& stu, vector<course>& cour);
};

