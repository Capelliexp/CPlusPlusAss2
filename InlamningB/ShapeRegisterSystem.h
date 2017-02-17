#ifndef SHAPEREGISTERSYSTEM_H
#define SHAPEREGISTERSYSTEM_H

#include "ShapeRegister.h"

void AddCone(ShapeRegister* SR);
void AddBox(ShapeRegister* SR);
void RemoveShape(ShapeRegister* SR);
void PrintShapes(ShapeRegister* SR);
void PrintCones(ShapeRegister* SR);
void PrintBoxes(ShapeRegister* SR);
void EditCone(ShapeRegister* SR);
void EditBox(ShapeRegister* SR);
void PrintShapeAmount(ShapeRegister* SR);
void PrintConesAmount(ShapeRegister* SR);
void PrintBoxesAmount(ShapeRegister* SR);

#endif