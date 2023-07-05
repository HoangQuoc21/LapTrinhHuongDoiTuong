#include <iostream>
#include <sstream>
#include <string>
#include <regex>
using namespace std;

//bool isValidDate(const string& date) {
//	static const regex re(R"(^(?:(?:(?:0?[1-9]|1\d|2[0-8])([-./])(?:0?[1-9]|1[0-2]))|(?:(?:31([-./])(?:0?[13578]|1[02]))|(?:(?:29|30)([-./])(?:0?[13-9]|1[0-2]))))(?:\3|\2|\1)(?:(?:20[2-9]\d|2[3-9]\d{2})|(?:19\d{2})|(?:0?\d{2}))(?:(?=\x20\d)\x20|$))");
//	return regex_match(date, re);
//}

const int maxDays[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };

bool isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0 ));
}

bool isValidDate(string date) {
	stringstream ss(date);
	string buffer;
	int day;
	int month;
	int year;

	getline(ss, buffer, '/');
	day = stoi(buffer);
	getline(ss, buffer, '/');
	month = stoi(buffer);
	getline(ss, buffer);
	year = stoi(buffer);

	if (year < 0)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (isLeapYear(year) && month == 2) {
		if (day > maxDays[2] + 1)
			return false;
		else
			return true;
	}
	if (day > maxDays[month])
		return false;

	return true;
}

//==================================================
class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(string d);
	Date operator=(Date d2);
	Date operator+(int n);
	bool operator==(Date d2);
	bool operator<(Date d2);
	int distance(Date d2);

	friend ostream& operator<<(ostream& out,const Date d);
};

Date::Date(string d) {
	stringstream ss(d);
	string buffer;
	
	getline(ss, buffer, '/');
	day = stoi(buffer);
	getline(ss, buffer, '/');
	month = stoi(buffer);
	getline(ss, buffer);
	year = stoi(buffer);
}

Date Date::operator=(Date d2) {
	this->day = d2.day;
	this->month = d2.month;
	this->year = d2.year;
	return *this;
}

Date Date::operator+(int n) {
	Date returnDate = *this;
	if (n > 0) {
		for (int i = 1; i <= n; i++){
			int maxDay = maxDays[returnDate.month];
			if (isLeapYear(year) && returnDate.month == 2)
				maxDay++;

			returnDate.day += 1;
			if (returnDate.day > maxDays[month]) {
				returnDate.day -= maxDay;
				returnDate.month++;
			}
			if (returnDate.month > 12) {
				returnDate.month = 1;
				returnDate.year++;
			}
		}
		
	}
	else if (n < 0) {
		for (int i = 1; i <= n; i++) {
			int maxDayBefore = maxDays[returnDate.month - 1];
			if (isLeapYear(year) && returnDate.month - 1 == 2)
				maxDayBefore++;

			returnDate.day -= 1;
			if (returnDate.day <= 0) {
				returnDate.day = maxDayBefore + returnDate.day;
				returnDate.month--;
			}
			if (returnDate.month <= 0) {
				returnDate.day = 31;
				returnDate.month = 12;
				returnDate.year--;
			}
		}
	}
	return returnDate;
}

bool Date::operator==(Date d2) {
	return (this->day == d2.day) && (this->month == d2.month) && (this->year == d2.year);
}

bool Date::operator<(Date d2) {
	if (this->year > d2.year)
		return false;
	else if (this->year < d2.year)
		return true;

	if (this->month > d2.month)
		return false;
	else if (this->month < d2.month)
		return true;

	if (this->day >= d2.day)
		return false;
	else if (this->day < d2.day)
		return true;
}

int Date::distance(Date d2) {
	int dis = 0;
	
	if (*this < d2) {
		Date now = *this;
		while (!(now == d2)) {
			dis++;
			now = now + 1;
		}
	}
	else if (d2 < *this) {
		Date now = d2;
		while (!(now == *this)) {
			dis++;
			now = now + 1;
		}
	}
	return dis;
}

ostream& operator<<(ostream& out, const Date d) {
	out << d.day << "/" << d.month << "/" << d.year;
	return out;
}

int main() {
	Date d1("23/05/2023");
	
	Date d3("30/05/2022");
	cout << d1.distance(d3) << endl;
	cout << d3.distance(d1) << endl;
	
	return 0;
}