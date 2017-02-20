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

	bool SetRadius(float newRadius);

	void CalcVolume();
	virtual std::string toString() const;

	Cone(Cone &otherConeObject);
	Cone& operator=(Cone &otherConeObject);

	Cone(float startRadius, float startHeight);
	virtual ~Cone();

};
#endif