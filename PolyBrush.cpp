//
// PolyBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "polyBrush.h"
#include "math.h"

extern float frand();

PolyBrush::PolyBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void PolyBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);

}

void PolyBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("PolyBursh::BrushMove  document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	float corner = (float)pDoc->getCorner();
	float angle = (float)pDoc->getAngle();
	float pi = 3.141592;
	float degToRad = pi / 180;


	// init matrix
	glPushMatrix();
	glTranslated(target.x, target.y, 0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glTranslated(-target.x, -target.y, 0);
	glBegin(GL_POLYGON);
	SetColor(source);

	for (int i = 0; i < corner; i++) {
		glVertex2i(target.x + cos((float)degToRad*((float)i) * 360.0 / corner)*size, target.y + sin((float)degToRad*((float)i) * 360.0 / corner)*size);
	}

	//gl_draw("hello", target.x , target.y);
	glEnd();
	//glFlush();

	glPopMatrix();
}

void PolyBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}



