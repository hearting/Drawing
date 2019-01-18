#pragma once
#include "CShape.h"
#include"AttributeDialog.h"
class CEllipse :public CShape
{
public:
	CEllipse();
	~CEllipse();
	CEllipse(int orgX, int orgY, int hRadius, int vRadius, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void GetShapeValue(AttributeDialog& shapedlg);
	void SetShapeValue(AttributeDialog& shapedlg);
	void Draw(CDC*pDC);//绘制正方形
	bool IsMatched(CPoint pnt);	//重载点pnt是否落在图元内
	void Serialize(CArchive& ar);//序列化正方形图元
	int width,height;
	DECLARE_SERIAL(CEllipse)//声明类CEllipse支持序列化
};

