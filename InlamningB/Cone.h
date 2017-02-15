#ifndef CONE_H
#define CONE_H

#include "Shape.h"
#include <string>

class Cone : public Shape {
private:
	const float pi = 3.14;
	float radius;
public:
	float GetRadius() const;
	float GetHeight() const;

	void SetRadius(float newRadius);

	void CalcVolume();
	virtual std::string toString() const;

	Cone(float startRadius, float startHeight);
	virtual ~Cone();

};
#endif