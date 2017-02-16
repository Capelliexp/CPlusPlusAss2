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
bool Shape::SetHeight(float newHeight) {
	this->height = newHeight;
	CalcVolume();
	return true;
}
bool Shape::SetLength(float newLength) {
	return false;
}
bool Shape::SetWidth(float newWidth) {
	return false;
}
bool Shape::SetRadius(float newRadius) {
	return false;
}

Shape::Shape(float startHeight){
	this->height = startHeight;
}
Shape::~Shape() {
	//empty
}