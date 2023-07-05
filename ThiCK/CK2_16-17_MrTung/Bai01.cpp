#include <iostream>
using namespace std;

class fibonacci {
private:
	int size;
	int* elements;
public:
	fibonacci();
	fibonacci(const fibonacci& f);
	~fibonacci();
	void generate(int n);
	fibonacci& operator=(const fibonacci& f);
	friend ostream& operator<<(ostream& out, const fibonacci& f);
};

fibonacci::fibonacci() {
	size = 0;
	elements = NULL;
}

fibonacci::fibonacci(const fibonacci& f) {
	if (elements)
		delete[]elements;
	size = f.size;
	elements = new int[size];
	for (int i = 0; i < size; i++)
		elements[i] = f.elements[i];
}

fibonacci::~fibonacci() {
	if (elements) {
		delete[]elements;
		elements = NULL;
		size = 0;
	}
}

void fibonacci::generate(int n) {
	int* b = new int[n+1];
	for (int i = 0; i < n+1; i++) {
		if (i == 0 || i == 1)
			b[i] = 1;
		else {
			b[i] = b[i - 1] + b[i - 2];
		}
	}
	if (elements) {
		delete[]elements;
	}
	elements = b;
	size = n+1;
}

fibonacci& fibonacci::operator=(const fibonacci& f) {
	if (this->elements) {
		delete[]elements;
	}
	this->size = f.size;
	this->elements = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = f.elements[i];
	return*this;
}

ostream& operator<<(ostream& out, const fibonacci& f) {
	for (int i = 0; i < f.size; i++)
		out << "F[" << i << "]=" << f.elements[i] << endl;
	return out;
}


int main() {
	fibonacci f1;
	f1.generate(10);
	cout << f1;
	cout << "-----------------------------\n";
	fibonacci f2 = f1;
	cout << f2;
	cout << "-----------------------------\n";
	fibonacci f3 = f2;
	f3.generate(5);
	cout << f3;
	cout << "-----------------------------\n";
	fibonacci f4 = f3;
	cout << f4;
	cout << "-----------------------------\n";
	fibonacci f5(f2);
	cout << f5;
	return 0;
}