#ifndef BOX_H
#define BOX_H

#include "Shape.h"
#include <string>

class Box : public Shape {
private:
	float length;
	float width;
public:
	float GetLength() const;
	float GetWidth() const;

	void SetLength(float newLength);
	void SetWidth(float newWidth);

	void CalcVolume();
	virtual std::string toString() const;

	Box(float startLength, float startWidth, float startHeight);
	virtual ~Box();

};
#endif