//
// PointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "anglemousedirection.h"
#include "math.h"
#include <iostream>

AngleMouseDirection::AngleMouseDirection(ImpressionistDoc* pDoc, char* name) :
ImpAngle(pDoc, name)
{
}


void AngleMouseDirection::calculateMouseDirection(const Point source, const Point target){



	// set current mouse location
	currentMouseX = target.x;
	currentMouseY = target.y;

	if (prevMouseX != 0 && prevMouseY != 0){

		// calculate the direction vector
		int x = target.x - prevMouseX;
		int y = target.y - prevMouseY;


		// get angle
		float degToRad = 3.141592f / 180.0f;
		float mouseSize = sqrt((float)((x)*(x)+(y)*(y)));

		float angle;

		float deltaY = (float)y;
		angle = asinf(deltaY / mouseSize);
		angle = angle / degToRad;
		std::cout << "true angle: " << angle << std::endl;

		if (currentMouseX - prevMouseX > 0 && currentMouseY - prevMouseY> 0) {
			// first quadrant
		}
		else if (currentMouseX - prevMouseX< 0 && currentMouseY - prevMouseY> 0) {
			// second quadrant
			angle = 180 - angle;

		}
		else if (currentMouseX - prevMouseX< 0 && currentMouseY - prevMouseY< 0) {
			// third quadrant
			angle = -1 * angle;

		}
		else if (currentMouseX - prevMouseX> 0 && currentMouseY - prevMouseY< 0) {
			// forth quadrant
			angle = angle + 180;

		}


		ImpressionistDoc * pDoc = GetDocument();
		pDoc->setAngle((int)angle);


	}

	prevMouseX = target.x;
	prevMouseY = target.y;



}

