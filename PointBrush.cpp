//
// PointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "pointbrush.h"
#include "math.h"
#include <iostream>

extern float frand();

PointBrush::PointBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void PointBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize( (float)size );

	BrushMove( source, target );
}

void PointBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;


	if ( pDoc == NULL ) {
		printf( "PointBrush::BrushMove  document is NULL\n" );
		return;
	}

	glBegin( GL_POINTS );
		SetColor( source );

		glVertex2d( target.x, target.y );

	glEnd();
}

void PointBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}


void PointBrush::startMouseScaling(const Point source, const Point target)
{
	std::cout << "-------- - PointBrush::startMouseScaling() called---------" << std::endl;
	std::cout << "-------- - startMouseScaling() called---------" << std::endl;
	startMouseX = target.x;
	startMouseY = target.y;
	std::cout << "start(x,y) = (" << startMouseX << ", " << startMouseY << ")" << std::endl;
}

void PointBrush::stopMouseScaling(const Point source, const Point target)
{
	std::cout << "---------stopMouseScaling() called-------- - " << std::endl;
	stopMouseX = target.x;
	stopMouseY = target.y;
	std::cout << "stop(x,y) = (" << stopMouseX << ", " << stopMouseY << ")" << std::endl;
	calculateSizeAndAngle();
}


void PointBrush::calculateSizeAndAngle() {

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;
	float degToRad = 3.141592f / 180.0f;

	
	// set size by pythagoras
	float mouseSize = sqrt((float)((startMouseX - stopMouseX)*(startMouseX - stopMouseX) + (startMouseY - stopMouseY)*(startMouseY - stopMouseY)));
	std::cout << "setSize: " << (float)((startMouseX - stopMouseX)*(startMouseX - stopMouseX) + (startMouseY - stopMouseY)*(startMouseY - stopMouseY)) << std::endl;
	pDoc->setSize((int)mouseSize);

	// get angle

	float angle;

		float y = stopMouseY - startMouseY;
		angle = asinf(y/mouseSize);
		std::cout << "arcsin(y/hyp) * radToDeg: " << angle / degToRad << std::endl;

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
		else if (stopMouseX > startMouseX && stopMouseY > startMouseY) {
			// forth quadrant
			angle = -1 * angle;

		}



	


}



void PointBrush::dragMouseScaling(const Point source, const Point target)
{

}