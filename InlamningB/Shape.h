#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape {
private:
	float volume;
	float height;
public:
	virtual float GetVolume() const;	//base
	virtual float GetHeight() const;	//base
	virtual float GetLength() const;	//box
	virtual float GetWidth() const;		//box
	virtual float GetRadius() const;	//cone

	virtual bool SetVolume(const float newVolume);	//base
	virtual bool SetHeight(const float newHeight);	//base
	virtual bool SetLength(const float newLength);	//box
	virtual bool SetWidth(const float newWidth);	//box
	virtual bool SetRadius(const float newRadius);	//cone

	virtual std::string toString() const = 0;	//pure virtual
	virtual void CalcVolume() = 0;				//pure virtual

	Shape(Shape &otherShapeObject);	//base
	Shape(const float startHeight);
	virtual ~Shape();

};
#endif