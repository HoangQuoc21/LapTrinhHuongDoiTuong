#include <iostream>
#include <string>
using namespace std;

bool hasSpecialCharacter(string s) {
	for (char c : s)
		if (c == '+' || c == '-' || c == '*' || c == '/')
			return true;
	return false;
}

bool hasDomain(string s) {
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '@') {
			for (int j = i; j < s.size(); j++)
				if (s[j] == '.')
					return true;
		}
			
	return false;
}

bool hasUpper(string s) {
	for (char c : s) {
		if (c >= 'A' && c <= 'Z')
			return true;
	}
	return false;
}

bool hasLetter(string s) {
	for (char c : s) {
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
			return true;
	}
	return false;
}

bool hasNumber(string s) {
	for (char c : s) {
		if (c >= '0' && c <= '9')
			return true;
	}
	return false;
}

int main() {
	string email, pass;
	try {
		cout << "Nhap email: ";
		getline(cin, email);
		if (hasSpecialCharacter(email))
			throw "Email co chua ky tu dac biet";
		else if (!hasDomain(email))
			throw "Khong co @.";
		cout << "Email hop le.\n";
	}
	catch (const char* str) {
		cout << "Email khong hop le: " << str << endl;
	}
	
	cout << "-----------------------------------------\n";
	try {
		cout << "Nhap password: ";
		getline(cin, pass);
		if (pass.length() < 8)
			throw "Do dai pass nho hon 8.";
		else if (!hasUpper(pass))
			throw "Khong co ky tu viet hoa.";
		else if (!hasLetter(pass))
			throw "Khong co chu.";
		else if (!hasNumber(pass))
			throw "Khong co so.";
		cout << "Pass hop le.\n";
	}
	catch (const char* str) {
		cout << "Pass khong hop le: " << str << endl;
	}
	
	return 0;
}