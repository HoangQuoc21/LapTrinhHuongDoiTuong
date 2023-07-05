#pragma once
#ifndef AGEINPUT_CPP
#define AGEINPUT_CPP
#include <iostream>
#include <exception>
#include <string>
using namespace std;
#include "myexception.h"
class AgeInput : public myException {
private:
	string DEFAULT_MESSAGE = "Your age: ";
	int DEFAULT_LOWER_BOUND = 0;
	int DEFAULT_UPPER_BOUND = 99;
	int lowerBound;
	int upperBound;
public:
	
	AgeInput();
	AgeInput(int low, int high);

	int getAge() {
		return getAge(DEFAULT_MESSAGE);
	}
	
	int getAge(string promt);
};
#endif