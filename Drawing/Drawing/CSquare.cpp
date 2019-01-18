#include "stdafx.h"
#include "CSquare.h"
#include"AttributeDialog.h"
IMPLEMENT_SERIAL(CSquare, CObject, 1)//实现类CSquare的序列化，指定版本为1
CSquare::CSquare()
{
	Type = (ElementType)0;
}


CSquare::~CSquare()
{
}
void CSquare::Draw(CDC* pDC)//绘制图形函数
{
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	pDC->Rectangle(OrgX - width / 2, OrgY - width / 2, OrgX + width , OrgY + width);
	
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
} 
void CSquare::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//原点坐标
		ar << BorderColor;//边界颜色
		ar << BorderType;
		ar << BorderWidth;//边界宽度
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//原点坐标
		ar >> BorderColor;//边界颜色
		ar >> BorderType;
		ar >> BorderWidth;//边界宽度
		ar >> FillColor;//
		ar >> FillType;
		ar << width;
	}
}
bool CSquare::IsMatched(CPoint pnt)//正方形重载点pnt是否落在图元内
{
	if ((pnt.x >= OrgX - width / 2) && (pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY - width / 2) 
		&& (pnt.y <= OrgY + width / 2))
		return true;
	else
		return false;
}
CSquare::CSquare(int orgX, int orgY, int Width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)0;
	OrgX = orgX;
	OrgY = orgY;
	width = Width;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}

void CSquare::GetShapeValue(AttributeDialog& shapedlg)
{

	shapedlg.Width = width;
}

void  CSquare::SetShapeValue(AttributeDialog& shapedlg)
{

	width = shapedlg.Width;
}