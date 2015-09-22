//
// AngleMouseRightClick.h
//
// The header file for Angle Slider. 
//

#ifndef ANGLEMOUSERIGHTCLICK_H
#define ANGLEMOUSERIGHTCLICK_H

#include "ImpAngle.h"


class AngleMouseRightClick : public ImpAngle
{
public:

	AngleMouseRightClick(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	// initial mouse click coodinate
	int startMouseX;
	int startMouseY;

	// final mouse release coordinate
	int stopMouseX;
	int stopMouseY;

	//void setAngle(const Point source, const Point target);
	void startMouseScaling(const Point source, const Point target);
	void stopMouseScaling(const Point source, const Point target);
	void dragMouseScaling(const Point source, const Point target);
	void calculateSizeAndAngle();

	char* AngleName(void);
};

#endif
