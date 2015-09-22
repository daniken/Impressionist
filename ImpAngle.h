#ifndef IMPANGLE_H
#define IMPANGLE_H

//
// ImpAngle.h
//
// The header file of virtual angle. All the other angle cofigurations inherit from it.
//

#include <stdlib.h>

// Each brush type has an associated constant.
enum
{
	ANGLE_SLIDER = 0,
	ANGLE_MOUSE_DIRECTION = 1,
	ANGLE_MOUSE_RIGHT_CLICK = 2,
	ANGLE_GRADIENT = 3,
	NUM_ANGLE_TYPE // Make sure this stays at the end!
};


class ImpressionistDoc; // Pre-declaring class



class ImpAngle
{
protected:
	ImpAngle::ImpAngle(ImpressionistDoc* pDoc = NULL, char* name = NULL);

public:
	/*
	// coordinates for resizing and rotation of lines
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

	// The implementation of your brush should realize these virtual functions
	//virtual void BrushBegin(const Point source, const Point target) = 0;
	//virtual void BrushMove(const Point source, const Point target) = 0;
	//virtual void BrushEnd(const Point source, const Point target) = 0;
	

	// right mouse button functions
	void startMouseScaling(const Point source, const Point target);
	void stopMouseScaling(const Point source, const Point target);
	void dragMouseScaling(const Point source, const Point target);
	float getMouseAngle(int x, int y); // returns the angle made by the mouse with the branch 0 deg. input arg are the vector components
	void calculateSizeAndAngle();


	// according to the source image and the position, determine the draw color
	void SetColor(const Point source);
	*/


	// sets the angle of the different angle configurations
	//virtual void setAngle(const Point soruce, const Point target) = 0;

	// get Doc to communicate with it
	ImpressionistDoc* GetDocument(void);

	// Return the name of the brush (not used in this version).
	char* AngleName(void);
	//int getAngle();

	static int			c_nAngleCount;	// How many brushes we have,
	static ImpAngle**	c_pAngles;		// and what they are.

private:
	ImpressionistDoc*	m_pDoc;

	// Brush's name (not used in this version).
	char*				m_pAngleName;
};

#endif
