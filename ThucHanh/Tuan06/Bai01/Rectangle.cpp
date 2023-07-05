#include "Rectangle.h"

Rectangle::Rectangle() {
	X.X = X.Y = 0;
	W = H = 0;
}

Rectangle::Rectangle(const Rectangle& r) {
	X = r.X;
	W = r.W;
	H = r.H;
}

Rectangle::~Rectangle(){}

bool Rectangle::IsSelectedPoint(Point p) {
	return (X.X == p.X) && (X.Y == p.Y);
}

Shape* Rectangle::Clone() {
	Shape* clone = new Rectangle;
	*clone = *this;
	return clone;
}

void Rectangle::input() {
	cout << "X.X: ";
	cin >> X.X;
	cout << "X.Y: ";
	cin >> X.Y;
	cout << "W: ";
	cin >> W;
	cout << "H: ";
	cin >> H;
}

void Rectangle::print() {
	cout << "X: (" << X.X << ", " << X.Y << ")\n";
	cout << "W: " << W << endl;
	cout << "H: " << H << endl;
}

// others
string Rectangle::type() {
	return "Rectangle";
}