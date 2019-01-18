#include "stdafx.h"
#include "CRectangle.h"
#include"AttributeDialog.h"
IMPLEMENT_SERIAL(CRectangle, CObject, 2)//实现类CRectangle的序列化，指定版本为2

CRectangle::CRectangle()
{
	Type = (ElementType)1;
}


CRectangle::~CRectangle()
{
}
void CRectangle::GetShapeValue(AttributeDialog& shapedlg)
{

	shapedlg.Width = width;
	shapedlg.Height = height;
}

void  CRectangle::SetShapeValue(AttributeDialog& shapedlg)
{

	width= shapedlg.Width;
	height = shapedlg.Height;
}
CRectangle::CRectangle(int orgX, int orgY, int Width, int Height, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)1;//图元类型
	OrgX = orgX;
	OrgY = orgY;
	width = Width;
	height = Height;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}
void CRectangle::Draw(CDC* pDC)//绘制图形函数
{//创建画笔及用来保存原画笔的指针
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	//创建刷子及用来保存原刷子的指针
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	//绘制图形
	pDC->Rectangle(OrgX -  width/ 2, OrgY - height / 2, OrgX + width / 2, OrgY + height / 2);
	//使用当前画笔和刷子
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
bool CRectangle::IsMatched(CPoint pnt)//图元匹配函数
{
	if ((pnt.x >= OrgX - width / 2) && (pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY -height/2)
    && (pnt.y <= OrgY + height / 2))
	return true;
	else
	return false;
}

void CRectangle::Serialize(CArchive &ar)
{//保存文件
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
	{		//读取文件
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
