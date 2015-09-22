//
// ScatteredPolygon.h
//
// The header file for Point Brush. 
//

#ifndef SCATTERPOLYGON_H
#define SCATTERPOLYGON_H

#include "ImpBrush.h"
#include "math.h"

class ScatteredPolygon : public ImpBrush
{
public:
	ScatteredPolygon(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	/*
	void startMouseScaling(const Point source, const Point target);
	void stopMouseScaling(const Point source, const Point target);
	void dragMouseScaling(const Point source, const Point target);
	void calculateSizeAndAngle();
	*/
	char* BrushName(void);
};

#endif