// 
// impressionistDoc.cpp
//
// It basically maintain the bitmap for answering the color query from the brush.
// It also acts as the bridge between brushes and UI (including views)
//

#include <FL/fl_ask.H>

#include "impressionistDoc.h"
#include "impressionistUI.h"

#include "ImpBrush.h"
#include "ImpAngle.h"

// Include individual brush headers here.
#include "PointBrush.h"
#include "PolyBrush.h"
#include "ScatterPoints.h"
#include "LineBrush.h"
#include "ScatteredPolygon.h"
#include "ScatteredLines.h"

// Include individual angle headers here.
#include "AngleSlider.h" 
#include "AngleMouseDirection.h"
#include "AngleMouseRightClick.h"
#include "AngleGradient.h"


#define DESTROY(p)	{  if ((p)!=NULL) {delete [] p; p=NULL; } }

ImpressionistDoc::ImpressionistDoc() 
{
	// Set NULL image name as init. 
	m_imageName[0]	='\0';	

	m_nWidth		= -1;
	m_ucBitmap		= NULL;
	m_ucPainting	= NULL;


	// create one instance of each brush
	ImpBrush::c_nBrushCount	= NUM_BRUSH_TYPE;
	ImpBrush::c_pBrushes	= new ImpBrush* [ImpBrush::c_nBrushCount];

	// create one instance of each angle type
	ImpAngle::c_nAngleCount = NUM_ANGLE_TYPE;
	ImpAngle::c_pAngles = new ImpAngle* [ImpAngle::c_nAngleCount];

	ImpBrush::c_pBrushes[BRUSH_POINTS]	= new PointBrush( this, "Points" );
	// Note: You should implement these 5 brushes.  They are set the same (PointBrush) for now
	ImpBrush::c_pBrushes[BRUSH_LINES]				
		= new LineBrush( this, "Lines" );
	ImpBrush::c_pBrushes[BRUSH_POLYGON]				
		= new PolyBrush(this, "Polygon");
	ImpBrush::c_pBrushes[BRUSH_SCATTERED_POINTS]	
		= new ScatterPoints( this, "Scattered Points" );
	ImpBrush::c_pBrushes[BRUSH_SCATTERED_LINES]		
		= new ScatteredLines( this, "Scattered Lines" );
	ImpBrush::c_pBrushes[BRUSH_SCATTERED_CIRCLES]	
		= new ScatteredPolygon( this, "Scattered Polygon" );





	// initialize all the angle types
	ImpAngle::c_pAngles[ANGLE_SLIDER] = new AngleSlider(this, "Angle Slider");
	ImpAngle::c_pAngles[ANGLE_MOUSE_DIRECTION] = new AngleMouseDirection(this, "Mouse Direction");
	ImpAngle::c_pAngles[ANGLE_MOUSE_RIGHT_CLICK] = new AngleMouseRightClick(this, "Mouse Right Click");
	ImpAngle::c_pAngles[ANGLE_GRADIENT] = new AngleGradient(this, "Gradient");


	// make one of the brushes current
	m_pCurrentBrush	= ImpBrush::c_pBrushes[0];

	// make one of the angle types current
	m_pCurrentAngleType = ImpAngle::c_pAngles[0];

}


//---------------------------------------------------------
// Set the current UI 
//---------------------------------------------------------
void ImpressionistDoc::setUI(ImpressionistUI* ui) 
{
	m_pUI	= ui;
}

//---------------------------------------------------------
// Returns the active picture/painting name
//---------------------------------------------------------
char* ImpressionistDoc::getImageName() 
{
	return m_imageName;
}

//---------------------------------------------------------
// Called by the UI when the user changes the brush type.
// type: one of the defined brush types.
//---------------------------------------------------------
void ImpressionistDoc::setBrushType(int type)
{
	m_pCurrentBrush	= ImpBrush::c_pBrushes[type];
}

void ImpressionistDoc::setAngleType(int type)
{
	m_pCurrentAngleType = ImpAngle::c_pAngles[type];
	m_nCurrentAngleIntType = type;
}


ImpAngle* ImpressionistDoc::getCurrentAngleType() {

	return m_pCurrentAngleType;
}

int ImpressionistDoc::getCurrentAngleIntType() {

	return m_nCurrentAngleIntType;
}


//---------------------------------------------------------
// Returns the size of the brush.
//---------------------------------------------------------
int ImpressionistDoc::getSize()
{
	return m_pUI->getSize();
}

//---------------------------------------------------------
// Returns the amount of corners of the brush.
//---------------------------------------------------------
int ImpressionistDoc::getCorner()
{
	return m_pUI->getCorner();
}

