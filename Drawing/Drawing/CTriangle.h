#pragma once
#include "CShape.h"
#include "AttributeDialog.h"
class CTriangle :public CShape
{
public:
	CTriangle();
	~CTriangle();
	CTriangle(int orgX, int orgY, int Width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	virtual void GetShapeValue(AttributeDialog& shapedlg);
	virtual void SetShapeValue(AttributeDialog& shapedlg);
	void Draw(CDC*pDC);//绘制正方形
	bool IsMatched(CPoint pnt);	//重载点pnt是否落在图元内
	virtual void Serialize(CArchive& ar);//序列化正方形图元
	int width;
	DECLARE_SERIAL(CTriangle)//声明类CSquare支持序列化
};

