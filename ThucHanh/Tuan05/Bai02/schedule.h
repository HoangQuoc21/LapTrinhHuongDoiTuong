#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Date {
	string day;
	string morning;
	string afternoon;
};

class schedule
{
private:
	Date days[7];
public:
	schedule();
	bool set(string d, string ses, string cN);
	friend ostream& operator<<(ostream& out, const schedule& s);
};

