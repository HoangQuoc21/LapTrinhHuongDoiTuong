#include "schedule.h"

schedule::schedule() {
	days[0].day = "Mon";
	days[1].day = "Tues";
	days[2].day = "Wed";
	days[3].day = "Thurs";
	days[4].day = "Fri";
	days[5].day = "Sat";
	days[6].day = "Sun";
	for (int i = 0; i < 7; i++) 
		days[i].morning = days[i].afternoon = "x";
	
}

bool schedule::set(string d, string ses, string cN) {
	int i = -1;
	if (d == "Mon")
		i = 0;
	else if (d == "Tues")
		i = 1;
	else if (d == "Wed")
		i = 2;
	else if (d == "Thurs")
		i = 3;
	else if (d == "Fri")
		i = 4;
	else if (d == "Sat")
		i = 5;
	else if (d == "Sun")
		i = 6;
	if (i == -1)
		return false;

	if (ses == "Morning") {
		if (days[i].morning == "x") {
			days[i].morning = cN;
			return true;
		}
	}
	else if (ses == "Afternoon") {
		if (days[i].afternoon == "x") {
			days[i].afternoon = cN;
			return true;
		}
	}
	return false;
}

ostream& operator<<(ostream& out, const schedule& s) {
	for (int i = 0; i < 7; i++)
		out << s.days[i].day << ": " << s.days[i].morning << " " << s.days[i].afternoon << endl;
	return out;
}