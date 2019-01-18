#include "stdafx.h"
#include "CCircle.h"
#include"AttributeDialog.h"
IMPLEMENT_SERIAL(CCircle, CObject, 3)//实现类CCircle的序列化，指定版本为3

CCircle::CCircle()
{
	Type = (ElementType)2;
}

void CCircle::GetShapeValue(AttributeDialog &shapedlg)
{

	shapedlg.Width = radius;
}

void  CCircle::SetShapeValue(AttributeDialog& shapedlg)
{
	radius = shapedlg.Width;
}

CCircle::CCircle(int orgX, int orgY, int Radius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)2;
	OrgX = orgX;
	OrgY = orgY;
	radius = Radius;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}

void CCircle::Draw(CDC* pDC)//绘制图形函数
{//创建画笔及用来保存原画笔的指针
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	//创建刷子及用来保存原刷子的指针
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	//绘制图形
	pDC->Ellipse(OrgX - radius / 2, OrgY + radius / 2, OrgX + radius / 2, OrgY - radius / 2);
	//使用当前画笔和刷子
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
bool CCircle::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((pnt.x >= OrgX - radius/ 2) && (pnt.x <= OrgX + radius / 2) && (pnt.y >= OrgY - radius / 2)
		&& (pnt.y <= OrgY + radius / 2))
		return true;
	else
	return false;
}

void CCircle::Serialize(CArchive &ar)
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
		ar << radius;
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
		ar << radius;
	}
}
CCircle::~CCircle()
{
}
