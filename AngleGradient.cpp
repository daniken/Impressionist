//
// AngleGradient.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "anglegradient.h"
#include "math.h"
#include <iostream>

AngleGradient::AngleGradient(ImpressionistDoc* pDoc, char* name) :
ImpAngle(pDoc, name)
{
}


void AngleGradient::calculateGradientDirection(const Point source, const Point target)
{

	ImpressionistDoc * pDoc = GetDocument();

	// get colors
	GLubyte color[3];

	// get y component of intensity vector
	memcpy(color, pDoc->GetOriginalPixel(source.x, source.y), 3);
	float intCenter = (0.2126*color[0] + 0.7152*color[1] + 0.0722*color[2]);

	std::cout << "intensity at center: " << intCenter << std::endl;

	// get y component of intensity vector
	memcpy(color, pDoc->GetOriginalPixel(source.x, source.y - 1), 3);
	float intNorth = (0.2126*color[0] + 0.7152*color[1] + 0.0722*color[2]);

	memcpy(color, pDoc->GetOriginalPixel(source.x, source.y + 1), 3);
	float intSouth = (0.2126*color[0] + 0.7152*color[1] + 0.0722*color[2]);
	
	// get x component of intensity vector
	memcpy(color, pDoc->GetOriginalPixel(source.x + 1, source.y), 3);
	float intEast = (0.2126*color[0] + 0.7152*color[1] + 0.0722*color[2]);

	memcpy(color, pDoc->GetOriginalPixel(source.x - 1, source.y), 3);
	float intWest = (0.2126*color[0] + 0.7152*color[1] + 0.0722*color[2]);


	float y = intNorth - intSouth;
	float x = intEast - intWest;
	std::cout << "(x,y) = " << "(" << x << ", " << y << ")" << std::endl;

	// get angle
	float angle = 0.0f;

	if (sqrt(x*x + y*y) > 0) {

		// calculate angle from intensity vector
		float degToRad = 3.141592f / 180.0f;
		float vectorAmplitude = sqrt(x*x + y*y);

		//(float deltaY = (float)y;
		angle = asinf(y / vectorAmplitude);
		angle = angle / degToRad;

		if (x > 0 && y > 0) {
			// first quadrant
		}
		else if (x < 0 && y > 0) {
			// second quadrant
			angle = 180 - angle;
		}
		else if (x < 0 && y < 0) {
			// third quadrant
			angle = -1 * angle;
		}
		else if (x > 0 && y < 0) {
			// forth quadrant
			angle = angle + 180;
		}
		// make it perpendicular to the gradient
		savedAngle = (int)angle + 90;
		std::cout << "perpendicular angle: " << savedAngle << std::endl;
	}
	else{
		std::cout << "Gradient angle preserved: " << savedAngle << std::endl;
	}


	pDoc->setAngle(savedAngle);
}
	
	


