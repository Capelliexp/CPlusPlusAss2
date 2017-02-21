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
	bool AddCone(const float startRadius, const float startHeight);
	bool AddBox(const float startLength, const float startWidth, const float startHeight);
	bool RemoveShape(const float height);

	bool GetAllShapesAsStrings(std::string arr[], const int capOfArr);
	bool GetAllConesAsStrings(std::string arr[], const int capOfArr);
	bool GetAllBoxesAsStrings(std::string arr[], const int capOfArr);

	bool EditACone(const float searchHeight, const float newRadius, const float newHeight);
	bool EditABox(const float searchHeight, const float newLength, const float newWidth, const float newHeight);

	int NrOfShapes();
	int NrOfCones();
	int NrOfBoxes();

	int SearchShapeHeight(const float height);

	int TestCopyConstructor();
	int TestAssignmentOperator();

	ShapeRegister(const unsigned int startValue);
	~ShapeRegister();
};
#endif