//
// AngleMouseRightClick.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "anglemouserightclick.h"
#include "math.h"
#include <iostream>

AngleMouseRightClick::AngleMouseRightClick(ImpressionistDoc* pDoc, char* name) :
ImpAngle(pDoc, name)
{
}

void AngleMouseRightClick::stopMouseScaling(const Point source, const Point target)
{
	//std::cout << "---------stopMouseScaling() called-------- - " << std::endl;
	stopMouseX = target.x;
	stopMouseY = target.y;
	//std::cout << "stop(x,y) = (" << stopMouseX << ", " << stopMouseY << ")" << std::endl;
	calculateSizeAndAngle();
}

void AngleMouseRightClick::startMouseScaling(const Point source, const Point target)
{
	//std::cout << "-------- - startMouseScaling() called---------" << std::endl;
	startMouseX = target.x;
	startMouseY = target.y;
	//std::cout << "start(x,y) = (" << startMouseX << ", " << startMouseY << ")" << std::endl;
}


void AngleMouseRightClick::calculateSizeAndAngle() {

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;
	float degToRad = 3.141592f / 180.0f;


	// set size by pythagoras
	float mouseSize = sqrt((float)((startMouseX - stopMouseX)*(startMouseX - stopMouseX) + (startMouseY - stopMouseY)*(startMouseY - stopMouseY)));
	//std::cout << "setSize: " << (float)((startMouseX - stopMouseX)*(startMouseX - stopMouseX) + (startMouseY - stopMouseY)*(startMouseY - stopMouseY)) << std::endl;
	pDoc->setSize((int)mouseSize);

	// get angle

	float angle;

	float y = stopMouseY - startMouseY;
	angle = asinf(y / mouseSize);
	angle = angle / degToRad;
	//std::cout << "true angle: " << angle << std::endl;

	if (stopMouseX > startMouseX && stopMouseY > startMouseY) {
		// first quadrant
	}
	else if (stopMouseX < startMouseX && stopMouseY > startMouseY) {
		// second quadrant
		angle = 180 - angle;

	}
	else if (stopMouseX < startMouseX && stopMouseY < startMouseY) {
		// third quadrant
		angle = -1 * angle;

	}
	else if (stopMouseX > startMouseX && stopMouseY < startMouseY) {
		// forth quadrant
		angle = angle + 180;

	}

	//std::cout << "modified angle: " << angle << std::endl;
	pDoc->setAngle((int)angle);

}




void AngleMouseRightClick::dragMouseScaling(const Point source, const Point target)
{
}