//---------------------------------------------------------
// Returns the alpha value
//---------------------------------------------------------
int ImpressionistDoc::getAlpha()
{
	return m_pUI->getAlpha();
}

//---------------------------------------------------------
// Returns the angle value
//---------------------------------------------------------
int ImpressionistDoc::getAngle()
{
	return m_pUI->getAngle();
}

//---------------------------------------------------------
// Returns the line width
//---------------------------------------------------------
int ImpressionistDoc::getLineWidth()
{
	return m_pUI->getLineWidth();
}

//---------------------------------------------------------
// sets the size of the brush.
//---------------------------------------------------------
void ImpressionistDoc::setSize(int size)
{
	m_pUI->setSize(size);
}

//---------------------------------------------------------
// sets the corner count
//---------------------------------------------------------
void ImpressionistDoc::setCorner(int corner)
{
	m_pUI->setCorner(corner);
}


//---------------------------------------------------------
// sets the alpha value
//---------------------------------------------------------
void ImpressionistDoc::setAlpha(int alpha)
{
	m_pUI->setAlpha(alpha);
}

//---------------------------------------------------------
// sets the angle.
//---------------------------------------------------------
void ImpressionistDoc::setAngle(int angle)
{
	m_pUI->setAngle(angle);
}

//---------------------------------------------------------
// Load the specified image
// This is called by the UI when the load image button is 
// pressed.
//---------------------------------------------------------
int ImpressionistDoc::loadImage(char *iname) 
{
	// try to open the image to read
	unsigned char*	data;
	int				width, 
					height;

	if ( (data=readBMP(iname, width, height))==NULL ) 
	{
		fl_alert("Can't load bitmap file");
		return 0;
	}

	// reflect the fact of loading the new image
	m_nWidth		= width;
	m_nPaintWidth	= width;
	m_nHeight		= height;
	m_nPaintHeight	= height;

	// release old storage
	if ( m_ucBitmap ) delete [] m_ucBitmap;
	if ( m_ucPainting ) delete [] m_ucPainting;

	m_ucBitmap		= data;

	// allocate space for draw view
	m_ucPainting	= new unsigned char [width*height*3];
	memset(m_ucPainting, 0, width*height*3);

	m_pUI->m_mainWindow->resize(m_pUI->m_mainWindow->x(), 
								m_pUI->m_mainWindow->y(), 
								width*2, 
								height+25);

	// display it on origView
	m_pUI->m_origView->resizeWindow(width, height);	
	m_pUI->m_origView->refresh();

	// refresh paint view as well
	m_pUI->m_paintView->resizeWindow(width, height);	
	m_pUI->m_paintView->refresh();


	return 1;
}


//----------------------------------------------------------------
// Save the specified image
// This is called by the UI when the save image menu button is 
// pressed.
//----------------------------------------------------------------
int ImpressionistDoc::saveImage(char *iname) 
{

	writeBMP(iname, m_nPaintWidth, m_nPaintHeight, m_ucPainting);

	return 1;
}

//----------------------------------------------------------------
// Clear the drawing canvas
// This is called by the UI when the clear canvas menu item is 
// chosen
//-----------------------------------------------------------------
int ImpressionistDoc::clearCanvas() 
{

	// Release old storage
	if ( m_ucPainting ) 
	{
		delete [] m_ucPainting;

		// allocate space for draw view
		m_ucPainting	= new unsigned char [m_nPaintWidth*m_nPaintHeight*3];
		memset(m_ucPainting, 0, m_nPaintWidth*m_nPaintHeight*3);

		// refresh paint view as well	
		m_pUI->m_paintView->refresh();
	}
	
	return 0;
}

//------------------------------------------------------------------
// Get the color of the pixel in the original image at coord x and y
//------------------------------------------------------------------
GLubyte* ImpressionistDoc::GetOriginalPixel( int x, int y )
{
	if ( x < 0 ) 
		x = 0;
	else if ( x >= m_nWidth ) 
		x = m_nWidth-1;

	if ( y < 0 ) 
		y = 0;
	else if ( y >= m_nHeight ) 
		y = m_nHeight-1;

	return (GLubyte*)(m_ucBitmap + 3 * (y*m_nWidth + x));
}

//----------------------------------------------------------------
// Get the color of the pixel in the original image at point p
//----------------------------------------------------------------
GLubyte* ImpressionistDoc::GetOriginalPixel( const Point p )
{
	return GetOriginalPixel( p.x, p.y );
}

