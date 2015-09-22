//
// LineBrush.h
//
// The header file for Point Brush. 
//

#ifndef LINEBRUSH_H
#define LINEBRUSH_H

#include "ImpBrush.h"
#include "math.h"

class LineBrush : public ImpBrush
{
public:


	LineBrush(ImpressionistDoc* pDoc = NULL, char* name = NULL);

	void BrushBegin(const Point source, const Point target);
	void BrushMove(const Point source, const Point target);
	void BrushEnd(const Point source, const Point target);
	void startMouseScaling(const Point source, const Point target);
	void stopMouseScaling(const Point source, const Point target);
	void dragMouseScaling(const Point source, const Point target);
	void calculateMouseDirection(const Point source, const Point target);
	void calculateSizeAndAngle();
	char* BrushName(void);

	// controls what kind of direction the lines should follow
	//bool mouseDirection;
};

#endif