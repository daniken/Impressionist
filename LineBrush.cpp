//
// PolyBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "lineBrush.h"
#include "math.h"
#include <iostream>

extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void LineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);



	//mouseDirection = true;
	// if mouse direction is chosen
	//if (mouseDirection) {
		//isDraging = true;
		
	//}

	BrushMove(source, target);

}

void LineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;


	if (pDoc == NULL) {
		printf("PolyBursh::BrushMove  document is NULL\n");
		return;
	}

	/*
	if (mouseDirection) {
		calculateMouseDirection(source, target);
	}
	*/

		// size
		int size = pDoc->getSize();
		size = size / 2;

		// rotation
		float pi = 3.141592;
		float degToRad = pi / 180;
		float angle = (float)pDoc->getAngle();

		// extension coordinates
		int x = size*cos(angle*degToRad);
		int y = size*sin(angle*degToRad);

		// line width
		int lineWidth = pDoc->getLineWidth();
		GLfloat width((float)lineWidth);
		glLineWidth(width);

		glBegin(GL_LINES);
		SetColor(source);


		glVertex2i(target.x - x, target.y - y);
		glVertex2i(target.x + x, target.y + y);

		
		glEnd();
		glFlush();



}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// stop the calculation of mouse direction 
	//if (mouseDirection) {
		//isDraging = false;
		//prevMouseX = 0;
		//prevMouseY = 0;
	//}
	
}



