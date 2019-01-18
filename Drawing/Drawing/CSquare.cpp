#include "stdafx.h"
#include "CSquare.h"
#include"AttributeDialog.h"
IMPLEMENT_SERIAL(CSquare, CObject, 1)//ʵ����CSquare�����л���ָ���汾Ϊ1
CSquare::CSquare()
{
	Type = (ElementType)0;
}


CSquare::~CSquare()
{
}
void CSquare::Draw(CDC* pDC)//����ͼ�κ���
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
bool CSquare::IsMatched(CPoint pnt)//���������ص�pnt�Ƿ�����ͼԪ��
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