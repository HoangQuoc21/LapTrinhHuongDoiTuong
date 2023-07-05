#include <iostream>
#include "Student.h"
using namespace std;

void testPerson() {
	//test các constructors
	Person p1;
	Person p2(211276111);

	//test copy constructor
	Person p3(p2);

	//test phương thức print()
	cout << "-p1: ";
	p1.print();
	cout << endl;

	cout << "-p2: ";
	p2.print();
	cout << endl;

	cout << "-p3: ";
	p3.print();
	cout << endl;

	//test phương thức getID()
	cout << "-p2'Id: " << p2.getId() << endl;
	cout << endl;

	//test phương thức setID(long id)
	p1.setId(211276222);
	cout << "-p1'Id: " << p1.getId() << endl;
	cout << endl;
}

void testStudent() {
	//test các constructors
	Student s1;
	Student s2(211276111, 7.8);

	//test copy constructor
	Student s3(s2);

	//test phương thức print()
	cout << "-s1:\n";
	s1.print();
	cout << endl;

	cout << "-s2:\n";
	s2.print();
	cout << endl;

	cout << "-s3:\n";
	s3.print();
	cout << endl;

	//test phương thức getGPA()
	cout << "-s2'gpa: " << s2.getGpa() << endl;
	cout << endl;

	//test phương thức setGpa(double gp)
	s1.setGpa(9.6);
	cout << "-s1's gpa: " << s1.getGpa() << endl;
	cout << endl;
}


int main() {
	system("cls");
	cout << "Test Person:\n";
	testPerson();
	cout << "===========================================\n";
	cout << "Test Student:\n";
	testStudent();
	return 0;
}