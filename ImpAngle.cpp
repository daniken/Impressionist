//
// ImpBrush.cpp
//
// The implementation of virtual brush. All the other brushes inherit from it.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ImpAngle.h"
#include <iostream>

// Static class member initializations
int			ImpAngle::c_nAngleCount = 0;
ImpAngle**	ImpAngle::c_pAngles = NULL;


ImpAngle::ImpAngle(ImpressionistDoc*	pDoc,
	char*				name) :
	m_pDoc(pDoc),
	m_pAngleName(name)
{
}

//---------------------------------------------------
// Return m_pDoc, which connects the UI and angles
//---------------------------------------------------
ImpressionistDoc* ImpAngle::GetDocument(void)
{
	return m_pDoc;
}

//---------------------------------------------------
// Return the name of the current angle configuration
//---------------------------------------------------
char* ImpAngle::AngleName(void)
{
	return m_pAngleName;
}




