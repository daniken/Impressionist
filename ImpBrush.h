#ifndef IMPBRUSH_H
#define IMPBRUSH_H

//
// ImpBrush.h
//
// The header file of virtual brush. All the other brushes inherit from it.
//

#include <stdlib.h>

// Each brush type has an associated constant.
enum
{
	BRUSH_POINTS = 0,
	BRUSH_LINES = 1,
	BRUSH_POLYGON = 2,
	BRUSH_SCATTERED_POINTS = 3,
	BRUSH_SCATTERED_LINES = 4,
	BRUSH_SCATTERED_CIRCLES = 5,
	NUM_BRUSH_TYPE // Make sure this stays at the end!
};


class ImpressionistDoc; // Pre-declaring class

class Point 
{
public:
	Point() {};
	Point(int xx, int yy) { x = xx; y = yy; };

	int x, y;
};

class ImpBrush 
{
protected:
	ImpBrush::ImpBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

public:

	// coordinates for resizing and rotation of lines
	/*	SHOULD RESIDE IN IMPANGLE
	int startMouseX;
	int startMouseY;
	int stopMouseX;
	int stopMouseY;
	
	// coodinates for calculating mouse direction
	int prevMouseX;
	int prevMouseY;
	int currentMouseX;
	int currentMouseY;
	bool isDraging;
	*/

	// The implementation of your brush should realize these virtual functions
	virtual void BrushBegin( const Point source, const Point target ) = 0;
	virtual void BrushMove( const Point source, const Point target ) = 0;
	virtual void BrushEnd( const Point source, const Point target ) = 0;

	/*	SHOULD RESIDE IN IMPANGLE
	// right mouse button functions
	void startMouseScaling(const Point source, const Point target);
	void stopMouseScaling(const Point source, const Point target);
	void dragMouseScaling(const Point source, const Point target);
	float getMouseAngle(int x, int y); // returns the angle made by the mouse with the branch 0 deg. input arg are the vector components
	void calculateSizeAndAngle();
	*/

	// according to the source image and the position, determine the draw color
	void SetColor( const Point source );

	// get Doc to communicate with it
	ImpressionistDoc* GetDocument( void );

	// Return the name of the brush (not used in this version).
	char* BrushName( void );
	
	static int			c_nBrushCount;	// How many brushes we have,
	static ImpBrush**	c_pBrushes;		// and what they are.

private:
	ImpressionistDoc*	m_pDoc;

	// Brush's name (not used in this version).
	char*				m_pBrushName;
};

#endif