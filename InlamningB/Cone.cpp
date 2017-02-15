#include "Cone.h"

float Cone::GetRadius() const {
	return this->radius;
}

void Cone::SetRadius(float newRadius) {
	this->radius = newRadius;
	Cone::CalcVolume();
}

void Cone::CalcVolume() {
	float volume = (pi*radius*radius*Shape::GetHeight())/3;
	Shape::SetVolume(volume);
}

std::string Cone::toString() const {
	std::string radiusString = std::to_string(this->radius);
	radiusString.erase(radiusString.find_last_not_of('0') + 2, std::string::npos);

	std::string heightString = std::to_string(Shape::GetHeight());
	heightString.erase(heightString.find_last_not_of('0') + 2, std::string::npos);

	std::string volumeString = std::to_string(Shape::GetVolume());
	volumeString.erase(volumeString.find_last_not_of('0') + 2, std::string::npos);

	return("Radius: " + radiusString + " || Height: " + heightString + " || Total Volume: " + volumeString);
}

Cone::Cone(float startRadius, float startHeight) : Shape(startHeight) {
	this->radius = startRadius;
	Cone::CalcVolume;
}

Cone::~Cone() {
	//empty
}