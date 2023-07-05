#include "Shape.h"
Shape::Shape(){}
Shape::~Shape(){}
Shape::Shape(const Shape& s){}
Shape* Shape::Clone(){
	return this;
}
bool Shape::IsSelectedPoint(Point p) {
	return false;
}
void Shape::input() {};
void Shape::print() {};
string Shape::type() {
	return "";
};