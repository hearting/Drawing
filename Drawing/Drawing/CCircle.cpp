#include "stdafx.h"
#include "CCircle.h"
#include"AttributeDialog.h"
IMPLEMENT_SERIAL(CCircle, CObject, 3)//ʵ����CCircle�����л���ָ���汾Ϊ3

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

void CCircle::Draw(CDC* pDC)//����ͼ�κ���
{//�������ʼ���������ԭ���ʵ�ָ��
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	//����ˢ�Ӽ���������ԭˢ�ӵ�ָ��
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	//����ͼ��
	pDC->Ellipse(OrgX - radius / 2, OrgY + radius / 2, OrgX + radius / 2, OrgY - radius / 2);
	//ʹ�õ�ǰ���ʺ�ˢ��
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
bool CCircle::IsMatched(CPoint pnt)//ͼԪƥ�亯��
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
		ar << OrgX << OrgY;//ԭ������
		ar << BorderColor;//�߽���ɫ
		ar << BorderType;
		ar << BorderWidth;//�߽���
		ar << FillColor;//
		ar << FillType;
		ar << radius;
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
		ar << radius;
	}
}
CCircle::~CCircle()
{
}
