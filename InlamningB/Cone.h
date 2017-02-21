#ifndef CONE_H
#define CONE_H
#define _USE_MATH_DEFINES

#include "Shape.h"
#include <iostream>
#include <string>
#include <cmath>

class Cone : public Shape {
private:
	float radius;
public:
	float GetRadius() const;

	bool SetRadius(const float newRadius);

	void CalcVolume();
	virtual std::string toString() const;

	Cone(Cone &otherConeObject);
	Cone& operator=(Cone &otherConeObject);

	Cone(const float startRadius, const float startHeight);
	virtual ~Cone();

};
#endif