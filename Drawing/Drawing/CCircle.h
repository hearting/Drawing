#pragma once
#include "CShape.h"
#include"AttributeDialog.h"
class CCircle :public CShape
{
public:
	CCircle();
	~CCircle();
	CCircle(int orgX, int orgY, int radius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);//绘制正方形
	bool IsMatched(CPoint pnt);	//重载点pnt是否落在图元内
	void Serialize(CArchive& ar);//序列化正方形图元
	virtual void GetShapeValue(AttributeDialog& shapedlg);
	virtual void SetShapeValue(AttributeDialog& shapedlg);
	int radius;
	DECLARE_SERIAL(CCircle)//声明类CCircle支持序列化
};

