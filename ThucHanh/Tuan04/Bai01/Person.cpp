#include "person.h"

// Parameter constructor
Person::Person() {
	identity = 0;
}

Person::Person(long id):identity(id){
	assert(identity >= 100000000 && identity <= 999999999);
}
// … Other member functions
Person::~Person(){
	cout << "Ham huy Person.\n";
}

Person::Person(const Person& person) {
	identity = person.identity;
}

//getter, setter
long Person::getId() const {
	return identity;
}
void Person::setId(long id) {
	identity = id;
}
//other methods
void Person::print() {
	cout << "Id: " << identity << endl;
}