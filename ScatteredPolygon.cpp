//
// ScatteredPolygon.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ScatteredPolygon.h"
#include "math.h"

extern float frand();

ScatteredPolygon::ScatteredPolygon(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatteredPolygon::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);

}

void ScatteredPolygon::BrushMove(const Point source, const Point target)
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

	int amountOfCircles = 4;
	int randomX;
	int randomY;


	for (int i = 0; i < amountOfCircles; i++){

		randomX = rand() % size - size/2;
		randomY = rand() % size - size/2;



		int x = target.x + randomX;
		int y = target.y + randomY;

		glBegin(GL_POLYGON);

		SetColor(Point(x,y));

		for (int j = 0; j < corner; j++) {
			glVertex2i(x + cos((float)degToRad*((float)j) * 360.0 / corner)*size, y + sin((float)degToRad*((float)j) * 360.0 / corner)*size);
		}

		glEnd();


	}



}

void ScatteredPolygon::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}



void ScatteredPolygon::startMouseScaling(const Point source, const Point target)
{
	//std::cout << "-------- - startMouseScaling() called---------" << std::endl;
	startMouseX = target.x;
	startMouseY = target.y;
	//std::cout << "start(x,y) = (" << startMouseX << ", " << startMouseY << ")" << std::endl;
}

void ScatteredPolygon::stopMouseScaling(const Point source, const Point target)
{
	//std::cout << "---------stopMouseScaling() called-------- - " << std::endl;
	stopMouseX = target.x;
	stopMouseY = target.y;
	//std::cout << "stop(x,y) = (" << stopMouseX << ", " << stopMouseY << ")" << std::endl;
	calculateSizeAndAngle();
}


void ScatteredPolygon::calculateSizeAndAngle() {

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;
	float degToRad = 3.141592f / 180.0f;


	// set size by pythagoras
	float mouseSize = sqrt((float)((startMouseX - stopMouseX)*(startMouseX - stopMouseX) + (startMouseY - stopMouseY)*(startMouseY - stopMouseY)));
	//std::cout << "setSize: " << (float)((startMouseX - stopMouseX)*(startMouseX - stopMouseX) + (startMouseY - stopMouseY)*(startMouseY - stopMouseY)) << std::endl;
	pDoc->setSize((int)mouseSize);

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

	//std::cout << "modified angle: " << angle << std::endl;
	pDoc->setAngle((int)angle);






}



void ScatteredPolygon::dragMouseScaling(const Point source, const Point target)
{

}