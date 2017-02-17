#ifndef SHAPE_H
#define SHAPE_H

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

	virtual bool SetVolume(float newVolume);	//base
	virtual bool SetHeight(float newHeight);	//base
	virtual bool SetLength(float newLength);	//box
	virtual bool SetWidth(float newWidth);		//box
	virtual bool SetRadius(float newRadius);	//cone

	virtual std::string toString() const = 0;	//pure virtual
	virtual void CalcVolume() = 0;				//pure virtual

	Shape(Shape &otherShapeObject);
	virtual void operator=(Shape &otherShapeObject) = 0;	//pure virtual

	Shape(float startHeight);
	virtual ~Shape();

};
#endif