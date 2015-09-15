//
// ImpBrush.cpp
//
// The implementation of virtual brush. All the other brushes inherit from it.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ImpBrush.h"
#include <iostream>

// Static class member initializations
int			ImpBrush::c_nBrushCount	= 0;
ImpBrush**	ImpBrush::c_pBrushes	= NULL;

ImpBrush::ImpBrush(ImpressionistDoc*	pDoc, 
				   char*				name) :
					m_pDoc(pDoc), 
					m_pBrushName(name)
{
}

//---------------------------------------------------
// Return m_pDoc, which connects the UI and brushes
//---------------------------------------------------
ImpressionistDoc* ImpBrush::GetDocument(void)
{
	return m_pDoc;
}

//---------------------------------------------------
// Return the name of the current brush
//---------------------------------------------------
char* ImpBrush::BrushName(void)
{
	return m_pBrushName;
}

//----------------------------------------------------
// Set the color to paint with to the color at source,
// which is the coord at the original window to sample 
// the color from
//----------------------------------------------------
void ImpBrush::SetColor (const Point source)
{
	ImpressionistDoc* pDoc = GetDocument();

	float alpha = ((float)(pDoc->getAlpha()));
	// get alpha value from slider and force cast
	
	GLubyte GLubyteAlpha = static_cast<GLubyte>(alpha);

	GLubyte color[3];
	


	memcpy ( color, pDoc->GetOriginalPixel( source ), 3 );

	glColor4ub(color[0], color[1], color[2], GLubyteAlpha);

}

void ImpBrush::startMouseScaling(const Point source, const Point target)
{

	startMouseX = target.x;
	startMouseY = target.y;


}

void ImpBrush::stopMouseScaling(const Point source, const Point target)
{



	//std::cout << "---------stopMouseScaling() called-------- - " << std::endl;
	stopMouseX = target.x;
	stopMouseY = target.y;
	//std::cout << "stop(x,y) = (" << stopMouseX << ", " << stopMouseY << ")" << std::endl;
	calculateSizeAndAngle();
}


void ImpBrush::calculateSizeAndAngle() {

	ImpressionistDoc* pDoc = GetDocument();
	float degToRad = 3.141592f / 180.0f;


	// set size by pythagoras
	float mouseSize = sqrt((float)((startMouseX - stopMouseX)*(startMouseX - stopMouseX) + (startMouseY - stopMouseY)*(startMouseY - stopMouseY)));
	std::cout << "setSize: " << (float)((startMouseX - stopMouseX)*(startMouseX - stopMouseX) + (startMouseY - stopMouseY)*(startMouseY - stopMouseY)) << std::endl;
	pDoc->setSize((int)mouseSize);

	/*		REPLACED BY A FUNCTION INSTEAD
	// get angle

	float angle;

	float y = stopMouseY - startMouseY;
	angle = asinf(y / mouseSize);
	angle = angle / degToRad;
	//std::cout << "true angle: " << angle << std::endl;

	if (stopMouseX > startMouseX && stopMouseY > startMouseY) {
		// first quadrant
	}
	else if (stopMouseX < startMouseX && stopMouseY > startMouseY) {
		// second quadrant
		angle = 180 - angle;

	}
	else if (stopMouseX < startMouseX && stopMouseY < startMouseY) {
		// third quadrant
		angle = -1 * angle;

	}
	else if (stopMouseX > startMouseX && stopMouseY < startMouseY) {
		// forth quadrant
		angle = angle + 180;

	}

	std::cout << "modified angle: " << angle << std::endl;

	*/
	pDoc->setAngle((int)getMouseAngle(stopMouseX-startMouseX, stopMouseY - startMouseY));






}

float ImpBrush::getMouseAngle(int x, int y) {

	// get angle
	float degToRad = 3.141592f / 180.0f;
	float mouseSize = sqrt((float)((x)*(x) + (y)*(y)));

	float angle;

	float deltaY = (float)y;
	angle = asinf(deltaY / mouseSize);
	angle = angle / degToRad;
	std::cout << "true angle: " << angle << std::endl;

	if (stopMouseX - startMouseX > 0 && stopMouseY - startMouseY> 0) {
		// first quadrant
	}
	else if (stopMouseX - startMouseX< 0 && stopMouseY - startMouseY> 0) {
		// second quadrant
		angle = 180 - angle;

	}
	else if (stopMouseX - startMouseX< 0 && stopMouseY - startMouseY< 0) {
		// third quadrant
		angle = -1 * angle;

	}
	else if (stopMouseX - startMouseX> 0 && stopMouseY - startMouseY< 0) {
		// forth quadrant
		angle = angle + 180;

	}

	return angle;

}



void ImpBrush::dragMouseScaling(const Point source, const Point target)
{

	//TODO: Render a red line that shows the new line brush size and angle
}

