#include "Cone.h"

float Cone::GetRadius() const {
	return this->radius;
}

bool Cone::SetRadius(const float newRadius) {
	this->radius = newRadius;
	Cone::CalcVolume();
	return true;
}

void Cone::CalcVolume() {
	float volume = (M_PI*radius*radius*Shape::GetHeight())/3;
	Shape::SetVolume(volume);
}
std::string Cone::toString() const {
	std::string radiusString = std::to_string(this->radius);
	radiusString.erase(radiusString.find_last_not_of('0') + 2, std::string::npos);

	std::string heightString = std::to_string(Shape::GetHeight());
	heightString.erase(heightString.find_last_not_of('0') + 2, std::string::npos);

	std::string volumeString = std::to_string(Shape::GetVolume());

	return ("(Cone) Radius: " + radiusString + " || Height: " + heightString + " || Total Volume: " + volumeString);
}

Cone::Cone(Cone &otherConeObject) : Shape(otherConeObject) {
	this->radius = otherConeObject.GetRadius();
}
Cone& Cone::operator=(Cone &otherConeObject) {
	this->radius = otherConeObject.GetRadius();
	Shape::SetVolume(otherConeObject.GetVolume());
	Shape::SetHeight(otherConeObject.GetHeight());

	return *this;
}

Cone::Cone(const float startRadius, const float startHeight) : Shape(startHeight) {
	this->radius = startRadius;
	Cone::CalcVolume();
}
Cone::~Cone() {
	//empty
}