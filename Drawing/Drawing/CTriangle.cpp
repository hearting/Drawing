#include "stdafx.h"
#include "CTriangle.h"
#include "AttributeDialog.h"
#include <math.h>
IMPLEMENT_SERIAL(CTriangle, CObject, 5)//ʵ����CTriangle�����л���ָ���汾Ϊ5

CTriangle::CTriangle()
{
	Type = (ElementType)4;
}
void CTriangle::GetShapeValue(AttributeDialog& shapedlg)
{
	shapedlg.Width = width;
}

void  CTriangle::SetShapeValue(AttributeDialog& shapedlg)
{
	width = shapedlg.Width;
}

CTriangle::~CTriangle()
{
}

CTriangle::CTriangle(int orgX, int orgY, int Width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)4;//ͼԪ����
	OrgX = orgX;
	OrgY = orgY;
	width = Width;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}
void CTriangle::Draw(CDC* pDC)//����ͼ�κ���
{   // �������ʼ���������ԭ���ʵ�ָ��
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	//����ˢ�Ӽ���������ԭˢ�ӵ�ָ��
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	POINT pts[3] = {{OrgX - width /2, long(OrgY + width /2/1.73)},{OrgX, long(OrgY-width/1.73)},{OrgX+width/2,long(OrgY+width/2 /1.73)}};
	pDC->Polygon(pts,3);
	
	//ʹ�õ�ǰ���ʺ�ˢ��
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
bool CTriangle::IsMatched(CPoint pnt)//ͼԪƥ�亯��
{
	CPoint p0, p1, p2;
	p0.x = (OrgX - width / 2) - pnt.x;  p0.y = long ((OrgY + width / 2 / 1.73) - pnt.y);
	p1.x = (OrgX + width / 2) - pnt.x;  p1.y = long((OrgY + width / 2 / 1.73) - pnt.y);
	p2.x = OrgX - pnt.x;  p2.y =long((OrgY - width / 1.73) - pnt.y);
	double a = p0.x*p0.x + p0.y*p0.y;
	double b = p1.x*p1.x + p1.y*p1.y;
	double c = p2.x*p2.x + p2.y*p2.y;
	double A = (p0.x - p1.x)*(p0.x - p1.x) + (p0.y - p1.y)*(p0.y - p1.y);
	double B = (p0.x - p2.x)*(p0.x - p2.x) + (p0.y - p2.y)*(p0.y - p2.y);
	double C = (p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y);
	double a1 = acos((a + b - A) / (2 * sqrt(a) * sqrt(b)));
	double a2 = acos((a + c - B) / (2 * sqrt(a) * sqrt(c)));
	double a3 = acos((b + c - C) / (2 * sqrt(b) * sqrt(c)));
	if (fabs(2 * 3.1415926 - a1 - a2 - a3) < 0.000001)
		return true;
	else
	return false;
}

void CTriangle::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)Type;
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;
		ar << width;
	}
	else
	{
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
		ar << width;
	}
}
