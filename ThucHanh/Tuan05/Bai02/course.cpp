#include "course.h"
course::course() {

}

string course::getID() {
	return id;
}

string course::getName() {
	return name;
}

string course::getDay() {
	return day;
}

string course::getSession() {
	return session;
}

void course::resgis(student s) {
	courseRoster.push_back(s);
}


void course::getStudentList() {
	for (auto x : courseRoster) {
		cout << x << endl;
		cout << "-------------------------------------------\n";
	}
		
}

void course::set(string i, string n, string oD, string d, string ses) {
	id = i;
	name = n;
	openDay = oD;
	day = d;
	session = ses;
}

ostream& operator<<(ostream& out, const course& c) {
	out << "Id: " << c.id << endl;
	out << "Name: " << c.name << endl;
	out << "Open day: " << c.openDay << endl;
	out << "Day: " << c.day << endl;
	out << "Session: " << c.session << endl;
	out << "*List of student registered*:\n";
	for (auto x : c.courseRoster) {
		cout << "---------------------\n";
		cout << x;
		
	}
		
	return out;
}