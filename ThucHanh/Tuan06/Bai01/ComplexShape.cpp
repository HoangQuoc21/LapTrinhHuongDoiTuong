#include "ComplexShape.h"

// Constructors
ComplexShape::ComplexShape() {
	sz = 0;
	Children = NULL;
}

// Destructor
ComplexShape::~ComplexShape() {
	if (Children != NULL) {
		for (int i = 0; i < sz; i++)
			delete Children[i];
		delete Children;
		Children = NULL;
	}
}

bool ComplexShape::IsSelectedPoint(Point p) {
	for (int i = 0; i < sz; i++) {
		if (Children[i]->IsSelectedPoint(p) == true)
			return true;
	}
	return false;
}

Shape* ComplexShape::Clone() {
	return this;
}

void ComplexShape::input() {
	cout << "Input size: ";
	cin >> sz;
	Children = new Shape*[sz];
	int choice;
	for (int i = 0; i < sz; i++) {
		cout << "Which shape do you want to input: \n";
		cout << "1. Cirlce.\n";
		cout << "2. Rectangle.\n";
		cout << "-----------------\n";
		cin >> choice;
		if (choice == 1) {
			Children[i] = new Circle;
			Children[i]->input();
		}
		else if (choice == 2) {
			Children[i] = new Rectangle;
			Children[i]->input();
		}
		cout << "----------------------------------\n";
	}
}

void ComplexShape::print() {
	for (int i = 0; i < sz; i++) {
		Children[i]->print();
		cout << "--------------------------------\n";
	}
		
}

int ComplexShape::circle_Num() {
	int count = 0;
	for (int i = 0; i < sz; i++)
		if (Children[i]->type() == "Circle")
			count++;
	return count;
}

//others
int ComplexShape::rectangle_Num() {
	int count = 0;
	for (int i = 0; i < sz; i++)
		if (Children[i]->type() == "Rectangle")
			count++;
	return count;
}

string ComplexShape::type() {
	return "Complex Shape";
}