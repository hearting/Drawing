#pragma once
#include "CShape.h"
#include "AttributeDialog.h"
class CSquare :public CShape
{
public:
	CSquare();
	~CSquare();
	void Draw(CDC*pDC);//绘制正方形
	bool IsMatched(CPoint pnt);	//重载点pnt是否落在图元内
	void Serialize(CArchive& ar);//序列化正方形图元
	virtual void GetShapeValue(AttributeDialog& shapedlg);
	virtual void SetShapeValue(AttributeDialog& shapedlg);
	CSquare(int orgX, int orgY, int Width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	int width;
	DECLARE_SERIAL(CSquare)//声明类CSquare支持序列化
};

