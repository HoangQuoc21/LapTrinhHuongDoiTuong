#pragma once
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

class ComplexShape : public Shape {
protected:
	// Các hình vẽ thành phần: Circle, rectangle, ...
	int sz; //Number of shapes
	Shape** Children; //Array of <Shape*>
public:
	// Constructors
	ComplexShape();
	// Destructor
	~ComplexShape();
	bool IsSelectedPoint(Point);
	Shape* Clone();
	void input();
	void print();
	int circle_Num();
	//others
	int rectangle_Num();
	string type();
};

