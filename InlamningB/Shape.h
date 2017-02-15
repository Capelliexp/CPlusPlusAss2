#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
private:
	float volume;
	float height;
public:
	virtual float GetVolume() const;
	virtual float GetHeight() const;

	virtual float SetVolume(float newVolume);
	virtual float SetHeight(float newHeight);

	virtual std::string toString() const = 0;
	virtual void CalcVolume() = 0;

	Shape(float startHeight);
	virtual ~Shape();

};
#endif