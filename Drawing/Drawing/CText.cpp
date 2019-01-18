#include "stdafx.h"
#include "CText.h"
#include"AttributeDialog.h"
#include <math.h>
IMPLEMENT_SERIAL(CText, CObject, 6)//ʵ����CSquare�����л���ָ���汾Ϊ6
CText::CText()
{
	Type = (ElementType)5;
}

void CText::GetShapeValue(AttributeDialog& shapedlg)
{
	shapedlg.Width = (int)(angle*0.1);
	shapedlg.Height = height;
	shapedlg.textContent= text;
}

void  CText::SetShapeValue(AttributeDialog& shapedlg)
{
	angle = shapedlg.Width * 10;
	height = shapedlg.Height;
	text = shapedlg.textContent;
}

CText::CText(int orgX, int orgY, CString textContent, int textAngle,int h, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)5;
	OrgX = orgX;
	OrgY = orgY;
	text = textContent;
	angle = textAngle*10;
	height = h;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}

void CText::Draw(CDC* pDC)
{
	//�������ʼ���������ԭ���ʵ�ָ��
	CFont*		pOldFont;
	CFont*		pNewFont = new CFont;
	pNewFont->CreateFont(
		height, //1.����߶�
		50,//2.������
		angle,//3.��λ������x�ܼн� ����б�Ƕȣ�0.1��Ϊ��λ)
		0,//4.�ַ����ߺ�x��н�
		100,//5.����Ȩֵ�������Ŀ�ȣ�
		FALSE,//6.б�壨TRUE��
		FALSE,//7.�»��ߣ�TRUE��
		0,//8.ɾ���ߣ�TRUE����FALSE����Ҳ������0��1
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,//�ַ�����һ�㲻��
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH&FF_SWISS,
		"Aerial");//����
	pOldFont = (CFont *)pDC->SelectObject(pNewFont);
	pDC->SetBkColor(FillColor);
	pDC->TextOut(OrgX, OrgY, text);
	pot = pDC->GetTextExtent(text);//ʹ�øú��������ѡ������ָ���ַ����ĸ߶ȺͿ��
	pDC->SelectObject(pOldFont);
	delete pNewFont;
}
void CText::Serialize(CArchive &ar)
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
		ar << height;
		ar << angle;
		ar << text;
	}
	//��ȡ�ļ�
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
		ar >> height;
		ar >> angle;
		ar >> text;
	}
}
bool CText::IsMatched(CPoint pnt)//ͼԪƥ�亯��
{
		int L = pot.cx;
		int W = pot.cy;//�ַ�������*�ַ����
		int x1, y1, x2, y2, x3, y3, x4, y4;
		x1 = OrgX; y1 = OrgY;
		x2 =int(( cos(3.1415926 / 2 - angle * 0.1*0.01745)*W + OrgX + cos(angle*0.1*0.01745)*L));
		y2 = int(OrgY + sin(3.1415926 / 2 - angle * 0.1*0.01745)*W - L * sin(angle*0.1*0.01745));
		x3 = int(cos(3.1415926 / 2 - angle * 0.1*0.01745)*W + OrgX);
		y3 =int( OrgY + sin(3.1415926 / 2 - angle * 0.1*0.01745)*W);
		x4 =int (cos(angle*0.1*0.01745)*L + OrgX);
		y4 =int( OrgY - sin(angle*0.1*0.01745)*L);
		CPoint P[4];
		P[0].x = x1; P[0].y = y1;
		P[1].x =x3; P[1].y = y3;
		P[2].x = x2; P[2].y = y2;
		P[3].x = x4; P[3].y = y4;
		CRgn rgn;
		rgn.CreatePolygonRgn(P, 4, ALTERNATE);
		if (rgn.PtInRegion(pnt))
			return true;
		else
			return false;
}
CText::~CText()
{
}