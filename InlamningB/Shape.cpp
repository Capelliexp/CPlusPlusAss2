#include "Shape.h"

float Shape::GetVolume() const {
	return this->volume;
}
float Shape::GetHeight() const {
	return this->height;
}

float Shape::SetVolume(float newVolume) {
	this->volume = newVolume;
}
float Shape::SetHeight(float newHeight) {
	this->height = newHeight;
	CalcVolume();
}

Shape::Shape(float startHeight){
	this->height = startHeight;
}

Shape::~Shape() {
	//empty
}