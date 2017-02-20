#include "ShapeRegister.h" 
#include <string>
#include <iostream>

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

		shapeArray[size] = new Cone(startRadius, startHeight);

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

		shapeArray[size] = new Box(startLength, startWidth, startHeight);

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

	delete[] this->shapeArray[iterator];
	delete[] this->shapeArray;

	this->shapeArray = new Shape*[size - 1 + freeSpace];

	for (int i = 0; i < (size - 1 - freeSpace); i++) {
		shapeArray[i] = temp[i];
	}

	this->size = size - 1;
	delete[] temp;

	return true;
}

bool ShapeRegister::GetAllShapesAsStrings(std::string arr[], int capOfArr){
	if (capOfArr < (size - freeSpace)) return false;

	int looper;
	for (looper = 0; looper < (size - freeSpace); looper++) {
		arr[looper] = shapeArray[looper]->toString();
	}
	arr[looper] = "end";

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
	arr[arrayIterator] = "end";

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
	arr[arrayIterator] = "end";

	return true;
}

bool ShapeRegister::EditACone(float searchHeight, float newRadius, float newHeight){
	int iterator = SearchShapeHeight(searchHeight);
	if (iterator == -1) return false;

	if (dynamic_cast<Cone*>(shapeArray[iterator])) {
		if (this->shapeArray[iterator]->SetRadius(newRadius) == false) return false;
		if (this->shapeArray[iterator]->SetHeight(newHeight) == false) return false;
		return true;
	}

	return false;
}
bool ShapeRegister::EditABox(float searchHeight, float newLength, float newWidth, float newHeight){
	int iterator = SearchShapeHeight(searchHeight);
	if (iterator == -1) return false;

	if (dynamic_cast<Box*>(shapeArray[iterator])) {
		if (this->shapeArray[iterator]->SetLength(newLength) == false) return false;
		if (this->shapeArray[iterator]->SetWidth(newWidth) == false) return false;
		if (this->shapeArray[iterator]->SetHeight(newHeight) == false) return false;
		return true;
	}

	return false;
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

int ShapeRegister::TestCopyConstructor() {
	int res = -1;
	Box *testC = new Box(33.0f, 33.0f, 33.0f);
	Box *testD = new Box(*testC);

	if ((testD->GetHeight() == testC->GetHeight()) && (testD->GetLength() == testC->GetLength()) &&
		(testD->GetWidth() == testC->GetWidth()))
		res = 1;

	delete[] testC;
	delete[] testD;

	return res;
}
int ShapeRegister::TestAssignmentOperator() {
	int res = -1;
	Cone *testA = new Cone(11.0f, 11.0f);
	Cone *testB = new Cone(22.0f, 22.0f);
	
	*testB = *testA;

	if ((testB->GetHeight() == testA->GetHeight()) && (testB->GetRadius() == testA->GetRadius()))
		res = 1;

	delete[] testA;	
	delete[] testB;
	

	return res;
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