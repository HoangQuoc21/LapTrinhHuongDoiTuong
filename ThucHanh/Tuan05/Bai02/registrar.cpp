#include "registrar.h"
#include <fstream>
#include <sstream>

void registrar::readCourseList(vector<course>& cour, string fileName) {
	ifstream fin(fileName);
	string line;
	while (!fin.eof()) {
		getline(fin, line);
		stringstream ss(line);
		string id;
		string name;
		string openDay;
		string day;
		string session;
		getline(ss, id, '|');
		getline(ss, name, '|');
		getline(ss, openDay, '|');
		getline(ss, day, '|');
		getline(ss, session);
		course buffer;
		buffer.set(id, name, openDay, day, session);

		cour.push_back(buffer);
	}
	fin.close();
}

void registrar::readStudentList(vector<student>& stu, string fileName) {
	ifstream fin(fileName);
	string line;
	while (!fin.eof()) {
		getline(fin, line);
		stringstream ss(line);
		string id;
		string name;
		string dob;
		string address;
		getline(ss, id, '|');
		getline(ss, name, '|');
		getline(ss, dob, '|');
		getline(ss, address);
		student buffer;
		buffer.set(id, name, dob, address);

		stu.push_back(buffer);
	}
	fin.close();
}

void registrar::writeStudentList(vector<student>& stu, string fileName) {
	ofstream fout(fileName);
	fout << "STUDENT LIST:\n";
	fout << "=============================================================================\n";
	for (auto x : stu) {
		fout << x ;
		fout << "---------------------------------------------------------------------\n";
	}
	fout.close();
}

void registrar::registering(vector<student>& stu, vector<course>& cour) {
	string studentID;
	string courseID;
	cout << "Input the registering student's id: ";
	cin >> studentID;
	cout << "Input the course wanting to register's id: ";
	cin >> courseID;
	for (auto& x : stu) {
		if (x.getID() == studentID) {
			for (auto& y : cour) {
				if (y.getID() == courseID) {
					if (x.registering(y)) {
						y.resgis(x);
						return;
					}
						
				}
			}
		}
	}
	cout << "*Can't register.*\n";
}
