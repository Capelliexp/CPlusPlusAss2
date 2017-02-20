#ifndef BOX_H
#define BOX_H

#include "Shape.h"
#include <iostream>
#include <string>

class Box : public Shape {
private:
	float length;
	float width;
public:
	float GetLength() const;
	float GetWidth() const;

	bool SetLength(float newLength);
	bool SetWidth(float newWidth);

	void CalcVolume();
	virtual std::string toString() const;

	Box(Box &otherBoxObject);
	Box& operator=(Box &otherBoxObject);

	Box(float startLength, float startWidth, float startHeight);
	virtual ~Box();

};
#endif