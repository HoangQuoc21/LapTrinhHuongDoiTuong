#include "student.h"

void student::set(string i, string n, string d, string a) {
	id = i;
	name = n;
	DOB = d;
	address = a;
}

string student::getID() {
	return id;
}

bool student::registering(course c) {
	if (learningSchedule.set(c.getDay(), c.getSession(), c.getName())) {
		cout << "*Successfully registered.*\n";
		return true;
	}
	else {
		cout << "*Fail to register.*\n";
		return false;
	}
		
}

istream& operator>>(istream& in, student& s) {
	
	cout << "Id: ";
	cin.ignore();
	getline(in, s.id);
	cout << "Name: ";
	getline(in, s.name);
	cout << "DOB: ";
	getline(in, s.DOB);
	cout << "Address: ";
	getline(in, s.address);
	
	return in;
}

ostream& operator<<(ostream& out, const student& s) {
	out << "Id: " << s.id << endl;
	out << "Name: " << s.name << endl;
	out << "DOB: " << s.DOB << endl;
	out << "Address: " << s.address << endl;
	out << "*Learning schedule*:\n";
	out << s.learningSchedule;
	return out;
}