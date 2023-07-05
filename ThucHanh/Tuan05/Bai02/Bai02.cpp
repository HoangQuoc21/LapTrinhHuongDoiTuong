#include <iostream>
#include <fstream>
#include <sstream>
#include  "student.h"
#include "course.h"
#include "registrar.h"

using namespace std;


void printCourse(vector<course> c) {
	for (auto x : c) {
		cout << x << endl;
		cout << "-----------------------------------------------------\n";
	}
}

void printStudent(vector<student> stu) {
	for (auto x : stu) {
		cout << x ;
		cout << "-------------------------------------------\n";
	}
}

int main() {
	vector<course> cour;
	vector<student> stu;
	registrar r;
	r.readCourseList(cour, "course.txt");
	r.readStudentList(stu, "student.txt");
	int choice;
	while (1) {
		system("cls");
		cout << "================================ MENU =============================\n";
		cout << "1. Print student list.\n";
		cout << "2. Print course list.\n";
		cout << "3. Register a course for a student.\n";
		cout << "4. Write student list to file.\n";
		cout << "0. Exit program.\n";
		cout << "================================ END ==============================\n";
		cout << "Your choice: ";
		cin >> choice;
		cout << "===================================================================\n";
		if (choice == 1) {
			cout << "STUDENT LIST:\n";
			cout << "===================================================================\n";
			printStudent(stu);
		}
		else if (choice == 2) {
			cout << "COURSE LIST:\n";
			cout << "===================================================================\n";
			printCourse(cour);
		}
		else if (choice == 3) {
			r.registering(stu, cour);
		}
		else if (choice == 4) {
			r.writeStudentList(stu, "registeredStudent.txt");
			cout << "*Successfully write student list to file.*\n";
		}
		else if (choice == 0) {
			break;
		}
		else
			cout << "*Invalid choice.*\n";
		system("pause");
	}
	cout << "*End of program.*\n";
	return 0;
}