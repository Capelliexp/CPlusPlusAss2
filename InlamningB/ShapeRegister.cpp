#include "ShapeRegister.h"

bool ShapeRegister::AddCone(float startRadius, float startHeight){
	if (SearchShapeHeight(startHeight) != -1) return false;

	if (freeSpace > 0) {
		shapeArray[size - freeSpace] = new Cone(startRadius, startHeight);
		return true;
	}
	else {
		Shape** temp = new Shape*[size];
		for (int i = 0; i < size; i++) {
			temp[i] = shapeArray[i];
		}

		delete[] this->shapeArray;
		this->shapeArray = new Shape*[size + 1];

		for (int i = 0; i < size; i++) {
			shapeArray[i] = temp[i];
		}

		shapeArray[size + 1] = new Cone(startRadius, startHeight);

		this->size = size + 1;
		delete[] temp;

		return true;
	}

	return false;
}
bool ShapeRegister::AddBox(float startLength, float startWidth, float startHeight){
	if (SearchShapeHeight(startHeight) != -1) return false;

	if (freeSpace > 0) {
		shapeArray[size - freeSpace] = new Box(startLength, startWidth, startHeight);
		return true;
	}
	else {
		Shape** temp = new Shape*[size];
		for (int i = 0; i < size; i++) {
			temp[i] = shapeArray[i];
		}

		delete[] this->shapeArray;
		this->shapeArray = new Shape*[size + 1];

		for (int i = 0; i < size; i++) {
			shapeArray[i] = temp[i];
		}

		shapeArray[size + 1] = new Box(startLength, startWidth, startHeight);

		this->size = size + 1;
		delete[] temp;

		return true;
	}

	return false;
}
bool ShapeRegister::RemoveShape(float height){
	if (SearchShapeHeight(height) == -1) return false;



}

bool ShapeRegister::GetAllShapesAsStrings(std::string arr[], int capOfArr){}
bool ShapeRegister::GetAllConesAsStrings(std::string arr[], int capOfArr){}
bool ShapeRegister::GetAllBoxesAsStrings(std::string arr[], int capOfArr){}

bool ShapeRegister::EditACone(float searchHeight, float newRadius, float newHeight){}
bool ShapeRegister::EditABox(float searchHeight, float newLength, float newWidth, float newHeight){}

int ShapeRegister::NrOfShapes(){}
int ShapeRegister::NrOfCones(){}
int ShapeRegister::NrOfBoxes(){}

int ShapeRegister::SearchShapeHeight(float height) {
	for (int i = 0; i < (size - freeSpace); i++) {
		if (shapeArray[i]->GetHeight() == height) {
			return i;	//funnen height
		}
	}
	return -1;	//ingen height funnen
}

ShapeRegister::ShapeRegister(unsigned int startValue){
	this->shapeArray = new Shape*[startValue];
	this->freeSpace = startValue;
	this->size = startValue;
}
ShapeRegister::~ShapeRegister(){
	for (int i = 0; i < size; i++) {
		delete shapeArray[i];
	}
	delete[] this->shapeArray;
}