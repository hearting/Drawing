#include "stdafx.h"
#include "CText.h"
#include"AttributeDialog.h"
#include <math.h>
IMPLEMENT_SERIAL(CText, CObject, 6)//实现类CSquare的序列化，指定版本为6
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
	//创建画笔及用来保存原画笔的指针
	CFont*		pOldFont;
	CFont*		pNewFont = new CFont;
	pNewFont->CreateFont(
		height, //1.字体高度
		50,//2.字体宽度
		angle,//3.移位向量和x周夹角 （倾斜角度：0.1度为单位)
		0,//4.字符基线和x轴夹角
		100,//5.字体权值（线条的宽度）
		FALSE,//6.斜体（TRUE）
		FALSE,//7.下划线（TRUE）
		0,//8.删除线（TRUE或者FALSE），也可以用0，1
		ANSI_CHARSET, OUT_DEFAULT_PRECIS,//字符集，一般不动
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH&FF_SWISS,
		"Aerial");//字体
	pOldFont = (CFont *)pDC->SelectObject(pNewFont);
	pDC->SetBkColor(FillColor);
	pDC->TextOut(OrgX, OrgY, text);
	pot = pDC->GetTextExtent(text);//使用该函数获得所选字体中指定字符串的高度和宽度
	pDC->SelectObject(pOldFont);
	delete pNewFont;
}
void CText::Serialize(CArchive &ar)
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
		ar << height;
		ar << angle;
		ar << text;
	}
	//读取文件
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
		ar >> height;
		ar >> angle;
		ar >> text;
	}
}
bool CText::IsMatched(CPoint pnt)//图元匹配函数
{
		int L = pot.cx;
		int W = pot.cy;//字符串长度*字符宽度
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