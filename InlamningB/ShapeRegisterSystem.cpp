//https://msdn.microsoft.com/en-us/library/c8whxhf1.aspx
//http://stackoverflow.com/questions/2717854/how-to-create-a-dynamic-array-of-an-abstract-class

#include "ShapeRegisterSystem.h"
#include "ShapeRegister.h"
#include <string>
#include <iostream>
#include <crtdbg.h>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ShapeRegister(0);

	char choice;
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
			"11. Print amount of boxes" << std::endl << std::endl <<
			">";
		std::cin >> choice;
		std::cout << std::endl << "------------------------------------" << std::endl;

		switch (choice) {
			case '1':
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				break;
			case '5':
				break;
			case '6':
				break;
			case '7':
				break;
			case '8':
				break;
			case '9':
				break;
			case '10':
				break;
			case '11':
				break;
			default:
				break;
		}
	
	}

	return 1;
}

void AddCone() {}
void AddBox() {}
void RemoveShape() {}
void PrintShapes() {}
void PrintCones() {}
void PrintBoxes() {}
void EditCone() {}
void EditBox() {}
void PrintShapeAmount() {}
void PrintConesAmount() {}
void PrintBoxesAmount() {}