#include "Circle.h"
Circle::Circle() {
	C.X = C.Y = 0;
	R = 0;
}

Circle::Circle(const Circle& c) {
	C = c.C;
	R = c.R;
}

Circle::~Circle(){}


bool Circle::IsSelectedPoint(Point p) {
	return (C.X == p.X) && (C.Y == p.Y);
}

Shape* Circle::Clone() {
	Shape* clone = new Circle;
	*clone = *this;
	return clone;
}

void Circle::input() {
	cout << "C.x: ";
	cin >> C.X;
	cout << "C.y:";
	cin >> C.Y;
	cout << "R: ";
	cin >> R;
}

void Circle::print() {
	cout << "C: (" << C.X << ", " << C.Y << ")\n";
	cout << "R: " << R << endl;
}

string Circle::type() {
	return "Circle";
}