//
// ScatteredLines.h
//
// The header file for Point Brush. 
//

#ifndef SCATTERLINES_H
#define SCATTERLINES_H

#include "ImpBrush.h"
#include "math.h"

class ScatteredLines : public ImpBrush
{
public:
	ScatteredLines(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	char* BrushName(void);
};

#endif