// 
// impressionistDoc.h
//
// header file for Doc 
//

#ifndef ImpressionistDoc_h
#define ImpressionistDoc_h

#include "impressionist.h"
#include "bitmap.h"

class ImpressionistUI;

class ImpressionistDoc 
{
public:
	ImpressionistDoc();

	void	setUI(ImpressionistUI* ui);		// Assign the UI to use

	int		loadImage(char *iname);			// called by the UI to load image
	int		saveImage(char *iname);			// called by the UI to save image


	int     clearCanvas();                  // called by the UI to clear the drawing canvas

	void	setBrushType(int type);			// called by the UI to set the brushType
	void	setAngleType(int type);			// called by the UI to record what angle configuration is active

	int		getCurrentAngleIntType();				// called by the UI to set angle depending on what angle type is active
	ImpAngle*	getCurrentAngleType();


	int		getSize();						// get the UI size
	int		getCorner();					// get the UI corner
	int		getAlpha();						// get the UI alpha
	int		getAngle();						// get the UI angle
	int		getLineWidth();					// get the UI width

	void	setSize(int size);				// set the UI size
	void	setCorner(int corner);			// set the UIc corner
	void	setAlpha(int alpha);			// set the UI alpha
	void	setAngle(int angle);			// set the UI angle
	void	setLineWidth(int width);			// set the UI width

	char*	getImageName();					// get the current image name
	

// Attributes
public:
	// Dimensions of original window.
	int				m_nWidth, 
					m_nHeight;
	// Dimensions of the paint window.
	int				m_nPaintWidth, 
					m_nPaintHeight;	
	// Bitmaps for original image and painting.
	unsigned char*	m_ucBitmap;
	unsigned char*	m_ucPainting;


	// The current active brush.
	ImpBrush*			m_pCurrentBrush;
	ImpAngle*			m_pCurrentAngleType;

	
	int m_nSize;			// Size of the brush.		
	int m_nCorner;			// amount of coners for the polygon brush
	int m_nAlpha;			// alpha value of the brush
	int m_nAngle;			// angle value of the brush
	int m_nLineWidth;		// line width of the line brushes
	int m_nCurrentAngleIntType;	// the corresponding of the active angle configuration

	ImpressionistUI*	m_pUI;

// Operations
public:
	// Get the color of the original picture at the specified coord
	GLubyte* GetOriginalPixel( int x, int y );   
	// Get the color of the original picture at the specified point	
	GLubyte* GetOriginalPixel( const Point p );  


private:
	char			m_imageName[256];

};

extern void MessageBox(char *message);

#endif