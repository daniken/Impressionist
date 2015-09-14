//
// ScatterPoints.h
//
// The header file for Point Brush. 
//

#ifndef SCATTERPOINTBRUSH_H
#define SCATTERPOINTBRUSH_H

#include "ImpBrush.h"
#include "math.h"

class ScatterPoints : public ImpBrush
{
public:
	ScatterPoints(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	void startMouseScaling(const Point source, const Point target);
	void stopMouseScaling(const Point source, const Point target);
	void dragMouseScaling(const Point source, const Point target);
	char* BrushName(void);
};

#endif