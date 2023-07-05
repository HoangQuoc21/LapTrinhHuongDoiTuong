#pragma once
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
#include <string>
using namespace std;
class myException {
private:
	string message;
public:
	myException() {
		message = "";
	}
	myException(string msg) {
		message = msg;
	}
	string getMessage() {
		return message;
	}
};
#endif