//
// AngleSlider.h
//
// The header file for Angle Slider. 
//

#ifndef ANGLEMOUSEDIRECTION_H
#define ANGLEMOUSEDIRECTION_H

#include "ImpAngle.h"


class AngleMouseDirection : public ImpAngle
{
public:

	AngleMouseDirection(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	// current mouse position
	int currentMouseX;
	int currentMouseY;

	// mouse position one iteration ago
	int prevMouseX;
	int prevMouseY;

	//void setAngle(const Point source, const Point target);
	void calculateMouseDirection(const Point source, const Point target);

	char* AngleName(void);
};

#endif
