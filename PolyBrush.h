//
// CircleBrush.h
//
// The header file for Point Brush. 
//

#ifndef POLYBRUSH_H
#define POLYEBRUSH_H

#include "ImpBrush.h"
#include "math.h"

class PolyBrush : public ImpBrush
{
public:
	PolyBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	void startMouseScaling(const Point source, const Point target);
	void stopMouseScaling(const Point source, const Point target);
	void dragMouseScaling(const Point source, const Point target);
	void calculateSizeAndAngle();
	char* BrushName(void);
};

#endif