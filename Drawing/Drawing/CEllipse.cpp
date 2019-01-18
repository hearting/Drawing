#include "stdafx.h"
#include "CEllipse.h"
#include"AttributeDialog.h"
IMPLEMENT_SERIAL(CEllipse, CObject, 4)//实现类CSquare的序列化，指定版本为4

CEllipse::CEllipse()
{
	Type = (ElementType)3;
}

void CEllipse::GetShapeValue(AttributeDialog& shapedlg)
{
	shapedlg.Width = width;
	shapedlg.Height = height;
}

void  CEllipse::SetShapeValue(AttributeDialog& shapedlg)
{
	width = shapedlg.Width;
	height = shapedlg.Height;
}
CEllipse::CEllipse(int orgX, int orgY, int hRadius, int vRadius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)3;
	OrgX = orgX;
	OrgY = orgY;
	height = hRadius;
	width = vRadius;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}
void CEllipse::Draw(CDC* pDC)//绘制图形函数
{//创建画笔及用来保存原画笔的指针
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	//创建刷子及用来保存原刷子的指针
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	//绘制图形
	pDC->Ellipse(OrgX - width / 2, OrgY - height/ 2, OrgX + width, OrgY + height);
	//使用当前画笔和刷子
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
bool CEllipse::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((pnt.x >= OrgX - width / 2) && (pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY - height / 2)
		&& (pnt.y <= OrgY + height / 2))
		return true;
	else
	return false;
}

void CEllipse::Serialize(CArchive &ar)
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
		ar << height;
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
		ar << height;
	}
}

CEllipse::~CEllipse()
{
}
