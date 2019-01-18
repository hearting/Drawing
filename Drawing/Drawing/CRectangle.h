#pragma once
#include"CShape.h"
#include"AttributeDialog.h"
class CRectangle : public CShape
{
public:
	CRectangle();
	~CRectangle();
	void Draw(CDC*pDC);//绘制正方形
	bool IsMatched(CPoint pnt);	//重载点pnt是否落在图元内
	void Serialize(CArchive& ar);//序列化正方形图元
	CRectangle(int orgX, int orgY, int Width, int Height, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	virtual void GetShapeValue(AttributeDialog& shapedlg);
	virtual void SetShapeValue(AttributeDialog& shapedlg);
	int width, height;
	DECLARE_SERIAL(CRectangle)//声明类CSquare支持序列化
};



