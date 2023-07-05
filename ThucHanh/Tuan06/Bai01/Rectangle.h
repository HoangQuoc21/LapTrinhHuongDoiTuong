#pragma once
#include "Shape.h"

// Lớp hình chu nhat
class Rectangle : public Shape {
protected:
	Point X;
	double W, H;
public:
	//Constructors
	Rectangle();
	Rectangle(const Rectangle& r);
	~Rectangle();
	bool IsSelectedPoint(Point);
	Shape* Clone();
	void input();
	void print();
	// others
	string type();
};

