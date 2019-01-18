#include "stdafx.h"
#include "CShape.h"
#include"AttributeDialog.h"
CShape::CShape()
{
}

void CShape::SetAttribute(int orgX, int orgY, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType)
{
	OrgX = orgX;
	OrgY = orgY;
	BorderColor = borderColor;
	BorderType = borderType;
	BorderWidth = borderWidth;
	FillColor = fillColor;
	FillType = fillType;
}
CShape::~CShape()
{
}
