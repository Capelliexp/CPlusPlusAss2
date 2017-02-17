#ifndef SHAPEREGISTER_H
#define SHAPEREGISTER_H

#include "Shape.h"
#include "Box.h"
#include "Cone.h"
#include <string>

class ShapeRegister {
private:
	Shape** shapeArray;
	int freeSpace;
	int size;
public:
	bool AddCone(float startRadius, float startHeight);
	bool AddBox(float startLength, float startWidth, float startHeight);
	bool RemoveShape(float height);

	bool GetAllShapesAsStrings(std::string arr[], int capOfArr);
	bool GetAllConesAsStrings(std::string arr[], int capOfArr);
	bool GetAllBoxesAsStrings(std::string arr[], int capOfArr);

	bool EditACone(float searchHeight, float newRadius, float newHeight);
	bool EditABox(float searchHeight, float newLength, float newWidth, float newHeight);

	int NrOfShapes();
	int NrOfCones();
	int NrOfBoxes();

	int SearchShapeHeight(float height);

	ShapeRegister(unsigned int startValue);
	~ShapeRegister();
};
#endif