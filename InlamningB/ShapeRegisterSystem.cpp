//https://msdn.microsoft.com/en-us/library/c8whxhf1.aspx
//http://stackoverflow.com/questions/2717854/how-to-create-a-dynamic-array-of-an-abstract-class

#include "ShapeRegisterSystem.h"
#include "ShapeRegister.h"
#include <string>
#include <iostream>
#include <crtdbg.h>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ShapeRegister SR(0);

	int choice;
	while (1) {
		std::cout <<
			"1. Add cone" << std::endl <<
			"2. Add box" << std::endl <<
			"3. Remove shape" << std::endl <<
			"4. Print all shapes" << std::endl <<
			"5. Print all cones" << std::endl <<
			"6. Print all boxes" << std::endl <<
			"7. Edit a cone" << std::endl <<
			"8. Edit a box" << std::endl <<
			"9. Print total amount of shapes" << std::endl <<
			"10. Print amount of cones" << std::endl <<
			"11. Print amount of boxes" << std::endl <<
			"12. Exit" << std::endl << std::endl <<
			">";
		std::cin >> choice;
		std::cout /*<< "------------------------------------"*/ << std::endl;

		switch (choice) {
			case 1:
				AddCone(&SR);
				break;
			case 2:
				AddBox(&SR);
				break;
			case 3:
				RemoveShape(&SR);
				break;
			case 4:
				PrintShapes(&SR);
				break;
			case 5:
				PrintCones(&SR);
				break;
			case 6:
				PrintBoxes(&SR);
				break;
			case 7:
				EditCone(&SR);
				break;
			case 8:
				EditBox(&SR);
				break;
			case 9:
				PrintShapeAmount(&SR);
				break;
			case 10:
				PrintConesAmount(&SR);
				break;
			case 11:
				PrintBoxesAmount(&SR);
				break;
			case 12:
				return 0;
				break;
			default:
				std::cout << "Unhandled command" << std::endl;
				break;
		}
		std::cout << std::endl;
	}

	return 1;
}

void AddCone(ShapeRegister* SR) {
	float startRadius, startHeight;
	bool errorBlob;

	std::cout << "   Cone's radius: ";
	std::cin >> startRadius;
	std::cout << "   Cone's height: ";
	std::cin >> startHeight;

	errorBlob = SR->AddCone(startRadius, startHeight);
	if (errorBlob)
		std::cout << "   Cone successfully created" << std::endl;
	else
		std::cout << "   Unable to create cone" << std::endl << "   Invalid height OR unhandled error" << std::endl;
}
void AddBox(ShapeRegister* SR) {
	float startLength, startWidth, startHeight;
	bool errorBlob;

	std::cout << "   Box's length: ";
	std::cin >> startLength;
	std::cout << "   Box's width: ";
	std::cin >> startWidth;
	std::cout << "   Box's height: ";
	std::cin >> startHeight;

	errorBlob = SR->AddBox(startLength, startWidth, startHeight);
	if (errorBlob)
		std::cout << "   Box successfully created" << std::endl;
	else
		std::cout << "   Unable to create box" << std::endl << "   Invalid height OR unhandled error" << std::endl;
}
void RemoveShape(ShapeRegister* SR) {
	float objectHeight;
	bool errorBlob;

	std::cout << "   Height of object to be removed: ";
	std::cin >> objectHeight;

	errorBlob = SR->RemoveShape(objectHeight);
	if (errorBlob)
		std::cout << "   Shape removed" << std::endl;
	else
		std::cout << "   Unable to remove shape" << std::endl << "   Invalid height OR unhandled error" << std::endl;
}

