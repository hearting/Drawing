#include "stdafx.h"
#include "CEllipse.h"
#include"AttributeDialog.h"
IMPLEMENT_SERIAL(CEllipse, CObject, 4)//ʵ����CSquare�����л���ָ���汾Ϊ4

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
void CEllipse::Draw(CDC* pDC)//����ͼ�κ���
{//�������ʼ���������ԭ���ʵ�ָ��
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	//����ˢ�Ӽ���������ԭˢ�ӵ�ָ��
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	//����ͼ��
	pDC->Ellipse(OrgX - width / 2, OrgY - height/ 2, OrgX + width, OrgY + height);
	//ʹ�õ�ǰ���ʺ�ˢ��
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
bool CEllipse::IsMatched(CPoint pnt)//ͼԪƥ�亯��
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
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
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
		ar >> OrgX >> OrgY;//ԭ������
		ar >> BorderColor;//�߽���ɫ
		ar >> BorderType;
		ar >> BorderWidth;//�߽���
		ar >> FillColor;//
		ar >> FillType;
		ar << width;
		ar << height;
	}
}

CEllipse::~CEllipse()
{
}
