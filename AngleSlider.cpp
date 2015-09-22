//
// PointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "angleslider.h"
#include "math.h"
#include <iostream>

extern float frand();

AngleSlider::AngleSlider(ImpressionistDoc* pDoc, char* name) :
	ImpAngle(pDoc, name)
{
}

