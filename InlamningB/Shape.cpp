#include "Shape.h"

float Shape::GetVolume() const {
	return this->volume;
}
float Shape::GetHeight() const {
	return this->height;
}
float Shape::GetLength() const {
	return -1;
}
float Shape::GetWidth() const {
	return -1;
}
float Shape::GetRadius() const {
	return -1;
}

bool Shape::SetVolume(float newVolume) {
	this->volume = newVolume;
	return true;
}
bool Shape::SetHeight(const float newHeight) {
	this->height = newHeight;
	CalcVolume();
	return true;
}
bool Shape::SetLength(const float newLength) {
	return false;
}
bool Shape::SetWidth(const float newWidth) {
	return false;
}
bool Shape::SetRadius(const float newRadius) {
	return false;
}

Shape::Shape(Shape &otherShapeObject) {
	this->volume = otherShapeObject.GetVolume();
	this->height = otherShapeObject.GetHeight();
}
Shape::Shape(const float startHeight){
	this->height = startHeight;
}
Shape::~Shape() {
	//empty
}