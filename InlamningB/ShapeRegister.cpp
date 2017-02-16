#include "ShapeRegister.h"

bool ShapeRegister::AddCone(float startRadius, float startHeight){
	if (SearchShapeHeight(startHeight) != -1) return false;

	if (freeSpace > 0) {
		shapeArray[size - freeSpace] = new Cone(startRadius, startHeight);
		this->freeSpace = freeSpace - 1;
		return true;
	}
	else {
		Shape** temp = new Shape*[size];
		for (int i = 0; i < size; i++) {
			temp[i] = shapeArray[i];
		}

		delete[] this->shapeArray;
		this->shapeArray = new Shape*[size + 1];

		for (int i = 0; i < (size - freeSpace); i++) {
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
bool ShapeRegister::RemoveShape(float height) {
	int iterator = SearchShapeHeight(height);
	if (iterator == -1) return false;

	Shape** temp = new Shape*[size - 1];

	for (int i = 0; i < iterator; i++) {
		temp[i] = shapeArray[i];
	}
	for (int i = iterator; i < (size - 1 - freeSpace); i++) {
		temp[i] = shapeArray[i + 1];
	}

	delete[] this->shapeArray;
	this->shapeArray = new Shape*[size - 1];

	for (int i = 0; i < (size - 1 - freeSpace); i++) {
		shapeArray[i] = temp[i];
	}

	this->size = size - 1;
	delete[] temp;

	return true;
}

bool ShapeRegister::GetAllShapesAsStrings(std::string arr[], int capOfArr){
	if (capOfArr < (size - freeSpace)) return false;

	for (int i = 0; i < (size - freeSpace); i++) {
		arr[i] = shapeArray[i]->toString();
	}
	return true;
}
bool ShapeRegister::GetAllConesAsStrings(std::string arr[], int capOfArr){
	if (capOfArr < ShapeRegister::NrOfCones()) return false;

	int arrayIterator = 0;
	for (int i = 0; i < (size - freeSpace); i++) {
		if (dynamic_cast<Cone*>(shapeArray[i])) {
			arr[arrayIterator] = shapeArray[i]->toString();
			arrayIterator++;
		}
	}
	return true;
}
bool ShapeRegister::GetAllBoxesAsStrings(std::string arr[], int capOfArr){
	if (capOfArr < ShapeRegister::NrOfBoxes()) return false;

	int arrayIterator = 0;
	for (int i = 0; i < (size - freeSpace); i++) {
		if (dynamic_cast<Box*>(shapeArray[i])) {
			arr[arrayIterator] = shapeArray[i]->toString();
			arrayIterator++;
		}
	}
	return true;
}

bool ShapeRegister::EditACone(float searchHeight, float newRadius, float newHeight){
	int iterator = SearchShapeHeight(searchHeight);
	if (iterator = -1) return false;

	if (this->shapeArray[iterator]->SetRadius(newRadius) == false) return false;
	if (this->shapeArray[iterator]->SetHeight(newHeight) == false) return false;

	return true;
}
bool ShapeRegister::EditABox(float searchHeight, float newLength, float newWidth, float newHeight){
	int iterator = SearchShapeHeight(searchHeight);
	if (iterator = -1) return false;

	if (this->shapeArray[iterator]->SetLength(newLength) == false) return false;
	if (this->shapeArray[iterator]->SetWidth(newWidth) == false) return false;
	if (this->shapeArray[iterator]->SetHeight(newHeight) == false) return false;

	return true;
}

int ShapeRegister::NrOfShapes(){
	return (size - freeSpace);
}
int ShapeRegister::NrOfCones(){
	int numberOfCones = 0;
	for (int i = 0; i < (size - freeSpace); i++) {
		if (dynamic_cast<Cone*>(shapeArray[i])) numberOfCones++;
	}
	return numberOfCones;
}
int ShapeRegister::NrOfBoxes(){
	int numberOfBoxes = 0;
	for (int i = 0; i < (size - freeSpace); i++) {
		if (dynamic_cast<Box*>(shapeArray[i])) numberOfBoxes++;
	}
	return numberOfBoxes;
}

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