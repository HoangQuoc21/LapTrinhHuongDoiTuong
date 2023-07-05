#include "student.h"
// Parameter constructor
// Person(id), thua ke tu lop Person

//Constructors
//call constructor of Person class
//Gọi constructor của lớp cha thì ở ngoài, các phương thức thường còn lại gọi ở trong
Student::Student(long id, double gp):Person(id), gpa(gp){
	assert(gpa >= 0.0 && gpa <= 10.0);
}

Student::Student(): Person(){
	gpa = 0;
}

Student::~Student(){
	cout << "Ham huy Student.\n";
}

//copy constructor của lớp cha nhận lớp con vào được
Student::Student(const Student& student): Person(student){
	gpa = student.gpa;
}

//getter(); setter()
double Student::getGpa() const{
	return gpa;
}

void Student::setGpa(double gp) {
	gpa = gp;
}

//Other methods
void Student::print() {
	Person::print();
	cout << "GPA: " << gpa << endl;
}