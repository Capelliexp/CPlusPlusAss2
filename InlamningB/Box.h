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

	bool SetLength(const float newLength);
	bool SetWidth(const float newWidth);

	void CalcVolume();
	virtual std::string toString() const;

	Box(Box &otherBoxObject);
	Box& operator=(Box &otherBoxObject);

	Box(const float startLength, const float startWidth, const float startHeight);
	virtual ~Box();

};
#endif