//
// PointBrush.h
//
// The header file for Point Brush. 
//

#ifndef POINTBRUSH_H
#define POINTBRUSH_H

#include "ImpBrush.h"

class PointBrush : public ImpBrush
{
public:


	PointBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	void startMouseScaling(const Point source, const Point target);
	void stopMouseScaling(const Point source, const Point target);
	void dragMouseScaling(const Point source, const Point target);
	void calculateSizeAndAngle();
	char* BrushName( void );
};

#endif