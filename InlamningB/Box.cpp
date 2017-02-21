#include "Box.h"

float Box::GetLength() const {
	return this->length;
}
float Box::GetWidth() const {
	return this->width;
}

bool Box::SetLength(const float newLength){
	this->length = newLength;
	Box::CalcVolume();
	return true;
}
bool Box::SetWidth(const float newWidth){
	this->width = newWidth;
	Box::CalcVolume();
	return true;
}

void Box::CalcVolume() {
	float volume = length * width * Shape::GetHeight();
	Shape::SetVolume(volume);
}
std::string Box::toString() const {
	std::string lengthString = std::to_string(this->length);
	lengthString.erase(lengthString.find_last_not_of('0') + 2, std::string::npos);

	std::string widthString = std::to_string(this->width);
	widthString.erase(widthString.find_last_not_of('0') + 2, std::string::npos);

	std::string heightString = std::to_string(Shape::GetHeight());
	heightString.erase(heightString.find_last_not_of('0') + 2, std::string::npos);

	std::string volumeString = std::to_string(Shape::GetVolume());

	return("(Box)  Length: " + lengthString + " || Width:  " + widthString + " || Height: " + heightString + " || Total Volume: " + volumeString);
}

Box::Box(Box &otherBoxObject) : Shape(otherBoxObject) {
	this->length = otherBoxObject.GetLength();
	this->width = otherBoxObject.GetWidth();
}
Box& Box::operator=(Box &otherBoxObject) {
	this->length = otherBoxObject.GetLength();
	this->width = otherBoxObject.GetWidth();
	Shape::SetVolume(otherBoxObject.GetVolume());
	Shape::SetHeight(otherBoxObject.GetHeight());

	return *this;
}

Box::Box(const float startLength, const float startWidth, const float startHeight) : Shape(startHeight){
	this->length = startLength;
	this->width = startWidth;
	Box::CalcVolume();
}
Box::~Box(){
	//empty
}