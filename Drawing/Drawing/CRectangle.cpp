#include "stdafx.h"
#include "CRectangle.h"
#include"AttributeDialog.h"
IMPLEMENT_SERIAL(CRectangle, CObject, 2)//ʵ����CRectangle�����л���ָ���汾Ϊ2

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
	Type = (ElementType)1;//ͼԪ����
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
void CRectangle::Draw(CDC* pDC)//����ͼ�κ���
{//�������ʼ���������ԭ���ʵ�ָ��
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);
	//����ˢ�Ӽ���������ԭˢ�ӵ�ָ��
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);
	//����ͼ��
	pDC->Rectangle(OrgX -  width/ 2, OrgY - height / 2, OrgX + width / 2, OrgY + height / 2);
	//ʹ�õ�ǰ���ʺ�ˢ��
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
bool CRectangle::IsMatched(CPoint pnt)//ͼԪƥ�亯��
{
	if ((pnt.x >= OrgX - width / 2) && (pnt.x <= OrgX + width / 2) && (pnt.y >= OrgY -height/2)
    && (pnt.y <= OrgY + height / 2))
	return true;
	else
	return false;
}

void CRectangle::Serialize(CArchive &ar)
{//�����ļ�
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
	{		//��ȡ�ļ�
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
