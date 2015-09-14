//
// ScatteredLines.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredLines.h"
#include "math.h"

extern float frand();

ScatteredLines::ScatteredLines(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatteredLines::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);

}

void ScatteredLines::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("PolyBursh::BrushMove  document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	size = size / 2;


	float angle = (float)pDoc->getAngle();
	float pi = 3.141592;
	float degToRad = pi / 180;

	int amountOfLines = 4;
	int randomX;
	int randomY;


	// line width
	int lineWidth = pDoc->getLineWidth();
	GLfloat width((float)lineWidth);
	glLineWidth(width);

	for (int i = 0; i < amountOfLines; i++){

		randomX = rand() % size - size / 2;
		randomY = rand() % size - size / 2;


		// extension coordinates
		int vertexX = size*cos(angle*degToRad);
		int vertexY = size*sin(angle*degToRad);

		int x = target.x + randomX;
		int y = target.y + randomY;


		glBegin(GL_LINES);
		SetColor(Point(x, y));

		glVertex2i(x - vertexX, y - vertexY);
		glVertex2i(x + vertexX, y + vertexY);

		glEnd();
	}
}

void ScatteredLines::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}
