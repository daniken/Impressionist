//
// AngleSlider.h
//
// The header file for Angle Slider. 
//

#ifndef ANGLESLIDER_H
#define ANGLESLIDER_H

#include "ImpAngle.h"

class AngleSlider : public ImpAngle
{
public:


	AngleSlider(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	
	char* AngleName(void);
	//void setAngle(const Point soruce, const Point target);
};

#endif
