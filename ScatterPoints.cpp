//
// PolyBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatterPoints.h"
#include "math.h"

extern float frand();

ScatterPoints::ScatterPoints(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatterPoints::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)1);

	BrushMove(source, target);

}

void ScatterPoints::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatterPoints::BrushMove  document is NULL\n");
		return;
	}

	int size = pDoc->getSize();


	glBegin(GL_POINTS);
	

	int randomX;
	int randomY;
	int directionX;
	int directionY;
	Point newPoint;

	for (int i = 0; i < size; i++) {

		randomX = rand() % size;
		randomY = rand() % size;

		// decides if point shoud be negative or positive relative to target
		directionX = rand() % 1;
		if (directionX == 0) directionX = -1;

		// decides if point shoud be negative or positive relative to target
		directionY = rand() % 1;
		if (directionY == 0) directionY = -1;

		// get the correct color
		newPoint = Point(target.x + directionX * randomX, target.y + directionY * randomY);
		SetColor(newPoint);

		glVertex2i(target.x + directionX * randomX, target.y + directionY * randomY);
	}

	glEnd();
}

void ScatterPoints::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}


void ScatterPoints::startMouseScaling(const Point source, const Point target)
{

}

void ScatterPoints::stopMouseScaling(const Point source, const Point target)
{

}



void ScatterPoints::dragMouseScaling(const Point source, const Point target)
{

}