void PrintShapes(ShapeRegister* SR) {
	int capOfArr;
	bool errorBlob;
	std::string endTest;

	std::cout << "   Max amount of rows: ";
	std::cin >> capOfArr;

	std::string *arr = new std::string[capOfArr + 1];
	errorBlob = SR->GetAllShapesAsStrings(arr, capOfArr);
	if (errorBlob) {
		std::cout << "   Shapes list:" << std::endl;
		for (int i = 0; i < (capOfArr + 1); i++) {
			endTest = arr[i];
			if (!arr[i].compare("end")) {
				delete[] arr;
				return;
			}
			std::cout << "      " << arr[i] << std::endl;
		}
	}
	else
		std::cout << "   Unable to print list" << std::endl << "   Too low max row amount OR unhandled error" << std::endl;

	delete[] arr;
}
void PrintCones(ShapeRegister* SR) {
	int capOfArr;
	bool errorBlob;
	std::string endTest;

	std::cout << "   Max amount of rows: ";
	std::cin >> capOfArr;

	std::string *arr = new std::string[capOfArr + 1];
	errorBlob = SR->GetAllConesAsStrings(arr, capOfArr);
	if (errorBlob) {
		std::cout << "   Cones list:" << std::endl;
		for (int i = 0; i < (capOfArr + 1); i++) {
			endTest = arr[i];
			if (!arr[i].compare("end")) {
				delete[] arr;
				return;
			}
			std::cout << "      " << arr[i] << std::endl;
		}
	}
	else
		std::cout << "   Unable to print list" << std::endl << "   Too low max row amount OR unhandled error" << std::endl;

	delete[] arr;
}
void PrintBoxes(ShapeRegister* SR) {
	int capOfArr;
	bool errorBlob;
	std::string endTest;

	std::cout << "   Max amount of rows: ";
	std::cin >> capOfArr;

	std::string *arr = new std::string[capOfArr + 1];
	errorBlob = SR->GetAllBoxesAsStrings(arr, capOfArr);
	if (errorBlob) {
		std::cout << "   Box list:" << std::endl;
		for (int i = 0; i < (capOfArr + 1); i++) {
			endTest = arr[i];
			if (!arr[i].compare("end")) {
				delete[] arr;
				return;
			}
			std::cout << "      " << arr[i] << std::endl;
		}
	}
	else
		std::cout << "   Unable to print list" << std::endl << "   Too low max row amount OR unhandled error" << std::endl;

	delete[] arr;
}

void EditCone(ShapeRegister* SR) {
	float searchHeight, newRadius, newHeight;
	bool errorBlob;

	std::cout << "   Height of cone to edit: ";
	std::cin >> searchHeight;
	std::cout << "   New radius of cone: ";
	std::cin >> newRadius;
	std::cout << "   New height of cone: ";
	std::cin >> newHeight;

	errorBlob = SR->EditACone(searchHeight, newRadius, newHeight);

	if (errorBlob)
		std::cout << "   Cone successfully edited" << std::endl;
	else
		std::cout << "   Unable edit cone" << std::endl << "   Could not find cone hight OR unhandled error" << std::endl;

}
void EditBox(ShapeRegister* SR) {
	float searchHeight, newLength, newWidth, newHeight;
	bool errorBlob;

	std::cout << "   Height of box to edit: ";
	std::cin >> searchHeight;
	std::cout << "   New length of box: ";
	std::cin >> newLength;
	std::cout << "   New width of box: ";
	std::cin >> newWidth;
	std::cout << "   New height of box: ";
	std::cin >> newHeight;

	errorBlob = SR->EditABox(searchHeight, newLength, newWidth, newHeight);

	if (errorBlob)
		std::cout << "   Box successfully edited" << std::endl;
	else
		std::cout << "   Unable edit box" << std::endl << "   Could not find cone hight OR unhandled error" << std::endl;
}

void PrintShapeAmount(ShapeRegister* SR) {
	int nr = SR->NrOfShapes();
	std::cout << "   Number of shapes: " << nr << std::endl;
}
void PrintConesAmount(ShapeRegister* SR) {
	int nr = SR->NrOfCones();
	std::cout << "   Number of cones: " << nr << std::endl;
}
void PrintBoxesAmount(ShapeRegister* SR) {
	int nr = SR->NrOfBoxes();
	std::cout << "   Number of boxes: " << nr << std::endl;
}