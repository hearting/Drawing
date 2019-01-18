#pragma once
#include <afx.h>
#include"AttributeDialog.h"
enum ElementType {SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT };

class CShape : public CObject
{
public:
	CShape();
	virtual ~CShape();
	virtual void Draw(CDC*pDC) = 0;//绘制图元
	virtual bool IsMatched(CPoint pnt) = 0;//点是否落在图形内部
	virtual void Serialize(CArchive& ar) = 0;
	void SetAttribute(int orgX, int orgY,COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType); //改变图形属性表函数
	/*virtual void GetShapeValue(AttributeDialog & shapedlg) = 0;
	virtual void SetShapeValue(AttributeDialog & shapedlg) = 0;*/

	ElementType Type;//图元类型
	int OrgX;//原点坐标
	int OrgY;
	int width;
	COLORREF   BorderColor;//边界颜色
	int BorderType;//边界线型--实线、虚线、虚点线等
	int BorderWidth;//边界宽度
	COLORREF  FillColor;//填充颜色
	int FillType;//填充类型--实心、双对角、十字交叉等
};


