#include "ShapeRegister.h"
#include <string>
#include <iostream>
#include <crtdbg.h>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ShapeRegister Register(4);	//skapa objektet (startkapacitet 4)

	Register.AddCone(1.0f, 1.0f);	//skapa 3 cone-objekt
	Register.AddCone(2.0f, 2.0f);
	Register.AddCone(3.0f, 3.0f);
	std::cout << "<Skapa 3 cone-objekt>" << std::endl << std::endl;

	Register.AddBox(4.0f, 4.0f, 4.0f);	//skapa 3 box-objekt
	Register.AddBox(5.0f, 5.0f, 5.0f);
	Register.AddBox(6.0f, 6.0f, 6.0f);
	std::cout << "<Skapa 3 box-objekt>" << std::endl << std::endl;

	Register.RemoveShape(99.0f);	//ta bort ett icke-existerande objekt
	std::cout << "<Ta bort ett icke-existerande objekt>" << std::endl << std::endl;

	std::cout << "Skriv ut alla objekt:" << std::endl;
	std::string *arr1 = new std::string[7];	//skriv ut alla objekt
	Register.GetAllShapesAsStrings(arr1, 6);
	for (int i = 0; i < 6; i++) {
		std::cout << arr1[i] << std::endl;
	}
	std::cout << std::endl;
	delete[] arr1;

	Register.RemoveShape(1.0f);	//ta bort 1 kon och 1 låda
	Register.RemoveShape(4.0f);
	std::cout << "<Ta bort den första konen och lådan>" << std::endl << std::endl;

	std::cout << "Skriv ut alla objekt:" << std::endl;
	std::string *arr2 = new std::string[5];	//skriv ut alla objekt
	Register.GetAllShapesAsStrings(arr2, 4);
	for (int i = 0; i < 4; i++) {
		std::cout << arr2[i] << std::endl;
	}
	std::cout << std::endl;
	delete[] arr2;

	Register.EditACone(2.0f, 22.0f, 22.0f);	//ändra konen med 2 i höjd
	std::cout << "<Ändra konen med 2 i höjd>" << std::endl << std::endl;

	std::cout << "Skriv ut alla kon-objekt:" << std::endl;
	std::string *arr3 = new std::string[3];	//skriv ut alla objekt
	Register.GetAllConesAsStrings(arr3, 2);
	for (int i = 0; i < 2; i++) {
		std::cout << arr3[i] << std::endl;
	}
	std::cout << std::endl;
	delete[] arr3;

	std::cout << "Antalet former: " << Register.NrOfShapes() << std::endl;	//skriv ut antalet former
	std::cout << "Antalet koner: " << Register.NrOfCones() << std::endl;	//skriv ut antalet koner
	std::cout << "Antalet lådor: " << Register.NrOfBoxes() << std::endl << std::endl;	//skriv ut antalet lådor

	std::cout << "test copy & assignment:" << std::endl;
	int res1 = Register.TestAssignmentOperator();	//testa tilldelningsoperator
	int res2 = Register.TestCopyConstructor();		//testa kopieringskonstruktor
	if (res1 == 1 && res2 == 1)	std::cout << "CopyTest & AssignmentTest successful" << std::endl;
	else {
		if (res1 == 1)			std::cout << "AssignmentTest successful, CopyTest failed" << std::endl;
		else if(res2 == 1)		std::cout << "CopyTest successful, AssignmentTest failed" << std::endl;
		else					std::cout << "CopyTest & AssignmentTest failed" << std::endl;
	}

	getchar();
	return 0;
}