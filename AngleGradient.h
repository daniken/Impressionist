#pragma once
//
// AngleGradient.h
//
// The header file for Angle Slider. 
//

#ifndef ANGLEGRADIENT_H
#define ANGLEGRADIENT_H

#include "ImpAngle.h"
#include "ImpBrush.h"


class AngleGradient : public ImpAngle
{
public:

	AngleGradient(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	int savedAngle;

	//void setAngle(const Point source, const Point target);
	void calculateGradientDirection(const Point source, const Point target);

	char* AngleName(void);
};

#endif
